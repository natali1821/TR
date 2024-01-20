
// Generated from gram.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "gramListener.h"


/**
 * This class provides an empty implementation of gramListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  gramBaseListener : public gramListener {
public:

  virtual void enterDecl(gramParser::DeclContext * /*ctx*/) override { }
  virtual void exitDecl(gramParser::DeclContext * /*ctx*/) override { }

  virtual void enterInit(gramParser::InitContext * /*ctx*/) override { }
  virtual void exitInit(gramParser::InitContext * /*ctx*/) override { }

  virtual void enterAssign(gramParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(gramParser::AssignContext * /*ctx*/) override { }

  virtual void enterValue(gramParser::ValueContext * /*ctx*/) override { }
  virtual void exitValue(gramParser::ValueContext * /*ctx*/) override { }

  virtual void enterCalc(gramParser::CalcContext * /*ctx*/) override { }
  virtual void exitCalc(gramParser::CalcContext * /*ctx*/) override { }

  virtual void enterType(gramParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(gramParser::TypeContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

