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
 *   Author       :     Martial BORNET (MB) - February 16, 2013
 *
 *   File         :     al_cpub.h
 *
 *   @(#)  [Zen] al_cpub.h Version 1.3 of 23/09/17 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

#if ! defined(AL_CPUB_H)
#    define AL_CPUB_H

/*   Structure d'un descripteur de package Debian
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
 struct al_dpkg {
     char                     *pkgname;
     char                     *version;
     char                     *descr;
};

#endif    /* AL_CPUB_H */
