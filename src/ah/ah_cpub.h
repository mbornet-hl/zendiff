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
 *   Author       :     Martial BORNET (MB) - September 19, 2009
 *
 *   File         :     ah_cpub.h
 *
 *   @(#)  [Zen] ah_cpub.h Version 1.18 of 23/09/17 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

#if !defined(AH_CPUB_H)
#  define AH_CPUB_H

#include  <stdio.h>
#include  <sys/time.h>
#include  "../b/b_types.h"

/*   Definitions de types
 *   ~~~~~~~~~~~~~~~~~~~~ */
typedef   struct ah_prompt              *ah_ref_prompt;

#define   AH_PRT(out, type, ...)        ah_prt(out, __file__, __LINE__, type, __VA_ARGS__)
#define   AH_CTX_PRT(ctx, type, ...)    ah_ctx_prt(ctx, __file__, __func__, __LINE__, type, __VA_ARGS__)

#if 0
#define   AH_DEBUG(cond, ctx, type, ...)     \
                                        { if (cond) { ah_ctx_prt(ctx, __file__, __func__, __LINE__, type, __VA_ARGS__); } }
#endif

#define   AH_DEBUG_N(cond, N, ctx, type, ...)     \
                                        { if (cond >= (N)) { \
                                             ah_ctx_prt(ctx, __file__, __func__, __LINE__, type, __VA_ARGS__); } }

#define   AH_DEBUG(cond, ctx, type, ...)          AH_DEBUG_N(cond, 1, ctx, type, __VA_ARGS__)
#define   AH_DEBUG2(cond, ctx, type, ...)         AH_DEBUG_N(cond, 2, ctx, type, __VA_ARGS__)
#define   AH_DEBUG3(cond, ctx, type, ...)         AH_DEBUG_N(cond, 3, ctx, type, __VA_ARGS__)
#define   AH_DEBUG4(cond, ctx, type, ...)         AH_DEBUG_N(cond, 4, ctx, type, __VA_ARGS__)
#define   AH_DEBUG5(cond, ctx, type, ...)         AH_DEBUG_N(cond, 5, ctx, type, __VA_ARGS__)
#define   AH_DEBUG6(cond, ctx, type, ...)         AH_DEBUG_N(cond, 6, ctx, type, __VA_ARGS__)
#define   AH_DEBUG7(cond, ctx, type, ...)         AH_DEBUG_N(cond, 7, ctx, type, __VA_ARGS__)
#define   AH_DEBUG8(cond, ctx, type, ...)         AH_DEBUG_N(cond, 8, ctx, type, __VA_ARGS__)
#define   AH_DEBUG9(cond, ctx, type, ...)         AH_DEBUG_N(cond, 9, ctx, type, __VA_ARGS__)
      
/*   Traces de debut et fin de fonctions
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#if defined(AH_TRACE_FUNCT)
#  define AH_BEGIN                      { AH_CTX_PRT(0, AH_F_IN |AH_DSP_WHERE, "%s() ...\n", __func__); }
#  define AH_END                        { AH_CTX_PRT(0, AH_F_OUT|AH_DSP_WHERE, "%s()\n",     __func__); }
#else
#  define AH_BEGIN
#  define AH_END
#endif

/*   Macros pour les traces lex et yacc
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define   AH_TRACE_LEX(...)             { if (AH_DISP_LEX)  AH_CTX_PRT(0, AH_TRACE, "LEX  : " __VA_ARGS__); }
#define   AH_TRACE_YACC(...)            { if (AH_DISP_YACC) AH_CTX_PRT(0, AH_TRACE, "    YACC : " __VA_ARGS__); }

/*   Taille du buffer d'affichage
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define   AH_BUFSIZE                    4096

/*   Modes d'affichage
 *   ~~~~~~~~~~~~~~~~~~ */
#define   AH_DSP_HIRES_TIMESTAMP        0x00010000
#define   AH_DSP_TIMESTAMP              0x00020000
#define   AH_DSP_DELTA_T                0x00040000
#define   AH_DSP_ORIGIN_FULL            0x00080000
#define   AH_DSP_ORIGIN_BASE            0x00100000
#define   AH_DSP_PID                    0x00200000
#define   AH_DSP_TID                    0x00400000
#define   AH_DSP_THREAD                 0x00800000
#define   AH_DSP_WHERE                  0x01000000
#define   AH_DSP_RMTSRV                 0x02000000
#define   AH_DSP_TTY                    0x04000000
#define   AH_DSP_FUNCT                  0x08000000

/*   Types de prompts
 *   ~~~~~~~~~~~~~~~~ */
#define   AH_VOID                        0x00000000
#define   AH_NULL                        0x00000001
#define   AH_NORM                        0x00000002
#define   AH_ERR                        (0x00000003 | AH_DSP_TTY | AH_DSP_WHERE)
#define   AH_TRACE                       0x00000004
#define   AH_SPACE                       0x00000005
#define   AH_MARK                        0x00000006
#define   AH_WARN                        0x00000007
#define   AH_HORROR                      0x00000008
#define   AH_INTERNAL                   (0x00000009 | AH_DSP_TTY | AH_DSP_WHERE)
#define   AH_SEND                        0x0000000A
#define   AH_RECV                        0x0000000B
#define   AH_TODO                        0x0000000C
#define   AH_SOURCE                      0x0000000D
#define   AH_DBG_R                      (0x0000000E | AH_DSP_WHERE | AH_DSP_FUNCT)
#define   AH_DBG_G                      (0x0000000F | AH_DSP_WHERE | AH_DSP_FUNCT)
#define   AH_DBG_Y                      (0x00000010 | AH_DSP_WHERE | AH_DSP_FUNCT)
#define   AH_DBG_B                      (0x00000011 | AH_DSP_WHERE | AH_DSP_FUNCT)
#define   AH_DBG_M                      (0x00000012 | AH_DSP_WHERE | AH_DSP_FUNCT)
#define   AH_DBG_C                      (0x00000013 | AH_DSP_WHERE | AH_DSP_FUNCT)
#define   AH_DBG_RR                     (0x00000014 | AH_DSP_WHERE | AH_DSP_FUNCT)
#define   AH_DBG_GR                     (0x00000015 | AH_DSP_WHERE | AH_DSP_FUNCT)
#define   AH_DBG_YR                     (0x00000016 | AH_DSP_WHERE | AH_DSP_FUNCT)
#define   AH_DBG_BR                     (0x00000017 | AH_DSP_WHERE | AH_DSP_FUNCT)
#define   AH_DBG_MR                     (0x00000018 | AH_DSP_WHERE | AH_DSP_FUNCT)
#define   AH_DBG_CR                     (0x00000019 | AH_DSP_WHERE | AH_DSP_FUNCT)
#define   AH_F_IN                        0x0000001A
#define   AH_F_OUT                       0x0000001B
#define   AH_UNKNOWN                     0x0000001C

#define   AH_ACTION                      AH_DBG_C

#define   AH_DBG                         AH_DBG_G

/*   Bit de demande d'affichage des durees
 *   (si AH_DSP_DELTA_T est selectionne dans le mode)
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define   AH_T                          0x00008000

/*   Masques
 *   ~~~~~~~ */
#define   AH_MASK_PROMPT                0x0000FFFF
#define   AH_MASK_MODE                  0xFFFF0000
#define   AH_PROMPT(dsp)                ((dsp) & AH_MASK_PROMPT)
#define   AH_MODE(dsp)                  ((dsp) & AH_MASK_MODE)

/*   Descripteur de prompt
 *   ~~~~~~~~~~~~~~~~~~~~~
 */
struct ah_prompt {
     int                            indice;
     char                          *prompt;
     int                            lg;
};

/*   Macros relatives aux messages d'erreurs
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
#define   AH_FILE                       __file__
#define   AH_LINE                       __LINE__
#define   AH_TIME                       __TIME__
#define   AH_DATE                       __DATE__

struct ah_ctx {
     const char                    *progname,
                                   *prog_basename;
     FILE                          *fp_log,
                                   *fp_tty;
     const char                    *server;
     struct timeval                 time;
     b_uint32                       mode,
                                    columns;
};
typedef struct ah_ctx              *ah_ref_ctx;

#define   AH_LG_SERVER                  20

#endif    /* AH_CPUB_H */
