
// Generated from PMAC.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "PMACVisitor.h"


/**
 * This class provides an empty implementation of PMACVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  PMACBaseVisitor : public PMACVisitor {
public:

  virtual antlrcpp::Any visitFile(PMACParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitName(PMACParser::NameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAction(PMACParser::ActionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSize(PMACParser::SizeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShape(PMACParser::ShapeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColor(PMACParser::ColorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPosition(PMACParser::PositionContext *ctx) override {
    return visitChildren(ctx);
  }


};

