
// Generated from PMAC.g4 by ANTLR 4.7.1


#include "PMACVisitor.h"

#include "PMACParser.h"


using namespace antlrcpp;
using namespace antlr4;

PMACParser::PMACParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

PMACParser::~PMACParser() {
  delete _interpreter;
}

std::string PMACParser::getGrammarFileName() const {
  return "PMAC.g4";
}

const std::vector<std::string>& PMACParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& PMACParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

PMACParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PMACParser::ProgramContext::EOF() {
  return getToken(PMACParser::EOF, 0);
}

std::vector<PMACParser::LineContext *> PMACParser::ProgramContext::line() {
  return getRuleContexts<PMACParser::LineContext>();
}

PMACParser::LineContext* PMACParser::ProgramContext::line(size_t i) {
  return getRuleContext<PMACParser::LineContext>(i);
}


size_t PMACParser::ProgramContext::getRuleIndex() const {
  return PMACParser::RuleProgram;
}

antlrcpp::Any PMACParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::ProgramContext* PMACParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, PMACParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(51);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PMACParser::IF)
      | (1ULL << PMACParser::WHILE)
      | (1ULL << PMACParser::Q_VAR)
      | (1ULL << PMACParser::P_VAR)
      | (1ULL << PMACParser::I_VAR)
      | (1ULL << PMACParser::M_VAR)
      | (1ULL << PMACParser::ABS)
      | (1ULL << PMACParser::LINEAR)
      | (1ULL << PMACParser::RAPID)
      | (1ULL << PMACParser::CIRCLE1)
      | (1ULL << PMACParser::CIRCLE2)
      | (1ULL << PMACParser::PVT)
      | (1ULL << PMACParser::SPLINE1)
      | (1ULL << PMACParser::SPLINE2)
      | (1ULL << PMACParser::CC0)
      | (1ULL << PMACParser::CC1)
      | (1ULL << PMACParser::CC2)
      | (1ULL << PMACParser::CC3)
      | (1ULL << PMACParser::INC)
      | (1ULL << PMACParser::FRAX)
      | (1ULL << PMACParser::AX_X)
      | (1ULL << PMACParser::AX_Y)
      | (1ULL << PMACParser::AX_Z)
      | (1ULL << PMACParser::AX_A)
      | (1ULL << PMACParser::AX_B)
      | (1ULL << PMACParser::AX_C)
      | (1ULL << PMACParser::AX_U)
      | (1ULL << PMACParser::AX_V)
      | (1ULL << PMACParser::AX_W)
      | (1ULL << PMACParser::RADIUS))) != 0) || _la == PMACParser::NL) {
      setState(48);
      dynamic_cast<ProgramContext *>(_localctx)->lineContext = line();
      dynamic_cast<ProgramContext *>(_localctx)->lines.push_back(dynamic_cast<ProgramContext *>(_localctx)->lineContext);
      setState(53);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(54);
    match(PMACParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineContext ------------------------------------------------------------------

PMACParser::LineContext::LineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PMACParser::StatementContext* PMACParser::LineContext::statement() {
  return getRuleContext<PMACParser::StatementContext>(0);
}

tree::TerminalNode* PMACParser::LineContext::NL() {
  return getToken(PMACParser::NL, 0);
}


size_t PMACParser::LineContext::getRuleIndex() const {
  return PMACParser::RuleLine;
}

antlrcpp::Any PMACParser::LineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitLine(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::LineContext* PMACParser::line() {
  LineContext *_localctx = _tracker.createInstance<LineContext>(_ctx, getState());
  enterRule(_localctx, 2, PMACParser::RuleLine);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(61);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PMACParser::IF:
      case PMACParser::WHILE:
      case PMACParser::Q_VAR:
      case PMACParser::P_VAR:
      case PMACParser::I_VAR:
      case PMACParser::M_VAR:
      case PMACParser::ABS:
      case PMACParser::LINEAR:
      case PMACParser::RAPID:
      case PMACParser::CIRCLE1:
      case PMACParser::CIRCLE2:
      case PMACParser::PVT:
      case PMACParser::SPLINE1:
      case PMACParser::SPLINE2:
      case PMACParser::CC0:
      case PMACParser::CC1:
      case PMACParser::CC2:
      case PMACParser::CC3:
      case PMACParser::INC:
      case PMACParser::FRAX:
      case PMACParser::AX_X:
      case PMACParser::AX_Y:
      case PMACParser::AX_Z:
      case PMACParser::AX_A:
      case PMACParser::AX_B:
      case PMACParser::AX_C:
      case PMACParser::AX_U:
      case PMACParser::AX_V:
      case PMACParser::AX_W:
      case PMACParser::RADIUS: {
        enterOuterAlt(_localctx, 1);
        setState(56);
        statement();
        setState(58);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          setState(57);
          match(PMACParser::NL);
          break;
        }

        }
        break;
      }

      case PMACParser::NL: {
        enterOuterAlt(_localctx, 2);
        setState(60);
        match(PMACParser::NL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

PMACParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PMACParser::ActionContext* PMACParser::StatementContext::action() {
  return getRuleContext<PMACParser::ActionContext>(0);
}

PMACParser::IfStatementContext* PMACParser::StatementContext::ifStatement() {
  return getRuleContext<PMACParser::IfStatementContext>(0);
}

PMACParser::WhileStatementContext* PMACParser::StatementContext::whileStatement() {
  return getRuleContext<PMACParser::WhileStatementContext>(0);
}


size_t PMACParser::StatementContext::getRuleIndex() const {
  return PMACParser::RuleStatement;
}

antlrcpp::Any PMACParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::StatementContext* PMACParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, PMACParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(66);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PMACParser::Q_VAR:
      case PMACParser::P_VAR:
      case PMACParser::I_VAR:
      case PMACParser::M_VAR:
      case PMACParser::ABS:
      case PMACParser::LINEAR:
      case PMACParser::RAPID:
      case PMACParser::CIRCLE1:
      case PMACParser::CIRCLE2:
      case PMACParser::PVT:
      case PMACParser::SPLINE1:
      case PMACParser::SPLINE2:
      case PMACParser::CC0:
      case PMACParser::CC1:
      case PMACParser::CC2:
      case PMACParser::CC3:
      case PMACParser::INC:
      case PMACParser::FRAX:
      case PMACParser::AX_X:
      case PMACParser::AX_Y:
      case PMACParser::AX_Z:
      case PMACParser::AX_A:
      case PMACParser::AX_B:
      case PMACParser::AX_C:
      case PMACParser::AX_U:
      case PMACParser::AX_V:
      case PMACParser::AX_W:
      case PMACParser::RADIUS: {
        enterOuterAlt(_localctx, 1);
        setState(63);
        action(0);
        break;
      }

      case PMACParser::IF: {
        enterOuterAlt(_localctx, 2);
        setState(64);
        ifStatement();
        break;
      }

      case PMACParser::WHILE: {
        enterOuterAlt(_localctx, 3);
        setState(65);
        whileStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ActionContext ------------------------------------------------------------------

PMACParser::ActionContext::ActionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PMACParser::AssignContext* PMACParser::ActionContext::assign() {
  return getRuleContext<PMACParser::AssignContext>(0);
}

PMACParser::MoveCmdsContext* PMACParser::ActionContext::moveCmds() {
  return getRuleContext<PMACParser::MoveCmdsContext>(0);
}

PMACParser::AxisAttrCmdsContext* PMACParser::ActionContext::axisAttrCmds() {
  return getRuleContext<PMACParser::AxisAttrCmdsContext>(0);
}

std::vector<PMACParser::ActionContext *> PMACParser::ActionContext::action() {
  return getRuleContexts<PMACParser::ActionContext>();
}

PMACParser::ActionContext* PMACParser::ActionContext::action(size_t i) {
  return getRuleContext<PMACParser::ActionContext>(i);
}


size_t PMACParser::ActionContext::getRuleIndex() const {
  return PMACParser::RuleAction;
}

antlrcpp::Any PMACParser::ActionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitAction(this);
  else
    return visitor->visitChildren(this);
}


PMACParser::ActionContext* PMACParser::action() {
   return action(0);
}

PMACParser::ActionContext* PMACParser::action(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PMACParser::ActionContext *_localctx = _tracker.createInstance<ActionContext>(_ctx, parentState);
  PMACParser::ActionContext *previousContext = _localctx;
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, PMACParser::RuleAction, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(72);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PMACParser::Q_VAR:
      case PMACParser::P_VAR:
      case PMACParser::I_VAR:
      case PMACParser::M_VAR: {
        setState(69);
        assign();
        break;
      }

      case PMACParser::LINEAR:
      case PMACParser::RAPID:
      case PMACParser::CIRCLE1:
      case PMACParser::CIRCLE2:
      case PMACParser::PVT:
      case PMACParser::SPLINE1:
      case PMACParser::SPLINE2:
      case PMACParser::CC0:
      case PMACParser::CC1:
      case PMACParser::CC2:
      case PMACParser::CC3:
      case PMACParser::AX_X:
      case PMACParser::AX_Y:
      case PMACParser::AX_Z:
      case PMACParser::AX_A:
      case PMACParser::AX_B:
      case PMACParser::AX_C:
      case PMACParser::AX_U:
      case PMACParser::AX_V:
      case PMACParser::AX_W:
      case PMACParser::RADIUS: {
        setState(70);
        moveCmds();
        break;
      }

      case PMACParser::ABS:
      case PMACParser::INC:
      case PMACParser::FRAX: {
        setState(71);
        axisAttrCmds();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(78);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ActionContext>(parentContext, parentState);
        _localctx->leftAction = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleAction);
        setState(74);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(75);
        dynamic_cast<ActionContext *>(_localctx)->rightAction = action(2); 
      }
      setState(80);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

PMACParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PMACParser::IfStatementContext::IF() {
  return getToken(PMACParser::IF, 0);
}

PMACParser::CompoundConditionContext* PMACParser::IfStatementContext::compoundCondition() {
  return getRuleContext<PMACParser::CompoundConditionContext>(0);
}

std::vector<PMACParser::ActionContext *> PMACParser::IfStatementContext::action() {
  return getRuleContexts<PMACParser::ActionContext>();
}

PMACParser::ActionContext* PMACParser::IfStatementContext::action(size_t i) {
  return getRuleContext<PMACParser::ActionContext>(i);
}

std::vector<tree::TerminalNode *> PMACParser::IfStatementContext::NL() {
  return getTokens(PMACParser::NL);
}

tree::TerminalNode* PMACParser::IfStatementContext::NL(size_t i) {
  return getToken(PMACParser::NL, i);
}

tree::TerminalNode* PMACParser::IfStatementContext::ELSE() {
  return getToken(PMACParser::ELSE, 0);
}

tree::TerminalNode* PMACParser::IfStatementContext::ENDIF() {
  return getToken(PMACParser::ENDIF, 0);
}

std::vector<PMACParser::LineContext *> PMACParser::IfStatementContext::line() {
  return getRuleContexts<PMACParser::LineContext>();
}

PMACParser::LineContext* PMACParser::IfStatementContext::line(size_t i) {
  return getRuleContext<PMACParser::LineContext>(i);
}


size_t PMACParser::IfStatementContext::getRuleIndex() const {
  return PMACParser::RuleIfStatement;
}

antlrcpp::Any PMACParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::IfStatementContext* PMACParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 8, PMACParser::RuleIfStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(112);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(81);
      match(PMACParser::IF);
      setState(82);
      compoundCondition(0);
      setState(83);
      dynamic_cast<IfStatementContext *>(_localctx)->ifAction = action(0);
      setState(87);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
      case 1: {
        setState(84);
        match(PMACParser::NL);
        setState(85);
        match(PMACParser::ELSE);
        setState(86);
        dynamic_cast<IfStatementContext *>(_localctx)->elseAction = action(0);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(89);
      match(PMACParser::IF);
      setState(90);
      compoundCondition(0);
      setState(91);
      match(PMACParser::NL);
      setState(93); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(92);
        dynamic_cast<IfStatementContext *>(_localctx)->lineContext = line();
        dynamic_cast<IfStatementContext *>(_localctx)->ifLines.push_back(dynamic_cast<IfStatementContext *>(_localctx)->lineContext);
        setState(95); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PMACParser::IF)
        | (1ULL << PMACParser::WHILE)
        | (1ULL << PMACParser::Q_VAR)
        | (1ULL << PMACParser::P_VAR)
        | (1ULL << PMACParser::I_VAR)
        | (1ULL << PMACParser::M_VAR)
        | (1ULL << PMACParser::ABS)
        | (1ULL << PMACParser::LINEAR)
        | (1ULL << PMACParser::RAPID)
        | (1ULL << PMACParser::CIRCLE1)
        | (1ULL << PMACParser::CIRCLE2)
        | (1ULL << PMACParser::PVT)
        | (1ULL << PMACParser::SPLINE1)
        | (1ULL << PMACParser::SPLINE2)
        | (1ULL << PMACParser::CC0)
        | (1ULL << PMACParser::CC1)
        | (1ULL << PMACParser::CC2)
        | (1ULL << PMACParser::CC3)
        | (1ULL << PMACParser::INC)
        | (1ULL << PMACParser::FRAX)
        | (1ULL << PMACParser::AX_X)
        | (1ULL << PMACParser::AX_Y)
        | (1ULL << PMACParser::AX_Z)
        | (1ULL << PMACParser::AX_A)
        | (1ULL << PMACParser::AX_B)
        | (1ULL << PMACParser::AX_C)
        | (1ULL << PMACParser::AX_U)
        | (1ULL << PMACParser::AX_V)
        | (1ULL << PMACParser::AX_W)
        | (1ULL << PMACParser::RADIUS))) != 0) || _la == PMACParser::NL);
      setState(108);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
      case 1: {
        setState(97);
        match(PMACParser::ELSE);
        setState(98);
        dynamic_cast<IfStatementContext *>(_localctx)->elseAction = action(0);
        setState(99);
        match(PMACParser::NL);
        break;
      }

      case 2: {
        setState(101);
        match(PMACParser::ELSE);
        setState(102);
        match(PMACParser::NL);
        setState(104); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(103);
          dynamic_cast<IfStatementContext *>(_localctx)->lineContext = line();
          dynamic_cast<IfStatementContext *>(_localctx)->elseLines.push_back(dynamic_cast<IfStatementContext *>(_localctx)->lineContext);
          setState(106); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PMACParser::IF)
          | (1ULL << PMACParser::WHILE)
          | (1ULL << PMACParser::Q_VAR)
          | (1ULL << PMACParser::P_VAR)
          | (1ULL << PMACParser::I_VAR)
          | (1ULL << PMACParser::M_VAR)
          | (1ULL << PMACParser::ABS)
          | (1ULL << PMACParser::LINEAR)
          | (1ULL << PMACParser::RAPID)
          | (1ULL << PMACParser::CIRCLE1)
          | (1ULL << PMACParser::CIRCLE2)
          | (1ULL << PMACParser::PVT)
          | (1ULL << PMACParser::SPLINE1)
          | (1ULL << PMACParser::SPLINE2)
          | (1ULL << PMACParser::CC0)
          | (1ULL << PMACParser::CC1)
          | (1ULL << PMACParser::CC2)
          | (1ULL << PMACParser::CC3)
          | (1ULL << PMACParser::INC)
          | (1ULL << PMACParser::FRAX)
          | (1ULL << PMACParser::AX_X)
          | (1ULL << PMACParser::AX_Y)
          | (1ULL << PMACParser::AX_Z)
          | (1ULL << PMACParser::AX_A)
          | (1ULL << PMACParser::AX_B)
          | (1ULL << PMACParser::AX_C)
          | (1ULL << PMACParser::AX_U)
          | (1ULL << PMACParser::AX_V)
          | (1ULL << PMACParser::AX_W)
          | (1ULL << PMACParser::RADIUS))) != 0) || _la == PMACParser::NL);
        break;
      }

      }
      setState(110);
      match(PMACParser::ENDIF);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStatementContext ------------------------------------------------------------------

