/* ============================================================================
 *   (C) Copyright Martial Bornet, 2009-2022
 *
 *   Author       :     Martial BORNET (MB) - March 29, 2009
 *
 *   File         :     n_check.c
 *
 *   @(#)  [Zen] n_check.c Version 1.4 of 22/09/27 - 
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
