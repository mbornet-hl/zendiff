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
 *   Author       :     Martial BORNET (MB) - February 15, 2013
 *
 *   File         :     al_epri.h
 *
 *   @(#)  [Zen] al_epri.h Version 1.7 of 23/09/17 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

#if ! defined(AL_EPRI_H)
#    define AL_EPRI_H

#include  "al_cpub.h"

/*   Pointeur vers le descripteur du fichier de logs
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
extern FILE                        *al_fp_log;

/*   Descripteur de package
 *   ~~~~~~~~~~~~~~~~~~~~~~ */
extern struct al_dpkg               al_dpkg;

extern struct k_ctx                *al_ctx;

/*   Indice de parametre
 *   ~~~~~~~~~~~~~~~~~~~ */
extern b_uint32                     al_param_ID;

/*   Variable de debug
 *   ~~~~~~~~~~~~~~~~~ */
extern b_uint32                     al_debug;

/*   Pathname de la commande "dpkg"
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
extern char                        *al_dpkg_pathname;

extern FILE                        *AL_in;

/*   Fonctions
 *   ~~~~~~~~~ */
int                                 AL_lex();
int                                 AL_parse();
int                                 AL_error(char *);


/*   al_za_dpkg.c
 *   ~~~~~~~~~~~~ */
int                                 al_agent(int, char *[]);
void                                al_send_infos(void *, struct al_dpkg *);
FILE                               *al_run_dpkg(void);

#endif    /* AL_EPRI_H */
