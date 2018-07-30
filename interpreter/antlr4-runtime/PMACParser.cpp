
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
    setState(39);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PMACParser::IF)
      | (1ULL << PMACParser::WHILE)
      | (1ULL << PMACParser::Q_VAR)
      | (1ULL << PMACParser::P_VAR)
      | (1ULL << PMACParser::I_VAR)
      | (1ULL << PMACParser::M_VAR)
      | (1ULL << PMACParser::NL))) != 0)) {
      setState(36);
      dynamic_cast<ProgramContext *>(_localctx)->lineContext = line();
      dynamic_cast<ProgramContext *>(_localctx)->lines.push_back(dynamic_cast<ProgramContext *>(_localctx)->lineContext);
      setState(41);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(42);
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
    setState(49);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PMACParser::IF:
      case PMACParser::WHILE:
      case PMACParser::Q_VAR:
      case PMACParser::P_VAR:
      case PMACParser::I_VAR:
      case PMACParser::M_VAR: {
        enterOuterAlt(_localctx, 1);
        setState(44);
        statement();
        setState(46);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          setState(45);
          match(PMACParser::NL);
          break;
        }

        }
        break;
      }

      case PMACParser::NL: {
        enterOuterAlt(_localctx, 2);
        setState(48);
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
    setState(54);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PMACParser::Q_VAR:
      case PMACParser::P_VAR:
      case PMACParser::I_VAR:
      case PMACParser::M_VAR: {
        enterOuterAlt(_localctx, 1);
        setState(51);
        action(0);
        break;
      }

      case PMACParser::IF: {
        enterOuterAlt(_localctx, 2);
        setState(52);
        ifStatement();
        break;
      }

      case PMACParser::WHILE: {
        enterOuterAlt(_localctx, 3);
        setState(53);
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
    setState(57);
    assign();
    _ctx->stop = _input->LT(-1);
    setState(63);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ActionContext>(parentContext, parentState);
        _localctx->leftAction = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleAction);
        setState(59);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(60);
        dynamic_cast<ActionContext *>(_localctx)->rightAction = action(2); 
      }
      setState(65);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
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
    setState(97);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(66);
      match(PMACParser::IF);
      setState(67);
      compoundCondition(0);
      setState(68);
      dynamic_cast<IfStatementContext *>(_localctx)->ifAction = action(0);
      setState(72);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
      case 1: {
        setState(69);
        match(PMACParser::NL);
        setState(70);
        match(PMACParser::ELSE);
        setState(71);
        dynamic_cast<IfStatementContext *>(_localctx)->elseAction = action(0);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(74);
      match(PMACParser::IF);
      setState(75);
      compoundCondition(0);
      setState(76);
      match(PMACParser::NL);
      setState(78); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(77);
        dynamic_cast<IfStatementContext *>(_localctx)->lineContext = line();
        dynamic_cast<IfStatementContext *>(_localctx)->ifLines.push_back(dynamic_cast<IfStatementContext *>(_localctx)->lineContext);
        setState(80); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PMACParser::IF)
        | (1ULL << PMACParser::WHILE)
        | (1ULL << PMACParser::Q_VAR)
        | (1ULL << PMACParser::P_VAR)
        | (1ULL << PMACParser::I_VAR)
        | (1ULL << PMACParser::M_VAR)
        | (1ULL << PMACParser::NL))) != 0));
      setState(93);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
      case 1: {
        setState(82);
        match(PMACParser::ELSE);
        setState(83);
        dynamic_cast<IfStatementContext *>(_localctx)->elseAction = action(0);
        setState(84);
        match(PMACParser::NL);
        break;
      }

      case 2: {
        setState(86);
        match(PMACParser::ELSE);
        setState(87);
        match(PMACParser::NL);
        setState(89); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(88);
          dynamic_cast<IfStatementContext *>(_localctx)->lineContext = line();
          dynamic_cast<IfStatementContext *>(_localctx)->elseLines.push_back(dynamic_cast<IfStatementContext *>(_localctx)->lineContext);
          setState(91); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << PMACParser::IF)
          | (1ULL << PMACParser::WHILE)
          | (1ULL << PMACParser::Q_VAR)
          | (1ULL << PMACParser::P_VAR)
          | (1ULL << PMACParser::I_VAR)
          | (1ULL << PMACParser::M_VAR)
          | (1ULL << PMACParser::NL))) != 0));
        break;
      }

      }
      setState(95);
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
    setState(99);
    match(PMACParser::WHILE);
    setState(100);
    compoundCondition(0);
    setState(110);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PMACParser::Q_VAR:
      case PMACParser::P_VAR:
      case PMACParser::I_VAR:
      case PMACParser::M_VAR: {
        setState(101);
        dynamic_cast<WhileStatementContext *>(_localctx)->whileAction = action(0);
        break;
      }

      case PMACParser::NL: {
        setState(102);
        match(PMACParser::NL);
        setState(104); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(103);
          dynamic_cast<WhileStatementContext *>(_localctx)->lineContext = line();
          dynamic_cast<WhileStatementContext *>(_localctx)->whileLines.push_back(dynamic_cast<WhileStatementContext *>(_localctx)->lineContext);
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
          | (1ULL << PMACParser::NL))) != 0));
        setState(108);
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
    setState(118);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      setState(113);
      match(PMACParser::LPAR);
      setState(114);
      dynamic_cast<CompoundConditionContext *>(_localctx)->center = compoundCondition(0);
      setState(115);
      match(PMACParser::RPAR);
      break;
    }

    case 2: {
      setState(117);
      condition();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(134);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(132);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<CompoundConditionContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleCompoundCondition);
          setState(120);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(122);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PMACParser::NL) {
            setState(121);
            match(PMACParser::NL);
          }
          setState(124);
          dynamic_cast<CompoundConditionContext *>(_localctx)->logicalOp = match(PMACParser::AND);
          setState(125);
          dynamic_cast<CompoundConditionContext *>(_localctx)->right = compoundCondition(4);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<CompoundConditionContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleCompoundCondition);
          setState(126);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(128);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PMACParser::NL) {
            setState(127);
            match(PMACParser::NL);
          }
          setState(130);
          dynamic_cast<CompoundConditionContext *>(_localctx)->logicalOp = match(PMACParser::OR);
          setState(131);
          dynamic_cast<CompoundConditionContext *>(_localctx)->right = compoundCondition(3);
          break;
        }

        } 
      }
      setState(136);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
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
    setState(137);
    dynamic_cast<ConditionContext *>(_localctx)->left = expr(0);
    setState(138);
    comparator();
    setState(139);
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
    setState(146);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PMACParser::EOF: {
        enterOuterAlt(_localctx, 1);
        setState(141);
        constant();
        break;
      }

      case PMACParser::LPAR: {
        enterOuterAlt(_localctx, 2);
        setState(142);
        match(PMACParser::LPAR);
        setState(143);
        expr(0);
        setState(144);
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

tree::TerminalNode* PMACParser::AssignContext::EQ() {
  return getToken(PMACParser::EQ, 0);
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
    enterOuterAlt(_localctx, 1);
    setState(150);
    var();
    setState(151);
    match(PMACParser::EQ);
    setState(152);
    expr(0);
   
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
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, PMACParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(167);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PMACParser::LPAR: {
        setState(155);
        match(PMACParser::LPAR);
        setState(156);
        dynamic_cast<ExprContext *>(_localctx)->center = expr(0);
        setState(157);
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
        setState(159);
        function();
        setState(160);
        match(PMACParser::LPAR);
        setState(161);
        dynamic_cast<ExprContext *>(_localctx)->argument = expr(0);
        setState(162);
        match(PMACParser::RPAR);
        break;
      }

      case PMACParser::MIN: {
        setState(164);
        match(PMACParser::MIN);
        setState(165);
        dynamic_cast<ExprContext *>(_localctx)->minExpr = expr(2);
        break;
      }

      case PMACParser::Q_VAR:
      case PMACParser::P_VAR:
      case PMACParser::I_VAR:
      case PMACParser::M_VAR:
      case PMACParser::INTEGER:
      case PMACParser::DECIMAL:
      case PMACParser::HEX: {
        setState(166);
        atom();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(186);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(184);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(169);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(170);
          dynamic_cast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << PMACParser::MULT)
            | (1ULL << PMACParser::DIV)
            | (1ULL << PMACParser::MOD))) != 0))) {
            dynamic_cast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(171);
          dynamic_cast<ExprContext *>(_localctx)->right = expr(8);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(172);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(173);
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
          setState(174);
          dynamic_cast<ExprContext *>(_localctx)->right = expr(7);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(175);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(176);
          dynamic_cast<ExprContext *>(_localctx)->op = match(PMACParser::AND_OP);
          setState(177);
          dynamic_cast<ExprContext *>(_localctx)->right = expr(6);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(178);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(179);
          dynamic_cast<ExprContext *>(_localctx)->op = match(PMACParser::XOR);
          setState(180);
          dynamic_cast<ExprContext *>(_localctx)->right = expr(5);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(181);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(182);
          dynamic_cast<ExprContext *>(_localctx)->op = match(PMACParser::OR_OP);
          setState(183);
          dynamic_cast<ExprContext *>(_localctx)->right = expr(4);
          break;
        }

        } 
      }
      setState(188);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
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
  enterRule(_localctx, 24, PMACParser::RuleComparator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PMACParser::EQ)
      | (1ULL << PMACParser::NEQ)
      | (1ULL << PMACParser::LT)
      | (1ULL << PMACParser::GT)
      | (1ULL << PMACParser::NLT)
      | (1ULL << PMACParser::NGT))) != 0))) {
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
  enterRule(_localctx, 26, PMACParser::RuleAxis);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(191);
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
      | (1ULL << PMACParser::AX_W))) != 0))) {
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
  enterRule(_localctx, 28, PMACParser::RuleAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(195);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PMACParser::INTEGER:
      case PMACParser::DECIMAL:
      case PMACParser::HEX: {
        enterOuterAlt(_localctx, 1);
        setState(193);
        number();
        break;
      }

      case PMACParser::Q_VAR:
      case PMACParser::P_VAR:
      case PMACParser::I_VAR:
      case PMACParser::M_VAR: {
        enterOuterAlt(_localctx, 2);
        setState(194);
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
  enterRule(_localctx, 30, PMACParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(197);
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
  enterRule(_localctx, 32, PMACParser::RuleVar);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
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
  enterRule(_localctx, 34, PMACParser::RuleFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
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
    case 11: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

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
    case 3: return precpred(_ctx, 7);
    case 4: return precpred(_ctx, 6);
    case 5: return precpred(_ctx, 5);
    case 6: return precpred(_ctx, 4);
    case 7: return precpred(_ctx, 3);

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
  "compoundCondition", "condition", "data", "constant", "assign", "expr", 
  "comparator", "axis", "atom", "number", "var", "function"
};

std::vector<std::string> PMACParser::_literalNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "'+'", "'-'", "'*'", "'/'", "'%'", 
  "'&'", "'|'", "'^'", "'='", "'!='", "'<'", "'>'", "'!<'", "'!>'", "'('", 
  "')'", "'\n'"
};

std::vector<std::string> PMACParser::_symbolicNames = {
  "", "IF", "ELSE", "ENDIF", "WHILE", "ENDWHILE", "AND", "OR", "Q_VAR", 
  "P_VAR", "I_VAR", "M_VAR", "SIN", "COS", "TAN", "ASIN", "ACOS", "ATAN", 
  "ATAN2", "LN", "EXP", "SQRT", "ABS", "INT", "LINEAR", "RAPID", "CIRCLE1", 
  "CIRCLE2", "SPLINE1", "SPLINE2", "CC0", "CC1", "CC2", "CC3", "AX_X", "AX_Y", 
  "AX_Z", "AX_A", "AX_B", "AX_C", "AX_U", "AX_V", "AX_W", "INTEGER", "DECIMAL", 
  "HEX", "PLUS", "MIN", "MULT", "DIV", "MOD", "AND_OP", "OR_OP", "XOR", 
  "EQ", "NEQ", "LT", "GT", "NLT", "NGT", "LPAR", "RPAR", "NL", "COMMENT", 
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
    0x3, 0x42, 0xce, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x3, 0x2, 0x7, 0x2, 0x28, 0xa, 0x2, 
    0xc, 0x2, 0xe, 0x2, 0x2b, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x31, 0xa, 0x3, 0x3, 0x3, 0x5, 0x3, 0x34, 0xa, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x39, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x40, 0xa, 0x5, 0xc, 0x5, 0xe, 
    0x5, 0x43, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x5, 0x6, 0x4b, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x6, 0x6, 0x51, 0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0x52, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x6, 0x6, 0x5c, 
    0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0x5d, 0x5, 0x6, 0x60, 0xa, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x5, 0x6, 0x64, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x6, 0x7, 0x6b, 0xa, 0x7, 0xd, 0x7, 0xe, 0x7, 0x6c, 0x3, 
    0x7, 0x3, 0x7, 0x5, 0x7, 0x71, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x79, 0xa, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x5, 0x8, 0x7d, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x5, 0x8, 0x83, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x87, 0xa, 0x8, 
    0xc, 0x8, 0xe, 0x8, 0x8a, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x95, 
    0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 
    0xaa, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xbb, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 
    0xbe, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x5, 0x10, 0xc6, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x2, 0x5, 0x8, 0xe, 0x18, 0x14, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x1c, 0x1e, 0x20, 0x22, 0x24, 0x2, 0x9, 0x3, 0x2, 0x32, 0x34, 0x3, 0x2, 
    0x30, 0x31, 0x3, 0x2, 0x38, 0x3d, 0x3, 0x2, 0x24, 0x2c, 0x3, 0x2, 0x2d, 
    0x2f, 0x3, 0x2, 0xa, 0xd, 0x3, 0x2, 0xe, 0x19, 0x2, 0xd8, 0x2, 0x29, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x33, 0x3, 0x2, 0x2, 0x2, 0x6, 0x38, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0x3a, 0x3, 0x2, 0x2, 0x2, 0xa, 0x63, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0x65, 0x3, 0x2, 0x2, 0x2, 0xe, 0x78, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x8b, 0x3, 0x2, 0x2, 0x2, 0x12, 0x94, 0x3, 0x2, 0x2, 0x2, 0x14, 0x96, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0x98, 0x3, 0x2, 0x2, 0x2, 0x18, 0xa9, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xc1, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0xc5, 0x3, 0x2, 0x2, 0x2, 0x20, 0xc7, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x24, 0xcb, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0x28, 0x5, 0x4, 0x3, 0x2, 0x27, 0x26, 0x3, 0x2, 0x2, 0x2, 0x28, 
    0x2b, 0x3, 0x2, 0x2, 0x2, 0x29, 0x27, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x29, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x2d, 0x7, 0x2, 0x2, 0x3, 0x2d, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x2e, 0x30, 0x5, 0x6, 0x4, 0x2, 0x2f, 0x31, 0x7, 0x40, 0x2, 
    0x2, 0x30, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x3, 0x2, 0x2, 0x2, 
    0x31, 0x34, 0x3, 0x2, 0x2, 0x2, 0x32, 0x34, 0x7, 0x40, 0x2, 0x2, 0x33, 
    0x2e, 0x3, 0x2, 0x2, 0x2, 0x33, 0x32, 0x3, 0x2, 0x2, 0x2, 0x34, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x35, 0x39, 0x5, 0x8, 0x5, 0x2, 0x36, 0x39, 0x5, 
    0xa, 0x6, 0x2, 0x37, 0x39, 0x5, 0xc, 0x7, 0x2, 0x38, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0x38, 0x36, 0x3, 0x2, 0x2, 0x2, 0x38, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x39, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x8, 0x5, 0x1, 0x2, 
    0x3b, 0x3c, 0x5, 0x16, 0xc, 0x2, 0x3c, 0x41, 0x3, 0x2, 0x2, 0x2, 0x3d, 
    0x3e, 0xc, 0x3, 0x2, 0x2, 0x3e, 0x40, 0x5, 0x8, 0x5, 0x4, 0x3f, 0x3d, 
    0x3, 0x2, 0x2, 0x2, 0x40, 0x43, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 
    0x2, 0x2, 0x2, 0x41, 0x42, 0x3, 0x2, 0x2, 0x2, 0x42, 0x9, 0x3, 0x2, 
    0x2, 0x2, 0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x7, 0x3, 0x2, 
    0x2, 0x45, 0x46, 0x5, 0xe, 0x8, 0x2, 0x46, 0x4a, 0x5, 0x8, 0x5, 0x2, 
    0x47, 0x48, 0x7, 0x40, 0x2, 0x2, 0x48, 0x49, 0x7, 0x4, 0x2, 0x2, 0x49, 
    0x4b, 0x5, 0x8, 0x5, 0x2, 0x4a, 0x47, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 
    0x3, 0x2, 0x2, 0x2, 0x4b, 0x64, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x7, 
    0x3, 0x2, 0x2, 0x4d, 0x4e, 0x5, 0xe, 0x8, 0x2, 0x4e, 0x50, 0x7, 0x40, 
    0x2, 0x2, 0x4f, 0x51, 0x5, 0x4, 0x3, 0x2, 0x50, 0x4f, 0x3, 0x2, 0x2, 
    0x2, 0x51, 0x52, 0x3, 0x2, 0x2, 0x2, 0x52, 0x50, 0x3, 0x2, 0x2, 0x2, 
    0x52, 0x53, 0x3, 0x2, 0x2, 0x2, 0x53, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x54, 
    0x55, 0x7, 0x4, 0x2, 0x2, 0x55, 0x56, 0x5, 0x8, 0x5, 0x2, 0x56, 0x57, 
    0x7, 0x40, 0x2, 0x2, 0x57, 0x60, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x7, 
    0x4, 0x2, 0x2, 0x59, 0x5b, 0x7, 0x40, 0x2, 0x2, 0x5a, 0x5c, 0x5, 0x4, 
    0x3, 0x2, 0x5b, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x3, 0x2, 0x2, 
    0x2, 0x5d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x3, 0x2, 0x2, 0x2, 
    0x5e, 0x60, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x54, 0x3, 0x2, 0x2, 0x2, 0x5f, 
    0x58, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 
    0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x7, 0x5, 0x2, 0x2, 0x62, 0x64, 0x3, 
    0x2, 0x2, 0x2, 0x63, 0x44, 0x3, 0x2, 0x2, 0x2, 0x63, 0x4c, 0x3, 0x2, 
    0x2, 0x2, 0x64, 0xb, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x7, 0x6, 0x2, 
    0x2, 0x66, 0x70, 0x5, 0xe, 0x8, 0x2, 0x67, 0x71, 0x5, 0x8, 0x5, 0x2, 
    0x68, 0x6a, 0x7, 0x40, 0x2, 0x2, 0x69, 0x6b, 0x5, 0x4, 0x3, 0x2, 0x6a, 
    0x69, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6a, 
    0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x3, 
    0x2, 0x2, 0x2, 0x6e, 0x6f, 0x7, 0x7, 0x2, 0x2, 0x6f, 0x71, 0x3, 0x2, 
    0x2, 0x2, 0x70, 0x67, 0x3, 0x2, 0x2, 0x2, 0x70, 0x68, 0x3, 0x2, 0x2, 
    0x2, 0x71, 0xd, 0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0x8, 0x8, 0x1, 0x2, 
    0x73, 0x74, 0x7, 0x3e, 0x2, 0x2, 0x74, 0x75, 0x5, 0xe, 0x8, 0x2, 0x75, 
    0x76, 0x7, 0x3f, 0x2, 0x2, 0x76, 0x79, 0x3, 0x2, 0x2, 0x2, 0x77, 0x79, 
    0x5, 0x10, 0x9, 0x2, 0x78, 0x72, 0x3, 0x2, 0x2, 0x2, 0x78, 0x77, 0x3, 
    0x2, 0x2, 0x2, 0x79, 0x88, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7c, 0xc, 0x5, 
    0x2, 0x2, 0x7b, 0x7d, 0x7, 0x40, 0x2, 0x2, 0x7c, 0x7b, 0x3, 0x2, 0x2, 
    0x2, 0x7c, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x3, 0x2, 0x2, 0x2, 
    0x7e, 0x7f, 0x7, 0x8, 0x2, 0x2, 0x7f, 0x87, 0x5, 0xe, 0x8, 0x6, 0x80, 
    0x82, 0xc, 0x4, 0x2, 0x2, 0x81, 0x83, 0x7, 0x40, 0x2, 0x2, 0x82, 0x81, 
    0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x3, 
    0x2, 0x2, 0x2, 0x84, 0x85, 0x7, 0x9, 0x2, 0x2, 0x85, 0x87, 0x5, 0xe, 
    0x8, 0x5, 0x86, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x86, 0x80, 0x3, 0x2, 0x2, 
    0x2, 0x87, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x88, 0x86, 0x3, 0x2, 0x2, 0x2, 
    0x88, 0x89, 0x3, 0x2, 0x2, 0x2, 0x89, 0xf, 0x3, 0x2, 0x2, 0x2, 0x8a, 
    0x88, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x5, 0x18, 0xd, 0x2, 0x8c, 0x8d, 
    0x5, 0x1a, 0xe, 0x2, 0x8d, 0x8e, 0x5, 0x18, 0xd, 0x2, 0x8e, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x8f, 0x95, 0x5, 0x14, 0xb, 0x2, 0x90, 0x91, 0x7, 0x3e, 
    0x2, 0x2, 0x91, 0x92, 0x5, 0x18, 0xd, 0x2, 0x92, 0x93, 0x7, 0x3f, 0x2, 
    0x2, 0x93, 0x95, 0x3, 0x2, 0x2, 0x2, 0x94, 0x8f, 0x3, 0x2, 0x2, 0x2, 
    0x94, 0x90, 0x3, 0x2, 0x2, 0x2, 0x95, 0x13, 0x3, 0x2, 0x2, 0x2, 0x96, 
    0x97, 0x3, 0x2, 0x2, 0x2, 0x97, 0x15, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 
    0x5, 0x22, 0x12, 0x2, 0x99, 0x9a, 0x7, 0x38, 0x2, 0x2, 0x9a, 0x9b, 0x5, 
    0x18, 0xd, 0x2, 0x9b, 0x17, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x8, 0xd, 
    0x1, 0x2, 0x9d, 0x9e, 0x7, 0x3e, 0x2, 0x2, 0x9e, 0x9f, 0x5, 0x18, 0xd, 
    0x2, 0x9f, 0xa0, 0x7, 0x3f, 0x2, 0x2, 0xa0, 0xaa, 0x3, 0x2, 0x2, 0x2, 
    0xa1, 0xa2, 0x5, 0x24, 0x13, 0x2, 0xa2, 0xa3, 0x7, 0x3e, 0x2, 0x2, 0xa3, 
    0xa4, 0x5, 0x18, 0xd, 0x2, 0xa4, 0xa5, 0x7, 0x3f, 0x2, 0x2, 0xa5, 0xaa, 
    0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x7, 0x31, 0x2, 0x2, 0xa7, 0xaa, 0x5, 
    0x18, 0xd, 0x4, 0xa8, 0xaa, 0x5, 0x1e, 0x10, 0x2, 0xa9, 0x9c, 0x3, 0x2, 
    0x2, 0x2, 0xa9, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xa6, 0x3, 0x2, 0x2, 
    0x2, 0xa9, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xbc, 0x3, 0x2, 0x2, 0x2, 
    0xab, 0xac, 0xc, 0x9, 0x2, 0x2, 0xac, 0xad, 0x9, 0x2, 0x2, 0x2, 0xad, 
    0xbb, 0x5, 0x18, 0xd, 0xa, 0xae, 0xaf, 0xc, 0x8, 0x2, 0x2, 0xaf, 0xb0, 
    0x9, 0x3, 0x2, 0x2, 0xb0, 0xbb, 0x5, 0x18, 0xd, 0x9, 0xb1, 0xb2, 0xc, 
    0x7, 0x2, 0x2, 0xb2, 0xb3, 0x7, 0x35, 0x2, 0x2, 0xb3, 0xbb, 0x5, 0x18, 
    0xd, 0x8, 0xb4, 0xb5, 0xc, 0x6, 0x2, 0x2, 0xb5, 0xb6, 0x7, 0x37, 0x2, 
    0x2, 0xb6, 0xbb, 0x5, 0x18, 0xd, 0x7, 0xb7, 0xb8, 0xc, 0x5, 0x2, 0x2, 
    0xb8, 0xb9, 0x7, 0x36, 0x2, 0x2, 0xb9, 0xbb, 0x5, 0x18, 0xd, 0x6, 0xba, 
    0xab, 0x3, 0x2, 0x2, 0x2, 0xba, 0xae, 0x3, 0x2, 0x2, 0x2, 0xba, 0xb1, 
    0x3, 0x2, 0x2, 0x2, 0xba, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xba, 0xb7, 0x3, 
    0x2, 0x2, 0x2, 0xbb, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xba, 0x3, 0x2, 
    0x2, 0x2, 0xbc, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbd, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0xbe, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x9, 0x4, 0x2, 0x2, 
    0xc0, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x9, 0x5, 0x2, 0x2, 0xc2, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc6, 0x5, 0x20, 0x11, 0x2, 0xc4, 0xc6, 
    0x5, 0x22, 0x12, 0x2, 0xc5, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc4, 0x3, 
    0x2, 0x2, 0x2, 0xc6, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 0x9, 0x6, 
    0x2, 0x2, 0xc8, 0x21, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x9, 0x7, 0x2, 
    0x2, 0xca, 0x23, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x9, 0x8, 0x2, 0x2, 
    0xcc, 0x25, 0x3, 0x2, 0x2, 0x2, 0x18, 0x29, 0x30, 0x33, 0x38, 0x41, 
    0x4a, 0x52, 0x5d, 0x5f, 0x63, 0x6c, 0x70, 0x78, 0x7c, 0x82, 0x86, 0x88, 
    0x94, 0xa9, 0xba, 0xbc, 0xc5, 
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
