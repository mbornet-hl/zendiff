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
 *   Author       :     Martial BORNET (MB) - August 02, 2010
 *
 *   File         :     x_gpub.h
 *
 *   @(#)  [Zen] x_gpub.c Version 1.6 of 23/09/18 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

/* Includes {{{ */

#include  <stdio.h>
#include  <sys/types.h>
#include  <pwd.h>

#include  "../b/b_types.h"
#include  "../n/n_magic.h"
#include  "../i/i_cpub.h"
#include  "../k/k_cpub.h"
#include  "../e/e_modules.h"
#include  "../e/e_cpub.h"
#include  "../e/e_epub.h"
#include  "x_cpub.h"
#include  "x_epub.h"

/* Includes }}} */

/*   Tableaux des descripteurs d'informations
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
struct k_desc_info             x_server[] = {
     {    N_MAGIC(N_MAGIC_k_desc_info)  E_STYPE_BASE_HOSTNAME,                                 0,
          B_STRING,      0,                            0,                                      K_OFFSET(x_server, hostname)
     },

     {    N_MAGIC(N_MAGIC_k_desc_info)  E_STYPE_BASE_SYS_IP,                                   0,
          B_STRING,      0,                            0,                                      K_OFFSET(x_server, IP)
     },

     {    N_MAGIC(N_MAGIC_k_desc_info)  E_EOR,                                                 0,
          0,             0,                            0,                                      0
     },

     {    N_MAGIC(0)                    0,                                                     0,
          0,             0,                            0,                                      0
     }
};

struct k_desc_info             x_module[] = {
     {    N_MAGIC(N_MAGIC_k_desc_info)  E_STYPE_BASE_MODULE_NAME,                              0,
          B_STRING,      0,                            0,                                      K_OFFSET(x_module, name)
     },

     {    N_MAGIC(N_MAGIC_k_desc_info)  E_STYPE_BASE_MODULE_VERSION,                           0,
          B_STRING,      0,                            0,                                      K_OFFSET(x_module, version)
     },

     {    N_MAGIC(N_MAGIC_k_desc_info)  E_STYPE_BASE_MODULE_DATE,                              0,
          B_STRING,      0,                            0,                                      K_OFFSET(x_module, date)
     },

     {    N_MAGIC(N_MAGIC_k_desc_info)  E_STYPE_BASE_MODULE_SERIAL,                            0,
          B_UINT32,      0,                            K_SIZE(x_module, serial),               K_OFFSET(x_module, serial)
     },

     {    N_MAGIC(N_MAGIC_k_desc_info)  E_STYPE_BASE_PROTOCOL_SERIAL,                          0,
          B_UINT32,      0,                            K_SIZE(x_module, protocol_serial),      K_OFFSET(x_module, protocol_serial)
     },

     {    N_MAGIC(N_MAGIC_k_desc_info)  E_EOR,                                                 0,
          0,             0,                            0,                                      0
     },

     {    N_MAGIC(0)                    0,                                                     0,
          0,             0,                            0,                                      0
     }
};

