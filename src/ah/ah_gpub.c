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
 *   Author       :     Martial BORNET (MB) - October 19, 2009
 *
 *   File         :     ah_gpub.h
 *
 *   @(#)  [Zen] ah_gpub.c Version 1.12 of 23/09/17 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

#include  <stdio.h>
#include  <sys/time.h>

#include  "../b/b_types.h"
#include  "ah_cpub.h"
#include  "ah_epub.h"

/*   Versions alpha et beta du logiciel
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
int                            ah_alpha                          = 0,
                               ah_beta                           = 0;

/*   Modes d'affichage
 *   ~~~~~~~~~~~~~~~~~
 */
b_uint32                       ah_mode                           = 0;

/*   Contexte global
 *   ~~~~~~~~~~~~~~~
 */
struct ah_ctx                  ah_ctx                            = { 0 };

/*   Demande de desactivation d'affichage
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
b_uint32                       ah_no_print                       = 0;

/*   Nom du programme
 *   ~~~~~~~~~~~~~~~~
 */
char                          *ah_progname                       = 0,
                              *ah_prog_basename                  = 0;

/*   Indicateur d'appel par exec()
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
bool                           ah_called                         = FALSE;

/*   Prompts
 *   ~~~~~~~
 */
struct ah_prompt ah_prompt[] = {
     { AH_VOID,     "",                                     0         },
     { AH_NULL,     "",                                     0         },
     { AH_NORM,     "\033[01;36m-----\033[0m  ",            7         },
     { AH_ERR,      "\033[01;31m*****\033[0m  ",            7         },
     { AH_TRACE,    "\033[01;33m>>>>>\033[0m  ",            7         },
     { AH_SPACE,    "       ",                              0         },
     { AH_MARK,     "---->  ",                              0         },
     { AH_WARN,     "\033[01;35m<<!>>\033[0m  ",            0         },
     { AH_HORROR,   "!?!?!  ",                              0         },
     { AH_INTERNAL, "\033[01;31m#####\033[0m  ",            7         },
     { AH_SEND,     "\033[01;34m====>\033[0m  ",            7         },
     { AH_RECV,     "\033[01;32m<====\033[0m  ",            7         },
     { AH_TODO,     "\033[01;31mTODO:\033[0m  ",            7         },
     { AH_SOURCE,   "\033[01;36m.....\033[0m  ",            7         },
     { AH_DBG_R,    "\033[01;31mDEBUG\033[0m  ",            7         },
     { AH_DBG_G,    "\033[01;32mDEBUG\033[0m  ",            7         },
     { AH_DBG_Y,    "\033[01;33mDEBUG\033[0m  ",            7         },
     { AH_DBG_B,    "\033[01;34mDEBUG\033[0m  ",            7         },
     { AH_DBG_M,    "\033[01;35mDEBUG\033[0m  ",            7         },
     { AH_DBG_C,    "\033[01;36mDEBUG\033[0m  ",            7         },
     { AH_DBG_RR,   "\033[01;41mDEBUG\033[0m  ",            7         },
     { AH_DBG_GR,   "\033[01;42mDEBUG\033[0m  ",            7         },
     { AH_DBG_YR,   "\033[01;43mDEBUG\033[0m  ",            7         },
     { AH_DBG_BR,   "\033[01;44mDEBUG\033[0m  ",            7         },
     { AH_DBG_MR,   "\033[01;45mDEBUG\033[0m  ",            7         },
     { AH_DBG_CR,   "\033[01;46mDEBUG\033[0m  ",            7         },
     { AH_F_IN,     "\033[01;32m====>\033[0m  ",            7         },
     { AH_F_OUT,    "\033[01;36m<====\033[0m  ",            7         },
     { AH_UNKNOWN,  "\033[01;31m?????\033[0m  ",            7         },
     { 0,           0,                                      0         }
};

/*   Index des messages d'erreurs
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
int                            ah_ind                            = 0;

/*   Nombre de colonnes d'un ecran
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
int                            ah_columns                        = 80;

/*   Pathnames des commandes
 *   ~~~~~~~~~~~~~~~~~~~~~~~
 */
char                          *ah_path_get                       = 0,
                              *ah_path_mkdir                     = 0,
                              *ah_path_tee                       = 0,
                              *ah_path_update                    = 0;

/*   Pathname du repertoire contenant la CDD
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
char                          *ah_cdd                            = 0;

/*   Pathnames des repertoires d'archives
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
char                          *ah_mis_ref_dir                    = 0,
                              *ah_mis_dir                        = 0;

/*   Type de controle sur les pathnames
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
int                            ah_check                          = 0;

/*   Nom des fichiers de trace
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~
 */
char                          *ah_trace_file                     = 0,
                              *ah_update_out                     = 0;

/*   Nom de la liste des MIS
 *   ~~~~~~~~~~~~~~~~~~~~~~~
 */
char                          *ah_liste_mis                      = 0;

/*   Couleurs
 *   ~~~~~~~~
 */
int                            ah_col_background                 = 0,
                               ah_col_banner                     = 0,
                               ah_col_cmd                        = 0,
                               ah_col_env                        = 0,
                               ah_col_error                      = 0,
                               ah_col_foreground                 = 0,
                               ah_col_horror                     = 0,
                               ah_col_options                    = 0,
                               ah_col_origin                     = 0,
                               ah_col_PID                        = 0,
                               ah_col_TID                        = 0,
                               ah_col_timestamp                  = 0,
                               ah_col_usage                      = 0,
                               ah_col_value                      = 0,
                               ah_col_warning                    = 0,
                               ah_col_where                      = 0,
                               ah_col_funct                      = 0,
                               ah_col_rmtsrv                     = 0;

/*   Pointeur vers le nom du fichier en cours d'analyse
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
char                          *ah_parsed_file                    = 0;

/*   Structure pour les mesures de temps d'execution
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
struct timeval                 ah_time                           = { 0 };
