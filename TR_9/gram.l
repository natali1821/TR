%{
#define YYSTYPE std::string
#include <iostream>
#include <string>
#include "gram.tab.h"
extern std::string varType;

int yylex();
%}


%%
[ ]                         { }
int                         { yylval = "int "; varType = "int";  return INT; }
bool                        { yylval = "bool "; varType = "bool"; return BOOL; }
True                        { yylval = "true"; return TRUE; }
False                       { yylval = "false"; return FALSE; }
\+                          { return PLUS; }
\,                          { return COMMA; }
\=                          { yylval = " = "; return EQUAL; }
\;                          { return SEMICOLON; }
[-]?[0-9]+                  { yylval = std::string(yytext); return NUMBER; }
[a-zA-Z][a-zA-Z0-9]*        { yylval = std::string(yytext); return VAR; }
\n                          { return EOL; }
.                           { return EOL; }
[\t\r]+                     { return EOL; }
<<EOF>>                     { return 0; }
%%

int yywrap() {
    return 1;
}