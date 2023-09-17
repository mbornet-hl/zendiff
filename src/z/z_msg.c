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
 *   Author       :     Martial BORNET (MB) - June 26, 2010
 *
 *   File         :     z_msg.c
 *
 *   @(#)  [Zen] z_msg.c Version 1.7 of 23/09/17 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

/* Includes {{{ */

#include  "../b/b_types.h"
#include  "../n/n_magic.h"
#include  "../i/i_cpub.h"
#include  "../y/y_cpub.h"
#include  "../aa/aa_cpub.h"
#include  "z_epri.h"

/* Includes }}} */

struct y_desc_msgs        z_tab_msg[] = {
     {    AA_MSG(0x0001),          z_msg_00001    },
     {    AA_MSG(0x0002),          z_msg_00002    },
     {    0,                       (char **) 0    }
};

struct y_desc_msgs        z_tab_htm[] = {
     {    AA_HTM(0x0001),          z_htm_00001    },
     {    AA_HTM(0x0002),          z_htm_00002    },
     {    0,                       (char **) 0    }
};



/*   Message 00001
 *   ~~~~~~~~~~~~~ */
char                     *z_msg_00001[] = {
     "00001 - Francais",
     "00001 - English",
     "00001 - Deutsch",
     (char *) 0
};

char                     *z_htm_00001[] = {
     "00001 - HTML - Fran&ccedil;ais",
     "00001 - HTML - English",
     "00001 - HTML - Deutsch",
     (char *) 0
};

/*   Message 00002
 *   ~~~~~~~~~~~~~ */
char                     *z_msg_00002[] = {
     "00002 - Francais",
     "00002 - English",
     "00002 - Deutsch",
     (char *) 0
};

char                     *z_htm_00002[] = {
     "00002 - HTML - Fran&ccedil;ais",
     "00002 - HTML - English",
     "00002 - HTML - Deutsch",
     (char *) 0
};
