%{
        /*****************************************************************
        *This file sets the rules for the parser. It is used with the
        *bison and c files provided.
        *Reference:
        *   Regex Cheat Sheet(http://www.rexegg.com/regex-quickstart.html)
        *
        *@authors Cade Baker and Megan Thomas
        *@version March 2018
        *****************************************************************/
       
        #include "zoomjoystrong.tab.h"
        #include <stdlib.h>
%}

%option noyywrap

%%


(end)                                   {yylval.str = strdup(yytext); return END;}
\;                                      {return END_STATEMENT;}
(point)                                 {yylval.str = strdup(yytext); return POINT;}
(line)                                  {yylval.str = strdup(yytext); return LINE;}
(circle)                                {yylval.str = strdup(yytext); return CIRCLE;}
(rectangle)                             {yylval.str = strdup(yytext); return RECTANGLE;}
(set_color)                             {yylval.str = strdup(yytext); return SET_COLOR;}
[-]?[0-9]+                              {yylval.i = atoi(yytext); return INT;}
[-]?[0-9]+\.[0-9]+                      {yylval.f = atof(yytext); return FLOAT;}
[ \t\n]                                 ;//ignores whitespace, indent, and new line characters
.                                       { printf("Input is Invalid\n");//if we have any characters not listed then the value is invalid
                                        }
%%
