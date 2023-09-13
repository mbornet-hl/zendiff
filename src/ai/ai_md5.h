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
 *   Author       :     Martial BORNET (MB) - March 17, 2011
 *
 *   File         :     ai_md5.h
 *
 *   @(#)  [Zen] ai_md5.h Version 1.2 of 23/09/13 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

/*
Christophe Devine 
c.devine@cr0.net
http://www.cr0.net:8040/code/crypto/
*/
#ifndef _MD5_H
#define _MD5_H

#ifndef uint8
#define uint8  unsigned char
#endif

#ifndef uint32
#define uint32 unsigned long int
#endif

/*   Taille du buffer
 *   ~~~~~~~~~~~~~~~~ */
#define AI_BUFSIZ_MD5                   (1000)

/*   Taille du checksum
 *   ~~~~~~~~~~~~~~~~~~~ */
#define   AI_SIZE_MD5                   16


typedef struct {
    uint32 total[2];
    uint32 state[4];
    uint8 buffer[64];
}
ai_md5_context;

void ai_md5_starts( ai_md5_context *ctx );
void ai_md5_update( ai_md5_context *ctx, uint8 *input, uint32 length );
void ai_md5_finish( ai_md5_context *ctx, uint8 digest[16] );

#endif /* ai_md5.h */

