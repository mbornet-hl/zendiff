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
 *   Author       :     Martial BORNET (MB) - June 06, 2011
 *
 *   File         :     z_gencat.c
 *
 *   @(#)  [Zen] z_gencat.c Version 1.10 of 23/09/17 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

/* Includes {{{ */

#include  <stdio.h>
#include  <fcntl.h>
#include  <unistd.h>
#include  <stdlib.h>
#include  <string.h>

#include  "../b/b_types.h"
#include  "../n/n_magic.h"
#include  "../i/i_cpub.h"
#include  "../m/m_cpub.h"
#include  "../y/y_cpub.h"
#include  "../c/c_msg.h"
#include  "z_epri.h"

/* Includes }}} */

/* main() {{{ */

/******************************************************************************

                              MAIN

******************************************************************************/
int main(int argc, char *argv[])
{
     int                                 _fd;
     struct y_desc_msgs                 *_ref_msgs;
     struct y_desc_msgs                 *_ref_htm;
     struct y_tl                         _tl;
     char                               *_catalog, *_m;
     int                                 _lang;

     if (argc != 3) {
          fprintf(stderr, "Usage : %s num_lang catalog\n", argv[0]);
          fprintf(stderr, " 0 : FR\n");
          fprintf(stderr, " 1 : UK\n");
          fprintf(stderr, " 2 : DE\n");
          exit(M_ERR_USAGE);
     }

     _lang          = atoi(argv[1]);
     _catalog       = argv[2];

     /* Ouverture du catalogue en ecriture
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     if ((_fd = open(_catalog, O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1) {
          fprintf(stderr, "open error\n");
          exit(M_ERR_OPEN);
     }

     _ref_msgs           = c_tab_msg;
     while (_ref_msgs->msgs) {
#if 0
          _p                  = _ref_msgs->msgs;
          while (*_p) {
               //fprintf(stderr, "%s\n", *_p);
               _tl.type            = _ref_msgs->id;
               _tl.length          = strlen(*_p) + 1;
               if (write(_fd, (char *) &_tl, sizeof(_tl)) != sizeof(_tl)) {
                    fprintf(stderr, "write error for TL\n");
                    exit(M_ERR_WRITE);
               }
               if (write(_fd, (char *) *_p, _tl.length) != _tl.length) {
                    fprintf(stderr, "write error for value\n");
                    exit(M_ERR_WRITE);
               }
               _p++;
          }
#else
          _m                  = _ref_msgs->msgs[_lang];
          _tl.type            = _ref_msgs->id;
//fprintf(stderr, "LANG [%d] ID [0x%08X] MSG[%s]\n", 0,  _tl.type,  _ref_msgs->msgs[0]);
//fprintf(stderr, "LANG [%d] ID [0x%08X] MSG[%s]\n", _lang,  _tl.type, _m);
          _tl.length          = strlen(_m) + 1;

          if (write(_fd, (char *) &_tl, sizeof(_tl)) != sizeof(_tl)) {
               fprintf(stderr, "write error for TL\n");
               exit(M_ERR_WRITE);
          }
          if (write(_fd, (char *) _m, _tl.length) != _tl.length) {
               fprintf(stderr, "write error for value\n");
               exit(M_ERR_WRITE);
          }
#endif
          _ref_msgs++;
     }

     _ref_htm                      = c_tab_htm;
     while (_ref_htm->msgs) {
#if 0
          _p                            = _ref_htm->msgs;
          while (*_p) {
               //fprintf(stderr, "%s\n", *_p);
               _tl.type            = _ref_msgs->id;
               _tl.length          = strlen(*_p) + 1;
               if (write(_fd, (char *) &_tl, sizeof(_tl)) != sizeof(_tl)) {
                    fprintf(stderr, "write error for TL\n");
                    exit(M_ERR_WRITE);
               }
               if (write(_fd, (char *) *_p, _tl.length) != _tl.length) {
                    fprintf(stderr, "write error for value\n");
                    exit(M_ERR_WRITE);
               }
               _p++;
          }
#else
          _m                  = _ref_htm->msgs[_lang];
          _tl.type            = _ref_htm->id;
//fprintf(stderr, "ID [0x%08X] HTM[%s]\n", _tl.type, _m);
          _tl.length          = strlen(_m) + 1;
          if (write(_fd, (char *) &_tl, sizeof(_tl)) != sizeof(_tl)) {
               fprintf(stderr, "write error for TL\n");
               exit(M_ERR_WRITE);
          }
          if (write(_fd, (char *) _m, _tl.length) != _tl.length) {
               fprintf(stderr, "write error for value\n");
               exit(M_ERR_WRITE);
          }
#endif
          _ref_htm++;
     }

     _ref_msgs           = c_tab_man;
     while (_ref_msgs->msgs) {
          _m                  = _ref_msgs->msgs[_lang];
          _tl.type            = _ref_msgs->id;
          _tl.length          = strlen(_m) + 1;

          if (write(_fd, (char *) &_tl, sizeof(_tl)) != sizeof(_tl)) {
               fprintf(stderr, "write error for TL\n");
               exit(M_ERR_WRITE);
          }
          if (write(_fd, (char *) _m, _tl.length) != _tl.length) {
               fprintf(stderr, "write error for value\n");
               exit(M_ERR_WRITE);
          }
          _ref_msgs++;
     }


     close(_fd);
     return 0;
}

/* main() }}} */
