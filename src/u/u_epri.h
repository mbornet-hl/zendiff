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
 *   Author       :     Martial BORNET (MB) - May 04, 2009
 *
 *   File         :     u_epri.h
 *
 *   @(#)  [Zen] u_epri.h Version 1.4 of 23/09/17 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

/*   Pointeur vers le descripteur du fichier de logs
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
extern FILE                        *u_fp_log;

/*   Identificateur de parametre
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
extern b_uint32                     u_param_ID;

/*   Offset pour l'acces au pathname relatif
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
extern b_uint32                     u_param_offset;

extern struct u_prs_kw_desc         u_prs_desc[];
extern char                        *u_prs_opt;

/*   Fonctions
 *   ~~~~~~~~~ */
int                                 u_agent(int, char *[]);
int                                 u_send_infos(char *, struct h_entry *, void *);

/*   u_lex.c             */
int                                 U_lex();
int                                 U_error(char *);