PMACParser::WhileStatementContext::WhileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PMACParser::WhileStatementContext::WHILE() {
  return getToken(PMACParser::WHILE, 0);
}

PMACParser::CompoundConditionContext* PMACParser::WhileStatementContext::compoundCondition() {
  return getRuleContext<PMACParser::CompoundConditionContext>(0);
}

tree::TerminalNode* PMACParser::WhileStatementContext::NL() {
  return getToken(PMACParser::NL, 0);
}

tree::TerminalNode* PMACParser::WhileStatementContext::ENDWHILE() {
  return getToken(PMACParser::ENDWHILE, 0);
}

PMACParser::ActionContext* PMACParser::WhileStatementContext::action() {
  return getRuleContext<PMACParser::ActionContext>(0);
}

std::vector<PMACParser::LineContext *> PMACParser::WhileStatementContext::line() {
  return getRuleContexts<PMACParser::LineContext>();
}

PMACParser::LineContext* PMACParser::WhileStatementContext::line(size_t i) {
  return getRuleContext<PMACParser::LineContext>(i);
}


size_t PMACParser::WhileStatementContext::getRuleIndex() const {
  return PMACParser::RuleWhileStatement;
}

antlrcpp::Any PMACParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::WhileStatementContext* PMACParser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 10, PMACParser::RuleWhileStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(114);
    match(PMACParser::WHILE);
    setState(115);
    compoundCondition(0);
    setState(125);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PMACParser::Q_VAR:
      case PMACParser::P_VAR:
      case PMACParser::I_VAR:
      case PMACParser::M_VAR:
      case PMACParser::ABS:
      case PMACParser::LINEAR:
      case PMACParser::RAPID:
      case PMACParser::CIRCLE1:
      case PMACParser::CIRCLE2:
      case PMACParser::PVT:
      case PMACParser::SPLINE1:
      case PMACParser::SPLINE2:
      case PMACParser::CC0:
      case PMACParser::CC1:
      case PMACParser::CC2:
      case PMACParser::CC3:
      case PMACParser::INC:
      case PMACParser::FRAX:
      case PMACParser::AX_X:
      case PMACParser::AX_Y:
      case PMACParser::AX_Z:
      case PMACParser::AX_A:
      case PMACParser::AX_B:
      case PMACParser::AX_C:
      case PMACParser::AX_U:
      case PMACParser::AX_V:
      case PMACParser::AX_W:
      case PMACParser::RADIUS: {
        setState(116);
        dynamic_cast<WhileStatementContext *>(_localctx)->whileAction = action(0);
        break;
      }

      case PMACParser::NL: {
        setState(117);
        match(PMACParser::NL);
        setState(119); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(118);
          dynamic_cast<WhileStatementContext *>(_localctx)->lineContext = line();
          dynamic_cast<WhileStatementContext *>(_localctx)->whileLines.push_back(dynamic_cast<WhileStatementContext *>(_localctx)->lineContext);
          setState(121); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PMACParser::IF)
          | (1ULL << PMACParser::WHILE)
          | (1ULL << PMACParser::Q_VAR)
          | (1ULL << PMACParser::P_VAR)
          | (1ULL << PMACParser::I_VAR)
          | (1ULL << PMACParser::M_VAR)
          | (1ULL << PMACParser::ABS)
          | (1ULL << PMACParser::LINEAR)
          | (1ULL << PMACParser::RAPID)
          | (1ULL << PMACParser::CIRCLE1)
          | (1ULL << PMACParser::CIRCLE2)
          | (1ULL << PMACParser::PVT)
          | (1ULL << PMACParser::SPLINE1)
          | (1ULL << PMACParser::SPLINE2)
          | (1ULL << PMACParser::CC0)
          | (1ULL << PMACParser::CC1)
          | (1ULL << PMACParser::CC2)
          | (1ULL << PMACParser::CC3)
          | (1ULL << PMACParser::INC)
          | (1ULL << PMACParser::FRAX)
          | (1ULL << PMACParser::AX_X)
          | (1ULL << PMACParser::AX_Y)
          | (1ULL << PMACParser::AX_Z)
          | (1ULL << PMACParser::AX_A)
          | (1ULL << PMACParser::AX_B)
          | (1ULL << PMACParser::AX_C)
          | (1ULL << PMACParser::AX_U)
          | (1ULL << PMACParser::AX_V)
          | (1ULL << PMACParser::AX_W)
          | (1ULL << PMACParser::RADIUS))) != 0) || _la == PMACParser::NL);
        setState(123);
        match(PMACParser::ENDWHILE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompoundConditionContext ------------------------------------------------------------------

PMACParser::CompoundConditionContext::CompoundConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PMACParser::CompoundConditionContext::LPAR() {
  return getToken(PMACParser::LPAR, 0);
}

tree::TerminalNode* PMACParser::CompoundConditionContext::RPAR() {
  return getToken(PMACParser::RPAR, 0);
}

std::vector<PMACParser::CompoundConditionContext *> PMACParser::CompoundConditionContext::compoundCondition() {
  return getRuleContexts<PMACParser::CompoundConditionContext>();
}

PMACParser::CompoundConditionContext* PMACParser::CompoundConditionContext::compoundCondition(size_t i) {
  return getRuleContext<PMACParser::CompoundConditionContext>(i);
}

PMACParser::ConditionContext* PMACParser::CompoundConditionContext::condition() {
  return getRuleContext<PMACParser::ConditionContext>(0);
}

tree::TerminalNode* PMACParser::CompoundConditionContext::AND() {
  return getToken(PMACParser::AND, 0);
}

tree::TerminalNode* PMACParser::CompoundConditionContext::NL() {
  return getToken(PMACParser::NL, 0);
}

tree::TerminalNode* PMACParser::CompoundConditionContext::OR() {
  return getToken(PMACParser::OR, 0);
}


size_t PMACParser::CompoundConditionContext::getRuleIndex() const {
  return PMACParser::RuleCompoundCondition;
}

antlrcpp::Any PMACParser::CompoundConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitCompoundCondition(this);
  else
    return visitor->visitChildren(this);
}


