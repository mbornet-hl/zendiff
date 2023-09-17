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
 *   File         :     al_lex.l
 *
 *   @(#)  [Zen] al_lex.l Version 1.4 of 23/09/17 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

#include  <stdio.h>
#include  <string.h>

#include  "../b/b_types.h"
#include  "al_yacc.h"
#include  "al_epub.h"
#include  "al_epri.h"

%}


%option yylineno
%option nounput

marker    (ii)
package   ([-+.a-zA-Z0-9]+)
space     ([ \t]+)
version   ([-+_.:~0-9a-zA-Z]+)
descr     ([^ \n].+)

%start    PKG VERS DESCR
%%

^{marker}                {
                              //printf("MARKER\n");
                              BEGIN PKG;
                         }

<PKG>{space}             {
                              // printf("SPACE2\n");
                         }

<PKG>{package}           {
                              // ATTENTION AUX TRACES : RISQUE DE MELANGE AVEC LES DONNEES DE PROTOCOLE !!!
                              // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                              // => pas de traces sur stdout !!!

                              //printf("PACKAGE        [%s]\n", yytext);
                              yylval.str          = strdup(yytext);
                              BEGIN VERS;
                              return AL_PKG;
                         }

<VERS>{space}            {
                              // printf("SPACE3\n");
                         }

<VERS>{version}          {
                              //printf("VERSION        [%s]\n", yytext);
                              yylval.str          = strdup(yytext);
                              BEGIN DESCR;
                              return AL_VERSION;
                         }

<DESCR>{space}           {
                              // printf("SPACE4\n");
                         }

<DESCR>{descr}           {
                              //printf("DESCR          [%s]\n", yytext);
                              yylval.str          = strdup(yytext);
                              return AL_DESCR;
                         }

<DESCR>\n                {
                              // printf("DESCR NEWLINE\n");
                              BEGIN 0;
                         }

\n                       {
                              // printf("\n");
                              BEGIN 0;
                         }

{space}                  {
                              // printf("SPACE1\n");
                         }

.                        {
                              // printf("<%s>", yytext);
                         }


%%

/******************************************************************************

                              YYWRAP

******************************************************************************/
int yywrap()
{
     /* Pour supprimer le warning : input defined but not used
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     int            (*_input)()    = input;
     _input              = _input;

     return 1;
}

/******************************************************************************

                              YYERROR

******************************************************************************/
int yyerror(char *errmsg)
{
     fprintf(stderr, "ERROR: %s\n", errmsg);
     return 0;
}


#if 0
/******************************************************************************

                              MAIN

******************************************************************************/
int main(int argc, char *argv[])
{
     yyparse();
     //yylex();

     return 0;
}
#endif
