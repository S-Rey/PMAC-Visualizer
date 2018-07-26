
// Generated from PMAC.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  PMACLexer : public antlr4::Lexer {
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

  PMACLexer(antlr4::CharStream *input);
  ~PMACLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

