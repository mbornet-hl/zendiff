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
 *   Author       :     Martial BORNET (MB) - August 07, 2010
 *
 *   File         :     s_epri.h
 *
 *   @(#)  [Zen] s_epri.h Version 1.12 of 23/09/18 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

#if 0
/*   Pointeur vers le fichier de logs
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
extern FILE                        *s_fp_log;
#endif


/*   Identificateur de parametre
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
extern b_uint32                     s_param_ID;

/*   Offset pour l'acces au pathname relatif
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
extern b_uint32                     s_param_offset;

/*   Fonctions
 *   ~~~~~~~~~ */
/*   s_za_fs.c           */
int                                 s_agent(int, char *[]);
int                                 s_send_infos(char *, struct h_entry *, void *);

/*   Fonctions
 *   ~~~~~~~~~ */
int                                 s_agent(int, char *[]);
char                               *s_attr2str(unsigned long);
