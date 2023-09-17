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
 *   Author       :     Martial BORNET (MB) - September 19, 2009
 *
 *   File         :     ah_epub.h
 *
 *   @(#)  [Zen] ah_epub.h Version 1.17 of 23/09/17 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

#if ! defined(AH_EPUB_H)
#  define AH_EPUB_H

#include  "ah_cpub.h"

/*   Modes d'affichage
 *   ~~~~~~~~~~~~~~~~~
 */
extern b_uint32                ah_mode;

/*   Contexte global
 *   ~~~~~~~~~~~~~~~
 */
extern struct ah_ctx           ah_ctx;

/*   Demande de desactivation d'affichage
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
extern b_uint32                ah_no_print;

/*   Nom du programme
 *   ~~~~~~~~~~~~~~~~
 */
extern char                   *ah_progname,
                              *ah_prog_basename;

/*   Prompts
 *   ~~~~~~~
 */
extern struct ah_prompt        ah_prompt[];

/*   Nombre de colonnes d'un ecran
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
extern int                     ah_columns;

/*   Couleurs
 *   ~~~~~~~~
 */
extern int                     ah_col_background,
                               ah_col_banner,
                               ah_col_cmd,
                               ah_col_env,
                               ah_col_error,
                               ah_col_foreground,
                               ah_col_horror,
                               ah_col_options,
                               ah_col_origin,
                               ah_col_PID,
                               ah_col_TID,
                               ah_col_timestamp,
                               ah_col_usage,
                               ah_col_value,
                               ah_col_warning,
                               ah_col_where,
                               ah_col_funct,
                               ah_col_rmtsrv;

/*   Pointeur vers le nom du fichier en cours d'analyse
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
extern char                   *ah_parsed_file;

/*   Structure pour les mesures de temps d'execution
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
extern struct timeval          ah_time;

/*   Fonctions
 *   ~~~~~~~~~
 */
void                      ah_create_logfile(char *, char *);
void                      ah_init_ctx(ah_ref_ctx, FILE *, FILE *, char *);
void                      ah_init(ah_ref_ctx, const char *, char *, const char *, b_uint32, int);
void                      ah_clean_print(FILE *, char *, int, int, char *, int);
ah_ref_prompt             ah_get_prompt(int);
void                      ah_line(FILE *, char, int, bool);
int                       ah_tabprt(FILE *, char *, int, int, char **);
void                      ah_init_prompts(void);
void                      ah_prt(FILE *, char *, int, int, char *, ...);
void                      ah_ctx_prt(ah_ref_ctx, char *, const char *, int, int, char *, ...)
                              __attribute__ ((format (printf, 6, 7)));
void                      ah_clean_ctx_print(ah_ref_ctx, char *, const char *, int, int, char *, int);
void                      ah_set_server_lgth(b_uint32);
void                      ah_disp_exec_args(char *, char **);

#endif    /* AH_EPUB_H */
