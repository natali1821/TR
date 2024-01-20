
// Generated from gram.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "gramParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by gramParser.
 */
class  gramListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterDecl(gramParser::DeclContext *ctx) = 0;
  virtual void exitDecl(gramParser::DeclContext *ctx) = 0;

  virtual void enterInit(gramParser::InitContext *ctx) = 0;
  virtual void exitInit(gramParser::InitContext *ctx) = 0;

  virtual void enterAssign(gramParser::AssignContext *ctx) = 0;
  virtual void exitAssign(gramParser::AssignContext *ctx) = 0;

  virtual void enterValue(gramParser::ValueContext *ctx) = 0;
  virtual void exitValue(gramParser::ValueContext *ctx) = 0;

  virtual void enterCalc(gramParser::CalcContext *ctx) = 0;
  virtual void exitCalc(gramParser::CalcContext *ctx) = 0;

  virtual void enterType(gramParser::TypeContext *ctx) = 0;
  virtual void exitType(gramParser::TypeContext *ctx) = 0;


};

