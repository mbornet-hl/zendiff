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
 *   Author       :     Martial BORNET (MB) - March 19, 2011
 *
 *   File         :     ai_sha256.h
 *
 *   @(#)  [Zen] ai_sha256.h Version 1.2 of 23/09/13 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

#ifndef _SHA256_H
#define _SHA256_H

#ifndef uint8
#define uint8  unsigned char
#endif

#ifndef uint32
#define uint32 unsigned long int
#endif

typedef struct
{
    uint32 total[2];
    uint32 state[8];
    uint8 buffer[64];
}                                   ai_sha256_context;

void ai_sha256_starts( ai_sha256_context *ctx );
void ai_sha256_update( ai_sha256_context *ctx, uint8 *input, uint32 length );
void ai_sha256_finish( ai_sha256_context *ctx, uint8 digest[32] );

/*   Taille du buffer
 *   ~~~~~~~~~~~~~~~~ */
#define AI_BUFSIZ_SHA256                (1000)

/*   Taille du checksum
 *   ~~~~~~~~~~~~~~~~~~~ */
#define   AI_SIZE_SHA256                32

#endif /* ai_sha256.h */

