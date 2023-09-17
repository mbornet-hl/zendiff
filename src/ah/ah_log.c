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
 *   Author       :     Martial BORNET (MB) - August 03, 2016
 *
 *   File         :     ah_log.c
 *
 *   @(#)  [Zen] ah_log.c Version 1.4 of 23/09/17 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

/* Includes {{{ */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "../b/b_types.h"
#include "../x/x_cpub.h"
#include "../r/r_epub.h"
#include "ah_cpub.h"
#include "ah_epub.h"

/* Includes }}} */
/* __file__ {{{ */

static char         *__file__      = __FILE__;

/* __file__ }}} */

/**
 *   \addtogroup LOG
 */
/* ah_create_logfile() {{{ */

/******************************************************************************

                         AH_CREATE_LOGFILE

******************************************************************************/
/**
 *   \brief    Cree un fichier de logs
 *
 *   \param    progname       : nom du programme
 *   \param    log_pathname   : pathname du fichier de log a creer
 */
void ah_create_logfile(char *progname, char *log_pathname)
{
     char                     *_logfile,
                              *_strerr,
                               _uniq_logfile[512];
     b_uint32                  _columns;               // Nombre de colonnes des sorties
     int                       _error;
     struct stat               _statbuf;

     /* Generate log files names
        ~~~~~~~~~~~~~~~~~~~~~~~~ */
     _logfile            = log_pathname;
     sprintf(_uniq_logfile, "%s.%d", _logfile, getpid());
     _columns            = X_COL;
     ah_init(0, _uniq_logfile, progname, "",
             AH_DSP_WHERE | AH_DSP_HIRES_TIMESTAMP | AH_DSP_ORIGIN_BASE | AH_DSP_DELTA_T, _columns);

     if (stat(_logfile, &_statbuf) == 0) {
          /* Remove generic log file
             ~~~~~~~~~~~~~~~~~~~~~~~ */
          if (unlink(_logfile) < 0) {
               _error    = errno;
               _strerr   = strerror(_error);
               if (errno == ENOENT) {
                    AH_CTX_PRT(0, AH_ERR,
                               "Cannot unlink \"%s\" : file has probably been removed by a concurrent process\n",
                               _logfile);
               }
               else {
                    AH_CTX_PRT(0, AH_ERR, "Cannot unlink \"%s\" : %s (%d)!\n", _logfile,
                               _strerr, _error);
                    perror("unlink");
                    //exit(M_ERR_LINK);
               }
          }
     }
     else {
          AH_CTX_PRT(0, AH_WARN, "\"%s\" does not exist !\n", _logfile);
     }

     /* Link specific log file to generic log file
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     if (link(_uniq_logfile, _logfile) < 0) {
          _error    = errno;
          _strerr   = strerror(_error);
          AH_CTX_PRT(0, AH_ERR, "Erreur de creation du lien \"%s\" vers le fichier \"%s\"\n",
                     _logfile, _uniq_logfile);
          AH_CTX_PRT(0, AH_ERR, "link(): %s (%d)\n", _strerr, _error);
          //exit(M_ERR_LINK);
     }
     R_FREE(&_logfile);
}
/* ah_create_logfile() }}} */
