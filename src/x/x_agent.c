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
 *   File         :     x_agent.h
 *
 *   @(#)  [Zen] x_agent.c Version 1.7 of 23/09/18 - 
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

/* x_call_prgm() {{{ */

/******************************************************************************

                         X_CALL_PRGM

******************************************************************************/
int x_call_prgm(int (*agent)(int, char *[]), int argc, char *argv[])
{
     int                                 _status = 0, _retcode = 0;
     char                                _hostname[64];

     /* Recuperation du hostname
        ~~~~~~~~~~~~~~~~~~~~~~~~ */
     if (gethostname(_hostname, sizeof(_hostname)) != 0) {
          fprintf(stderr, "Erreur de recuperation du hostname\n");
          exit(M_ERR_GETHOSTNAME);
     }

#if 0
     /* Initialisation de l'heure de debut d'execution du programme
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     if (gettimeofday(&x_ctx.ts_launch, 0) != 0) {
          perror("gettimeofday");
          exit(M_ERR_GET_TIME);
     }
#endif

     /* Creation d'un processus fils pour traiter les problemes
      * divers (violation memoire, ...)
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     switch (fork()) {

     case -1:
          /* Erreur de creation de processus
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          fprintf(stderr, "[%s]%s : Cannot fork\n", _hostname, argv[0]);
          exit(M_ERR_FORK);
          break;

     case 0:
          /* Processus fils : appel de la fonction de traitement
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          (*agent)(argc, argv);
          break;

     default:
          /* Processus pere : attente de la fin d'execution du fils
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          wait(&_status);

          /* Traitement du code retour
             ~~~~~~~~~~~~~~~~~~~~~~~~~ */
          fprintf(stderr, "[%s]%s : status = 0x%08X\n", _hostname, argv[0], _status);
          if (WIFEXITED(_status)) {
               fprintf(stderr, "[%s]%s : Normal exit code = %d\n", _hostname, argv[0], WEXITSTATUS(_status));
               _retcode            = WEXITSTATUS(_status);
          }
          else if (WIFSIGNALED(_status)) {
               fprintf(stderr, "[%s]%s : Terminated by signal %d\n", _hostname, argv[0], WTERMSIG(_status));
               if (WCOREDUMP(_status)) {
                    fprintf(stderr, "[%s]%s : Core dumped\n", _hostname, argv[0]);
               }
          }
          break;
     }

     return _retcode;
}

/* x_call_prgm() }}} */
