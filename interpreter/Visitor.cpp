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
    } else if (ctx->whileStatement()) {
        this->visitWhileStatement(ctx->whileStatement());
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
        bool condition = this->visitCompoundCondition(ctx->compoundCondition()).as<bool>();
        if (condition) {
            if (ctx->ifAction) {
                this->visitAction(ctx->ifAction);
            } else if (ctx->ENDIF() && !(ctx->ifLines.empty())){
                for (auto line : ctx->ifLines) this->visitLine(line);
            }
        } else {
            if (ctx->ELSE()) {
                if (ctx->elseAction){
                   this->visitAction(ctx->elseAction);
                } else if (!ctx->elseLines.empty() && ctx->ENDIF()) {
                    for (auto line : ctx->elseLines) this->visitLine(line);
                } else {
                    throw std::invalid_argument("Action or lines expected");
                }
            }
        }
    } else {
        throw std::invalid_argument("IF statement expected at this line");
    }
    return antlrcpp::Any();
}

antlrcpp::Any Visitor::visitWhileStatement(PMACParser::WhileStatementContext *ctx) {
    if (ctx->WHILE()) {
        while (this->visitCompoundCondition(ctx->compoundCondition()).as<bool>()) {
            if(ctx->whileAction) {
                this->visitAction(ctx->whileAction);
            } else if (!ctx->whileLines.empty() && ctx->ENDWHILE()) {
                for (auto line : ctx->whileLines) this->visitLine(line);
            } else {
                throw std::invalid_argument("Action or lines expected");
            }
        }
    } else {
        throw std::invalid_argument("WHILE statement expected at this line");
    }
    return antlrcpp::Any();
}

antlrcpp::Any Visitor::visitCompoundCondition(PMACParser::CompoundConditionContext *ctx) {
    if (ctx->LPAR() && ctx->center && ctx->RPAR()) {
        return antlrcpp::Any(this->visitCompoundCondition(ctx->center));
    } else if (ctx->left && ctx->logicalOp && ctx->right) {
        bool left  = this->visitCompoundCondition(ctx->left).as<bool>();
        bool right = this->visitCompoundCondition(ctx->right).as<bool>();
        if (ctx->AND()) {
            return antlrcpp::Any(left && right);
        } else if (ctx->OR()) {
            return antlrcpp::Any(left || right);
        }
    } else if (ctx->condition()) {
        return antlrcpp::Any(this->visitCondition(ctx->condition()));
    }
    return PMACBaseVisitor::visitCompoundCondition(ctx);
}

antlrcpp::Any Visitor::visitCondition(PMACParser::ConditionContext *ctx) {
    if (ctx->left && ctx->comparator() && ctx->right) {
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

antlrcpp::Any Visitor::visitAssign(PMACParser::AssignContext *ctx) {
    // First visit the right side of the assignment
    double expr = this->visitExpr(ctx->expr()).as<double>();
    this->env.setVariable(ctx->var()->getText(), expr);
    //std::cout << ctx->var()->getText() << " = " << expr << std::endl << std::flush;
    return antlrcpp::Any();
}

antlrcpp::Any Visitor::visitExpr(PMACParser::ExprContext *ctx) {
    // if atom -> return its value
    if (ctx->atom()) return this->visitAtom(ctx->atom());
    // '(' center=expr ')'
    if (ctx->LPAR() && ctx->center && ctx->RPAR()) return this->visitExpr(ctx->center);
    // MIN expr
    if (ctx->minExpr) {
       return antlrcpp::Any(-(this->visitExpr(ctx->minExpr).as<double>()));
    }
    // left op right
    if (ctx->left && ctx->op && ctx->right) {
        double left  = this->visitExpr(ctx->left).as<double>();
        double right = this->visitExpr(ctx->right).as<double>();
        // left PLUS right
        if (ctx->PLUS()) {
            return antlrcpp::Any(left+right);
        // left MIN right
        } else if (ctx->MIN()) {
            return antlrcpp::Any(left-right);
        // left MULT right
        } else if (ctx->MULT()) {
            return antlrcpp::Any(left * right);
        // left DIV right
        } else if (ctx->DIV()) {
            if (right == 0) {
                throw std::logic_error("Division by zero");
            } else {
                return antlrcpp::Any(left / right);
            }
        }
    }
    // function '(' argument=expr ')'
    if (ctx->function() && ctx->LPAR() && ctx->argument && ctx->RPAR()) {
        double argument = this->visitExpr(ctx->argument).as<double>();

        // Standard functions
        if (ctx->function()->LN()) {
            return antlrcpp::Any(std::log(argument));
        } else if (ctx->function()->EXP()) {
            return antlrcpp::Any(std::exp(argument));
        } else if (ctx->function()->SQRT()) {
            if (argument >= 0.0) {
                return antlrcpp::Any(std::sqrt(argument));
            } else {
                throw std::invalid_argument("SQRT() must have a positive argument. "
                                            "Argument value:" + std::to_string(argument));
            }
        } else if (ctx->function()->ABS()) {
            return antlrcpp::Any(std::abs(argument));
        } else if (ctx->function()->INT()) {
            return antlrcpp::Any(std::floor(argument));
        }


        // Trigonometric functions
        double rad = argument;
        double angle = 0.0;
        // convert the input argument rad to degree if i15 == 0
        if (this->env.getValue("i15") == 0.0) {
            rad = argument / 180.0 * M_PI;
        }
        if (ctx->function()->SIN()) {
            return antlrcpp::Any(std::sin(rad));
        } else if (ctx->function()->COS()) {
            return antlrcpp::Any(std::cos(rad));
        } else if (ctx->function()->TAN()) {
            return antlrcpp::Any(std::tan(rad));
        } else if (ctx->function()->ASIN()) {
            angle = std::asin(argument);
        } else if (ctx->function()->ACOS()) {
            angle = std::acos(argument);
        } else if (ctx->function()->ATAN()) {
            angle = std::atan(argument);
        } else if (ctx->function()->ATAN2()) {
            double cos_val = this->env.getValue("q0");
            if ((argument == 0.0) && (cos_val == 0))
                throw std::invalid_argument("ATAN 2, both argument are equal to zero");
            angle = std::atan2(argument, cos_val);
        }
        // convert the angle result back to degree if i15 == 0
        if (this->env.getValue("i15") == 0.0) {
            angle = angle / M_PI * 180.0;
        }
        return antlrcpp::Any(angle);
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
