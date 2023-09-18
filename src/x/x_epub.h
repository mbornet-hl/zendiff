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
 *   Author       :     Martial BORNET (MB) - August 03, 2010
 *
 *   File         :     x_epub.h
 *
 *   @(#)  [Zen] x_epub.h Version 1.4 of 23/09/18 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */


/*   Tableaux des descripteurs d'informations
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
extern struct k_desc_info                x_server[],
                                         x_module[];

/*   Fonctions
 *   ~~~~~~~~~ */
/*   x_agent.c           */
int                            x_call_prgm(int (*)(int, char *[]), int argc, char *argv[]);

/*   x_main.c            */
int                            x_pause(int, char *[]);

