#include <string>
#include "antlr4-runtime/antlr4-runtime.h"
#include "antlr4-runtime/PMACBaseVisitor.h"
#include "Environment.h"

class  Visitor : PMACBaseVisitor {
public:
    antlrcpp::Any visitProgram(PMACParser::ProgramContext *ctx) override;
    antlrcpp::Any visitLine(PMACParser::LineContext *ctx) override;
    antlrcpp::Any visitAssign(PMACParser::AssignContext *ctx) override;
    antlrcpp::Any visitExpr(PMACParser::ExprContext *ctx) override;
    antlrcpp::Any visitAtom(PMACParser::AtomContext *ctx) override;
    antlrcpp::Any visitNumber(PMACParser::NumberContext *ctx) override;
    antlrcpp::Any visitVar(PMACParser::VarContext *ctx) override;

private:
    Environment env = Environment();
};
