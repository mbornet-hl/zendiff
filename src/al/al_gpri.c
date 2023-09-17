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
 *   Author       :     Martial BORNET (MB) - February 18, 2013
 *
 *   File         :     al_gpri.c
 *
 *   @(#)  [Zen] al_gpri.c Version 1.6 of 23/09/17 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

#include  <stdio.h>

#include  "../k/k_cpub.h"
#include  "al_epri.h"

/*   Pointeur vers le descripteur du fichier de logs
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
FILE                          *al_fp_log                                   = 0;

/*   Descripteur de package
 *   ~~~~~~~~~~~~~~~~~~~~~~ */
struct al_dpkg                 al_dpkg                                     = { 0 };

struct k_ctx                  *al_ctx                                      = 0;

/*   Indice de parametre
 *   ~~~~~~~~~~~~~~~~~~~ */
b_uint32                       al_param_ID                                 = 0;

/*   Variable de debug
 *   ~~~~~~~~~~~~~~~~~ */
b_uint32                       al_debug                                    = 0;

/*   Pathname de la commande "dpkg"
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
char                          *al_dpkg_pathname                            = "/usr/bin/dpkg";
