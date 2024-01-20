
// Generated from gram.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "gramParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by gramParser.
 */
class  gramVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by gramParser.
   */
    virtual antlrcpp::Any visitDecl(gramParser::DeclContext *context) = 0;

    virtual antlrcpp::Any visitInit(gramParser::InitContext *context) = 0;

    virtual antlrcpp::Any visitAssign(gramParser::AssignContext *context) = 0;

    virtual antlrcpp::Any visitValue(gramParser::ValueContext *context) = 0;

    virtual antlrcpp::Any visitCalc(gramParser::CalcContext *context) = 0;

    virtual antlrcpp::Any visitType(gramParser::TypeContext *context) = 0;


};

