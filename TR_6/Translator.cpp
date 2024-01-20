#include "Parser.h"
 
/// 
/// <decl> :: = type <init>; | type <init>; <decl>
/// <init> :: = <assign> | <assign>, <init>
/// <assign> :: = var = <value> | var
/// <calc> ::= number + <calc> | number
/// <value> :: = <calc> | True | False


int main()
{
    Parser p;
    p.parse();
    
}