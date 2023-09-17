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
 *   Author       :     Martial BORNET (MB) - September 03, 2023
 *
 *   File         :     u_lex.l
 *
 *   @(#)  [Zen] u_lex.l Version 1.8 of 23/09/17 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

#include <stdio.h>
#include <string.h>

#include "../b/b_types.h"
#include "../m/m_cpub.h"
#include "../n/n_magic.h"
#include "../i/i_cpub.h"
#include "../i/i_epub.h"
#include "../e/e_modules.h"
#include "../e/e_cpub.h"
#include "../e/e_epub.h"
#include "../ah/ah_cpub.h"
#include "../ah/ah_epub.h"
#include "u_cpri.h"
#include "u_epub.h"
#include "u_yacc.h"

// #define     AH_DISP_LEX              e_sccs_disp_lex

static char                   *__file__      = __FILE__;

%}

%option             nounput

last_version        (Last\ version)
author              (Author)
creat_date          (Creation\ date)
creat_time          (Creation\ time)
D_year              (Dy)
D_month             (Dm)
D_day               (Dd)
module_type         (Module\ type)
archive             (Archive\ name)
var_Q               (Variable\ Q)
comment             (Comment)
sep_comma           ([ \t]*:[ \t]*)
value               ([^ \n\001\002\005][^\n\001\002\005]*)
line                ([^\n\001\002\005]*)
begin_multi         (\001\002)
end_multi           (\001\005)

%start              VAL MULTI

%%

^{last_version}     {
                         AH_TRACE_LEX("LAST_VERSION    : [%s]\n", yytext);
                         return U_LAST_VERSION;
                    }

^{author}           {
                         AH_TRACE_LEX("AUTHOR          : [%s]\n", yytext);
                         return U_AUTHOR;
                    }

^{creat_date}       {
                         AH_TRACE_LEX("CREATION DATE   : [%s]\n", yytext);
                         return U_CREAT_DATE;
                    }

^{creat_time}       {
                         AH_TRACE_LEX("CREATION TIME   : [%s]\n", yytext);
                         return U_CREAT_TIME;
                    }

^{D_year}           {
                         AH_TRACE_LEX("DELTA YEAR      : [%s]\n", yytext);
                         return U_D_YEAR;
                    }

^{D_month}          {
                         AH_TRACE_LEX("DELTA MONTH     : [%s]\n", yytext);
                         return U_D_MONTH;
                    }

^{D_day}            {
                         AH_TRACE_LEX("DELTA DAY       : [%s]\n", yytext);
                         return U_D_DAY;
                    }

^{module_type}      {
                         AH_TRACE_LEX("MODULE TYPE     : [%s]\n", yytext);
                         return U_MODULE_TYPE;
                    }

^{archive}               {
                         AH_TRACE_LEX("ARCHIVE         : [%s]\n", yytext);
                         return U_ARCHIVE;
                    }

^{var_Q}            {
                         AH_TRACE_LEX("VARIABLE Q      : [%s]\n", yytext);
                         return U_VAR_Q;
                    }

^{comment}               {
                         AH_TRACE_LEX("COMMENT         : [%s]\n", yytext);
                         return U_COMMENT;
                    }

{sep_comma}         {
                         AH_TRACE_LEX("SEP\n");
                         BEGIN VAL;
                         return U_SEP_COMMA;
                    }

{begin_multi}\n     {
                         AH_TRACE_LEX("begin_multi\n");
                         BEGIN MULTI;
                    }

<MULTI>{end_multi}\n {
                         AH_TRACE_LEX("<MULTI>end_multi\n");
                         BEGIN 0;
                         return U_END_MULTI;
                    }

<MULTI>{line}       {
                         AH_TRACE_LEX("<MULTI>LINE     : [%s]\n", yytext);
                         yylval.value                  = strdup(yytext);
                         return U_MULTI_VAL;
                    }

<MULTI>\n           {
                         AH_TRACE_LEX("<MULTI>NEWLINE\n");
                         return U_NL;
                    }

<VAL>{value}        {
                         AH_TRACE_LEX("VALUE           : [%s]\n", yytext);
                         yylval.value                  = strdup(yytext);
                         BEGIN 0;
                         return U_VALUE;
                    }

<VAL>\n             {
                         AH_TRACE_LEX("<VAL>NEWLINE\n");
                         BEGIN 0;
                         return U_NL;
                    }

\n                  {
                         AH_TRACE_LEX("NEWLINE\n");
                         return U_NL;
                    }

.                   {
                         AH_TRACE_LEX("<%s>\n", yytext);
                    }
%%

#if 0
/******************************************************************************

                              MAIN

******************************************************************************/
int main(int argc, char *argv[])
{
     ah_init(0, "u_logfile.debug", argv[0], "",
             AH_DSP_TIMESTAMP| AH_DSP_TTY, 120);

     u_disp_lex          = TRUE;
     u_disp_yacc         = TRUE;

//   U_lex();
     U_parse();
     return 0;
}
#endif    /* 0 */

/******************************************************************************

                              YYWRAP

******************************************************************************/
int yywrap()
{
     /* Pour supprimer le warning : input defined but not used
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     int            (*_input)()    = input;
     _input                        = _input;

     return 1;
}

/******************************************************************************

                              YYERROR

******************************************************************************/
int yyerror(char *errmsg)
{
     AH_CTX_PRT(0, AH_ERR, "%d: %s at \"%s\"\n", yylineno, errmsg, yytext);
     exit(M_ERR_BAD_PARAM);
}

