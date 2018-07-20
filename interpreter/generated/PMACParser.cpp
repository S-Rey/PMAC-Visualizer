
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
    setState(19);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PMACParser::Q_VAR)
      | (1ULL << PMACParser::P_VAR)
      | (1ULL << PMACParser::I_VAR))) != 0)) {
      setState(16);
      line();
      setState(21);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
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
    enterOuterAlt(_localctx, 1);
    setState(22);
    statement();
   
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

PMACParser::AssignContext* PMACParser::StatementContext::assign() {
  return getRuleContext<PMACParser::AssignContext>(0);
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
    enterOuterAlt(_localctx, 1);
    setState(24);
    assign();
   
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
  enterRule(_localctx, 6, PMACParser::RuleAssign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(26);
    var();
    setState(27);
    match(PMACParser::EQ);
    setState(28);
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

std::vector<PMACParser::ExprContext *> PMACParser::ExprContext::expr() {
  return getRuleContexts<PMACParser::ExprContext>();
}

PMACParser::ExprContext* PMACParser::ExprContext::expr(size_t i) {
  return getRuleContext<PMACParser::ExprContext>(i);
}

tree::TerminalNode* PMACParser::ExprContext::RPAR() {
  return getToken(PMACParser::RPAR, 0);
}

PMACParser::AtomContext* PMACParser::ExprContext::atom() {
  return getRuleContext<PMACParser::AtomContext>(0);
}

tree::TerminalNode* PMACParser::ExprContext::PLUS() {
  return getToken(PMACParser::PLUS, 0);
}

tree::TerminalNode* PMACParser::ExprContext::MIN() {
  return getToken(PMACParser::MIN, 0);
}

tree::TerminalNode* PMACParser::ExprContext::MULT() {
  return getToken(PMACParser::MULT, 0);
}

tree::TerminalNode* PMACParser::ExprContext::DIV() {
  return getToken(PMACParser::DIV, 0);
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
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, PMACParser::RuleExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(36);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PMACParser::LPAR: {
        setState(31);
        match(PMACParser::LPAR);
        setState(32);
        expr(0);
        setState(33);
        match(PMACParser::RPAR);
        break;
      }

      case PMACParser::INTEGER:
      case PMACParser::DECIMAL:
      case PMACParser::Q_VAR:
      case PMACParser::P_VAR:
      case PMACParser::I_VAR: {
        setState(35);
        atom();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(52);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(50);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(38);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(39);
          match(PMACParser::PLUS);
          setState(40);
          expr(6);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(41);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(42);
          match(PMACParser::MIN);
          setState(43);
          expr(5);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(44);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(45);
          match(PMACParser::MULT);
          setState(46);
          expr(4);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(47);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(48);
          match(PMACParser::DIV);
          setState(49);
          expr(3);
          break;
        }

        } 
      }
      setState(54);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
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
  enterRule(_localctx, 10, PMACParser::RuleAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(57);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PMACParser::INTEGER:
      case PMACParser::DECIMAL: {
        enterOuterAlt(_localctx, 1);
        setState(55);
        number();
        break;
      }

      case PMACParser::Q_VAR:
      case PMACParser::P_VAR:
      case PMACParser::I_VAR: {
        enterOuterAlt(_localctx, 2);
        setState(56);
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
  enterRule(_localctx, 12, PMACParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(59);
    _la = _input->LA(1);
    if (!(_la == PMACParser::INTEGER

    || _la == PMACParser::DECIMAL)) {
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
  enterRule(_localctx, 14, PMACParser::RuleVar);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PMACParser::Q_VAR)
      | (1ULL << PMACParser::P_VAR)
      | (1ULL << PMACParser::I_VAR))) != 0))) {
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
    case 4: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool PMACParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);
    case 1: return precpred(_ctx, 4);
    case 2: return precpred(_ctx, 3);
    case 3: return precpred(_ctx, 2);

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
  "program", "line", "statement", "assign", "expr", "atom", "number", "var"
};

std::vector<std::string> PMACParser::_literalNames = {
  "", "", "", "'\n'", "", "", "", "", "'+'", "'='", "'-'", "'*'", "'/'", 
  "'('", "')'"
};

