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
 *   Author       :     Martial BORNET (MB) - September 10, 2009
 *
 *   File         :     c_msg.h
 *
 *   @(#)  [Zen] ah_print.c Version 1.28 of 23/09/17 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

/* Includes {{{ */
#include  <stdio.h>
#include  <pthread.h>
#include  <stdarg.h>
#include  <string.h>
#include  <stdlib.h>
#include  <time.h>
#include  <sys/time.h>
#include  <sys/types.h>
#include  <unistd.h>
#include  <libgen.h>

#include  "../b/b_types.h"
#include  "../ap/ap_cpub.h"
#include  "../ap/ap_epub.h"
#include  "../m/m_cpub.h"
#include  "../r/r_cpub.h"
#include  "../r/r_epub.h"
#include  "../bh/bh_cpub.h"
#include  "../bh/bh_epub.h"
#include  "../bi/bi_epub.h"
#include  "ah_cpub.h"
#include  "ah_epub.h"
#include  "ah_epri.h"

/* Includes }}} */
/* File {{{ */

#if defined(R_CODE)
static char         *__file__      = __FILE__;
#endif

/* File }}} */
/* Debug macro Z {{{ */

#define   Z                   fprintf(stderr, "%s(%d)\n", __FILE__, __LINE__);

/* Debug macro Z }}} */

/* ah_init_prompts() {{{ */

/*******************************************************************************

                              AH_INIT_PROMPTS

*******************************************************************************/
void ah_init_prompts()
{
     /**************************************************************************
      Initialisation des prompts.
     **************************************************************************/
     ah_ref_prompt        _p;
     int                  _i;

     _i   = 0;
     _p   = &ah_prompt[0];
     while (_p->prompt) {
          /* Controle de coherence du tableau
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          if (AH_PROMPT(_p->indice) != _i) {
               fprintf(stderr, "Erreur interne: prompts\n");
               exit(M_ERR_INTERNAL);
          }

          /* Initialisation de la longueur du prompt
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          if (_p->lg == 0) _p->lg  = strlen(_p->prompt);

          _p++;
          _i++;
     }

     bh_mutex_init(&ah_mutex, "Print");
}

/* ah_init_prompts() }}} */
/* ah_init_ctx() {{{ */

/******************************************************************************

                              AH_INIT_CTX

******************************************************************************/
void ah_init_ctx(ah_ref_ctx ctx, FILE *fp_log, FILE *fp_tty, char *server)
{
     ctx->fp_log              = fp_log;
     ctx->fp_tty              = fp_tty;
     ctx->server              = server;
     ctx->time.tv_sec         = 0;
     ctx->time.tv_usec        = 0;
     ctx->mode                = 0;
}

/* ah_init_ctx() }}} */
/* ah_init() {{{ */

/******************************************************************************

                              AH_INIT

******************************************************************************/
void ah_init(ah_ref_ctx ctx, const char *log_path, char *progname,
     const char *server, b_uint32 mode, int columns)
{
     int             _fd_tty;
     ah_ref_ctx      _ctx;


#undef    X
#define   X              fprintf(stderr, "%s(%4d) : %s()\n", __file__, __LINE__, __func__);

//X
     _ctx                     = ctx ? ctx : &ah_ctx;

     /* Deplacement de stderr vers fp_tty
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     if ((_ctx->fp_tty = fopen("/dev/null", "w")) == NULL) {
          fprintf(stderr, "Cannot open \"/dev/null\"\n");
          exit(M_ERR_FOPEN);
     }
//X
     _fd_tty   = fileno(_ctx->fp_tty);
//X
     close(_fd_tty);
//X
     dup2(2, _fd_tty);
//X
     close(2);

//X
     /* Ouverture du fichier de logs
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     if ((_ctx->fp_log = fopen(log_path, "w")) == NULL) {
          fprintf(_ctx->fp_tty, "*** Erreur de creation du fichier de logs (%s)\n", log_path);
          perror("fopen");
          exit(M_ERR_OPEN);
     }
//X
     if (setvbuf(_ctx->fp_log, (char *) 0, _IONBF, 0)) {
          fprintf(_ctx->fp_tty, "Erreur de setvbuf\n");
          exit(M_ERR_SETVBUF);
     }

//X

     /* Initialisation des prompts
        ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     ah_init_prompts();
//X

     /* Initialisation du contexte
        ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     _ctx->progname           = progname;
     _ctx->prog_basename      = basename(progname);
     _ctx->columns            = columns;
     _ctx->mode               = mode;
     _ctx->server             = server;
     _ctx->time.tv_sec        = 0;
     _ctx->time.tv_usec       = 0;
//X
}

/* ah_init() }}} */
/* ah_prt() {{{ */

/*******************************************************************************

                              AH_PRT

*******************************************************************************/
void ah_prt(FILE *out, char *file, int line, int type, char *fmt, ...)
{
     /**************************************************************************
      Affichage formatte de messages.
     **************************************************************************/
     va_list         _ap;
     char           *_buf;
     int             _nb;

     va_start(_ap, fmt);

     /* Allocation memoire pour le buffer de formattage
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     if ((_buf = R_MALLOC(AH_BUFSIZE)) == 0) {
//        ah_clean_print(stderr, file, line, AH_ERR, ah_msg_004[ah_ind], 0);
          exit(M_ERR_MALLOC);
     }

     /* Formattage du message
        ~~~~~~~~~~~~~~~~~~~~~ */
     _nb  = vsprintf(_buf, fmt, _ap);

     /* Affichage du message avec cesure propre
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     ah_clean_print(out, file, line, type, _buf, _nb);

     /* Liberation de la memoire
        ~~~~~~~~~~~~~~~~~~~~~~~~ */
     R_FREE(&_buf);

     va_end(_ap);
}

/* ah_prt() }}} */
/* ah_clean_print() {{{ */

/*******************************************************************************

                              AH_CLEAN_PRINT

*******************************************************************************/
void ah_clean_print(FILE *out, char *file, int line, int type, char *msg,
                                                                      int size)
{
     /**************************************************************************
      Affichage formatte avec cesure propre.
     **************************************************************************/
     int                       _i, _lg_start, _lg_msg, _change, _prompt, *_pcolor;
     char                     *_p0, *_p1, *_p2, _c, _date[32];
     struct timeval            _time;
     struct tm                *_tm;
     int                       _sec, _usec;
     ah_ref_prompt             _p;

     /* Initialisation des variables
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     _lg_start      = 0;
     _change        = FALSE;
     _prompt        = TRUE;

     /* Reservation du verrou
        ~~~~~~~~~~~~~~~~~~~~~ */
     if (bh_mutex_lock(&ah_mutex) != 0) {
          /* Erreur de prise de verrou
             ~~~~~~~~~~~~~~~~~~~~~~~~~ */
          fprintf(out, "*** ERROR : pthread_mutex_lock\n");
     }

     if (AH_PROMPT(type & ~AH_T) != AH_VOID) {
          if (((ah_mode | type) & (AH_DSP_TIMESTAMP | AH_DSP_HIRES_TIMESTAMP | AH_DSP_DELTA_T))) {
               /* Lecture de l'heure systeme
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               if (gettimeofday(&_time, 0) != 0) {
                    perror("gettimeofday");
                    exit(M_ERR_GET_TIME);
               }
          }

          if (((ah_mode | type) & (AH_DSP_TIMESTAMP | AH_DSP_HIRES_TIMESTAMP))) {
               _tm       = localtime(&_time.tv_sec);
               sprintf(_date, "%4d-%02d-%02d %02d:%02d:%02d", 1900 + _tm->tm_year, _tm->tm_mon + 1, _tm->tm_mday,
                         _tm->tm_hour, _tm->tm_min, _tm->tm_sec);
          }

          if ((ah_mode | type) & AH_DSP_HIRES_TIMESTAMP) {
               /* Affichage du timestamp haute resolution
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               ap_color_fg(out, ah_col_timestamp);
               _lg_start += fprintf(out, "%s.%06d ", _date, (int) _time.tv_usec);
               _change    = TRUE;
//             _prompt    = FALSE;
          }
          else if ((ah_mode | type) & AH_DSP_TIMESTAMP) {
               /* Affichage du timestamp
                  ~~~~~~~~~~~~~~~~~~~~~~ */
               ap_color_fg(out, ah_col_timestamp);
               _lg_start += fprintf(out, "%s ", _date);
               _change    = TRUE;
//             _prompt    = FALSE;
          }

          if (((ah_mode | type) & AH_DSP_DELTA_T)) {
               if (type & AH_T) {
                    /* Lecture de l'heure systeme
                       ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
                    if (ah_time.tv_sec != 0 || ah_time.tv_usec != 0) {
                         _sec           = _time.tv_sec - ah_time.tv_sec;
                         if (_time.tv_usec < ah_time.tv_usec) {
                              _usec          = 1000000 + _time.tv_usec - ah_time.tv_usec;
                              _sec           -= 1;
                         }
                         else {
                              _usec          = _time.tv_usec - ah_time.tv_usec;
                         }
                         _lg_start += fprintf(out, "%6d.%06d s ", _sec, _usec);
                    }
                    else {
                         _lg_start += fprintf(out, "******.****** s ");
                    }
                    ah_time.tv_sec      = _time.tv_sec;
                    ah_time.tv_usec     = _time.tv_usec;
               }
               else {
                    _lg_start += fprintf(out, "                ");
               }
          }

          if ((ah_mode | type) & AH_DSP_ORIGIN_FULL) {
               /* Affichage du pathname complet de la commande
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               ap_color_fg(out, ah_col_origin);
               _lg_start += fprintf(out, "%-7s ", ah_progname);
               _change    = TRUE;
//             _prompt    = FALSE;
          }
          else if ((ah_mode | type) & AH_DSP_ORIGIN_BASE) {
               /* Affichage du basename de la commande
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               ap_color_fg(out, ah_col_origin);
               _lg_start += fprintf(out, "%-7s ", ah_prog_basename);
               _change    = TRUE;
//             _prompt    = FALSE;
          }

          if ((ah_mode | type) & AH_DSP_PID) {
               /* Affichage du PID du process
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               ap_color_fg(out, ah_col_PID);
               _lg_start += fprintf(out, "[%5d] ", getpid());
               _change    = TRUE;
//             _prompt    = FALSE;
          }


          if ((ah_mode | type) & AH_DSP_WHERE) {
               /* Affichage du nom de fichier et du numero de ligne
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               ap_color_fg(out, ah_col_where);
               _lg_start += fprintf(out, " %-12s (%4d): ", file, line);
               _change    = TRUE;
//             _prompt    = FALSE;
          }
     }

     /* Selection de la couleur du message
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     switch (AH_PROMPT(type) & ~AH_T) {

     case AH_ERR:
          _pcolor   = &ah_col_error;
          _change   = TRUE;
          break;

     case AH_WARN:
          _pcolor   = &ah_col_warning;
          _change   = TRUE;
          break;

     case AH_HORROR:
          _pcolor   = &ah_col_horror;
          _change   = TRUE;
          break;

     default:
          _pcolor   = &ah_col_foreground;
          break;
     }
     if (_change) {
          ap_color_fg(out, *_pcolor);
     }

     if (_prompt) {
          /* Affichage du prompt
             ~~~~~~~~~~~~~~~~~~~ */
          _p         = ah_get_prompt(AH_PROMPT(type) & ~AH_T);
          _lg_start += fprintf(out, "%s", _p->prompt);
     }

     if (!size) {
          /* Calcul de la longueur de la chaine
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          _lg_msg        = strlen(msg);
     }
     else {
          _lg_msg        = size;
     }

     if (_lg_start + _lg_msg < ah_columns) {
          /* Affichage sur une seule ligne
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          fprintf(out, "%s", msg);
     }
     else {
          /* Initialisation des pointeurs
           * p0 : pointeur indiquant le debut de la chaine a afficher
           * p1 : pointeur vers le dernier espace rencontre
           * p2 : pointeur vers le caractere courant (pour la recopie)
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          _p0       =
          _p1       =
          _p2       = msg;

          while (1) {
               /* Recherche du dernier espace avant la fin de la ligne
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               for (_i = 0; _i < ah_columns - _lg_start; _i++, _p2++) {
                    /* Test fin de chaine
                       ~~~~~~~~~~~~~~~~~~ */
                    if (*_p2 == 0) {
                         goto fin_chaine;
                    }

                    /* Recherche des espaces ou tabulations
                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
                    if (*_p2 == ' ' || *_p2 == '\t') {
                         _p1  = _p2;

                         /* Remplacement eventuel de la tabulation
                          * par un espace
                            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
                         *_p2 = ' ';
                    }
               }

               if (_p1 == _p0) {
                    /* Pas d'espace dans la 1ere ligne :
                     * Sauvegarde du caractere avant RAZ
                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
                    _c        = *_p2;
                    *_p2      = 0;
               }
               else {
                    /* Coupure au dernier espace avant la fin de la ligne
                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
                    *_p1      = 0;
               }

               /* Affichage du message partiel
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               fprintf(out, "%s\n", _p0);

               if (_p1 == _p0) {
                    /* Restauration du caractere efface
                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
                    *_p2      = _c;

                    /* Reprise au niveau du caractere efface
                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
                    _p0       =
                    _p1       = _p2;
               }
               else {
                    /* Reprise apres la coupure
                      ~~~~~~~~~~~~~~~~~~~~~~~~~ */
                    _p0       = _p1 + 1;
                    _p1       =
                    _p2       = _p0;
               }

               /* Saut en debut de ligne
                  ~~~~~~~~~~~~~~~~~~~~~~ */
               for (_i = 0; _i < _lg_start; _i++) {
                    putc(' ', out);
               }
          }

fin_chaine:
          fprintf(out, "%s", _p0);
     }

     if (_change) {
          /* Retablissement de la couleur de texte
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          ap_color_fg(out, ah_col_foreground);
     }

     /* Relachement du verrou
        ~~~~~~~~~~~~~~~~~~~~~ */
     if (bh_mutex_unlock(&ah_mutex) != 0) {
          /* Erreur de relachement de verrou
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          fprintf(out, "*** ERROR : pthread_mutex_unlock\n");
     }
}

/* ah_clean_print() }}} */
/* ah_get_prompt() {{{ */

/*******************************************************************************

                              AH_GET_PROMPT

*******************************************************************************/
ah_ref_prompt ah_get_prompt(int type)
{
     /**************************************************************************
      Recuperation du pointeur de description d'un prompt.
     **************************************************************************/
     ah_ref_prompt       _p;

     if (type <= AH_UNKNOWN) {
          _p   = &ah_prompt[type];
     }
     else {
          _p   = &ah_prompt[AH_UNKNOWN];
     }

     return _p;
}

/* ah_get_prompt() }}} */
/* ah_line() {{{ */

/*******************************************************************************

                              AH_LINE

*******************************************************************************/
void ah_line(FILE *out, char c, int nb, bool newline)
{
     /**************************************************************************
      Affichage de N caracteres identiques.
     **************************************************************************/
     while (nb-- > 0) {
          putc(c, out);
     }
     if (newline) {
          putc('\n', out);
     }
}

/* ah_line() }}} */
/* ah_tabprt() {{{ */

/*******************************************************************************

                              AH_TABPRT

*******************************************************************************/
int ah_tabprt(FILE *out, char *file, int line, int type, char **tab)
{
     /**************************************************************************
      Affichage formatte d'un tableau d'arguments.
     **************************************************************************/
     char            *_buf;
     int             _nb;

     /* Allocation memoire pour le buffer de formattage
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     if ((_buf = R_MALLOC(AH_BUFSIZE)) == 0) {
//        ah_clean_print(stderr, file, line, AH_ERR, ah_msg_004[ah_ind], 0);
          exit(M_ERR_MALLOC);
     }

     /* Formattage du message
        ~~~~~~~~~~~~~~~~~~~~~ */
     _nb       = 0;
     while (*tab) {
          if (_nb) {
               _nb  += sprintf(_buf + _nb, " ");
          }
          _nb  += sprintf(_buf + _nb, "'%s'", *tab++);
     }
     _nb  += sprintf(_buf + _nb, "\n");

     /* Affichage du message avec cesure propre
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     ah_clean_print(out, file, line, type, _buf, _nb);

     /* Liberation de la memoire
        ~~~~~~~~~~~~~~~~~~~~~~~~ */
     R_FREE(&_buf);

     return _nb;
}

/* ah_tabprt() }}} */
/* ah_ctx_prt() {{{ */

/*******************************************************************************

                              AH_CTX_PRT

*******************************************************************************/
void ah_ctx_prt(ah_ref_ctx ctx, char *file, const char *funct, int line, int type, char *fmt, ...)
{
     /**************************************************************************
      Affichage formatte de messages.
     **************************************************************************/
     va_list         _ap;
     char           *_buf;
     int             _nb;
     b_uint32        _debug_level_copy;

     /* Faut-il afficher le message ?
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     if (ah_no_print) {
          switch (type) {

          case AH_ERR:
          case AH_INTERNAL:
               /* Message d'erreur : on continue => affichage
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               break;

          default:
               /* Autre type de message : on n'affiche pas
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               return;
          }
     }

     va_start(_ap, fmt);

     /* Allocation memoire pour le buffer de formattage
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     if ((_buf = R_MALLOC(AH_BUFSIZE)) == 0) {
//        ah_clean_print(stderr, file, line, AH_ERR, ah_msg_004[ah_ind], 0);
          exit(M_ERR_MALLOC);
     }

     /* Formattage du message
        ~~~~~~~~~~~~~~~~~~~~~ */
     _nb  = vsprintf(_buf, fmt, _ap);

     /* Affichage du message avec cesure propre
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     ah_clean_ctx_print(ctx, file, funct, line, type, _buf, _nb);

     /* Liberation de la memoire
        ~~~~~~~~~~~~~~~~~~~~~~~~ */
     _debug_level_copy   = r_debug;
     r_debug             = 0;
     R_FREE(&_buf);
     r_debug             = _debug_level_copy;

     va_end(_ap);
}

/* ah_ctx_prt() }}} */
/* ah_clean_ctx_print() {{{ */

/*******************************************************************************

                              AH_CLEAN_CTX_PRINT

*******************************************************************************/
void ah_clean_ctx_print(ah_ref_ctx ctx, char *file, const char *funct, int line, int dsp, char *msg,
                                                                      int size)
{
     /**************************************************************************
      Affichage formatte avec cesure propre.
     **************************************************************************/
     int                       _i, _lg_start, _lg_msg, _change, _prompt, *_pcolor;
     char                     *_p0, *_p1, *_p2, _c = 0, _date[32], _funct[128];
     struct timeval            _time;
     struct tm                *_tm;
     int                       _sec, _usec;
     ah_ref_prompt             _p;
     FILE                     *_out, *_tty;
     b_uint32                  _mode;
     int                       _on_tty;
     ah_ref_ctx                _ctx;

     /* Initialisation des variables
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     _ctx           = ctx ? ctx : &ah_ctx;
     _lg_start      = 0;
     _change        = FALSE;
     _prompt        = TRUE;
     _mode          = AH_MODE(_ctx->mode | dsp);
     _out           = _ctx->fp_log;
     _on_tty        = (_ctx->mode & AH_DSP_TTY) && (dsp & AH_DSP_TTY);
     if (_on_tty) {
          _tty           = _ctx->fp_tty;
     }
     else {
          _tty           = NULL;
     }

     /* Reservation du verrou
        ~~~~~~~~~~~~~~~~~~~~~ */
     if (bh_mutex_lock(&ah_mutex) != 0) {
          /* Erreur de prise de verrou
             ~~~~~~~~~~~~~~~~~~~~~~~~~ */
          fprintf(_out, "*** ERROR : pthread_mutex_lock\n");
     }

     if (AH_PROMPT(dsp & ~AH_T) != AH_VOID) {
          if ((_mode & (AH_DSP_TIMESTAMP | AH_DSP_HIRES_TIMESTAMP | AH_DSP_DELTA_T))) {
               /* Lecture de l'heure systeme
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               if (gettimeofday(&_time, 0) != 0) {
                    perror("gettimeofday");
                    exit(M_ERR_GET_TIME);
               }
          }

          if ((_mode & (AH_DSP_TIMESTAMP | AH_DSP_HIRES_TIMESTAMP))) {
               _tm       = localtime(&_time.tv_sec);
               sprintf(_date, "%4d-%02d-%02d %02d:%02d:%02d", 1900 + _tm->tm_year,
                       _tm->tm_mon + 1, _tm->tm_mday, _tm->tm_hour, _tm->tm_min, _tm->tm_sec);
          }

          if (_mode & AH_DSP_HIRES_TIMESTAMP) {
               /* Affichage du timestamp haute resolution
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               ap_color_fg(_ctx->fp_log, ah_col_timestamp);
               _lg_start += fprintf(_out, "%s.%06d ", _date, (int) _time.tv_usec);
               _change    = TRUE;
          }
          else if (_mode & AH_DSP_TIMESTAMP) {
               /* Affichage du timestamp
                  ~~~~~~~~~~~~~~~~~~~~~~ */
               ap_color_fg(_ctx->fp_log, ah_col_timestamp);
               _lg_start += fprintf(_out, "%s ", _date);
               _change    = TRUE;
          }

          if ((_mode & AH_DSP_DELTA_T)) {
               if (dsp & AH_T) {
                    if (_ctx->time.tv_sec != 0 || _ctx->time.tv_usec != 0) {
                         /* Calcul du delta-T
                            ~~~~~~~~~~~~~~~~~ */
                         _sec           = _time.tv_sec - _ctx->time.tv_sec;
                         if (_time.tv_usec < _ctx->time.tv_usec) {
                              _usec          = 1000000 + _time.tv_usec - _ctx->time.tv_usec;
                              _sec           -= 1;
                         }
                         else {
                              _usec          = _time.tv_usec - _ctx->time.tv_usec;
                         }
                         _lg_start += fprintf(_out, "%6d.%06d s ", _sec, _usec);
                    }
                    else {
                         /* Une seule valeur de temps : pas de calcul de difference
                            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
                         _lg_start += fprintf(_out, "******.****** s ");
                    }

                    /* Actualisation du timestamp du dernier affichage
                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
                    _ctx->time.tv_sec   = _time.tv_sec;
                    _ctx->time.tv_usec  = _time.tv_usec;
               }
               else {
                    _lg_start += fprintf(_out, "                ");
               }
          }

          if (_mode & AH_DSP_ORIGIN_FULL) {
               /* Affichage du pathname complet de la commande
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               ap_color_fg(_ctx->fp_log, ah_col_origin);
               _lg_start += fprintf(_out, "%-7s ", _ctx->progname);
               _change    = TRUE;
          }
          else if (_mode & AH_DSP_ORIGIN_BASE) {
               /* Affichage du basename de la commande
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               ap_color_fg(_ctx->fp_log, ah_col_origin);
               _lg_start += fprintf(_out, "%-7s ", _ctx->prog_basename);
               _change    = TRUE;
          }

          if (_mode & AH_DSP_PID) {
               /* Affichage du PID du process
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               ap_color_fg(_ctx->fp_log, ah_col_PID);
               _lg_start += fprintf(_out, "[%5d] ", getpid());
               _change    = TRUE;
          }

          if (_mode & AH_DSP_TID) {
               /* Affichage du thread ID
                  ~~~~~~~~~~~~~~~~~~~~~~ */
               ap_color_fg(_ctx->fp_log, ah_col_TID);
               _lg_start += fprintf(_out, "[%5d] ", bi_gettid());
               _change    = TRUE;
          }
          if (_mode & AH_DSP_RMTSRV) {
               /* Affichage du nom du serveur distant
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               ap_color_fg(_ctx->fp_log, ah_col_rmtsrv);
               _lg_start += fprintf(_out, "%-*s ", ah_lg_server ? ah_lg_server : AH_LG_SERVER,
                                    _ctx->server);
               _change    = TRUE;
          }


          if (_mode & AH_DSP_WHERE) {
               /* Affichage du nom de fichier et du numero de ligne
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               ap_color_fg(_ctx->fp_log, ah_col_where);
               _lg_start += fprintf(_out, " %-12s (%4d): ", file, line);
               _change    = TRUE;
          }

          if (_mode & AH_DSP_FUNCT) {
               /* Affichage du nom de la fonction
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               ap_color_fg(_ctx->fp_log, ah_col_funct);
               sprintf(_funct, "%s()", funct);
               _lg_start += fprintf(_out, " %-24s ", _funct);
               _change    = TRUE;
          }
     }

     /* Selection de la couleur du message
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     switch (AH_PROMPT(dsp) & ~AH_T) {

     case AH_ERR:
          _pcolor   = &ah_col_error;
          _change   = TRUE;
          break;

     case AH_WARN:
          _pcolor   = &ah_col_warning;
          _change   = TRUE;
          break;

     case AH_HORROR:
          _pcolor   = &ah_col_horror;
          _change   = TRUE;
          break;

     default:
          _pcolor   = &ah_col_foreground;
          break;
     }
     if (_change) {
          ap_color_fg(_ctx->fp_log, *_pcolor);
     }

     if (_prompt) {
          /* Affichage du prompt
             ~~~~~~~~~~~~~~~~~~~ */
          _p         = ah_get_prompt(AH_PROMPT(dsp) & ~AH_T);
          _lg_start += fprintf(_out, "%s", _p->prompt);
     }

     if (!size) {
          /* Calcul de la longueur de la chaine
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          _lg_msg        = strlen(msg);
     }
     else {
          _lg_msg        = size;
     }

     if (_lg_start + _lg_msg < _ctx->columns) {
          /* Affichage sur une seule ligne
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          fprintf(_out, "%s", msg);
          if (_on_tty) {
               fprintf(_tty, "%s", msg);
          }
     }
     else {
          /* Initialisation des pointeurs
           * p0 : pointeur indiquant le debut de la chaine a afficher
           * p1 : pointeur vers le dernier espace rencontre
           * p2 : pointeur vers le caractere courant (pour la recopie)
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          _p0       =
          _p1       =
          _p2       = msg;

          while (1) {
               /* Recherche du dernier espace avant la fin de la ligne
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               for (_i = 0; _i < _ctx->columns - _lg_start; _i++, _p2++) {
                    /* Test fin de chaine
                       ~~~~~~~~~~~~~~~~~~ */
                    if (*_p2 == 0) {
                         goto fin_chaine;
                    }

                    /* Recherche des espaces ou tabulations
                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
                    if (*_p2 == ' ' || *_p2 == '\t') {
                         _p1  = _p2;

                         /* Remplacement eventuel de la tabulation
                          * par un espace
                            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
                         *_p2 = ' ';
                    }
               }

               if (_p1 == _p0) {
                    /* Pas d'espace dans la 1ere ligne :
                     * Sauvegarde du caractere avant RAZ
                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
                    _c        = *_p2;
                    *_p2      = 0;
               }
               else {
                    /* Coupure au dernier espace avant la fin de la ligne
                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
                    *_p1      = 0;
               }

               /* Affichage du message partiel
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               fprintf(_out, "%s\n", _p0);
               if (_on_tty) {
                    fprintf(_tty, "%s\n", _p0);
               }

               if (_p1 == _p0) {
                    /* Restauration du caractere efface
                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
                    *_p2      = _c;

                    /* Reprise au niveau du caractere efface
                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
                    _p0       =
                    _p1       = _p2;
               }
               else {
                    /* Reprise apres la coupure
                      ~~~~~~~~~~~~~~~~~~~~~~~~~ */
                    _p0       = _p1 + 1;
                    _p1       =
                    _p2       = _p0;
               }

               /* Saut en debut de ligne
                  ~~~~~~~~~~~~~~~~~~~~~~ */
               for (_i = 0; _i < _lg_start; _i++) {
                    putc(' ', _ctx->fp_log);
               }
          }

fin_chaine:
          fprintf(_out, "%s", _p0);
          if (_on_tty) {
               fprintf(_tty, "%s", _p0);
          }
     }

     if (_change) {
          /* Retablissement de la couleur de texte
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          ap_color_fg(_ctx->fp_log, ah_col_foreground);
     }

     /* Relachement du verrou
        ~~~~~~~~~~~~~~~~~~~~~ */
     if (bh_mutex_unlock(&ah_mutex) != 0) {
          /* Erreur de relachement de verrou
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          fprintf(_out, "*** ERROR : pthread_mutex_unlock\n");
     }
}

/* ah_clean_ctx_print() }}} */
/* ah_set_server_lgth() {{{ */

/******************************************************************************

                         AH_SET_SERVER_LGTH

******************************************************************************/
void ah_set_server_lgth(b_uint32 server_length)
{
     ah_lg_server        = server_length;
}
/* ah_set_server_lgth() }}} */
/* ah_disp_exec_args() {{{ */

/******************************************************************************

                         AH_DISP_EXEC_ARGS

******************************************************************************/
void ah_disp_exec_args(char *path, char **argp)
{
     int                        _i;
     char                     **_p;

     fprintf(stderr, "PATH = [%s]\n", path);

     for (_p = argp, _i = 0; *_p != NULL; _p++, _i++) {
          fprintf(stderr, "ARGV[%3d : length = %3lu] = [%s]\n",
                  _i, (long unsigned int) strlen(*_p), *_p);
     }
     fprintf(stderr, "\n");
}

/* ah_disp_exec_args() }}} */
