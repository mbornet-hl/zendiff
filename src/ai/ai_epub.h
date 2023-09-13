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
 *   Author       :     Martial BORNET (MB) - October 7, 2010
 *
 *   File         :     ai_epub.h
 *
 *   @(#)  [Zen] ai_epub.h Version 1.4 of 23/09/13 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

int                            ai_file_checksums(char *, b_uint32, ai_ref_chksums);
int                            ai_checksums(FILE *, char *, b_int64, b_uint32, ai_ref_chksums);
void                           ai_init_chksums(ai_ref_chksums);
