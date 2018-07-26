
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

  virtual antlrcpp::Any visitProgram(PMACParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLine(PMACParser::LineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(PMACParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAction(PMACParser::ActionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStatement(PMACParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileStatement(PMACParser::WhileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitData(PMACParser::DataContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant(PMACParser::ConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssign(PMACParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(PMACParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondition(PMACParser::ConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp(PMACParser::OpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComparator(PMACParser::ComparatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAxis(PMACParser::AxisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAtom(PMACParser::AtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber(PMACParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar(PMACParser::VarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction(PMACParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }


};