PMACParser::CompoundConditionContext* PMACParser::compoundCondition() {
   return compoundCondition(0);
}

PMACParser::CompoundConditionContext* PMACParser::compoundCondition(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PMACParser::CompoundConditionContext *_localctx = _tracker.createInstance<CompoundConditionContext>(_ctx, parentState);
  PMACParser::CompoundConditionContext *previousContext = _localctx;
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, PMACParser::RuleCompoundCondition, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(133);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(128);
      match(PMACParser::LPAR);
      setState(129);
      dynamic_cast<CompoundConditionContext *>(_localctx)->center = compoundCondition(0);
      setState(130);
      match(PMACParser::RPAR);
      break;
    }

    case 2: {
      setState(132);
      condition();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(149);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(147);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<CompoundConditionContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleCompoundCondition);
          setState(135);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(137);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PMACParser::NL) {
            setState(136);
            match(PMACParser::NL);
          }
          setState(139);
          dynamic_cast<CompoundConditionContext *>(_localctx)->logicalOp = match(PMACParser::AND);
          setState(140);
          dynamic_cast<CompoundConditionContext *>(_localctx)->right = compoundCondition(4);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<CompoundConditionContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleCompoundCondition);
          setState(141);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(143);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PMACParser::NL) {
            setState(142);
            match(PMACParser::NL);
          }
          setState(145);
          dynamic_cast<CompoundConditionContext *>(_localctx)->logicalOp = match(PMACParser::OR);
          setState(146);
          dynamic_cast<CompoundConditionContext *>(_localctx)->right = compoundCondition(3);
          break;
        }

        } 
      }
      setState(151);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConditionContext ------------------------------------------------------------------

PMACParser::ConditionContext::ConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PMACParser::ComparatorContext* PMACParser::ConditionContext::comparator() {
  return getRuleContext<PMACParser::ComparatorContext>(0);
}

std::vector<PMACParser::ExprContext *> PMACParser::ConditionContext::expr() {
  return getRuleContexts<PMACParser::ExprContext>();
}

PMACParser::ExprContext* PMACParser::ConditionContext::expr(size_t i) {
  return getRuleContext<PMACParser::ExprContext>(i);
}


size_t PMACParser::ConditionContext::getRuleIndex() const {
  return PMACParser::RuleCondition;
}

