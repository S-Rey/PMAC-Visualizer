
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
    virtual antlrcpp::Any visitFile(PMACParser::FileContext *context) = 0;

    virtual antlrcpp::Any visitName(PMACParser::NameContext *context) = 0;

    virtual antlrcpp::Any visitAction(PMACParser::ActionContext *context) = 0;

    virtual antlrcpp::Any visitSize(PMACParser::SizeContext *context) = 0;

    virtual antlrcpp::Any visitShape(PMACParser::ShapeContext *context) = 0;

    virtual antlrcpp::Any visitColor(PMACParser::ColorContext *context) = 0;

    virtual antlrcpp::Any visitPosition(PMACParser::PositionContext *context) = 0;


};

