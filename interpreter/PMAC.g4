grammar PMAC;

program
	: (lines+=line)* EOF
	;

line
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
