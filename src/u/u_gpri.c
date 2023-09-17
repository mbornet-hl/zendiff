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
 *   Author       :     Martial BORNET (MB) - November 01, 2009
 *
 *   File         :     u_gpri.c
 *
 *   @(#)  [Zen] u_gpri.c Version 1.5 of 23/09/17 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

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
#include  "../h/h_cpub.h"
#include  "u_cpri.h"
#include  "u_epri.h"

/*   Pointeur vers le descripteur du fichier de logs
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
FILE                          *u_fp_log                                    = 0;

/*   Identificateur de parametre
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
b_uint32                       u_param_ID                                  = 0;

/*   Offset pour l'acces au pathname relatif
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
b_uint32                       u_param_offset                              = 0;

struct u_prs_kw_desc           u_prs_desc[] = {
     {    &e_sccs_archive,         FALSE,    "Archive name",          ":M:"                    },
     {    &e_sccs_last_version,    FALSE,    "Last version",          ":I:"                    },
     {    &e_sccs_author,          FALSE,    "Author",                ":P:"                    },
     {    &e_sccs_creat_date,      FALSE,    "Creation date",         ":Dy:-:Dm:-:Dd:"         },
     {    &e_sccs_creat_time,      FALSE,    "Creation time",         ":T:"                    },
     {    &e_sccs_module_type,     FALSE,    "Module type",           ":Y:"                    },
     {    &e_sccs_var_Q,           FALSE,    "Variable Q",            ":Q:"                    },
     {    &e_sccs_comment,         TRUE,     "Comment",               ":C:"                    },
     {    &e_sccs_D_year,          FALSE,    "Dy",                    ":Dy:"                   },
     {    &e_sccs_D_month,         FALSE,    "Dm",                    ":Dm:"                   },
     {    &e_sccs_D_day,           FALSE,    "Dd",                    ":Dd:"                   },
     {    NULL,                    0,        NULL,                    NULL                     }
};

/*   Option string describing which info to retrieve
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
char                          *u_prs_opt                                   = 0;