antlrcpp::Any PMACParser::ConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitCondition(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::ConditionContext* PMACParser::condition() {
  ConditionContext *_localctx = _tracker.createInstance<ConditionContext>(_ctx, getState());
  enterRule(_localctx, 14, PMACParser::RuleCondition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(152);
    dynamic_cast<ConditionContext *>(_localctx)->left = expr(0);
    setState(153);
    comparator();
    setState(154);
    dynamic_cast<ConditionContext *>(_localctx)->right = expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DataContext ------------------------------------------------------------------

PMACParser::DataContext::DataContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PMACParser::ConstantContext* PMACParser::DataContext::constant() {
  return getRuleContext<PMACParser::ConstantContext>(0);
}

tree::TerminalNode* PMACParser::DataContext::LPAR() {
  return getToken(PMACParser::LPAR, 0);
}

PMACParser::ExprContext* PMACParser::DataContext::expr() {
  return getRuleContext<PMACParser::ExprContext>(0);
}

tree::TerminalNode* PMACParser::DataContext::RPAR() {
  return getToken(PMACParser::RPAR, 0);
}


size_t PMACParser::DataContext::getRuleIndex() const {
  return PMACParser::RuleData;
}

antlrcpp::Any PMACParser::DataContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitData(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::DataContext* PMACParser::data() {
  DataContext *_localctx = _tracker.createInstance<DataContext>(_ctx, getState());
  enterRule(_localctx, 16, PMACParser::RuleData);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(161);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PMACParser::EOF: {
        enterOuterAlt(_localctx, 1);
        setState(156);
        constant();
        break;
      }

      case PMACParser::LPAR: {
        enterOuterAlt(_localctx, 2);
        setState(157);
        match(PMACParser::LPAR);
        setState(158);
        expr(0);
        setState(159);
        match(PMACParser::RPAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

PMACParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PMACParser::ConstantContext::getRuleIndex() const {
  return PMACParser::RuleConstant;
}

antlrcpp::Any PMACParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::ConstantContext* PMACParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 18, PMACParser::RuleConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignContext ------------------------------------------------------------------

PMACParser::AssignContext::AssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PMACParser::VarContext* PMACParser::AssignContext::var() {
  return getRuleContext<PMACParser::VarContext>(0);
}

std::vector<tree::TerminalNode *> PMACParser::AssignContext::EQ() {
  return getTokens(PMACParser::EQ);
}

tree::TerminalNode* PMACParser::AssignContext::EQ(size_t i) {
  return getToken(PMACParser::EQ, i);
}

PMACParser::ExprContext* PMACParser::AssignContext::expr() {
  return getRuleContext<PMACParser::ExprContext>(0);
}


size_t PMACParser::AssignContext::getRuleIndex() const {
  return PMACParser::RuleAssign;
}

antlrcpp::Any PMACParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::AssignContext* PMACParser::assign() {
  AssignContext *_localctx = _tracker.createInstance<AssignContext>(_ctx, getState());
  enterRule(_localctx, 20, PMACParser::RuleAssign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(174);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(165);
      var();
      setState(166);
      match(PMACParser::EQ);
      setState(167);
      match(PMACParser::EQ);
      setState(168);
      expr(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(170);
      var();
      setState(171);
      match(PMACParser::EQ);
      setState(172);
      expr(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MoveCmdsContext ------------------------------------------------------------------

PMACParser::MoveCmdsContext::MoveCmdsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PMACParser::MoveCmdSimpleContext *> PMACParser::MoveCmdsContext::moveCmdSimple() {
  return getRuleContexts<PMACParser::MoveCmdSimpleContext>();
}

PMACParser::MoveCmdSimpleContext* PMACParser::MoveCmdsContext::moveCmdSimple(size_t i) {
  return getRuleContext<PMACParser::MoveCmdSimpleContext>(i);
}

std::vector<PMACParser::MoveCmdVelocityContext *> PMACParser::MoveCmdsContext::moveCmdVelocity() {
  return getRuleContexts<PMACParser::MoveCmdVelocityContext>();
}

PMACParser::MoveCmdVelocityContext* PMACParser::MoveCmdsContext::moveCmdVelocity(size_t i) {
  return getRuleContext<PMACParser::MoveCmdVelocityContext>(i);
}

PMACParser::ModeMoveCmdsContext* PMACParser::MoveCmdsContext::modeMoveCmds() {
  return getRuleContext<PMACParser::ModeMoveCmdsContext>(0);
}


size_t PMACParser::MoveCmdsContext::getRuleIndex() const {
  return PMACParser::RuleMoveCmds;
}

antlrcpp::Any PMACParser::MoveCmdsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitMoveCmds(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::MoveCmdsContext* PMACParser::moveCmds() {
  MoveCmdsContext *_localctx = _tracker.createInstance<MoveCmdsContext>(_ctx, getState());
  enterRule(_localctx, 22, PMACParser::RuleMoveCmds);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(187);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(177); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(176);
                dynamic_cast<MoveCmdsContext *>(_localctx)->moveCmdSimpleContext = moveCmdSimple();
                dynamic_cast<MoveCmdsContext *>(_localctx)->listSimple.push_back(dynamic_cast<MoveCmdsContext *>(_localctx)->moveCmdSimpleContext);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(179); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(182); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(181);
                dynamic_cast<MoveCmdsContext *>(_localctx)->moveCmdVelocityContext = moveCmdVelocity();
                dynamic_cast<MoveCmdsContext *>(_localctx)->listVelocity.push_back(dynamic_cast<MoveCmdsContext *>(_localctx)->moveCmdVelocityContext);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(184); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(186);
      modeMoveCmds();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MoveCmdSimpleContext ------------------------------------------------------------------

PMACParser::MoveCmdSimpleContext::MoveCmdSimpleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PMACParser::AxisContext* PMACParser::MoveCmdSimpleContext::axis() {
  return getRuleContext<PMACParser::AxisContext>(0);
}

PMACParser::ExprContext* PMACParser::MoveCmdSimpleContext::expr() {
  return getRuleContext<PMACParser::ExprContext>(0);
}


size_t PMACParser::MoveCmdSimpleContext::getRuleIndex() const {
  return PMACParser::RuleMoveCmdSimple;
}

antlrcpp::Any PMACParser::MoveCmdSimpleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitMoveCmdSimple(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::MoveCmdSimpleContext* PMACParser::moveCmdSimple() {
  MoveCmdSimpleContext *_localctx = _tracker.createInstance<MoveCmdSimpleContext>(_ctx, getState());
  enterRule(_localctx, 24, PMACParser::RuleMoveCmdSimple);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    axis();
    setState(190);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MoveCmdVelocityContext ------------------------------------------------------------------

PMACParser::MoveCmdVelocityContext::MoveCmdVelocityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PMACParser::AxisContext* PMACParser::MoveCmdVelocityContext::axis() {
  return getRuleContext<PMACParser::AxisContext>(0);
}

tree::TerminalNode* PMACParser::MoveCmdVelocityContext::COLON() {
  return getToken(PMACParser::COLON, 0);
}

std::vector<PMACParser::ExprContext *> PMACParser::MoveCmdVelocityContext::expr() {
  return getRuleContexts<PMACParser::ExprContext>();
}

PMACParser::ExprContext* PMACParser::MoveCmdVelocityContext::expr(size_t i) {
  return getRuleContext<PMACParser::ExprContext>(i);
}


size_t PMACParser::MoveCmdVelocityContext::getRuleIndex() const {
  return PMACParser::RuleMoveCmdVelocity;
}

antlrcpp::Any PMACParser::MoveCmdVelocityContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitMoveCmdVelocity(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::MoveCmdVelocityContext* PMACParser::moveCmdVelocity() {
  MoveCmdVelocityContext *_localctx = _tracker.createInstance<MoveCmdVelocityContext>(_ctx, getState());
  enterRule(_localctx, 26, PMACParser::RuleMoveCmdVelocity);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
    axis();
    setState(193);
    dynamic_cast<MoveCmdVelocityContext *>(_localctx)->position = expr(0);
    setState(194);
    match(PMACParser::COLON);
    setState(195);
    dynamic_cast<MoveCmdVelocityContext *>(_localctx)->velocity = expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AxisAttrCmdsContext ------------------------------------------------------------------

PMACParser::AxisAttrCmdsContext::AxisAttrCmdsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PMACParser::AxisAttrCmdsContext::ABS() {
  return getToken(PMACParser::ABS, 0);
}

tree::TerminalNode* PMACParser::AxisAttrCmdsContext::LPAR() {
  return getToken(PMACParser::LPAR, 0);
}

tree::TerminalNode* PMACParser::AxisAttrCmdsContext::RPAR() {
  return getToken(PMACParser::RPAR, 0);
}

std::vector<PMACParser::AxisContext *> PMACParser::AxisAttrCmdsContext::axis() {
  return getRuleContexts<PMACParser::AxisContext>();
}

PMACParser::AxisContext* PMACParser::AxisAttrCmdsContext::axis(size_t i) {
  return getRuleContext<PMACParser::AxisContext>(i);
}

std::vector<tree::TerminalNode *> PMACParser::AxisAttrCmdsContext::COMMA() {
  return getTokens(PMACParser::COMMA);
}

tree::TerminalNode* PMACParser::AxisAttrCmdsContext::COMMA(size_t i) {
  return getToken(PMACParser::COMMA, i);
}

tree::TerminalNode* PMACParser::AxisAttrCmdsContext::INC() {
  return getToken(PMACParser::INC, 0);
}

tree::TerminalNode* PMACParser::AxisAttrCmdsContext::FRAX() {
  return getToken(PMACParser::FRAX, 0);
}


size_t PMACParser::AxisAttrCmdsContext::getRuleIndex() const {
  return PMACParser::RuleAxisAttrCmds;
}

antlrcpp::Any PMACParser::AxisAttrCmdsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitAxisAttrCmds(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::AxisAttrCmdsContext* PMACParser::axisAttrCmds() {
  AxisAttrCmdsContext *_localctx = _tracker.createInstance<AxisAttrCmdsContext>(_ctx, getState());
  enterRule(_localctx, 28, PMACParser::RuleAxisAttrCmds);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(239);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PMACParser::ABS: {
        enterOuterAlt(_localctx, 1);
        setState(197);
        match(PMACParser::ABS);
        setState(209);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
        case 1: {
          setState(198);
          match(PMACParser::LPAR);
          setState(199);
          dynamic_cast<AxisAttrCmdsContext *>(_localctx)->axisContext = axis();
          dynamic_cast<AxisAttrCmdsContext *>(_localctx)->axisList.push_back(dynamic_cast<AxisAttrCmdsContext *>(_localctx)->axisContext);
          setState(204);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PMACParser::COMMA) {
            setState(200);
            match(PMACParser::COMMA);
            setState(201);
            dynamic_cast<AxisAttrCmdsContext *>(_localctx)->axisContext = axis();
            dynamic_cast<AxisAttrCmdsContext *>(_localctx)->axisList.push_back(dynamic_cast<AxisAttrCmdsContext *>(_localctx)->axisContext);
            setState(206);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(207);
          match(PMACParser::RPAR);
          break;
        }

        }
        break;
      }

      case PMACParser::INC: {
        enterOuterAlt(_localctx, 2);
        setState(211);
        match(PMACParser::INC);
        setState(223);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
        case 1: {
          setState(212);
          match(PMACParser::LPAR);
          setState(213);
          dynamic_cast<AxisAttrCmdsContext *>(_localctx)->axisContext = axis();
          dynamic_cast<AxisAttrCmdsContext *>(_localctx)->axisList.push_back(dynamic_cast<AxisAttrCmdsContext *>(_localctx)->axisContext);
          setState(218);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PMACParser::COMMA) {
            setState(214);
            match(PMACParser::COMMA);
            setState(215);
            dynamic_cast<AxisAttrCmdsContext *>(_localctx)->axisContext = axis();
            dynamic_cast<AxisAttrCmdsContext *>(_localctx)->axisList.push_back(dynamic_cast<AxisAttrCmdsContext *>(_localctx)->axisContext);
            setState(220);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(221);
          match(PMACParser::RPAR);
          break;
        }

        }
        break;
      }

      case PMACParser::FRAX: {
        enterOuterAlt(_localctx, 3);
        setState(225);
        match(PMACParser::FRAX);
        setState(237);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
        case 1: {
          setState(226);
          match(PMACParser::LPAR);
          setState(227);
          dynamic_cast<AxisAttrCmdsContext *>(_localctx)->axisContext = axis();
          dynamic_cast<AxisAttrCmdsContext *>(_localctx)->axisList.push_back(dynamic_cast<AxisAttrCmdsContext *>(_localctx)->axisContext);
          setState(232);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PMACParser::COMMA) {
            setState(228);
            match(PMACParser::COMMA);
            setState(229);
            dynamic_cast<AxisAttrCmdsContext *>(_localctx)->axisContext = axis();
            dynamic_cast<AxisAttrCmdsContext *>(_localctx)->axisList.push_back(dynamic_cast<AxisAttrCmdsContext *>(_localctx)->axisContext);
            setState(234);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(235);
          match(PMACParser::RPAR);
          break;
        }

        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

PMACParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PMACParser::ExprContext::LPAR() {
  return getToken(PMACParser::LPAR, 0);
}

tree::TerminalNode* PMACParser::ExprContext::RPAR() {
  return getToken(PMACParser::RPAR, 0);
}

std::vector<PMACParser::ExprContext *> PMACParser::ExprContext::expr() {
  return getRuleContexts<PMACParser::ExprContext>();
}

PMACParser::ExprContext* PMACParser::ExprContext::expr(size_t i) {
  return getRuleContext<PMACParser::ExprContext>(i);
}

PMACParser::FunctionContext* PMACParser::ExprContext::function() {
  return getRuleContext<PMACParser::FunctionContext>(0);
}

tree::TerminalNode* PMACParser::ExprContext::MIN() {
  return getToken(PMACParser::MIN, 0);
}

PMACParser::AtomContext* PMACParser::ExprContext::atom() {
  return getRuleContext<PMACParser::AtomContext>(0);
}

tree::TerminalNode* PMACParser::ExprContext::MULT() {
  return getToken(PMACParser::MULT, 0);
}

tree::TerminalNode* PMACParser::ExprContext::DIV() {
  return getToken(PMACParser::DIV, 0);
}

tree::TerminalNode* PMACParser::ExprContext::MOD() {
  return getToken(PMACParser::MOD, 0);
}

tree::TerminalNode* PMACParser::ExprContext::PLUS() {
  return getToken(PMACParser::PLUS, 0);
}

tree::TerminalNode* PMACParser::ExprContext::AND_OP() {
  return getToken(PMACParser::AND_OP, 0);
}

tree::TerminalNode* PMACParser::ExprContext::XOR() {
  return getToken(PMACParser::XOR, 0);
}

tree::TerminalNode* PMACParser::ExprContext::OR_OP() {
  return getToken(PMACParser::OR_OP, 0);
}


size_t PMACParser::ExprContext::getRuleIndex() const {
  return PMACParser::RuleExpr;
}

antlrcpp::Any PMACParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


PMACParser::ExprContext* PMACParser::expr() {
   return expr(0);
}

PMACParser::ExprContext* PMACParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PMACParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  PMACParser::ExprContext *previousContext = _localctx;
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, PMACParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(254);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PMACParser::LPAR: {
        setState(242);
        match(PMACParser::LPAR);
        setState(243);
        dynamic_cast<ExprContext *>(_localctx)->center = expr(0);
        setState(244);
        match(PMACParser::RPAR);
        break;
      }

      case PMACParser::SIN:
      case PMACParser::COS:
      case PMACParser::TAN:
      case PMACParser::ASIN:
      case PMACParser::ACOS:
      case PMACParser::ATAN:
      case PMACParser::ATAN2:
      case PMACParser::LN:
      case PMACParser::EXP:
      case PMACParser::SQRT:
      case PMACParser::ABS:
      case PMACParser::INT: {
        setState(246);
        function();
        setState(247);
        match(PMACParser::LPAR);
        setState(248);
        dynamic_cast<ExprContext *>(_localctx)->argument = expr(0);
        setState(249);
        match(PMACParser::RPAR);
        break;
      }

      case PMACParser::MIN: {
        setState(251);
        match(PMACParser::MIN);
        setState(252);
        dynamic_cast<ExprContext *>(_localctx)->minExpr = expr(7);
        break;
      }

      case PMACParser::Q_VAR:
      case PMACParser::P_VAR:
      case PMACParser::I_VAR:
      case PMACParser::M_VAR:
      case PMACParser::INTEGER:
      case PMACParser::DECIMAL:
      case PMACParser::HEX: {
        setState(253);
        atom();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(273);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(271);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(256);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(257);
          dynamic_cast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(((((_la - 62) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 62)) & ((1ULL << (PMACParser::MULT - 62))
            | (1ULL << (PMACParser::DIV - 62))
            | (1ULL << (PMACParser::MOD - 62)))) != 0))) {
            dynamic_cast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(258);
          dynamic_cast<ExprContext *>(_localctx)->right = expr(7);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(259);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(260);
          dynamic_cast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == PMACParser::PLUS

          || _la == PMACParser::MIN)) {
            dynamic_cast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(261);
          dynamic_cast<ExprContext *>(_localctx)->right = expr(6);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(262);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(263);
          dynamic_cast<ExprContext *>(_localctx)->op = match(PMACParser::AND_OP);
          setState(264);
          dynamic_cast<ExprContext *>(_localctx)->right = expr(5);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(265);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(266);
          dynamic_cast<ExprContext *>(_localctx)->op = match(PMACParser::XOR);
          setState(267);
          dynamic_cast<ExprContext *>(_localctx)->right = expr(4);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(268);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(269);
          dynamic_cast<ExprContext *>(_localctx)->op = match(PMACParser::OR_OP);
          setState(270);
          dynamic_cast<ExprContext *>(_localctx)->right = expr(3);
          break;
        }

        } 
      }
      setState(275);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ModeMoveCmdsContext ------------------------------------------------------------------

PMACParser::ModeMoveCmdsContext::ModeMoveCmdsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PMACParser::ModeMoveCmdsContext::LINEAR() {
  return getToken(PMACParser::LINEAR, 0);
}

tree::TerminalNode* PMACParser::ModeMoveCmdsContext::RAPID() {
  return getToken(PMACParser::RAPID, 0);
}

tree::TerminalNode* PMACParser::ModeMoveCmdsContext::CIRCLE1() {
  return getToken(PMACParser::CIRCLE1, 0);
}

tree::TerminalNode* PMACParser::ModeMoveCmdsContext::CIRCLE2() {
  return getToken(PMACParser::CIRCLE2, 0);
}

tree::TerminalNode* PMACParser::ModeMoveCmdsContext::PVT() {
  return getToken(PMACParser::PVT, 0);
}

tree::TerminalNode* PMACParser::ModeMoveCmdsContext::SPLINE1() {
  return getToken(PMACParser::SPLINE1, 0);
}

tree::TerminalNode* PMACParser::ModeMoveCmdsContext::SPLINE2() {
  return getToken(PMACParser::SPLINE2, 0);
}

tree::TerminalNode* PMACParser::ModeMoveCmdsContext::CC0() {
  return getToken(PMACParser::CC0, 0);
}

tree::TerminalNode* PMACParser::ModeMoveCmdsContext::CC1() {
  return getToken(PMACParser::CC1, 0);
}

tree::TerminalNode* PMACParser::ModeMoveCmdsContext::CC2() {
  return getToken(PMACParser::CC2, 0);
}

tree::TerminalNode* PMACParser::ModeMoveCmdsContext::CC3() {
  return getToken(PMACParser::CC3, 0);
}


size_t PMACParser::ModeMoveCmdsContext::getRuleIndex() const {
  return PMACParser::RuleModeMoveCmds;
}

antlrcpp::Any PMACParser::ModeMoveCmdsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitModeMoveCmds(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::ModeMoveCmdsContext* PMACParser::modeMoveCmds() {
  ModeMoveCmdsContext *_localctx = _tracker.createInstance<ModeMoveCmdsContext>(_ctx, getState());
  enterRule(_localctx, 32, PMACParser::RuleModeMoveCmds);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(276);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PMACParser::LINEAR)
      | (1ULL << PMACParser::RAPID)
      | (1ULL << PMACParser::CIRCLE1)
      | (1ULL << PMACParser::CIRCLE2)
      | (1ULL << PMACParser::PVT)
      | (1ULL << PMACParser::SPLINE1)
      | (1ULL << PMACParser::SPLINE2)
      | (1ULL << PMACParser::CC0)
      | (1ULL << PMACParser::CC1)
      | (1ULL << PMACParser::CC2)
      | (1ULL << PMACParser::CC3))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AxisContext ------------------------------------------------------------------

PMACParser::AxisContext::AxisContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PMACParser::AxisContext::AX_X() {
  return getToken(PMACParser::AX_X, 0);
}

tree::TerminalNode* PMACParser::AxisContext::AX_Y() {
  return getToken(PMACParser::AX_Y, 0);
}

tree::TerminalNode* PMACParser::AxisContext::AX_Z() {
  return getToken(PMACParser::AX_Z, 0);
}

tree::TerminalNode* PMACParser::AxisContext::AX_A() {
  return getToken(PMACParser::AX_A, 0);
}

tree::TerminalNode* PMACParser::AxisContext::AX_B() {
  return getToken(PMACParser::AX_B, 0);
}

tree::TerminalNode* PMACParser::AxisContext::AX_C() {
  return getToken(PMACParser::AX_C, 0);
}

tree::TerminalNode* PMACParser::AxisContext::AX_U() {
  return getToken(PMACParser::AX_U, 0);
}

tree::TerminalNode* PMACParser::AxisContext::AX_V() {
  return getToken(PMACParser::AX_V, 0);
}

tree::TerminalNode* PMACParser::AxisContext::AX_W() {
  return getToken(PMACParser::AX_W, 0);
}

tree::TerminalNode* PMACParser::AxisContext::RADIUS() {
  return getToken(PMACParser::RADIUS, 0);
}


size_t PMACParser::AxisContext::getRuleIndex() const {
  return PMACParser::RuleAxis;
}

antlrcpp::Any PMACParser::AxisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitAxis(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::AxisContext* PMACParser::axis() {
  AxisContext *_localctx = _tracker.createInstance<AxisContext>(_ctx, getState());
  enterRule(_localctx, 34, PMACParser::RuleAxis);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(278);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PMACParser::AX_X)
      | (1ULL << PMACParser::AX_Y)
      | (1ULL << PMACParser::AX_Z)
      | (1ULL << PMACParser::AX_A)
      | (1ULL << PMACParser::AX_B)
      | (1ULL << PMACParser::AX_C)
      | (1ULL << PMACParser::AX_U)
      | (1ULL << PMACParser::AX_V)
      | (1ULL << PMACParser::AX_W)
      | (1ULL << PMACParser::RADIUS))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VectorCoordinateContext ------------------------------------------------------------------

PMACParser::VectorCoordinateContext::VectorCoordinateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PMACParser::VectorCoordinateContext::V_I() {
  return getToken(PMACParser::V_I, 0);
}

tree::TerminalNode* PMACParser::VectorCoordinateContext::V_J() {
  return getToken(PMACParser::V_J, 0);
}

tree::TerminalNode* PMACParser::VectorCoordinateContext::V_K() {
  return getToken(PMACParser::V_K, 0);
}


size_t PMACParser::VectorCoordinateContext::getRuleIndex() const {
  return PMACParser::RuleVectorCoordinate;
}

antlrcpp::Any PMACParser::VectorCoordinateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitVectorCoordinate(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::VectorCoordinateContext* PMACParser::vectorCoordinate() {
  VectorCoordinateContext *_localctx = _tracker.createInstance<VectorCoordinateContext>(_ctx, getState());
  enterRule(_localctx, 36, PMACParser::RuleVectorCoordinate);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(280);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PMACParser::V_I)
      | (1ULL << PMACParser::V_J)
      | (1ULL << PMACParser::V_K))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComparatorContext ------------------------------------------------------------------

PMACParser::ComparatorContext::ComparatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PMACParser::ComparatorContext::EQ() {
  return getToken(PMACParser::EQ, 0);
}

tree::TerminalNode* PMACParser::ComparatorContext::NEQ() {
  return getToken(PMACParser::NEQ, 0);
}

tree::TerminalNode* PMACParser::ComparatorContext::LT() {
  return getToken(PMACParser::LT, 0);
}

tree::TerminalNode* PMACParser::ComparatorContext::GT() {
  return getToken(PMACParser::GT, 0);
}

tree::TerminalNode* PMACParser::ComparatorContext::NLT() {
  return getToken(PMACParser::NLT, 0);
}

tree::TerminalNode* PMACParser::ComparatorContext::NGT() {
  return getToken(PMACParser::NGT, 0);
}


size_t PMACParser::ComparatorContext::getRuleIndex() const {
  return PMACParser::RuleComparator;
}

antlrcpp::Any PMACParser::ComparatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitComparator(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::ComparatorContext* PMACParser::comparator() {
  ComparatorContext *_localctx = _tracker.createInstance<ComparatorContext>(_ctx, getState());
  enterRule(_localctx, 38, PMACParser::RuleComparator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(282);
    _la = _input->LA(1);
    if (!(((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & ((1ULL << (PMACParser::EQ - 68))
      | (1ULL << (PMACParser::NEQ - 68))
      | (1ULL << (PMACParser::LT - 68))
      | (1ULL << (PMACParser::GT - 68))
      | (1ULL << (PMACParser::NLT - 68))
      | (1ULL << (PMACParser::NGT - 68)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

PMACParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PMACParser::NumberContext* PMACParser::AtomContext::number() {
  return getRuleContext<PMACParser::NumberContext>(0);
}

PMACParser::VarContext* PMACParser::AtomContext::var() {
  return getRuleContext<PMACParser::VarContext>(0);
}


size_t PMACParser::AtomContext::getRuleIndex() const {
  return PMACParser::RuleAtom;
}

antlrcpp::Any PMACParser::AtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitAtom(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::AtomContext* PMACParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 40, PMACParser::RuleAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(286);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PMACParser::INTEGER:
      case PMACParser::DECIMAL:
      case PMACParser::HEX: {
        enterOuterAlt(_localctx, 1);
        setState(284);
        number();
        break;
      }

      case PMACParser::Q_VAR:
      case PMACParser::P_VAR:
      case PMACParser::I_VAR:
      case PMACParser::M_VAR: {
        enterOuterAlt(_localctx, 2);
        setState(285);
        var();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

PMACParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PMACParser::NumberContext::INTEGER() {
  return getToken(PMACParser::INTEGER, 0);
}

tree::TerminalNode* PMACParser::NumberContext::DECIMAL() {
  return getToken(PMACParser::DECIMAL, 0);
}

tree::TerminalNode* PMACParser::NumberContext::HEX() {
  return getToken(PMACParser::HEX, 0);
}


size_t PMACParser::NumberContext::getRuleIndex() const {
  return PMACParser::RuleNumber;
}

antlrcpp::Any PMACParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::NumberContext* PMACParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 42, PMACParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(288);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PMACParser::INTEGER)
      | (1ULL << PMACParser::DECIMAL)
      | (1ULL << PMACParser::HEX))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarContext ------------------------------------------------------------------

PMACParser::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PMACParser::VarContext::Q_VAR() {
  return getToken(PMACParser::Q_VAR, 0);
}

tree::TerminalNode* PMACParser::VarContext::P_VAR() {
  return getToken(PMACParser::P_VAR, 0);
}

tree::TerminalNode* PMACParser::VarContext::I_VAR() {
  return getToken(PMACParser::I_VAR, 0);
}

tree::TerminalNode* PMACParser::VarContext::M_VAR() {
  return getToken(PMACParser::M_VAR, 0);
}


size_t PMACParser::VarContext::getRuleIndex() const {
  return PMACParser::RuleVar;
}

antlrcpp::Any PMACParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::VarContext* PMACParser::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 44, PMACParser::RuleVar);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(290);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PMACParser::Q_VAR)
      | (1ULL << PMACParser::P_VAR)
      | (1ULL << PMACParser::I_VAR)
      | (1ULL << PMACParser::M_VAR))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

PMACParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PMACParser::FunctionContext::SIN() {
  return getToken(PMACParser::SIN, 0);
}

tree::TerminalNode* PMACParser::FunctionContext::COS() {
  return getToken(PMACParser::COS, 0);
}

tree::TerminalNode* PMACParser::FunctionContext::TAN() {
  return getToken(PMACParser::TAN, 0);
}

tree::TerminalNode* PMACParser::FunctionContext::ASIN() {
  return getToken(PMACParser::ASIN, 0);
}

tree::TerminalNode* PMACParser::FunctionContext::ACOS() {
  return getToken(PMACParser::ACOS, 0);
}

tree::TerminalNode* PMACParser::FunctionContext::ATAN() {
  return getToken(PMACParser::ATAN, 0);
}

tree::TerminalNode* PMACParser::FunctionContext::ATAN2() {
  return getToken(PMACParser::ATAN2, 0);
}

tree::TerminalNode* PMACParser::FunctionContext::LN() {
  return getToken(PMACParser::LN, 0);
}

tree::TerminalNode* PMACParser::FunctionContext::EXP() {
  return getToken(PMACParser::EXP, 0);
}

tree::TerminalNode* PMACParser::FunctionContext::SQRT() {
  return getToken(PMACParser::SQRT, 0);
}

tree::TerminalNode* PMACParser::FunctionContext::ABS() {
  return getToken(PMACParser::ABS, 0);
}

tree::TerminalNode* PMACParser::FunctionContext::INT() {
  return getToken(PMACParser::INT, 0);
}


size_t PMACParser::FunctionContext::getRuleIndex() const {
  return PMACParser::RuleFunction;
}

antlrcpp::Any PMACParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::FunctionContext* PMACParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 46, PMACParser::RuleFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(292);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PMACParser::SIN)
      | (1ULL << PMACParser::COS)
      | (1ULL << PMACParser::TAN)
      | (1ULL << PMACParser::ASIN)
      | (1ULL << PMACParser::ACOS)
      | (1ULL << PMACParser::ATAN)
      | (1ULL << PMACParser::ATAN2)
      | (1ULL << PMACParser::LN)
      | (1ULL << PMACParser::EXP)
      | (1ULL << PMACParser::SQRT)
      | (1ULL << PMACParser::ABS)
      | (1ULL << PMACParser::INT))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool PMACParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 3: return actionSempred(dynamic_cast<ActionContext *>(context), predicateIndex);
    case 6: return compoundConditionSempred(dynamic_cast<CompoundConditionContext *>(context), predicateIndex);
    case 15: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool PMACParser::actionSempred(ActionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool PMACParser::compoundConditionSempred(CompoundConditionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 3);
    case 2: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool PMACParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 6);
    case 4: return precpred(_ctx, 5);
    case 5: return precpred(_ctx, 4);
    case 6: return precpred(_ctx, 3);
    case 7: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> PMACParser::_decisionToDFA;
atn::PredictionContextCache PMACParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN PMACParser::_atn;
std::vector<uint16_t> PMACParser::_serializedATN;

std::vector<std::string> PMACParser::_ruleNames = {
  "program", "line", "statement", "action", "ifStatement", "whileStatement", 
  "compoundCondition", "condition", "data", "constant", "assign", "moveCmds", 
  "moveCmdSimple", "moveCmdVelocity", "axisAttrCmds", "expr", "modeMoveCmds", 
  "axis", "vectorCoordinate", "comparator", "atom", "number", "var", "function"
};

std::vector<std::string> PMACParser::_literalNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "'+'", "'-'", "'*'", "'/'", "'%'", "'&'", "'|'", 
  "'^'", "'='", "'!='", "'<'", "'>'", "'!<'", "'!>'", "'('", "')'", "':'", 
  "';'", "','", "'\n'"
};

std::vector<std::string> PMACParser::_symbolicNames = {
  "", "IF", "ELSE", "ENDIF", "WHILE", "ENDWHILE", "AND", "OR", "Q_VAR", 
  "P_VAR", "I_VAR", "M_VAR", "SIN", "COS", "TAN", "ASIN", "ACOS", "ATAN", 
  "ATAN2", "LN", "EXP", "SQRT", "ABS", "INT", "LINEAR", "RAPID", "CIRCLE1", 
  "CIRCLE2", "PVT", "SPLINE1", "SPLINE2", "CC0", "CC1", "CC2", "CC3", "DWELL", 
  "DELAY", "HOME", "HOMEZ", "INC", "FRAX", "NOFRAX", "NORMAL", "PSET", "AX_X", 
  "AX_Y", "AX_Z", "AX_A", "AX_B", "AX_C", "AX_U", "AX_V", "AX_W", "V_I", 
  "V_J", "V_K", "RADIUS", "INTEGER", "DECIMAL", "HEX", "PLUS", "MIN", "MULT", 
  "DIV", "MOD", "AND_OP", "OR_OP", "XOR", "EQ", "NEQ", "LT", "GT", "NLT", 
  "NGT", "LPAR", "RPAR", "COLON", "SEMIOLON", "COMMA", "NL", "COMMENT", 
  "WS"
};

dfa::Vocabulary PMACParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> PMACParser::_tokenNames;

PMACParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x53, 0x129, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x3, 0x2, 0x7, 0x2, 0x34, 0xa, 0x2, 0xc, 
    0x2, 0xe, 0x2, 0x37, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 
    0x5, 0x3, 0x3d, 0xa, 0x3, 0x3, 0x3, 0x5, 0x3, 0x40, 0xa, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x45, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0x4b, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 
    0x4f, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x52, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x5a, 0xa, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x6, 0x6, 0x60, 0xa, 0x6, 0xd, 0x6, 
    0xe, 0x6, 0x61, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x6, 0x6, 0x6b, 0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0x6c, 0x5, 
    0x6, 0x6f, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x73, 0xa, 0x6, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x6, 0x7, 0x7a, 0xa, 0x7, 
    0xd, 0x7, 0xe, 0x7, 0x7b, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x80, 0xa, 0x7, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 
    0x88, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x8c, 0xa, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x92, 0xa, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x7, 0x8, 0x96, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x99, 0xb, 0x8, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x5, 0xa, 0xa4, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x5, 0xc, 0xb1, 0xa, 0xc, 0x3, 0xd, 0x6, 0xd, 0xb4, 0xa, 0xd, 
    0xd, 0xd, 0xe, 0xd, 0xb5, 0x3, 0xd, 0x6, 0xd, 0xb9, 0xa, 0xd, 0xd, 0xd, 
    0xe, 0xd, 0xba, 0x3, 0xd, 0x5, 0xd, 0xbe, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0xcd, 0xa, 0x10, 
    0xc, 0x10, 0xe, 0x10, 0xd0, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 
    0xd4, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x7, 0x10, 0xdb, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0xde, 0xb, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x5, 0x10, 0xe2, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0xe9, 0xa, 0x10, 0xc, 0x10, 0xe, 
    0x10, 0xec, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xf0, 0xa, 0x10, 
    0x5, 0x10, 0xf2, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x101, 0xa, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x7, 0x11, 0x112, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x115, 
    0xb, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x121, 
    0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x2, 0x5, 0x8, 0xe, 0x20, 0x1a, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 
    0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x2, 0xb, 0x3, 0x2, 
    0x40, 0x42, 0x3, 0x2, 0x3e, 0x3f, 0x3, 0x2, 0x1a, 0x24, 0x4, 0x2, 0x2e, 
    0x36, 0x3a, 0x3a, 0x3, 0x2, 0x37, 0x39, 0x3, 0x2, 0x46, 0x4b, 0x3, 0x2, 
    0x3b, 0x3d, 0x3, 0x2, 0xa, 0xd, 0x3, 0x2, 0xe, 0x19, 0x2, 0x13c, 0x2, 
    0x35, 0x3, 0x2, 0x2, 0x2, 0x4, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x6, 0x44, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x4a, 0x3, 0x2, 0x2, 0x2, 0xa, 0x72, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x74, 0x3, 0x2, 0x2, 0x2, 0xe, 0x87, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x12, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0xa5, 0x3, 0x2, 0x2, 0x2, 0x16, 0xb0, 0x3, 0x2, 0x2, 0x2, 0x18, 0xbd, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xc2, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0xf1, 0x3, 0x2, 0x2, 0x2, 0x20, 0x100, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0x116, 0x3, 0x2, 0x2, 0x2, 0x24, 0x118, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x28, 0x11c, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0x120, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x122, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x124, 0x3, 0x2, 0x2, 0x2, 0x30, 0x126, 0x3, 0x2, 0x2, 0x2, 0x32, 0x34, 
    0x5, 0x4, 0x3, 0x2, 0x33, 0x32, 0x3, 0x2, 0x2, 0x2, 0x34, 0x37, 0x3, 
    0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 0x2, 
    0x2, 0x2, 0x36, 0x38, 0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 0x3, 0x2, 0x2, 
    0x2, 0x38, 0x39, 0x7, 0x2, 0x2, 0x3, 0x39, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x3a, 0x3c, 0x5, 0x6, 0x4, 0x2, 0x3b, 0x3d, 0x7, 0x51, 0x2, 0x2, 0x3c, 
    0x3b, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x40, 
    0x3, 0x2, 0x2, 0x2, 0x3e, 0x40, 0x7, 0x51, 0x2, 0x2, 0x3f, 0x3a, 0x3, 
    0x2, 0x2, 0x2, 0x3f, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0x41, 0x45, 0x5, 0x8, 0x5, 0x2, 0x42, 0x45, 0x5, 0xa, 0x6, 
    0x2, 0x43, 0x45, 0x5, 0xc, 0x7, 0x2, 0x44, 0x41, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x42, 0x3, 0x2, 0x2, 0x2, 0x44, 0x43, 0x3, 0x2, 0x2, 0x2, 0x45, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x8, 0x5, 0x1, 0x2, 0x47, 0x4b, 
    0x5, 0x16, 0xc, 0x2, 0x48, 0x4b, 0x5, 0x18, 0xd, 0x2, 0x49, 0x4b, 0x5, 
    0x1e, 0x10, 0x2, 0x4a, 0x46, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x48, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x50, 0x3, 0x2, 0x2, 
    0x2, 0x4c, 0x4d, 0xc, 0x3, 0x2, 0x2, 0x4d, 0x4f, 0x5, 0x8, 0x5, 0x4, 
    0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x52, 0x3, 0x2, 0x2, 0x2, 0x50, 
    0x4e, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x3, 0x2, 0x2, 0x2, 0x51, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x52, 0x50, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 
    0x3, 0x2, 0x2, 0x54, 0x55, 0x5, 0xe, 0x8, 0x2, 0x55, 0x59, 0x5, 0x8, 
    0x5, 0x2, 0x56, 0x57, 0x7, 0x51, 0x2, 0x2, 0x57, 0x58, 0x7, 0x4, 0x2, 
    0x2, 0x58, 0x5a, 0x5, 0x8, 0x5, 0x2, 0x59, 0x56, 0x3, 0x2, 0x2, 0x2, 
    0x59, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x73, 0x3, 0x2, 0x2, 0x2, 0x5b, 
    0x5c, 0x7, 0x3, 0x2, 0x2, 0x5c, 0x5d, 0x5, 0xe, 0x8, 0x2, 0x5d, 0x5f, 
    0x7, 0x51, 0x2, 0x2, 0x5e, 0x60, 0x5, 0x4, 0x3, 0x2, 0x5f, 0x5e, 0x3, 
    0x2, 0x2, 0x2, 0x60, 0x61, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5f, 0x3, 0x2, 
    0x2, 0x2, 0x61, 0x62, 0x3, 0x2, 0x2, 0x2, 0x62, 0x6e, 0x3, 0x2, 0x2, 
    0x2, 0x63, 0x64, 0x7, 0x4, 0x2, 0x2, 0x64, 0x65, 0x5, 0x8, 0x5, 0x2, 
    0x65, 0x66, 0x7, 0x51, 0x2, 0x2, 0x66, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x67, 
    0x68, 0x7, 0x4, 0x2, 0x2, 0x68, 0x6a, 0x7, 0x51, 0x2, 0x2, 0x69, 0x6b, 
    0x5, 0x4, 0x3, 0x2, 0x6a, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x3, 
    0x2, 0x2, 0x2, 0x6c, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 
    0x2, 0x2, 0x6d, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x63, 0x3, 0x2, 0x2, 
    0x2, 0x6e, 0x67, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x3, 0x2, 0x2, 0x2, 
    0x6f, 0x70, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x7, 0x5, 0x2, 0x2, 0x71, 
    0x73, 0x3, 0x2, 0x2, 0x2, 0x72, 0x53, 0x3, 0x2, 0x2, 0x2, 0x72, 0x5b, 
    0x3, 0x2, 0x2, 0x2, 0x73, 0xb, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x7, 
    0x6, 0x2, 0x2, 0x75, 0x7f, 0x5, 0xe, 0x8, 0x2, 0x76, 0x80, 0x5, 0x8, 
    0x5, 0x2, 0x77, 0x79, 0x7, 0x51, 0x2, 0x2, 0x78, 0x7a, 0x5, 0x4, 0x3, 
    0x2, 0x79, 0x78, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x3, 0x2, 0x2, 0x2, 
    0x7b, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7c, 
    0x7d, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x7, 0x7, 0x2, 0x2, 0x7e, 0x80, 
    0x3, 0x2, 0x2, 0x2, 0x7f, 0x76, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x77, 0x3, 
    0x2, 0x2, 0x2, 0x80, 0xd, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x8, 0x8, 
    0x1, 0x2, 0x82, 0x83, 0x7, 0x4c, 0x2, 0x2, 0x83, 0x84, 0x5, 0xe, 0x8, 
    0x2, 0x84, 0x85, 0x7, 0x4d, 0x2, 0x2, 0x85, 0x88, 0x3, 0x2, 0x2, 0x2, 
    0x86, 0x88, 0x5, 0x10, 0x9, 0x2, 0x87, 0x81, 0x3, 0x2, 0x2, 0x2, 0x87, 
    0x86, 0x3, 0x2, 0x2, 0x2, 0x88, 0x97, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8b, 
    0xc, 0x5, 0x2, 0x2, 0x8a, 0x8c, 0x7, 0x51, 0x2, 0x2, 0x8b, 0x8a, 0x3, 
    0x2, 0x2, 0x2, 0x8b, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x3, 0x2, 
    0x2, 0x2, 0x8d, 0x8e, 0x7, 0x8, 0x2, 0x2, 0x8e, 0x96, 0x5, 0xe, 0x8, 
    0x6, 0x8f, 0x91, 0xc, 0x4, 0x2, 0x2, 0x90, 0x92, 0x7, 0x51, 0x2, 0x2, 
    0x91, 0x90, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x3, 0x2, 0x2, 0x2, 0x92, 
    0x93, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x7, 0x9, 0x2, 0x2, 0x94, 0x96, 
    0x5, 0xe, 0x8, 0x5, 0x95, 0x89, 0x3, 0x2, 0x2, 0x2, 0x95, 0x8f, 0x3, 
    0x2, 0x2, 0x2, 0x96, 0x99, 0x3, 0x2, 0x2, 0x2, 0x97, 0x95, 0x3, 0x2, 
    0x2, 0x2, 0x97, 0x98, 0x3, 0x2, 0x2, 0x2, 0x98, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x99, 0x97, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x5, 0x20, 0x11, 0x2, 
    0x9b, 0x9c, 0x5, 0x28, 0x15, 0x2, 0x9c, 0x9d, 0x5, 0x20, 0x11, 0x2, 
    0x9d, 0x11, 0x3, 0x2, 0x2, 0x2, 0x9e, 0xa4, 0x5, 0x14, 0xb, 0x2, 0x9f, 
    0xa0, 0x7, 0x4c, 0x2, 0x2, 0xa0, 0xa1, 0x5, 0x20, 0x11, 0x2, 0xa1, 0xa2, 
    0x7, 0x4d, 0x2, 0x2, 0xa2, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa3, 0x9e, 0x3, 
    0x2, 0x2, 0x2, 0xa3, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0xa5, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0xa7, 0xa8, 0x5, 0x2e, 0x18, 0x2, 0xa8, 0xa9, 0x7, 0x46, 0x2, 0x2, 
    0xa9, 0xaa, 0x7, 0x46, 0x2, 0x2, 0xaa, 0xab, 0x5, 0x20, 0x11, 0x2, 0xab, 
    0xb1, 0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x5, 0x2e, 0x18, 0x2, 0xad, 0xae, 
    0x7, 0x46, 0x2, 0x2, 0xae, 0xaf, 0x5, 0x20, 0x11, 0x2, 0xaf, 0xb1, 0x3, 
    0x2, 0x2, 0x2, 0xb0, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xac, 0x3, 0x2, 
    0x2, 0x2, 0xb1, 0x17, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb4, 0x5, 0x1a, 0xe, 
    0x2, 0xb3, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 0x3, 0x2, 0x2, 0x2, 
    0xb5, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb6, 
    0xbe, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb9, 0x5, 0x1c, 0xf, 0x2, 0xb8, 0xb7, 
    0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x3, 0x2, 0x2, 0x2, 0xba, 0xb8, 0x3, 
    0x2, 0x2, 0x2, 0xba, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbe, 0x3, 0x2, 
    0x2, 0x2, 0xbc, 0xbe, 0x5, 0x22, 0x12, 0x2, 0xbd, 0xb3, 0x3, 0x2, 0x2, 
    0x2, 0xbd, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbc, 0x3, 0x2, 0x2, 0x2, 
    0xbe, 0x19, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x5, 0x24, 0x13, 0x2, 0xc0, 
    0xc1, 0x5, 0x20, 0x11, 0x2, 0xc1, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 
    0x5, 0x24, 0x13, 0x2, 0xc3, 0xc4, 0x5, 0x20, 0x11, 0x2, 0xc4, 0xc5, 
    0x7, 0x4e, 0x2, 0x2, 0xc5, 0xc6, 0x5, 0x20, 0x11, 0x2, 0xc6, 0x1d, 0x3, 
    0x2, 0x2, 0x2, 0xc7, 0xd3, 0x7, 0x18, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x4c, 
    0x2, 0x2, 0xc9, 0xce, 0x5, 0x24, 0x13, 0x2, 0xca, 0xcb, 0x7, 0x50, 0x2, 
    0x2, 0xcb, 0xcd, 0x5, 0x24, 0x13, 0x2, 0xcc, 0xca, 0x3, 0x2, 0x2, 0x2, 
    0xcd, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xce, 
    0xcf, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xce, 
    0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0x4d, 0x2, 0x2, 0xd2, 0xd4, 0x3, 
    0x2, 0x2, 0x2, 0xd3, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x3, 0x2, 
    0x2, 0x2, 0xd4, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xe1, 0x7, 0x29, 0x2, 
    0x2, 0xd6, 0xd7, 0x7, 0x4c, 0x2, 0x2, 0xd7, 0xdc, 0x5, 0x24, 0x13, 0x2, 
    0xd8, 0xd9, 0x7, 0x50, 0x2, 0x2, 0xd9, 0xdb, 0x5, 0x24, 0x13, 0x2, 0xda, 
    0xd8, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xde, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xda, 
    0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdf, 0x3, 
    0x2, 0x2, 0x2, 0xde, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x7, 0x4d, 
    0x2, 0x2, 0xe0, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xd6, 0x3, 0x2, 0x2, 
    0x2, 0xe1, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xf2, 0x3, 0x2, 0x2, 0x2, 
    0xe3, 0xef, 0x7, 0x2a, 0x2, 0x2, 0xe4, 0xe5, 0x7, 0x4c, 0x2, 0x2, 0xe5, 
    0xea, 0x5, 0x24, 0x13, 0x2, 0xe6, 0xe7, 0x7, 0x50, 0x2, 0x2, 0xe7, 0xe9, 
    0x5, 0x24, 0x13, 0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xec, 0x3, 
    0x2, 0x2, 0x2, 0xea, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 0x3, 0x2, 
    0x2, 0x2, 0xeb, 0xed, 0x3, 0x2, 0x2, 0x2, 0xec, 0xea, 0x3, 0x2, 0x2, 
    0x2, 0xed, 0xee, 0x7, 0x4d, 0x2, 0x2, 0xee, 0xf0, 0x3, 0x2, 0x2, 0x2, 
    0xef, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf0, 
    0xf2, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xd5, 
    0x3, 0x2, 0x2, 0x2, 0xf1, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xf2, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0xf3, 0xf4, 0x8, 0x11, 0x1, 0x2, 0xf4, 0xf5, 0x7, 0x4c, 
    0x2, 0x2, 0xf5, 0xf6, 0x5, 0x20, 0x11, 0x2, 0xf6, 0xf7, 0x7, 0x4d, 0x2, 
    0x2, 0xf7, 0x101, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x5, 0x30, 0x19, 0x2, 
    0xf9, 0xfa, 0x7, 0x4c, 0x2, 0x2, 0xfa, 0xfb, 0x5, 0x20, 0x11, 0x2, 0xfb, 
    0xfc, 0x7, 0x4d, 0x2, 0x2, 0xfc, 0x101, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfe, 
    0x7, 0x3f, 0x2, 0x2, 0xfe, 0x101, 0x5, 0x20, 0x11, 0x9, 0xff, 0x101, 
    0x5, 0x2a, 0x16, 0x2, 0x100, 0xf3, 0x3, 0x2, 0x2, 0x2, 0x100, 0xf8, 
    0x3, 0x2, 0x2, 0x2, 0x100, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x100, 0xff, 0x3, 
    0x2, 0x2, 0x2, 0x101, 0x113, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0xc, 
    0x8, 0x2, 0x2, 0x103, 0x104, 0x9, 0x2, 0x2, 0x2, 0x104, 0x112, 0x5, 
    0x20, 0x11, 0x9, 0x105, 0x106, 0xc, 0x7, 0x2, 0x2, 0x106, 0x107, 0x9, 
    0x3, 0x2, 0x2, 0x107, 0x112, 0x5, 0x20, 0x11, 0x8, 0x108, 0x109, 0xc, 
    0x6, 0x2, 0x2, 0x109, 0x10a, 0x7, 0x43, 0x2, 0x2, 0x10a, 0x112, 0x5, 
    0x20, 0x11, 0x7, 0x10b, 0x10c, 0xc, 0x5, 0x2, 0x2, 0x10c, 0x10d, 0x7, 
    0x45, 0x2, 0x2, 0x10d, 0x112, 0x5, 0x20, 0x11, 0x6, 0x10e, 0x10f, 0xc, 
    0x4, 0x2, 0x2, 0x10f, 0x110, 0x7, 0x44, 0x2, 0x2, 0x110, 0x112, 0x5, 
    0x20, 0x11, 0x5, 0x111, 0x102, 0x3, 0x2, 0x2, 0x2, 0x111, 0x105, 0x3, 
    0x2, 0x2, 0x2, 0x111, 0x108, 0x3, 0x2, 0x2, 0x2, 0x111, 0x10b, 0x3, 
    0x2, 0x2, 0x2, 0x111, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x112, 0x115, 0x3, 
    0x2, 0x2, 0x2, 0x113, 0x111, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x3, 
    0x2, 0x2, 0x2, 0x114, 0x21, 0x3, 0x2, 0x2, 0x2, 0x115, 0x113, 0x3, 0x2, 
    0x2, 0x2, 0x116, 0x117, 0x9, 0x4, 0x2, 0x2, 0x117, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0x118, 0x119, 0x9, 0x5, 0x2, 0x2, 0x119, 0x25, 0x3, 0x2, 0x2, 0x2, 
    0x11a, 0x11b, 0x9, 0x6, 0x2, 0x2, 0x11b, 0x27, 0x3, 0x2, 0x2, 0x2, 0x11c, 
    0x11d, 0x9, 0x7, 0x2, 0x2, 0x11d, 0x29, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x121, 
    0x5, 0x2c, 0x17, 0x2, 0x11f, 0x121, 0x5, 0x2e, 0x18, 0x2, 0x120, 0x11e, 
    0x3, 0x2, 0x2, 0x2, 0x120, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x121, 0x2b, 0x3, 
    0x2, 0x2, 0x2, 0x122, 0x123, 0x9, 0x8, 0x2, 0x2, 0x123, 0x2d, 0x3, 0x2, 
    0x2, 0x2, 0x124, 0x125, 0x9, 0x9, 0x2, 0x2, 0x125, 0x2f, 0x3, 0x2, 0x2, 
    0x2, 0x126, 0x127, 0x9, 0xa, 0x2, 0x2, 0x127, 0x31, 0x3, 0x2, 0x2, 0x2, 
    0x24, 0x35, 0x3c, 0x3f, 0x44, 0x4a, 0x50, 0x59, 0x61, 0x6c, 0x6e, 0x72, 
    0x7b, 0x7f, 0x87, 0x8b, 0x91, 0x95, 0x97, 0xa3, 0xb0, 0xb5, 0xba, 0xbd, 
    0xce, 0xd3, 0xdc, 0xe1, 0xea, 0xef, 0xf1, 0x100, 0x111, 0x113, 0x120, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

PMACParser::Initializer PMACParser::_init;
