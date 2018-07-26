
// Generated from PMAC.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  PMACParser : public antlr4::Parser {
public:
  enum {
    IF = 1, ELSE = 2, ENDIF = 3, WHILE = 4, ENDWHILE = 5, AND = 6, OR = 7, 
    Q_VAR = 8, P_VAR = 9, I_VAR = 10, M_VAR = 11, SIN = 12, COS = 13, TAN = 14, 
    ASIN = 15, ACOS = 16, ATAN = 17, ATAN2 = 18, LN = 19, EXP = 20, SQRT = 21, 
    ABS = 22, INT = 23, LINEAR = 24, RAPID = 25, CIRCLE1 = 26, CIRCLE2 = 27, 
    SPLINE1 = 28, SPLINE2 = 29, CC0 = 30, CC1 = 31, CC2 = 32, CC3 = 33, 
    AX_X = 34, AX_Y = 35, AX_Z = 36, AX_A = 37, AX_B = 38, AX_C = 39, AX_U = 40, 
    AX_V = 41, AX_W = 42, INTEGER = 43, DECIMAL = 44, HEX = 45, PLUS = 46, 
    MIN = 47, MULT = 48, DIV = 49, MOD = 50, AND_OP = 51, OR_OP = 52, XOR = 53, 
    EQ = 54, NEQ = 55, LT = 56, GT = 57, NLT = 58, NGT = 59, LPAR = 60, 
    RPAR = 61, NL = 62, COMMENT = 63, WS = 64
  };

  enum {
    RuleProgram = 0, RuleLine = 1, RuleStatement = 2, RuleAction = 3, RuleIfStatement = 4, 
    RuleWhileStatement = 5, RuleData = 6, RuleConstant = 7, RuleAssign = 8, 
    RuleExpr = 9, RuleCondition = 10, RuleOp = 11, RuleComparator = 12, 
    RuleAxis = 13, RuleAtom = 14, RuleNumber = 15, RuleVar = 16, RuleFunction = 17
  };

  PMACParser(antlr4::TokenStream *input);
  ~PMACParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class LineContext;
  class StatementContext;
  class ActionContext;
  class IfStatementContext;
  class WhileStatementContext;
  class DataContext;
  class ConstantContext;
  class AssignContext;
  class ExprContext;
  class ConditionContext;
  class OpContext;
  class ComparatorContext;
  class AxisContext;
  class AtomContext;
  class NumberContext;
  class VarContext;
  class FunctionContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    PMACParser::LineContext *lineContext = nullptr;;
    std::vector<LineContext *> lines;;
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<LineContext *> line();
    LineContext* line(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  LineContext : public antlr4::ParserRuleContext {
  public:
    LineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    antlr4::tree::TerminalNode *NL();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LineContext* line();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ActionContext *action();
    IfStatementContext *ifStatement();
    WhileStatementContext *whileStatement();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  ActionContext : public antlr4::ParserRuleContext {
  public:
    PMACParser::ActionContext *leftAction = nullptr;;
    PMACParser::ActionContext *rightAction = nullptr;;
    ActionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignContext *assign();
    std::vector<ActionContext *> action();
    ActionContext* action(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ActionContext* action();
  ActionContext* action(int precedence);
  class  IfStatementContext : public antlr4::ParserRuleContext {
  public:
    PMACParser::ActionContext *ifAction = nullptr;;
    PMACParser::LineContext *lineContext = nullptr;;
    std::vector<LineContext *> ifLines;;
    PMACParser::ActionContext *elseAction = nullptr;;
    std::vector<LineContext *> elseLines;;
    IfStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *LPAR();
    ConditionContext *condition();
    antlr4::tree::TerminalNode *RPAR();
    ActionContext *action();
    std::vector<antlr4::tree::TerminalNode *> NL();
    antlr4::tree::TerminalNode* NL(size_t i);
    antlr4::tree::TerminalNode *ENDIF();
    antlr4::tree::TerminalNode *ELSE();
    std::vector<LineContext *> line();
    LineContext* line(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfStatementContext* ifStatement();

  class  WhileStatementContext : public antlr4::ParserRuleContext {
  public:
    PMACParser::ActionContext *whileAction = nullptr;;
    PMACParser::LineContext *lineContext = nullptr;;
    std::vector<LineContext *> whileLines;;
    WhileStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *LPAR();
    ConditionContext *condition();
    antlr4::tree::TerminalNode *RPAR();
    antlr4::tree::TerminalNode *NL();
    antlr4::tree::TerminalNode *ENDWHILE();
    ActionContext *action();
    std::vector<LineContext *> line();
    LineContext* line(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileStatementContext* whileStatement();

  class  DataContext : public antlr4::ParserRuleContext {
  public:
    DataContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstantContext *constant();
    antlr4::tree::TerminalNode *LPAR();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RPAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DataContext* data();

  class  ConstantContext : public antlr4::ParserRuleContext {
  public:
    ConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstantContext* constant();

  class  AssignContext : public antlr4::ParserRuleContext {
  public:
    AssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarContext *var();
    antlr4::tree::TerminalNode *EQ();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignContext* assign();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    PMACParser::ExprContext *left = nullptr;;
    PMACParser::ExprContext *center = nullptr;;
    PMACParser::ExprContext *minExpr = nullptr;;
    PMACParser::ExprContext *right = nullptr;;
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *RPAR();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *MIN();
    FunctionContext *function();
    AtomContext *atom();
    OpContext *op();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  ConditionContext : public antlr4::ParserRuleContext {
  public:
    PMACParser::ExprContext *left = nullptr;;
    PMACParser::ExprContext *right = nullptr;;
    ConditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ComparatorContext *comparator();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConditionContext* condition();

  class  OpContext : public antlr4::ParserRuleContext {
  public:
    OpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MIN();
    antlr4::tree::TerminalNode *MULT();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *AND_OP();
    antlr4::tree::TerminalNode *OR_OP();
    antlr4::tree::TerminalNode *XOR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OpContext* op();

  class  ComparatorContext : public antlr4::ParserRuleContext {
  public:
    ComparatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NEQ();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *NLT();
    antlr4::tree::TerminalNode *NGT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ComparatorContext* comparator();

  class  AxisContext : public antlr4::ParserRuleContext {
  public:
    AxisContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AX_X();
    antlr4::tree::TerminalNode *AX_Y();
    antlr4::tree::TerminalNode *AX_Z();
    antlr4::tree::TerminalNode *AX_A();
    antlr4::tree::TerminalNode *AX_B();
    antlr4::tree::TerminalNode *AX_C();
    antlr4::tree::TerminalNode *AX_U();
    antlr4::tree::TerminalNode *AX_V();
    antlr4::tree::TerminalNode *AX_W();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AxisContext* axis();

  class  AtomContext : public antlr4::ParserRuleContext {
  public:
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumberContext *number();
    VarContext *var();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AtomContext* atom();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *DECIMAL();
    antlr4::tree::TerminalNode *HEX();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberContext* number();

  class  VarContext : public antlr4::ParserRuleContext {
  public:
    VarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Q_VAR();
    antlr4::tree::TerminalNode *P_VAR();
    antlr4::tree::TerminalNode *I_VAR();
    antlr4::tree::TerminalNode *M_VAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarContext* var();

  class  FunctionContext : public antlr4::ParserRuleContext {
  public:
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SIN();
    antlr4::tree::TerminalNode *COS();
    antlr4::tree::TerminalNode *TAN();
    antlr4::tree::TerminalNode *ASIN();
    antlr4::tree::TerminalNode *ACOS();
    antlr4::tree::TerminalNode *ATAN();
    antlr4::tree::TerminalNode *ATAN2();
    antlr4::tree::TerminalNode *LN();
    antlr4::tree::TerminalNode *EXP();
    antlr4::tree::TerminalNode *SQRT();
    antlr4::tree::TerminalNode *ABS();
    antlr4::tree::TerminalNode *INT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionContext* function();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool actionSempred(ActionContext *_localctx, size_t predicateIndex);
  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

