
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
    PVT = 28, SPLINE1 = 29, SPLINE2 = 30, CC0 = 31, CC1 = 32, CC2 = 33, 
    CC3 = 34, DWELL = 35, DELAY = 36, HOME = 37, HOMEZ = 38, INC = 39, FRAX = 40, 
    NOFRAX = 41, NORMAL = 42, PSET = 43, AX_X = 44, AX_Y = 45, AX_Z = 46, 
    AX_A = 47, AX_B = 48, AX_C = 49, AX_U = 50, AX_V = 51, AX_W = 52, V_I = 53, 
    V_J = 54, V_K = 55, RADIUS = 56, INTEGER = 57, DECIMAL = 58, HEX = 59, 
    PLUS = 60, MIN = 61, MULT = 62, DIV = 63, MOD = 64, AND_OP = 65, OR_OP = 66, 
    XOR = 67, EQ = 68, NEQ = 69, LT = 70, GT = 71, NLT = 72, NGT = 73, LPAR = 74, 
    RPAR = 75, COLON = 76, SEMIOLON = 77, COMMA = 78, NL = 79, COMMENT = 80, 
    WS = 81
  };

  enum {
    RuleProgram = 0, RuleLine = 1, RuleStatement = 2, RuleAction = 3, RuleIfStatement = 4, 
    RuleWhileStatement = 5, RuleCompoundCondition = 6, RuleCondition = 7, 
    RuleData = 8, RuleConstant = 9, RuleAssign = 10, RuleMoveCmds = 11, 
    RuleMoveCmdSimple = 12, RuleMoveCmdVelocity = 13, RuleAxisAttrCmds = 14, 
    RuleExpr = 15, RuleModeMoveCmds = 16, RuleAxis = 17, RuleVectorCoordinate = 18, 
    RuleComparator = 19, RuleAtom = 20, RuleNumber = 21, RuleVar = 22, RuleFunction = 23
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
  class CompoundConditionContext;
  class ConditionContext;
  class DataContext;
  class ConstantContext;
  class AssignContext;
  class MoveCmdsContext;
  class MoveCmdSimpleContext;
  class MoveCmdVelocityContext;
  class AxisAttrCmdsContext;
  class ExprContext;
  class ModeMoveCmdsContext;
  class AxisContext;
  class VectorCoordinateContext;
  class ComparatorContext;
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
    antlr4::tree::TerminalNode *EOF_ANT();
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
    MoveCmdsContext *moveCmds();
    AxisAttrCmdsContext *axisAttrCmds();
    std::vector<ActionContext *> action();
    ActionContext* action(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ActionContext* action();
  ActionContext* action(int precedence);
  class  IfStatementContext : public antlr4::ParserRuleContext {
  public:
    PMACParser::ActionContext *ifAction = nullptr;;
    PMACParser::ActionContext *elseAction = nullptr;;
    PMACParser::LineContext *lineContext = nullptr;;
    std::vector<LineContext *> ifLines;;
    std::vector<LineContext *> elseLines;;
    IfStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    CompoundConditionContext *compoundCondition();
    std::vector<ActionContext *> action();
    ActionContext* action(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NL();
    antlr4::tree::TerminalNode* NL(size_t i);
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *ENDIF();
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
    CompoundConditionContext *compoundCondition();
    antlr4::tree::TerminalNode *NL();
    antlr4::tree::TerminalNode *ENDWHILE();
    ActionContext *action();
    std::vector<LineContext *> line();
    LineContext* line(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileStatementContext* whileStatement();

  class  CompoundConditionContext : public antlr4::ParserRuleContext {
  public:
    PMACParser::CompoundConditionContext *left = nullptr;;
    PMACParser::CompoundConditionContext *center = nullptr;;
    antlr4::Token *logicalOp = nullptr;;
    PMACParser::CompoundConditionContext *right = nullptr;;
    CompoundConditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *RPAR();
    std::vector<CompoundConditionContext *> compoundCondition();
    CompoundConditionContext* compoundCondition(size_t i);
    ConditionContext *condition();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *NL();
    antlr4::tree::TerminalNode *OR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompoundConditionContext* compoundCondition();
  CompoundConditionContext* compoundCondition(int precedence);
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
    std::vector<antlr4::tree::TerminalNode *> EQ();
    antlr4::tree::TerminalNode* EQ(size_t i);
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignContext* assign();

  class  MoveCmdsContext : public antlr4::ParserRuleContext {
  public:
    PMACParser::MoveCmdSimpleContext *moveCmdSimpleContext = nullptr;;
    std::vector<MoveCmdSimpleContext *> listSimple;;
    PMACParser::MoveCmdVelocityContext *moveCmdVelocityContext = nullptr;;
    std::vector<MoveCmdVelocityContext *> listVelocity;;
    MoveCmdsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<MoveCmdSimpleContext *> moveCmdSimple();
    MoveCmdSimpleContext* moveCmdSimple(size_t i);
    std::vector<MoveCmdVelocityContext *> moveCmdVelocity();
    MoveCmdVelocityContext* moveCmdVelocity(size_t i);
    ModeMoveCmdsContext *modeMoveCmds();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MoveCmdsContext* moveCmds();

  class  MoveCmdSimpleContext : public antlr4::ParserRuleContext {
  public:
    MoveCmdSimpleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AxisContext *axis();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MoveCmdSimpleContext* moveCmdSimple();

  class  MoveCmdVelocityContext : public antlr4::ParserRuleContext {
  public:
    PMACParser::ExprContext *position = nullptr;;
    PMACParser::ExprContext *velocity = nullptr;;
    MoveCmdVelocityContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AxisContext *axis();
    antlr4::tree::TerminalNode *COLON();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MoveCmdVelocityContext* moveCmdVelocity();

  class  AxisAttrCmdsContext : public antlr4::ParserRuleContext {
  public:
    PMACParser::AxisContext *axisContext = nullptr;;
    std::vector<AxisContext *> axisList;;
    AxisAttrCmdsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ABS();
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *RPAR();
    std::vector<AxisContext *> axis();
    AxisContext* axis(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *INC();
    antlr4::tree::TerminalNode *FRAX();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AxisAttrCmdsContext* axisAttrCmds();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    PMACParser::ExprContext *left = nullptr;;
    PMACParser::ExprContext *center = nullptr;;
    PMACParser::ExprContext *argument = nullptr;;
    PMACParser::ExprContext *minExpr = nullptr;;
    antlr4::Token *op = nullptr;;
    PMACParser::ExprContext *right = nullptr;;
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *RPAR();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    FunctionContext *function();
    antlr4::tree::TerminalNode *MIN();
    AtomContext *atom();
    antlr4::tree::TerminalNode *MULT();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *AND_OP();
    antlr4::tree::TerminalNode *XOR();
    antlr4::tree::TerminalNode *OR_OP();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  ModeMoveCmdsContext : public antlr4::ParserRuleContext {
  public:
    ModeMoveCmdsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LINEAR();
    antlr4::tree::TerminalNode *RAPID();
    antlr4::tree::TerminalNode *CIRCLE1();
    antlr4::tree::TerminalNode *CIRCLE2();
    antlr4::tree::TerminalNode *PVT();
    antlr4::tree::TerminalNode *SPLINE1();
    antlr4::tree::TerminalNode *SPLINE2();
    antlr4::tree::TerminalNode *CC0();
    antlr4::tree::TerminalNode *CC1();
    antlr4::tree::TerminalNode *CC2();
    antlr4::tree::TerminalNode *CC3();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModeMoveCmdsContext* modeMoveCmds();

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
    antlr4::tree::TerminalNode *RADIUS();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AxisContext* axis();

  class  VectorCoordinateContext : public antlr4::ParserRuleContext {
  public:
    VectorCoordinateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *V_I();
    antlr4::tree::TerminalNode *V_J();
    antlr4::tree::TerminalNode *V_K();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VectorCoordinateContext* vectorCoordinate();

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
  bool compoundConditionSempred(CompoundConditionContext *_localctx, size_t predicateIndex);
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

