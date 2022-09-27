/* ============================================================================
 * Copyright (C) 2009-2022, Martial Bornet
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
 *   Author       :     Martial BORNET (MB) - March 29, 2009
 *
 *   File         :     n_check.c
 *
 *   @(#)  [Zen] n_check.c Version 1.5 of 22/09/27 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

#include  <stdio.h>

#include  "../b/b_types.h"
#include  "../q/q_cpub.h"
#include  "../q/q_epub.h"
#include  "n_magic.h"
#include  "n_epub.h"

/*******************************************************************************

                              N_CHECK

*******************************************************************************/
void n_check(char *file, int line, int magic, int expected)
{
     /* Magic number check
        ~~~~~~~~~~~~~~~~~~ */
     if (magic != expected) {
          fprintf(stderr,
                  "Inconsistency %s, ligne %4d: magic = 0x%08X expected = 0x%08X\n",
                  file, line, magic, expected);
          Q_FATAL();
     }
}
