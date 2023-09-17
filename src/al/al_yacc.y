%{
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
 *   Author       :     Martial BORNET (MB) - February 15, 2013
 *
 *   File         :     al_yacc.y
 *
 *   @(#)  [Zen] al_yacc.y Version 1.5 of 23/09/17 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

#include  <stdio.h>

#include  "../b/b_types.h"
#include  "al_epub.h"
#include  "al_epri.h"

extern int yylineno;

%}

%union {
     char                *str;
}

%token    <str>          AL_PKG AL_VERSION AL_DESCR


%start                   lines

%%

lines          : line
               {
               }
               | lines line
               {
               }
               ;

line           : AL_PKG AL_VERSION AL_DESCR
               {
                    //printf("%-35s %-40s %s\n", $1, $2, $3);
                    //al_dpkg.file_list = 0;
                    al_dpkg.pkgname     = $1;
                    al_dpkg.version     = $2;
                    al_dpkg.descr       = $3;

                    /* Envoi des infos au manager
                       ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
                    al_send_infos(al_ctx, &al_dpkg);
               }
               ;

%%
