#include "Visitor.h"

antlrcpp::Any Visitor::visitProgram(PMACParser::ProgramContext *ctx) {
    size_t i = 1;
    for (auto line: ctx->lines) {
        try {
            this->visitLine(line);
        } catch (std::exception& e) {
            std::cerr << "line " << i << ": " << e.what() << std::endl << std::flush;
        }
        ++i;
    }
    std::cout << this->env.toString() << std::endl << std::flush;
    return antlrcpp::Any();
};

antlrcpp::Any Visitor::visitLine(PMACParser::LineContext *ctx) {
    if(ctx->statement()) {
        this->visitStatement(ctx->statement());
    }
    return antlrcpp::Any();
};

antlrcpp::Any Visitor::visitStatement(PMACParser::StatementContext *ctx) {
    if (ctx->action()){
        this->visitAction(ctx->action());
    } else if (ctx->ifStatement()) {
        this->visitIfStatement(ctx->ifStatement());
    }
    return antlrcpp::Any();
}

antlrcpp::Any Visitor::visitAction(PMACParser::ActionContext *ctx) {
    if (ctx->assign()) {
        this->visitAssign(ctx->assign());
    } else if (ctx->leftAction && ctx->rightAction) {
        this->visitAction(ctx->leftAction);
        this->visitAction(ctx->rightAction);
    } else {
        throw std::invalid_argument("Action error");
    }
    return antlrcpp::Any();
}

antlrcpp::Any Visitor::visitIfStatement(PMACParser::IfStatementContext *ctx) {
    if (ctx->IF()) {
        bool condition = this->visitCondition(ctx->condition()).as<bool>();
        if (condition) {
            if (ctx->ifAction) {
                this->visitAction(ctx->ifAction);
            } else if (ctx->ENDIF() && !(ctx->ifLines.empty())){
                for (auto line : ctx->ifLines) this->visitLine(line);
            }
        } else {
            if (ctx->ELSE() && ctx->ENDIF()) {
                if (ctx->elseAction) {
                    this->visitAction(ctx->elseAction);
                } else if (!(ctx->elseLines.empty())){
                    for (auto line : ctx->elseLines) this->visitLine(line);
                }
            }
        }
    } else {
        throw std::invalid_argument("If statement expected at this line");
    }
    return antlrcpp::Any();
}

antlrcpp::Any Visitor::visitAssign(PMACParser::AssignContext *ctx) {
    // First visit the right side of the assignment
    antlrcpp::Any result = this->visitExpr(ctx->expr());
    if (result.isNotNull()) {
        // set variable to the result value
        this->env.setVariable(ctx->var()->getText(), result.as<double>());
        std::cout << ctx->var()->getText() << " = " << result.as<double>() << std::endl;
    } else {
        throw std::invalid_argument("Assign null expression to variable " + ctx->var()->getText());
    }
    return antlrcpp::Any();
}

antlrcpp::Any Visitor::visitExpr(PMACParser::ExprContext *ctx) {
    // if atom -> return its value
    if (ctx->atom()) return this->visitAtom(ctx->atom());
    // '(' expr ')'
    if (ctx->LPAR() && ctx->RPAR()) return this->visitExpr(ctx->center);
    // MIN expr
    if (ctx->minExpr) {
       return antlrcpp::Any(-(this->visitExpr(ctx->minExpr).as<double>()));
    }
    // left op right
    if (ctx->op()) {
        double left  = this->visitExpr(ctx->left).as<double>();
        double right = this->visitExpr(ctx->right).as<double>();
        // left PLUS right
        if (ctx->op()->PLUS()) {
            return antlrcpp::Any(left+right);
        // left MIN right
        } else if (ctx->op()->MIN()) {
            return antlrcpp::Any(left+right);
        // left MULT right
        } else if (ctx->op()->MULT()) {
            return antlrcpp::Any(left * right);
        // left DIV right
        } else if (ctx->op()->DIV()) {
            if (right == 0) {
                throw std::logic_error("Division by zero");
            } else {
                return antlrcpp::Any(left / right);
            }
        }
    }
    return antlrcpp::Any();
}

antlrcpp::Any Visitor::visitCondition(PMACParser::ConditionContext *ctx) {
    if (ctx->comparator()) {
        double left  = this->visitExpr(ctx->left);
        double right = this->visitExpr(ctx->right);
        if (ctx->comparator()->EQ()) {
            return antlrcpp::Any(left == right);
        } else if (ctx->comparator()->NEQ()) {
            return antlrcpp::Any(left != right);
        } else if (ctx->comparator()->LT()) {
            return antlrcpp::Any(left < right);
        } else if (ctx->comparator()->GT()) {
            return antlrcpp::Any(left > right);
        } else if (ctx->comparator()->NLT()) {
            return antlrcpp::Any(left >= right);
        } else if (ctx->comparator()->NGT()) {
            return antlrcpp::Any(left <= right);
        } else {
            throw std::invalid_argument("Condition operator not yet implemented");
        }
    } else {
        throw std::invalid_argument("Condition does not have a comparator");
    }
    return antlrcpp::Any();
}

antlrcpp::Any Visitor::visitAtom(PMACParser::AtomContext *ctx) {
    if (ctx->var()) {
        return antlrcpp::Any(this->env.getValue(ctx->var()->getText()));
    } else if (ctx->number()) {
        return antlrcpp::Any(std::stod(ctx->getText()));
    } else {
        return antlrcpp::Any();
    }
}

antlrcpp::Any Visitor::visitNumber(PMACParser::NumberContext *ctx) {
    return antlrcpp::Any(std::stod(ctx->getText()));
}

antlrcpp::Any Visitor::visitVar(PMACParser::VarContext *ctx) {
    return PMACBaseVisitor::visitVar(ctx);
}





