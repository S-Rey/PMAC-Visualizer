#include <string>
#include "antlr4-runtime/antlr4-runtime.h"
#include "antlr4-runtime/PMACBaseVisitor.h"
#include "Scene.h"

class  ImageVisitor : PMACBaseVisitor {
public:    
    antlrcpp::Any visitFile(PMACParser::FileContext *ctx);

	antlrcpp::Any visitAction(PMACParser::ActionContext *ctx);

	antlrcpp::Any visitShape(PMACParser::ShapeContext *ctx);
};

