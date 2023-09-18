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
 *   Author       :     Martial BORNET (MB) - May 28, 2011
 *
 *   File         :     y_cpub.h
 *
 *   @(#)  [Zen] y_cpub.h Version 1.6 of 23/09/18 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

#if ! defined(Y_CPUB_H)
#  define Y_CPUB_H

#include  "../b/b_types.h"
#include  "../n/n_magic.h"

/*   Structure d'un entete de catalogue
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#if 0
#error    A DEFINIR
#endif

/*   Structure d'un TLV
 *   ~~~~~~~~~~~~~~~~~~ */
struct y_tl {
     b_uint32             type;
     b_uint32             length;
};

struct y_tlv {
     struct y_tl          TL;
     char                *V;
};

/*   Descripteur de message simple
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
struct y_desc_msg {
     N_DEFINE_MAGIC
     b_uint32             id;
     char                *msg;
     struct i_node        node;
};
typedef struct y_desc_msg               *y_ref_desc_msg;

/*   Descripteur de message multiple
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
struct y_desc_msgs {
     b_uint32              id;
     char                **msgs;
};
typedef struct y_desc_msgs              *y_ref_desc_msgs;

#endif    /* Y_CPUB_H */