std::vector<std::string> PMACParser::_symbolicNames = {
  "", "INTEGER", "DECIMAL", "NL", "WS", "Q_VAR", "P_VAR", "I_VAR", "PLUS", 
  "EQ", "MIN", "MULT", "DIV", "LPAR", "RPAR"
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
    0x3, 0x10, 0x42, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x3, 0x2, 0x7, 0x2, 0x14, 0xa, 0x2, 
    0xc, 0x2, 0xe, 0x2, 0x17, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x27, 0xa, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x35, 0xa, 0x6, 0xc, 
    0x6, 0xe, 0x6, 0x38, 0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x3c, 0xa, 
    0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x2, 0x3, 0xa, 
    0xa, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x2, 0x4, 0x3, 0x2, 0x3, 
    0x4, 0x3, 0x2, 0x7, 0x9, 0x2, 0x40, 0x2, 0x15, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x18, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x8, 0x1c, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x26, 0x3, 0x2, 0x2, 0x2, 0xc, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x10, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x14, 0x5, 0x4, 0x3, 0x2, 0x13, 0x12, 0x3, 0x2, 0x2, 0x2, 
    0x14, 0x17, 0x3, 0x2, 0x2, 0x2, 0x15, 0x13, 0x3, 0x2, 0x2, 0x2, 0x15, 
    0x16, 0x3, 0x2, 0x2, 0x2, 0x16, 0x3, 0x3, 0x2, 0x2, 0x2, 0x17, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0x19, 0x5, 0x6, 0x4, 0x2, 0x19, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0x1b, 0x5, 0x8, 0x5, 0x2, 0x1b, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x1c, 0x1d, 0x5, 0x10, 0x9, 0x2, 0x1d, 0x1e, 0x7, 0xb, 0x2, 
    0x2, 0x1e, 0x1f, 0x5, 0xa, 0x6, 0x2, 0x1f, 0x9, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x21, 0x8, 0x6, 0x1, 0x2, 0x21, 0x22, 0x7, 0xf, 0x2, 0x2, 0x22, 
    0x23, 0x5, 0xa, 0x6, 0x2, 0x23, 0x24, 0x7, 0x10, 0x2, 0x2, 0x24, 0x27, 
    0x3, 0x2, 0x2, 0x2, 0x25, 0x27, 0x5, 0xc, 0x7, 0x2, 0x26, 0x20, 0x3, 
    0x2, 0x2, 0x2, 0x26, 0x25, 0x3, 0x2, 0x2, 0x2, 0x27, 0x36, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0x29, 0xc, 0x7, 0x2, 0x2, 0x29, 0x2a, 0x7, 0xa, 0x2, 
    0x2, 0x2a, 0x35, 0x5, 0xa, 0x6, 0x8, 0x2b, 0x2c, 0xc, 0x6, 0x2, 0x2, 
    0x2c, 0x2d, 0x7, 0xc, 0x2, 0x2, 0x2d, 0x35, 0x5, 0xa, 0x6, 0x7, 0x2e, 
    0x2f, 0xc, 0x5, 0x2, 0x2, 0x2f, 0x30, 0x7, 0xd, 0x2, 0x2, 0x30, 0x35, 
    0x5, 0xa, 0x6, 0x6, 0x31, 0x32, 0xc, 0x4, 0x2, 0x2, 0x32, 0x33, 0x7, 
    0xe, 0x2, 0x2, 0x33, 0x35, 0x5, 0xa, 0x6, 0x5, 0x34, 0x28, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x34, 0x2e, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x31, 0x3, 0x2, 0x2, 0x2, 0x35, 0x38, 0x3, 0x2, 0x2, 0x2, 
    0x36, 0x34, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x3, 0x2, 0x2, 0x2, 0x37, 
    0xb, 0x3, 0x2, 0x2, 0x2, 0x38, 0x36, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3c, 
    0x5, 0xe, 0x8, 0x2, 0x3a, 0x3c, 0x5, 0x10, 0x9, 0x2, 0x3b, 0x39, 0x3, 
    0x2, 0x2, 0x2, 0x3b, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3c, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0x3d, 0x3e, 0x9, 0x2, 0x2, 0x2, 0x3e, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x3f, 0x40, 0x9, 0x3, 0x2, 0x2, 0x40, 0x11, 0x3, 0x2, 0x2, 0x2, 
    0x7, 0x15, 0x26, 0x34, 0x36, 0x3b, 
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
