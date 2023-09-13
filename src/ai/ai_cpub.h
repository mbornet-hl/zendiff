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
 *   Author       :     Martial BORNET (MB) - October 11, 2010
 *
 *   File         :     ai_cpub.h
 *
 *   @(#)  [Zen] ai_cpub.h Version 1.7 of 23/09/13 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

/*   Codes retours d'erreurs
 *   ~~~~~~~~~~~~~~~~~~~~~~~
 */
#define   AI_ERR_STAT                   1
#define   AI_ERR_OPEN                   2
#define   AI_ERR_MMAP                   3

/*   Flags de selection des checksums
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define   AI_SUM                   0x0001
#define   AI_BSD                   0x0002
#define   AI_SYSV                  0x0004
#define   AI_MD5                   0x0008
#define   AI_SHA256                0x0040
#if 0
#define   AI_SHA1                  0x0010
#define   AI_SHA224                0x0020
#define   AI_SHA384                0x0080
#define   AI_SHA512                0x0100
#endif

#define   AI_ALL_SUMS              0x00FF

/*   Taille du buffer de lecture des liens symboliques
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define   AI_BUFSIZE                 1024

/*   Taille max. des fichiers pour un mmap en mode 32 bits
 *   (2 Go)
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define   AI_MAX_SIZE              ((b_uint32)(1<<31))

/*   Structure de passage des checksums
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
struct ai_chksums {
     off_t                          size;
     b_uint32                       sum;
     b_uint32                       BSD;
     b_uint32                       Sys_V;
     char                          *MD5,
                                   *SHA256;
#if 0
                                   *SHA1,
                                   *SHA224,
                                   *SHA384,
                                   *SHA512;
#endif
};
typedef struct ai_chksums          *ai_ref_chksums;
