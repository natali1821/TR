%{
#define YYSTYPE std::string
#include <iostream>
#include <map>
#include <cstdlib>
#include <string>

int yylex();
void yyerror(const char*);
std::map<std::string, std::string> variables;
std::string varType;
%}


%define parse.error verbose

%token INT BOOL TRUE FALSE PLUS COMMA EQUAL SEMICOLON NUMBER VAR EOL

%start decl

%%

decl: type init SEMICOLON decl 
    | type init SEMICOLON EOL { return 0; }
    ;

init: assign 
    | assign COMMA init
    ;

assign: VAR EQUAL value { variables[$1] = $3; } 
    | VAR { if (varType == "int") {
                variables[$1] = "0";
            } 
            else if (varType == "bool") {
                variables[$1] = "false"; 
            } 
        }
    ;

value: calc 
    | TRUE 
    | FALSE
    ;

calc: NUMBER PLUS calc { $$ = std::to_string(std::stoi($1) + std::stoi($3)); }
    | NUMBER 
    ;

type: INT
    | BOOL
    ;

%%

void yyerror(const char* s) {
    std::cerr << "Error: " << s << std::endl;
}


int main() {
    
    yyparse();

    for(const auto& var : variables) {
        std::cout << var.first << " = " << var.second << std::endl;
    }

    return 0;
}