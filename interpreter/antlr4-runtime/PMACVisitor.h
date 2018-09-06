
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

    virtual antlrcpp::Any visitAction(PMACParser::ActionContext *context) = 0;

    virtual antlrcpp::Any visitIfStatement(PMACParser::IfStatementContext *context) = 0;

    virtual antlrcpp::Any visitWhileStatement(PMACParser::WhileStatementContext *context) = 0;

    virtual antlrcpp::Any visitCompoundCondition(PMACParser::CompoundConditionContext *context) = 0;

    virtual antlrcpp::Any visitCondition(PMACParser::ConditionContext *context) = 0;

    virtual antlrcpp::Any visitData(PMACParser::DataContext *context) = 0;

    virtual antlrcpp::Any visitConstant(PMACParser::ConstantContext *context) = 0;

    virtual antlrcpp::Any visitAssign(PMACParser::AssignContext *context) = 0;

    virtual antlrcpp::Any visitMoveCmds(PMACParser::MoveCmdsContext *context) = 0;

    virtual antlrcpp::Any visitMoveCmdSimple(PMACParser::MoveCmdSimpleContext *context) = 0;

    virtual antlrcpp::Any visitMoveCmdVelocity(PMACParser::MoveCmdVelocityContext *context) = 0;

    virtual antlrcpp::Any visitAxisAttrCmds(PMACParser::AxisAttrCmdsContext *context) = 0;

    virtual antlrcpp::Any visitExpr(PMACParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitModeMoveCmds(PMACParser::ModeMoveCmdsContext *context) = 0;

    virtual antlrcpp::Any visitAxis(PMACParser::AxisContext *context) = 0;

    virtual antlrcpp::Any visitVectorCoordinate(PMACParser::VectorCoordinateContext *context) = 0;

    virtual antlrcpp::Any visitComparator(PMACParser::ComparatorContext *context) = 0;

    virtual antlrcpp::Any visitAtom(PMACParser::AtomContext *context) = 0;

    virtual antlrcpp::Any visitNumber(PMACParser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitVar(PMACParser::VarContext *context) = 0;

    virtual antlrcpp::Any visitFunction(PMACParser::FunctionContext *context) = 0;


};

