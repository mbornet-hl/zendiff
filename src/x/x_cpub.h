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
 *   File         :     x_cpub.h
 *
 *   @(#)  [Zen] x_cpub.h Version 1.6 of 23/09/18 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

/*   Pathname du repertoire de logs
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define   X_LOGDIR                 "/opt/zenadmin/log"

/*   Largeur par defaut des lignes dans le fichier de logs
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
//#define X_COL                    157
//#define X_COL                    237
#define   X_COL                    319

struct x_server {
     char                          *hostname;
     char                          *IP;
};

struct x_module {
     char                          *name;
     char                          *version;
     char                          *date;
     b_uint32                       serial;
     b_uint32                       protocol_serial;
};
