#include "PMACVisitor.h"

using namespace std;

antlrcpp::Any ImageVisitor::visitFile(PMACParser::FileContext *ctx) {
    vector<Element> elements;
    
    for (auto element : ctx->elements) {                
		antlrcpp::Any el = visitAction(element);

        elements.push_back(el);		
    }    
        	
    antlrcpp::Any result = Scene(ctx->name()->NAME()->getText(), elements);
    
	return result;
}

antlrcpp::Any ImageVisitor::visitAction(PMACParser::ActionContext *ctx) {
	Action action;
	
	if (ctx->DRAW()) {
		action = Draw;
		Shape shape = visitShape(ctx->shape());
		return Element(action, ctx->size()->getText(), ctx->color()->getText(), ctx->position()->x->getText(), ctx->position()->y->getText(), shape);
	}
	else if (ctx->WRITE()) {
		action = Write;
		string text = ctx->STRING()->getText().substr(1, ctx->STRING()->getText().length() - 2);
		return Element(action, ctx->size()->getText(), ctx->color()->getText(), ctx->position()->x->getText(), ctx->position()->y->getText(), text);
	}
	else
		action = NoAction;

	return Element(action);
}

antlrcpp::Any ImageVisitor::visitShape(PMACParser::ShapeContext *ctx) {
	return Element::convertShape(ctx->getText());
}