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
 *   Author       :     Martial BORNET (MB) - April 23, 2011
 *
 *   File         :     ai_cpri.h
 *
 *   @(#)  [Zen] ai_cpri.h Version 1.3 of 23/09/13 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

/*   For a classical checksum
 *   ~~~~~~~~~~~~~~~~~~~~~~~~ */
struct words   {
     unsigned short       hi;
     unsigned short       lo;
};

#define   AI_MASK        0xFFFF
