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
 *   Author       :     Martial BORNET (MB) - August 22, 2010
 *
 *   File         :     x_main.c
 *
 *   @(#)  [Zen] x_main.c Version 1.2 of 23/09/18 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

/* Includes {{{ */

#include  <stdio.h>
#include  <stdlib.h>
#include  <unistd.h>          // Pour gethostname()
#include  <sys/wait.h>        // Pour wait()

#include  "../b/b_types.h"
#include  "../n/n_magic.h"
#include  "../k/k_cpub.h"
#include  "../m/m_cpub.h"
#include  "x_epub.h"

/* Includes }}} */

/* main() {{{ */

/******************************************************************************

                         MAIN

******************************************************************************/
int main(int argc, char *argv[])
{
     return x_call_prgm(x_pause, argc, argv);
}

/* main() }}} */
/* x_pause() {{{ */

/******************************************************************************

                         X_PAUSE

******************************************************************************/
int x_pause(int argc, char *argv[])
{
     pause();

     return 0;
}

/* x_pause() }}} */
