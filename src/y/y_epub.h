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
 *   Author       :     Martial BORNET (MB) - December 01, 2009
 *
 *   File         :     y_epub.h
 *
 *   @(#)  [Zen] y_epub.h Version 1.4 of 23/09/18 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

/*   Fonctions
 *   ~~~~~~~~~ */
y_ref_desc_msg                           y_msg_alloc(void);
void                                     y_msg_init(y_ref_desc_msg);
void                                     y_msg_add(i_ref_root, b_uint32, char *);
word                                     y_msg_cmp(i_ref_node, i_ref_node);
void                                     y_msg_drop(i_ref_node, i_ref_node);
char                                    *y_msg_search(i_ref_root, b_uint32);

void                                     y_init_msg(y_ref_desc_msg);

/*   y_funct.c           */
int                                      y_read_catalog(char *, i_ref_root *);
void                                     y_msg_add(i_ref_root, b_uint32, char *);
y_ref_desc_msg                           y_msg_alloc(void);
void                                     y_msg_init(y_ref_desc_msg);
word                                     y_msg_cmp(i_ref_node, i_ref_node);
void                                     y_msg_drop(i_ref_node, i_ref_node);
char                                    *y_msg_search(i_ref_root, b_uint32);
void                                     y_msg_tree_free(i_ref_root);
void                                     y_msg_free(i_ref_node);
void                                     y_msg_disp_node(i_ref_node);
void                                     y_msg_disp(y_ref_desc_msg);
