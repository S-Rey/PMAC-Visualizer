grammar PMAC;


///////////////// PARSER /////////////////

program
    : (lines+=line)* EOF
    ;

line
    : statement NL?
    | NL
    ;

statement
    : action                                        // setting variable
    | ifStatement
    | whileStatement
    ;

action
    : assign
    | leftAction=action rightAction=action
    ;

ifStatement
    : IF LPAR condition RPAR ifAction=action        // single line action
    | IF LPAR condition RPAR NL (ifLines+=line)+
      (ELSE elseAction=action NL | ELSE NL (elseLines+=line)+)?
      ENDIF
    ;

whileStatement
    : WHILE LPAR condition RPAR
        (whileAction=action
        | NL (whileLines+=line)+ ENDWHILE)
    ;

data
    : constant
    | LPAR expr RPAR
    ;

constant
    :
    ;

assign
    : var EQ expr
    ;

expr
    : LPAR center=expr RPAR
    | left=expr op right=expr
    | MIN minExpr=expr
    | function LPAR center=expr RPAR
    | atom
    ;

condition
    : left=expr comparator right=expr
    ;

op
    : PLUS
    | MIN
    | MULT
    | DIV
    | MOD
    | AND_OP
    | OR_OP
    | XOR
    ;

comparator
    : EQ
    | NEQ
    | LT
    | GT
    | NLT
    | NGT
    ;

axis
    : AX_X
    | AX_Y
    | AX_Z
    | AX_A
    | AX_B
    | AX_C
    | AX_U
    | AX_V
    | AX_W
    ;

atom
    : number
    | var
    ;

number
    : INTEGER
    | DECIMAL
    | HEX
    ;

var
    : Q_VAR
    | P_VAR
    | I_VAR
    | M_VAR
    ;

function
    : SIN
    | COS
    | TAN
    | ASIN
    | ACOS
    | ATAN
    | ATAN2
    | LN
    | EXP
    | SQRT
    | ABS
    | INT
    ;


///////////////// LEXER /////////////////

// If Condition
IF       : I F            ;
ELSE     : E L S E        ;
ENDIF    : E N D I F      ;
WHILE    : W H I L E      ;
ENDWHILE : E N D W H I L E;
AND      : A N D          ;
OR       : O R            ;

// Variables
Q_VAR   : Q [0-9][0-9]?[0-9]?;
P_VAR   : P [0-9][0-9]?[0-9]?;
I_VAR   : I [0-9][0-9]?[0-9]?;
M_VAR   : M [0-9][0-9]?[0-9]?;

// Functions
SIN   : S I N      ;
COS   : C O S      ;
TAN   : T A N      ;
ASIN  : A S I N    ;
ACOS  : A C O S    ;
ATAN  : A T A N    ;
ATAN2 : A T A N '2';
LN    : L N        ;
EXP   : E X P      ;
SQRT  : S Q R T    ;
ABS   : A B S      ;
INT   : I N T      ;

// Move mode commands
LINEAR  : L I N E A R    ;
RAPID   : R A P I D      ;
CIRCLE1 : C I R C L E '1';
CIRCLE2 : C I R C L E '2';
//PVT
SPLINE1 : S P L I N E '1';
SPLINE2 : S P L I N E '2';
CC0     : C C '0'        ;
CC1     : C C '1'        ;
CC2     : C C '2'        ;
CC3     : C C '3'        ;

// Axis
AX_X : X;
AX_Y : Y;
AX_Z : Z;
AX_A : A;
AX_B : B;
AX_C : C;
AX_U : U;
AX_V : V;
AX_W : W;

// Numbers
fragment DIGIT    : [0-9];
fragment HEXDIGIT : [a-f] | [A-F] | DIGIT;
INTEGER : DIGIT+;
DECIMAL : DIGIT*'.'DIGIT+;
HEX     : '$'HEXDIGIT+;

// Operators
PLUS   : '+' ;
MIN    : '-' ;
MULT   : '*' ;
DIV    : '/' ;
MOD    : '%' ;
AND_OP : '&' ;
OR_OP  : '|' ;
XOR    : '^' ;

// Comparators ('~' and '!~' not implemented)
EQ    : '=' ;
NEQ   : '!=';
LT    : '<' ;
GT    : '>' ;
NLT   : '!<';
NGT   : '!>';

// Parenthesis
LPAR  : '(' ;
RPAR  : ')' ;

// White spaces and newlines
NL      : '\n'                ;
COMMENT : ';' ~[\r\n]* -> skip;
WS      : [ \t\r]+     -> skip;

////////////////////////////
// For case insensitivity //
////////////////////////////
fragment A : [aA]; // match either an 'a' or 'A'
fragment B : [bB];
fragment C : [cC];
fragment D : [dD];
fragment E : [eE];
fragment F : [fF];
fragment G : [gG];
fragment H : [hH];
fragment I : [iI];
fragment J : [jJ];
fragment K : [kK];
fragment L : [lL];
fragment M : [mM];
fragment N : [nN];
fragment O : [oO];
fragment P : [pP];
fragment Q : [qQ];
fragment R : [rR];
fragment S : [sS];
fragment T : [tT];
fragment U:  [uU];
fragment V : [vV];
fragment W : [wW];
fragment X : [xX];
fragment Y : [yY];
fragment Z : [zZ];
