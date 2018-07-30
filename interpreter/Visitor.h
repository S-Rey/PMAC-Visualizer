#include "antlr4-runtime/antlr4-runtime.h"
#include "antlr4-runtime/PMACBaseVisitor.h"
#include "Environment.h"
#include <string>
#include <cmath>

class  Visitor : PMACBaseVisitor {
public:
    antlrcpp::Any visitProgram(PMACParser::ProgramContext *ctx) override;
    antlrcpp::Any visitLine(PMACParser::LineContext *ctx) override;
    antlrcpp::Any visitStatement(PMACParser::StatementContext*ctx) override;
    antlrcpp::Any visitAction(PMACParser::ActionContext *ctx) override;
    antlrcpp::Any visitIfStatement(PMACParser::IfStatementContext *ctx) override;
    antlrcpp::Any visitWhileStatement(PMACParser::WhileStatementContext *ctx) override;
    antlrcpp::Any visitCompoundCondition(PMACParser::CompoundConditionContext *ctx) override;
    antlrcpp::Any visitCondition(PMACParser::ConditionContext *ctx) override;
    antlrcpp::Any visitAssign(PMACParser::AssignContext *ctx) override;
    antlrcpp::Any visitExpr(PMACParser::ExprContext *ctx) override;
    antlrcpp::Any visitAtom(PMACParser::AtomContext *ctx) override;
    antlrcpp::Any visitNumber(PMACParser::NumberContext *ctx) override;
    antlrcpp::Any visitVar(PMACParser::VarContext *ctx) override;
private:
    Environment env = Environment();
};
