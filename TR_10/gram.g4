// gram.g4
grammar gram;

decl: type init SEMICOLON decl EOF
    | type init SEMICOLON 
    ;

init: assign 
    | assign COMMA init
    ;

assign: VAR EQUAL value 
    | VAR
    ;

value: calc
    | TRUE
    | FALSE
    ;

calc: NUMBER op=PLUS calc
    | NUMBER
    ;

type: INT 
    | BOOL
    ;

INT: 'int';
BOOL: 'bool';
TRUE: 'True';
FALSE: 'False';
PLUS: '+';
EQUAL: '=';
COMMA: ',';
SEMICOLON: ';';
VAR: [a-zA-Z][a-zA-Z0-9]*;
NUMBER: [-]?[0-9]+;
WS: [ \t\r\n]+ -> skip;