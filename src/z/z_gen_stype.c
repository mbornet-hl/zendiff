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
 *   Author       :     Martial BORNET (MB) - September 02, 2010
 *
 *   File         :     z_gen_stype.c
 *
 *   @(#)  [Zen] z_gen_stype.c Version 1.5 of 23/09/17 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

/* Includes {{{ */

#include  <stdio.h>
#include  <fcntl.h>
#include  <unistd.h>
#include  <stdlib.h>
#include  <string.h>

#include  "../b/b_types.h"
#include  "../n/n_magic.h"
#include  "../i/i_cpub.h"
#include  "../y/y_cpub.h"
#include  "../k/k_msg.h"
#include  "../m/m_cpub.h"
#include  "z_epri.h"

/* Includes }}} */

/* main() {{{ */

/******************************************************************************

                              MAIN

******************************************************************************/
int main(int argc, char *argv[])
{
     int                                 _fd;
     struct y_desc_msgs                 *_ref_msgs;
     struct y_tl                         _tl;
     char                               *_catalog, *_m;

     if (argc != 2) {
          fprintf(stderr, "Usage : %s catalog\n", argv[0]);
          exit(M_ERR_USAGE);
     }

     _catalog       = argv[1];

     /* Ouverture du catalogue en ecriture
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     if ((_fd = open(_catalog, O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1) {
          fprintf(stderr, "open error\n");
          exit(M_ERR_OPEN);
     }

#if 0
     z_write_catalog_hdr(_fd, &_catalog_hdr);
#endif

     /* Generation du catalogue
        ~~~~~~~~~~~~~~~~~~~~~~~ */
     _ref_msgs           = k_tab_stype;
     while (_ref_msgs->msgs) {
          _m                  = _ref_msgs->msgs[0];
          _tl.type            = _ref_msgs->id;
          _tl.length          = strlen(_m) + 1;
          if (write(_fd, (char *) &_tl, sizeof(_tl)) != sizeof(_tl)) {
               fprintf(stderr, "write error for TL\n");
               exit(M_ERR_WRITE);
          }
          if (write(_fd, (char *) _m, _tl.length) != _tl.length) {
               fprintf(stderr, "write error for value\n");
               exit(M_ERR_WRITE);
          }
          _ref_msgs++;
     }

     /* Fermeture du catalogue
        ~~~~~~~~~~~~~~~~~~~~~~ */
     close(_fd);

     return 0;
}

/* main() }}} */
