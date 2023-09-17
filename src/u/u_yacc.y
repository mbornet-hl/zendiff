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
 *   File         :     u_yacc.y
 *
 *   @(#)  [Zen] u_yacc.y Version 1.10 of 23/09/17 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../b/b_types.h"
#include "../ah/ah_cpub.h"
#include "../ah/ah_epub.h"
#include "../i/i_cpub.h"
#include "../h/h_cpub.h"
#include "../m/m_cpub.h"
#include "../n/n_magic.h"
#include "../k/k_cpub.h"
#include "../ah/ah_cpub.h"
#include "../ah/ah_epub.h"
#include "u_cpri.h"
#include "u_cpub.h"
#include "u_epri.h"
#include "u_epub.h"

static char                   *__file__                = __FILE__;

static char                   *u_yacc_comment          = 0;

%}

%union {
     char                     *value;
}

%token    <value>             U_VALUE U_MULTI_VAL
%token                        U_LAST_VERSION U_AUTHOR U_CREAT_DATE U_CREAT_TIME
%token                        U_D_YEAR U_D_MONTH U_D_DAY
%token                        U_MODULE_TYPE U_ARCHIVE U_VAR_Q U_COMMENT
%token                        U_SEP_COMMA U_NL U_END_MULTI

%type     <value>             value multi_value list_multi

%start    archive_info

%%

archive_info   : info_line
                    {
                         AH_TRACE_YACC("info_line\n\n");
                    }
               | archive_info info_line
                    {
                         AH_TRACE_YACC("archive_info info_line\n\n");
                    }
               ;

info_line      : U_LAST_VERSION  U_SEP_COMMA value
                    {
                         AH_TRACE_YACC("LAST_VERSION  : value\n");
                         u_info.last_vers              = $3;
                    }
               | U_AUTHOR        U_SEP_COMMA value
                    {
                         AH_TRACE_YACC("AUTHOR        : value\n");
                         u_info.author                 = $3;
                    }
               | U_CREAT_DATE    U_SEP_COMMA value
                    {
                         int                       _year;
                         char                      _str_year[8],
                                                   _str_date[16];

                         AH_TRACE_YACC("CREATION_DATE : value\n");

                         strncpy(_str_year, $3, 2);
                         _str_year[2]                  = 0;
                         _year                         = atoi(_str_year);

                         if (_year < 69) {
                              strcpy(_str_date, "20");
                         }
                         else {
                              strcpy(_str_date, "19");
                         }

                         strcat(_str_date, $3);
                         u_info.creation_date          = strdup(_str_date);
                    }
               | U_D_YEAR        U_SEP_COMMA value
                    {
                         int                       _year;
                         char                      _str_year[8];

                         AH_TRACE_YACC("DELTA YEAR    : value\n");
                         _year                         = atoi($3);
                         if (_year < 69) {
                              _year                    += 2000;
                         }
                         else {
                              _year                    += 1900;
                         }

                         sprintf(_str_year, "%d", _year);
                         u_info.D_year                 = strdup(_str_year);
                    }
               | U_D_MONTH       U_SEP_COMMA value
                    {
                         AH_TRACE_YACC("DELTA MONTH   : value\n");
                         u_info.D_month                = $3;
                    }
               | U_D_DAY         U_SEP_COMMA value
                    {
                         AH_TRACE_YACC("DELTA DAY     : value\n");
                         u_info.D_day                  = $3;
                    }
               | U_CREAT_TIME    U_SEP_COMMA value
                    {
                         AH_TRACE_YACC("CREATION_TIME : value\n");
                         u_info.creation_time          = $3;
                    }
               | U_MODULE_TYPE   U_SEP_COMMA value
                    {
                         AH_TRACE_YACC("MODULE_TYPE   : value\n");
                         u_info.module_type            = $3;
                    }
               | U_ARCHIVE       U_SEP_COMMA value
                    {
                         AH_TRACE_YACC("ARCHIVE       : value\n");
                         u_info.archive                = $3;
                    }
               | U_VAR_Q         U_SEP_COMMA value
                    {
                         AH_TRACE_YACC("VAR_Q         : value\n");
                         u_info.var_Q                  = $3;
                    }
               | U_COMMENT       U_SEP_COMMA U_END_MULTI
                    {
                         AH_TRACE_YACC("EMPTY COMMENT\n");
                         u_info.comment                = strdup("");
                    }
               | U_COMMENT       U_SEP_COMMA list_multi U_END_MULTI
                    {
                         AH_TRACE_YACC("COMMENT        : multi_value\n");
                         u_info.comment                = strdup(u_yacc_comment);
                         u_yacc_comment                = 0;
                    }
               | U_NL
                    {
                         AH_TRACE_YACC("Empty line\n");
                    }
               ;

value          : U_NL
                    {
                         AH_TRACE_YACC("NEWLINE\n");
                    }
               | U_VALUE U_NL
                    {
                         AH_TRACE_YACC("VALUE          : [%s]\n", $1);
                         $$                  = $1;
                    }
               ;

multi_value    : U_NL
                    {
                         AH_TRACE_YACC("Empty line\n");
                    }
               | U_MULTI_VAL U_NL
                    {
                         AH_TRACE_YACC("MULTI_VAL      : [%s]\n", $1);
                         $$                  = $1;
                    }
               ;
list_multi     : multi_value
                    {
                         AH_TRACE_YACC("multi_value   : [%s]\n", $1);
                         u_yacc_comment      = $1;
                         $$                  = u_yacc_comment;
                    }
               | list_multi multi_value
                    {
                         size_t               _len;
                         char                *_tmp, *_p;

                         AH_TRACE_YACC("list_multi multi_value : [%s]\n", $2);
                         AH_TRACE_YACC("list_multi multi_value : u_yacc_comment = [%s]\n",
                                       u_yacc_comment);
                         AH_TRACE_YACC("list_multi multi_value : multi_value    = [%s]\n",
                                       $2);

                         /* 3 : '\n', '\n' and '\0'
                            ~~~~~~~~~~~~~~~~~~~~~~~ */
                         _len                = strlen(u_yacc_comment) + strlen($2) + 3;
                         AH_TRACE_YACC("list_multi multi_value : len            = [%lu]\n",
                                       (unsigned long) _len);

                         _tmp                = u_yacc_comment;
                         if ((u_yacc_comment = malloc(_len)) == NULL) {
                              AH_CTX_PRT(0, AH_ERR, "Malloc error !\n");
                              exit(M_ERR_MALLOC);
                         }

                         _p                  = stpcpy(u_yacc_comment, _tmp);
                         _p                  = stpcpy(_p, "\n");
                         _p                  = stpcpy(_p, $2);
                         _p                  = stpcpy(_p, "\n");
//                         free(_tmp);

                         $$                  = u_yacc_comment;
                    }
               ;

%%
