
// Generated from PMAC.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "PMACParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by PMACParser.
 */
class  PMACVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by PMACParser.
   */
    virtual antlrcpp::Any visitProgram(PMACParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitLine(PMACParser::LineContext *context) = 0;

    virtual antlrcpp::Any visitStatement(PMACParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitAssign(PMACParser::AssignContext *context) = 0;

    virtual antlrcpp::Any visitExpr(PMACParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitAtom(PMACParser::AtomContext *context) = 0;

    virtual antlrcpp::Any visitNumber(PMACParser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitVar(PMACParser::VarContext *context) = 0;


};

