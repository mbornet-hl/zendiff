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
 *   Author       :     Martial BORNET (MB) - August 15, 2023
 *
 *   File         :     u_cpub.h
 *
 *   @(#)  [Zen] u_cpub.h Version 1.5 of 23/09/17 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

#if ! defined(U_CPUB_H)
#    define U_CPUB_H

/*   Structure d'un descripteur d'archive SCCS
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
 struct u_sccs {
     char                     *archive;
     char                     *last_vers;
     char                     *timestamp;
     char                     *creation_date;
     char                     *creation_time;
     char                     *D_year;
     char                     *D_month;
     char                     *D_day;
     char                     *author;
     char                     *md5;
     char                     *sha256;
     char                     *comment;
     b_uint64                  size;
     char                     *module_type;
     char                     *var_Q;
};

#endif    /* U_CPUB_H */
