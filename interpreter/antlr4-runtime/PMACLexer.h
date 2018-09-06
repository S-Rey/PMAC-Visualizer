
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

