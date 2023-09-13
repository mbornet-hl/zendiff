/* ============================================================================
 * Copyright (C) 2009-2023, Martial Bornet
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 *   Author       :     Martial BORNET (MB) - October 4, 2010
 *
 *   File         :     ai_sum.c
 *
 *   @(#)  [Zen] ai_sum.c Version 1.19 of 23/09/13 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

/* Includes {{{ */

#include  <stdio.h>
#include  <fcntl.h>
#include  <string.h>
#include  <unistd.h>
#include  <sys/types.h>
#include  <sys/stat.h>
#include  <stdlib.h>
#include  <utime.h>
#include  <sys/mman.h>

#include  "../b/b_types.h"
#include  "../m/m_cpub.h"
#include  "../ah/ah_cpub.h"
#include  "../ah/ah_epub.h"
#include  "../r/r_cpub.h"
#include  "../r/r_epub.h"
#include  "ai_md5.h"
#include  "ai_sha256.h"
#include  "ai_cpub.h"
#include  "ai_epub.h"
#include  "ai_cpri.h"

/* Includes }}} */
/* __file__ {{{ */

static char                   *__file__      = __FILE__;

/* __file__ }}} */

/* ai_file_checksums() {{{ */

/******************************************************************************

                              AI_FILE_CHECKSUMS

******************************************************************************/
int ai_file_checksums(char *pathname, b_uint32 sums, ai_ref_chksums ref_chksums)
{
     int                       _fd, _retcode, _filetype;
     unsigned long             _lg;
     FILE                     *_fp;
     struct stat               _stat;
     struct utimbuf            _inode_dates;
     char                     *_addr,
                               _buf[AI_BUFSIZE];
     bool                      _use_mmap;

     /* Initialisations
        ~~~~~~~~~~~~~~~ */
     _retcode            = M_RET_OK;
     _fp                 = 0;
     _addr               = 0;
     _use_mmap           = TRUE;

     /* Initialisation des checksums
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     ai_init_chksums(ref_chksums);

     /* Lecture des attributs du fichier
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     if (lstat(pathname, &_stat) == -1) {
          _retcode            = M_ERR_STAT;
          goto fin;
     }

     /* Memorisation des dates du fichier
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     _inode_dates.actime  = _stat.st_atime;
     _inode_dates.modtime = _stat.st_mtime;

     /* Initialisation de la longueur du fichier
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     _lg                 = _stat.st_size;

     _filetype           = _stat.st_mode & S_IFMT;
     if (_filetype == S_IFREG) {
          if (_lg != 0) {
               if (sizeof(void *) == 8 || _lg < AI_MAX_SIZE) {
                    /* Si programme 64 bits ou fichier < 2 Go : utilisation de mmap()
                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

                    /* Ouverture du fichier
                       ~~~~~~~~~~~~~~~~~~~~ */
                    if ((_fd = open(pathname, O_RDONLY)) == -1) {
                         _retcode            =  ai_checksums(0, 0, 0, sums, ref_chksums);
#if 0
                         _retcode            = M_ERR_OPEN;
                         perror("open()");
#endif
                         goto fin;
                    }

                    /* Mapping memoire du fichier
                       ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
                    if ((_addr = mmap(0, _lg, PROT_READ, MAP_PRIVATE, _fd, 0)) == MAP_FAILED) {
#if 0
                         fprintf(stderr, "%s (%d) : pathname = [%s] size = %lu\n", __file__, __LINE__, pathname, _lg);
                         perror("mmap");
#endif
                         _addr               = 0;
                         _use_mmap           = FALSE;

                         /* Reset du code retour
                            ~~~~~~~~~~~~~~~~~~~~ */
                         _retcode            = M_RET_OK;
                    }

                    /* Fermeture du fichier
                       ~~~~~~~~~~~~~~~~~~~~ */
                    close(_fd);
               }
               else {
                    _use_mmap           = FALSE;
               }

               if (!_use_mmap) {
                    /* Ouverture du fichier
                       ~~~~~~~~~~~~~~~~~~~~ */
                    if ((_fp = fopen(pathname, "r")) == 0) {
                         _retcode            = M_ERR_FOPEN;
                         goto fin;
                    }
               }

               /* Calculs des checksums
                  ~~~~~~~~~~~~~~~~~~~~~ */
               _retcode            =  ai_checksums(_fp, _addr, _lg, sums, ref_chksums);

               if (_use_mmap) {
                    /* Suppression du mapping memoire
                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
                    if (munmap(_addr, _lg) != 0) {
                         perror("munmap");
                         _retcode            = M_ERR_MUNMAP;
                         goto fin;
                    }
               }
               else {
                    /* Fermeture du fichier
                       ~~~~~~~~~~~~~~~~~~~~ */
                    if (fclose(_fp) != 0) {
                         _retcode            = M_ERR_FCLOSE;
                         goto fin;
                    }
               }

               /* Restauration des dates du fichier
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               utime(pathname, (const struct utimbuf *) &_inode_dates);
          }
     }
     else if (_filetype == S_IFLNK) {
          /* Recuperation du contenu du lien symbolique
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          if ((_lg = readlink(pathname, _buf, sizeof(_buf))) == -1) {
               perror("readlink");
               _retcode                 = M_ERR_READLINK;
          }
          else {
               /* Calcul de checksum du lien symbolique
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               _buf[_lg]           = 0;
               _retcode            =  ai_checksums(0, _buf, _lg, sums, ref_chksums);
//fprintf(stderr, "READLINK : %-50s => LENGTH = %3lu checksum = %d\n", pathname, _lg, ref_chksums->BSD);
          }
     }
     else {
          /* Initialisation des checksums a leur valeur par defaut
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          _retcode            =  ai_checksums(0, 0, 0, sums, ref_chksums);
     }

fin:
     return _retcode;
}

/* ai_file_checksums() }}} */
/* ai_next_char() {{{ */

