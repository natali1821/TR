
// Generated from gram.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "gramVisitor.h"


/**
 * This class provides an empty implementation of gramVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  gramBaseVisitor : public gramVisitor {
public:

  virtual antlrcpp::Any visitDecl(gramParser::DeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInit(gramParser::InitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssign(gramParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitValue(gramParser::ValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCalc(gramParser::CalcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(gramParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }


};

