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
 *   File         :     s_gpri.c
 *
 *   @(#)  [Zen] s_gpri.c Version 1.9 of 23/09/18 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

/* Includes {{{ */

#include  <stdio.h>
#include <sys/types.h>

#include  "../b/b_types.h"
#include  "../n/n_magic.h"
#include  "../i/i_cpub.h"
#include  "../k/k_cpub.h"
#include  "../e/e_modules.h"
#include  "../e/e_cpub.h"
#include  "../e/e_epub.h"
#include  "../h/h_cpub.h"
#include  "../h/h_epub.h"
#include  "../e/e_data_fs.h"
#include  "s_cpri.h"
#include  "s_epri.h"

/* Includes }}} */

#if 0
/*   Pointeur vers le fichier de logs
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
FILE                          *s_fp_log                                    = 0;
#endif

/*   Identificateur de parametre
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
b_uint32                       s_param_ID                                  = 0;

/*   Offset pour l'acces au pathname relatif
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
b_uint32                       s_param_offset                              = 0;