/******************************************************************************

                              AI_NEXT_CHAR

******************************************************************************/
bool ai_next_char(FILE *fp, char **p, b_int64 *len, int *c)
{
     bool                 _retcode = FALSE;
     int                  _c;

     if (*p) {
          if ((*len)-- > 0) {
               *c                  = *((*p)++);
               _retcode            = TRUE;
          }
          else {
               *c                  = 0;
               _retcode            = FALSE;
          }
     }
     else if (fp) {
#if 0
          if ((*len)-- > 0) {
               *c                  = getc(fp);
               _retcode            = TRUE;
          }
          else {
               *c                  = 0;
               _retcode            = FALSE;
          }
#else
          if ((_c = getc(fp)) != EOF) {
               *c                  = _c;
               _retcode            = TRUE;
          }
          else {
               *c                  = 0;
               _retcode            = FALSE;
          }
#endif    /* 0 */
     }
     else {
          *c                  = 0;
          _retcode            = FALSE;
     }

     return _retcode;
}

/* ai_next_char() }}} */
/* ai_checksums() {{{ */

/*******************************************************************************

                              AI_CHECKSUMS

*******************************************************************************/
int ai_checksums(FILE *fp, char *mem, b_int64 length, b_uint32 sums, ai_ref_chksums ref_chksums)
{
     /**************************************************************************
      Calcul du checksum de la zone memoire pointee par "mem", de longueur
      "length".
      Les checksums a calculer sont indiques par la variable "sums".
     **************************************************************************/

/* Variables {{{ */

     int                       _retcode, _i, _offset;
     char                     *_p;
#if 0          // Unused variables
     char                     *_NOT_INITIALIZED = "*** NOT INITIALIZED ***";
     char                     *_SHA1, *_SHA224, *_SHA256, *_SHA384, *_SHA512;
#endif
     b_int64                   _lg;
     b_int32                   _BSDsum, _Sys_V;
     unsigned                  _hi, _lo, _checksum;
     int                       _c;
     union {
          struct words    hl;
          long            lg;
     }                         _sum, _tmp;

     ai_md5_context            _ctx_MD5;
     b_uint32                  _nb_MD5;
     byte                      _buf_MD5[AI_BUFSIZ_MD5];
     byte                      _md5sum[AI_SIZE_MD5];

     ai_sha256_context         _ctx_sha256;
     b_uint32                  _nb_sha256;
     byte                      _buf_sha256[AI_BUFSIZ_SHA256];
     byte                      _sha256sum[AI_SIZE_SHA256];

/* Variables }}} */

     /* RAZ du code retour
        ~~~~~~~~~~~~~~~~~~ */
     _retcode            = M_RET_OK;

     /* Controle des checksums demandes
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     if ((sums & AI_ALL_SUMS) == 0) {
          /* Erreur : aucun checksum demande
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          _retcode            = M_ERR_BAD_PARAM;
          goto fin;
     }

     /* Initialisations
        ~~~~~~~~~~~~~~~ */
     _p                  = mem;
     _lg                 = length;

     /* Initialisation des checksums
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     ai_init_chksums(ref_chksums);

     /* Checksum classique
        ~~~~~~~~~~~~~~~~~~ */
     _sum.lg             = 0;

     /* BSD
        ~~~ */
     _BSDsum             = 0;
     _Sys_V              = 0;
#if 0          // Unused variables
     _SHA1               = _NOT_INITIALIZED;
     _SHA224             = _NOT_INITIALIZED;
     _SHA256             = _NOT_INITIALIZED;
     _SHA384             = _NOT_INITIALIZED;
     _SHA512             = _NOT_INITIALIZED;
#endif

     /* MD5
        ~~~ */
     if (sums & AI_MD5) {
          ai_md5_starts(&_ctx_MD5);
          _nb_MD5             = 0;
     }

     /* SHA256
        ~~~~~~ */
     if (sums & AI_SHA256) {
          ai_sha256_starts(&_ctx_sha256);
          _nb_sha256          = 0;
     }

     /* Calcul des checksums
        ~~~~~~~~~~~~~~~~~~~~ */
     while (ai_next_char(fp, &_p, &_lg, &_c)) {
          /* Increment size
             ~~~~~~~~~~~~~~ */
          ref_chksums->size++;

          if (sums & AI_SUM) {
               /* Checksum classique
                  ~~~~~~~~~~~~~~~~~~ */
               _sum.lg   += _c & AI_MASK;
          }
          if (sums & AI_BSD) {
               /* BSD
                  ~~~ */
               _BSDsum    = (_BSDsum >> 1) + ((_BSDsum & 1) << 15);
               _BSDsum   += _c;
               _BSDsum   &= 0xffff;     /* Keep it within bounds. */
          }
          if (sums & AI_MD5) {
               /* MD5
                  ~~~ */
               _buf_MD5[_nb_MD5]        = _c;
               if (++_nb_MD5 == AI_BUFSIZ_MD5) {
                    ai_md5_update(&_ctx_MD5, _buf_MD5, _nb_MD5);
                    _nb_MD5              = 0;
               }
          }
          if (sums & AI_SHA256) {
               /* SHA256
                  ~~~~~~ */
               _buf_sha256[_nb_sha256]  = _c;
               if (++_nb_sha256 == AI_BUFSIZ_SHA256) {
                    ai_sha256_update(&_ctx_sha256, _buf_sha256, _nb_sha256);
                    _nb_sha256           = 0;
               }
          }
     }

     if (sums & AI_SUM) {
          /* Checksum classique
             ~~~~~~~~~~~~~~~~~~ */
          _tmp.lg                  = (_sum.hl.lo & AI_MASK) + (_sum.hl.hi & AI_MASK);
          _hi                      = (unsigned) _tmp.hl.hi;
          _lo                      = (unsigned) _tmp.hl.lo;
          _checksum                = _hi + _lo;

          ref_chksums->sum         = _checksum;
     }
     if (sums & AI_BSD) {
          /* BSD
             ~~~ */
          ref_chksums->BSD         = _BSDsum;
     }
     if (sums & AI_SYSV) {
          /* Sys V
             ~~~~~ */
          ref_chksums->Sys_V       = _Sys_V;
     }
     if (sums & AI_MD5) {
          /* MD5
             ~~~ */
          if (_nb_MD5) {
               ai_md5_update(&_ctx_MD5, _buf_MD5, _nb_MD5);
          }
          if ((ref_chksums->MD5 = R_MALLOC((2 * AI_SIZE_MD5) + 1)) == 0) {
               _retcode                 = M_ERR_MALLOC;
          }
          else {
               ai_md5_finish(&_ctx_MD5, _md5sum);

               for (_offset = 0, _i = 0; _i < AI_SIZE_MD5; _i++) {
                 _offset += sprintf(ref_chksums->MD5 + _offset, "%02x", _md5sum[_i]);
               }
          }
     }
#if 0
     if (sums & AI_SHA1) {
          /* SHA1
             ~~~~ */
          ref_chksums->SHA1        = _SHA1;
     }
     if (sums & AI_SHA224) {
          /* SHA224
             ~~~~~~ */
          ref_chksums->SHA224      = _SHA224;
     }
#endif
     if (sums & AI_SHA256) {
          /* SHA256
             ~~~~~~ */
          if (_nb_sha256) {
               ai_sha256_update(&_ctx_sha256, _buf_sha256, _nb_sha256);
          }
          if ((ref_chksums->SHA256 = R_MALLOC((2 * AI_SIZE_SHA256) + 1)) == 0) {
               _retcode                 = M_ERR_MALLOC;
          }
          else {
               ai_sha256_finish(&_ctx_sha256, _sha256sum);

               for (_offset = 0, _i = 0; _i < AI_SIZE_SHA256; _i++) {
                 _offset += sprintf(ref_chksums->SHA256 + _offset, "%02x", _sha256sum[_i]);
               }
          }
     }
#if 0
     if (sums & AI_SHA384) {
          /* SHA384
             ~~~~~~ */
          ref_chksums->SHA384      = _SHA384;
     }
     if (sums & AI_SHA512) {
          /* SHA512
             ~~~~~~ */
          ref_chksums->SHA512      = _SHA512;
     }
#endif

fin:
     return _retcode;
}

/* ai_checksums() }}} */
/* ai_init_chksums() {{{ */

/******************************************************************************

                              AI_INIT_CHKSUMS

******************************************************************************/
void ai_init_chksums(ai_ref_chksums ref_chksums)
{
     char                     *_NOT_INITIALIZED = "*** NOT INITIALIZED ***";

     ref_chksums->size             = 0;

     ref_chksums->sum              = 0;
     ref_chksums->BSD              = 0;
     ref_chksums->Sys_V            = 0;
     ref_chksums->MD5              = _NOT_INITIALIZED;
     ref_chksums->SHA256           = _NOT_INITIALIZED;
#if 0
     ref_chksums->SHA1             = _NOT_INITIALIZED;
     ref_chksums->SHA224           = _NOT_INITIALIZED;
     ref_chksums->SHA384           = _NOT_INITIALIZED;
     ref_chksums->SHA512           = _NOT_INITIALIZED;
#endif
}

/* ai_init_chksums() }}} */
