
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


//----------------- FileContext ------------------------------------------------------------------

PMACParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PMACParser::FileContext::EOF() {
  return getToken(PMACParser::EOF, 0);
}

PMACParser::NameContext* PMACParser::FileContext::name() {
  return getRuleContext<PMACParser::NameContext>(0);
}

std::vector<tree::TerminalNode *> PMACParser::FileContext::NEWLINE() {
  return getTokens(PMACParser::NEWLINE);
}

tree::TerminalNode* PMACParser::FileContext::NEWLINE(size_t i) {
  return getToken(PMACParser::NEWLINE, i);
}

std::vector<tree::TerminalNode *> PMACParser::FileContext::TAB() {
  return getTokens(PMACParser::TAB);
}

tree::TerminalNode* PMACParser::FileContext::TAB(size_t i) {
  return getToken(PMACParser::TAB, i);
}

std::vector<PMACParser::ActionContext *> PMACParser::FileContext::action() {
  return getRuleContexts<PMACParser::ActionContext>();
}

PMACParser::ActionContext* PMACParser::FileContext::action(size_t i) {
  return getRuleContext<PMACParser::ActionContext>(i);
}


size_t PMACParser::FileContext::getRuleIndex() const {
  return PMACParser::RuleFile;
}

antlrcpp::Any PMACParser::FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::FileContext* PMACParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, PMACParser::RuleFile);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(14);
    name();
    setState(15);
    match(PMACParser::NEWLINE);
    setState(23);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PMACParser::TAB) {
      setState(16);
      match(PMACParser::TAB);
      setState(17);
      dynamic_cast<FileContext *>(_localctx)->actionContext = action();
      dynamic_cast<FileContext *>(_localctx)->elements.push_back(dynamic_cast<FileContext *>(_localctx)->actionContext);
      setState(19);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PMACParser::NEWLINE) {
        setState(18);
        match(PMACParser::NEWLINE);
      }
      setState(25);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(26);
    match(PMACParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameContext ------------------------------------------------------------------

PMACParser::NameContext::NameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PMACParser::NameContext::NAME() {
  return getToken(PMACParser::NAME, 0);
}


size_t PMACParser::NameContext::getRuleIndex() const {
  return PMACParser::RuleName;
}

antlrcpp::Any PMACParser::NameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitName(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::NameContext* PMACParser::name() {
  NameContext *_localctx = _tracker.createInstance<NameContext>(_ctx, getState());
  enterRule(_localctx, 2, PMACParser::RuleName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(28);
    match(PMACParser::NAME);
    setState(29);
    match(PMACParser::T__0);
   
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

tree::TerminalNode* PMACParser::ActionContext::DRAW() {
  return getToken(PMACParser::DRAW, 0);
}

PMACParser::SizeContext* PMACParser::ActionContext::size() {
  return getRuleContext<PMACParser::SizeContext>(0);
}

PMACParser::ShapeContext* PMACParser::ActionContext::shape() {
  return getRuleContext<PMACParser::ShapeContext>(0);
}

tree::TerminalNode* PMACParser::ActionContext::IN() {
  return getToken(PMACParser::IN, 0);
}

PMACParser::ColorContext* PMACParser::ActionContext::color() {
  return getRuleContext<PMACParser::ColorContext>(0);
}

tree::TerminalNode* PMACParser::ActionContext::AT() {
  return getToken(PMACParser::AT, 0);
}

PMACParser::PositionContext* PMACParser::ActionContext::position() {
  return getRuleContext<PMACParser::PositionContext>(0);
}

tree::TerminalNode* PMACParser::ActionContext::WRITE() {
  return getToken(PMACParser::WRITE, 0);
}

tree::TerminalNode* PMACParser::ActionContext::STRING() {
  return getToken(PMACParser::STRING, 0);
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
  ActionContext *_localctx = _tracker.createInstance<ActionContext>(_ctx, getState());
  enterRule(_localctx, 4, PMACParser::RuleAction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(47);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PMACParser::DRAW: {
        enterOuterAlt(_localctx, 1);
        setState(31);
        match(PMACParser::DRAW);
        setState(32);
        size();
        setState(33);
        shape();
        setState(34);
        match(PMACParser::IN);
        setState(35);
        color();
        setState(36);
        match(PMACParser::AT);
        setState(37);
        position();
        break;
      }

      case PMACParser::WRITE: {
        enterOuterAlt(_localctx, 2);
        setState(39);
        match(PMACParser::WRITE);
        setState(40);
        size();
        setState(41);
        match(PMACParser::STRING);
        setState(42);
        match(PMACParser::IN);
        setState(43);
        color();
        setState(44);
        match(PMACParser::AT);
        setState(45);
        position();
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

//----------------- SizeContext ------------------------------------------------------------------

PMACParser::SizeContext::SizeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PMACParser::SizeContext::SMALL() {
  return getToken(PMACParser::SMALL, 0);
}

tree::TerminalNode* PMACParser::SizeContext::MEDIUM() {
  return getToken(PMACParser::MEDIUM, 0);
}

tree::TerminalNode* PMACParser::SizeContext::BIG() {
  return getToken(PMACParser::BIG, 0);
}


size_t PMACParser::SizeContext::getRuleIndex() const {
  return PMACParser::RuleSize;
}

antlrcpp::Any PMACParser::SizeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitSize(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::SizeContext* PMACParser::size() {
  SizeContext *_localctx = _tracker.createInstance<SizeContext>(_ctx, getState());
  enterRule(_localctx, 6, PMACParser::RuleSize);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PMACParser::SMALL)
      | (1ULL << PMACParser::MEDIUM)
      | (1ULL << PMACParser::BIG))) != 0))) {
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

//----------------- ShapeContext ------------------------------------------------------------------

PMACParser::ShapeContext::ShapeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PMACParser::ShapeContext::CIRCLE() {
  return getToken(PMACParser::CIRCLE, 0);
}

tree::TerminalNode* PMACParser::ShapeContext::SQUARE() {
  return getToken(PMACParser::SQUARE, 0);
}


size_t PMACParser::ShapeContext::getRuleIndex() const {
  return PMACParser::RuleShape;
}

antlrcpp::Any PMACParser::ShapeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitShape(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::ShapeContext* PMACParser::shape() {
  ShapeContext *_localctx = _tracker.createInstance<ShapeContext>(_ctx, getState());
  enterRule(_localctx, 8, PMACParser::RuleShape);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(51);
    _la = _input->LA(1);
    if (!(_la == PMACParser::CIRCLE

    || _la == PMACParser::SQUARE)) {
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

//----------------- ColorContext ------------------------------------------------------------------

PMACParser::ColorContext::ColorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PMACParser::ColorContext::BLACK() {
  return getToken(PMACParser::BLACK, 0);
}

tree::TerminalNode* PMACParser::ColorContext::BLUE() {
  return getToken(PMACParser::BLUE, 0);
}

tree::TerminalNode* PMACParser::ColorContext::BROWN() {
  return getToken(PMACParser::BROWN, 0);
}

tree::TerminalNode* PMACParser::ColorContext::GREEN() {
  return getToken(PMACParser::GREEN, 0);
}

tree::TerminalNode* PMACParser::ColorContext::RED() {
  return getToken(PMACParser::RED, 0);
}

tree::TerminalNode* PMACParser::ColorContext::ORANGE() {
  return getToken(PMACParser::ORANGE, 0);
}

tree::TerminalNode* PMACParser::ColorContext::PURPLE() {
  return getToken(PMACParser::PURPLE, 0);
}

tree::TerminalNode* PMACParser::ColorContext::YELLOW() {
  return getToken(PMACParser::YELLOW, 0);
}

tree::TerminalNode* PMACParser::ColorContext::WHITE() {
  return getToken(PMACParser::WHITE, 0);
}


size_t PMACParser::ColorContext::getRuleIndex() const {
  return PMACParser::RuleColor;
}

antlrcpp::Any PMACParser::ColorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitColor(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::ColorContext* PMACParser::color() {
  ColorContext *_localctx = _tracker.createInstance<ColorContext>(_ctx, getState());
  enterRule(_localctx, 10, PMACParser::RuleColor);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PMACParser::BLACK)
      | (1ULL << PMACParser::BLUE)
      | (1ULL << PMACParser::BROWN)
      | (1ULL << PMACParser::GREEN)
      | (1ULL << PMACParser::RED)
      | (1ULL << PMACParser::ORANGE)
      | (1ULL << PMACParser::PURPLE)
      | (1ULL << PMACParser::YELLOW)
      | (1ULL << PMACParser::WHITE))) != 0))) {
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

//----------------- PositionContext ------------------------------------------------------------------

PMACParser::PositionContext::PositionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PMACParser::PositionContext::LEFT() {
  return getToken(PMACParser::LEFT, 0);
}

std::vector<tree::TerminalNode *> PMACParser::PositionContext::CENTER() {
  return getTokens(PMACParser::CENTER);
}

tree::TerminalNode* PMACParser::PositionContext::CENTER(size_t i) {
  return getToken(PMACParser::CENTER, i);
}

tree::TerminalNode* PMACParser::PositionContext::RIGHT() {
  return getToken(PMACParser::RIGHT, 0);
}

tree::TerminalNode* PMACParser::PositionContext::TOP() {
  return getToken(PMACParser::TOP, 0);
}

tree::TerminalNode* PMACParser::PositionContext::BOTTOM() {
  return getToken(PMACParser::BOTTOM, 0);
}


size_t PMACParser::PositionContext::getRuleIndex() const {
  return PMACParser::RulePosition;
}

antlrcpp::Any PMACParser::PositionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PMACVisitor*>(visitor))
    return parserVisitor->visitPosition(this);
  else
    return visitor->visitChildren(this);
}

PMACParser::PositionContext* PMACParser::position() {
  PositionContext *_localctx = _tracker.createInstance<PositionContext>(_ctx, getState());
  enterRule(_localctx, 12, PMACParser::RulePosition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(55);
    dynamic_cast<PositionContext *>(_localctx)->x = _input->LT(1);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PMACParser::LEFT)
      | (1ULL << PMACParser::RIGHT)
      | (1ULL << PMACParser::CENTER))) != 0))) {
      dynamic_cast<PositionContext *>(_localctx)->x = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(56);
    match(PMACParser::T__1);
    setState(57);
    dynamic_cast<PositionContext *>(_localctx)->y = _input->LT(1);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PMACParser::CENTER)
      | (1ULL << PMACParser::TOP)
      | (1ULL << PMACParser::BOTTOM))) != 0))) {
      dynamic_cast<PositionContext *>(_localctx)->y = _errHandler->recoverInline(this);
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

// Static vars and initialization.
std::vector<dfa::DFA> PMACParser::_decisionToDFA;
atn::PredictionContextCache PMACParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN PMACParser::_atn;
std::vector<uint16_t> PMACParser::_serializedATN;

std::vector<std::string> PMACParser::_ruleNames = {
  "file", "name", "action", "size", "shape", "color", "position"
};

std::vector<std::string> PMACParser::_literalNames = {
  "", "':'", "','", "'draw'", "'write'", "'in'", "'at'", "'circle'", "'square'", 
  "'small'", "'medium'", "'big'", "'left'", "'right'", "'center'", "'top'", 
  "'bottom'", "", "'black'", "'blue'", "'brown'", "'green'", "'red'", "'orange'", 
  "'purple'", "'yellow'", "'white'", "", "", "", "' '"
};

std::vector<std::string> PMACParser::_symbolicNames = {
  "", "", "", "DRAW", "WRITE", "IN", "AT", "CIRCLE", "SQUARE", "SMALL", 
  "MEDIUM", "BIG", "LEFT", "RIGHT", "CENTER", "TOP", "BOTTOM", "STRING", 
  "BLACK", "BLUE", "BROWN", "GREEN", "RED", "ORANGE", "PURPLE", "YELLOW", 
  "WHITE", "NAME", "NEWLINE", "TAB", "WHITESPACE"
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
    0x3, 0x20, 0x3e, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 
    0x2, 0x16, 0xa, 0x2, 0x7, 0x2, 0x18, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x1b, 
    0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x5, 0x4, 0x32, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x2, 0x2, 0x9, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x2, 0x7, 0x3, 
    0x2, 0xb, 0xd, 0x3, 0x2, 0x9, 0xa, 0x3, 0x2, 0x14, 0x1c, 0x3, 0x2, 0xe, 
    0x10, 0x3, 0x2, 0x10, 0x12, 0x2, 0x39, 0x2, 0x10, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x6, 0x31, 0x3, 0x2, 0x2, 0x2, 0x8, 0x33, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x35, 0x3, 0x2, 0x2, 0x2, 0xc, 0x37, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x39, 0x3, 0x2, 0x2, 0x2, 0x10, 0x11, 0x5, 0x4, 0x3, 
    0x2, 0x11, 0x19, 0x7, 0x1e, 0x2, 0x2, 0x12, 0x13, 0x7, 0x1f, 0x2, 0x2, 
    0x13, 0x15, 0x5, 0x6, 0x4, 0x2, 0x14, 0x16, 0x7, 0x1e, 0x2, 0x2, 0x15, 
    0x14, 0x3, 0x2, 0x2, 0x2, 0x15, 0x16, 0x3, 0x2, 0x2, 0x2, 0x16, 0x18, 
    0x3, 0x2, 0x2, 0x2, 0x17, 0x12, 0x3, 0x2, 0x2, 0x2, 0x18, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0x19, 0x17, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1a, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x1d, 0x7, 0x2, 0x2, 0x3, 0x1d, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x1f, 0x7, 0x1d, 0x2, 0x2, 0x1f, 0x20, 0x7, 0x3, 0x2, 0x2, 0x20, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x21, 0x22, 0x7, 0x5, 0x2, 0x2, 0x22, 0x23, 
    0x5, 0x8, 0x5, 0x2, 0x23, 0x24, 0x5, 0xa, 0x6, 0x2, 0x24, 0x25, 0x7, 
    0x7, 0x2, 0x2, 0x25, 0x26, 0x5, 0xc, 0x7, 0x2, 0x26, 0x27, 0x7, 0x8, 
    0x2, 0x2, 0x27, 0x28, 0x5, 0xe, 0x8, 0x2, 0x28, 0x32, 0x3, 0x2, 0x2, 
    0x2, 0x29, 0x2a, 0x7, 0x6, 0x2, 0x2, 0x2a, 0x2b, 0x5, 0x8, 0x5, 0x2, 
    0x2b, 0x2c, 0x7, 0x13, 0x2, 0x2, 0x2c, 0x2d, 0x7, 0x7, 0x2, 0x2, 0x2d, 
    0x2e, 0x5, 0xc, 0x7, 0x2, 0x2e, 0x2f, 0x7, 0x8, 0x2, 0x2, 0x2f, 0x30, 
    0x5, 0xe, 0x8, 0x2, 0x30, 0x32, 0x3, 0x2, 0x2, 0x2, 0x31, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0x31, 0x29, 0x3, 0x2, 0x2, 0x2, 0x32, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x33, 0x34, 0x9, 0x2, 0x2, 0x2, 0x34, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0x35, 0x36, 0x9, 0x3, 0x2, 0x2, 0x36, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x37, 0x38, 0x9, 0x4, 0x2, 0x2, 0x38, 0xd, 0x3, 0x2, 0x2, 0x2, 0x39, 
    0x3a, 0x9, 0x5, 0x2, 0x2, 0x3a, 0x3b, 0x7, 0x4, 0x2, 0x2, 0x3b, 0x3c, 
    0x9, 0x6, 0x2, 0x2, 0x3c, 0xf, 0x3, 0x2, 0x2, 0x2, 0x5, 0x15, 0x19, 
    0x31, 
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
