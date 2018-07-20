#include "Visitor.h"

antlrcpp::Any Visitor::visitProgram(PMACParser::ProgramContext *ctx) {
    antlrcpp::Any result;
    // visit each line
    for (auto line: ctx->lines) {
        this->visitLine(line);
    }
    return result;
};

antlrcpp::Any Visitor::visitLine(PMACParser::LineContext *ctx) {
    antlrcpp::Any result = antlrcpp::Any();
    // if the line is an assign rule
    if(ctx->assign()) {
        this->visitAssign(ctx->assign());
    }
    return result;
};

antlrcpp::Any Visitor::visitAssign(PMACParser::AssignContext *ctx) {
    antlrcpp::Any result = antlrcpp::Any();
    // First visit the right side of the assignment
    result = this->visitExpr(ctx->expr());
    if (result.isNotNull()) {
        // set variable to the result value
        this->env.setVariable(ctx->var()->getText(), result.as<double>());
        std::cout << ctx->var()->getText() << " = " << result.as<double>() << std::endl;
    }
    return result;
}

antlrcpp::Any Visitor::visitExpr(PMACParser::ExprContext *ctx) {
    antlrcpp::Any result = antlrcpp::Any();

    // if atom -> return its value
    if(ctx->atom()) return this->visitAtom(ctx->atom());

    // '(' expr ')'
    if(ctx->LPAR() && ctx->RPAR()) {
        return this->visitExpr(ctx->centExpr);
    }

    if(ctx->minExpr) {
       return antlrcpp::Any(-(this->visitExpr(ctx->minExpr).as<double>()));
    }

    double left  = this->visitExpr(ctx->leftExpr).as<double>();
    double right = this->visitExpr(ctx->rightExpr).as<double>();
    // left PLUS right
    if (ctx->PLUS()) {
        return antlrcpp::Any(left+right);
    }
    // left MIN right
    if (ctx->MIN()) {
        return antlrcpp::Any(left-right);
    }
    // left MULT right
    if (ctx->MULT()) {
        return antlrcpp::Any(left*right);
    }
    // left DIV right
    if (ctx->DIV()) {
        return antlrcpp::Any(left/right);
    }
    return result;
}

antlrcpp::Any Visitor::visitAtom(PMACParser::AtomContext *ctx) {
    if(ctx->var()) return antlrcpp::Any(this->env.getValue(ctx->var()->getText()));
    return PMACBaseVisitor::visitAtom(ctx);
}

antlrcpp::Any Visitor::visitNumber(PMACParser::NumberContext *ctx) {
    return antlrcpp::Any(std::stod(ctx->getText()));
}

antlrcpp::Any Visitor::visitVar(PMACParser::VarContext *ctx) {
    return PMACBaseVisitor::visitVar(ctx);
}

