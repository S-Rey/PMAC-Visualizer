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
    | moveCmds
    | axisAttrCmds
    | leftAction=action rightAction=action
    ;

ifStatement
    : IF compoundCondition ifAction=action        // single line action
      (NL ELSE elseAction=action)?
    | IF compoundCondition NL (ifLines+=line)+
      (ELSE elseAction=action NL | ELSE NL (elseLines+=line)+)?
      ENDIF
    ;

whileStatement
    : WHILE compoundCondition
        (whileAction=action
        |NL (whileLines+=line)+ ENDWHILE)
    ;

compoundCondition
    : LPAR center=compoundCondition RPAR
    | left=compoundCondition NL? logicalOp=AND right=compoundCondition // AND has higher precedence than OR
    | left=compoundCondition NL? logicalOp=OR  right=compoundCondition
    | condition
    ;

condition
    : left=expr comparator right=expr
    ;

data
    : constant
    | LPAR expr RPAR
    ;

constant
    :
    ;

assign
    : var EQ EQ expr
    | var EQ expr
    ;

moveCmds
	: (listSimple+=moveCmdSimple)+						// LINEAR, RAPID, SPLINE
	| (listVelocity+=moveCmdVelocity)+ 						// PVT
	//| (axis position+=expr caret=XOR expr)+ 			// RAPID
	//| (axis expr)+ (vectorCoordinate expr)+			// CIRCLE
	//| (axis expr)+ RADIUS expr						// CIRCLE
	| modeMoveCmds
	;

moveCmdSimple
	: (axis expr)
	;

moveCmdVelocity
	: (axis position=expr COLON velocity=expr)
	;


axisAttrCmds
	: ABS (LPAR axisList+=axis (COMMA axisList+=axis)* RPAR)?
	| INC (LPAR axisList+=axis (COMMA axisList+=axis)* RPAR)?
	| FRAX (LPAR axisList+=axis (COMMA axisList+=axis)* RPAR)?
	;


expr
    : LPAR center=expr RPAR
    | function LPAR argument=expr RPAR
    | MIN minExpr=expr
    | left=expr op=(MULT | DIV | MOD) right=expr
    | left=expr op=(PLUS | MIN)       right=expr
    | left=expr op=AND_OP             right=expr
    | left=expr op=XOR                right=expr
    | left=expr op=OR_OP              right=expr
    | atom
    ;

modeMoveCmds
	: LINEAR
	| RAPID
	| CIRCLE1
	| CIRCLE2
	| PVT
	| SPLINE1
	| SPLINE2
	| CC0
	| CC1
	| CC2
	| CC3
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
    | RADIUS
    ;

vectorCoordinate
	: V_I
	| V_J
	| V_K
	;

comparator
    : EQ
    | NEQ
    | LT
    | GT
    | NLT
    | NGT
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
PVT     : P V T			 ;
SPLINE1 : S P L I N E '1';
SPLINE2 : S P L I N E '2';
CC0     : C C '0'        ;
CC1     : C C '1'        ;
CC2     : C C '2'        ;
CC3     : C C '3'        ;

DWELL   : D W E L L 	 ;
DELAY   : D E L A Y 	 ;
HOME    : H O M E        ;
HOMEZ   : H O M E Z      ;


// Axis attribute commands
INC : I N C;
FRAX : F R A X;
NOFRAX : N O F R A X;
NORMAL : N O R M A L;
PSET : P S E T;


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

// Vector Coordinates
V_I : I;
V_J : J;
V_K : K;

// Radius
RADIUS : R;

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

// Other
COLON 	 : ':';
SEMIOLON : ';';
COMMA	 : ',';

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
