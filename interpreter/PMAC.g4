grammar PMAC;

//
//input
//    : setVar NL input     # ToSetVar
//    | plusOrMinus NL? EOF # Calculate
//    ;
//
//setVar
//    : ID EQUAL plusOrMinus # SetVariable
//    ;
//
//
//plusOrMinus 
//    : plusOrMinus PLUS multOrDiv  # Plus
//    | plusOrMinus MINUS multOrDiv # Minus
//    | multOrDiv                   # ToMultOrDiv
//    ;
//
//multOrDiv
//    : multOrDiv MULT pow # Multiplication
//    | multOrDiv DIV pow  # Division
//    | pow                # ToPow
//    ;
//
//pow
//    : unaryMinus (POW pow)? # Power
//    ;
//
//unaryMinus
//    : MINUS unaryMinus # ChangeSign
//    | atom             # ToAtom
//    ;
//
//atom
//    : INTEGER               
//    | DECIMAL
//    | ID                    # Variable
//    | LPAR plusOrMinus RPAR # Braces
//;

program
	: line*
	;

line
	: statement
	;

statement
	: assign
	;

assign
	: var EQ expr
	;

expr
	: LPAR expr RPAR
	| expr PLUS expr
	| expr MIN	expr
	| expr MULT	expr
	| expr DIV 	expr
	| atom
	//| substraction
	//| multiplication
	//| division
	;

	
atom
	: number
	| var
	;	

number
	: INTEGER
	| DECIMAL
	;
	
var 
	: Q_VAR
	| P_VAR
	| I_VAR
	;

	
	


INTEGER : [0-9]+;
DECIMAL : [0-9]+'.'[0-9]+;
NL      : '\n';			// Include command in NL => maybe ';'.?*'\n'
WS      : [ \t\r]+ -> skip;

Q_VAR	: 'Q'[0-9][0-9][0-9];
P_VAR	: 'P'[0-9][0-9][0-9];
I_VAR	: 'I'[0-9][0-9][0-9];

PLUS  : '+';
EQ    : '=';
MIN   : '-';
MULT  : '*';
DIV   : '/';
LPAR  : '(';
RPAR : ')';