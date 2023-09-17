/* ============================================================================
 * Copyright (C) 2023, Martial Bornet
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
 *   Author       :     Martial BORNET (MB) - September 03, 2023
 *
 *   File         :     u_cpri.h
 *
 *   @(#)  [Zen] u_cpri.h Version 1.7 of 23/09/17 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

#if ! defined(U_CPRI_H)
#define   U_CPRI_H

#define   U_COND_FREE(x)      { if (x != NULL) free(x); }

/* Pathnames of SCCS commands
   ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define   U_PATHNAME_PRS      "/home/machine/CSSC/prs"
#define   U_BASENAME_PRS      "prs"

#define   U_PATHNAME_GET      "/home/machine/CSSC/get"
#define   U_BASENAME_GET      "get"

/* Macros for parse trace
   ~~~~~~~~~~~~~~~~~~~~~~ */
#define   AH_DISP_LEX         u_disp_lex
#define   AH_DISP_YACC        u_disp_yacc

#define   U_KW_BEGIN_MULTI    "\001\002"
#define   U_KW_END_MULTI      "\001\005"

/* Descriptor for "prs" keywords
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
struct u_prs_kw_desc {
     b_uint32                 *ref_flag;
     bool                      multi_line;
     char                     *KW_lex;
     char                     *KW_SCCS;
};

struct u_ctx {
     N_DEFINE_MAGIC           
     struct k_ctx              tlv_ctx;
     b_uint32                  sums;
};
typedef struct u_ctx           u_ctx;
typedef struct u_ctx          *u_ref_ctx;

#endif    /* U_CPRI_H */
