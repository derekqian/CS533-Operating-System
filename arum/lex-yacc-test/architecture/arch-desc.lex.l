%{
#include "arch-desc.tab.h"
#include "arch-desc.lex.h"
#include <stdio.h>
#include <string.h>
int tokCount = 0;
%}

STRING		["][^"\n]*["]
NUMBER		[0-9]+
HEXVAL		[0][xX][0-9a-fA-F]+
PMC_T		PMC
ESCR_T		ESCR
CCCR_T		CCCR
REG		register
RSET		reg_set
EVENT		event
ESET		event_set
ARCH		arch
CTRSZ   	size_ctr
TYPE_NCTR	type_nonctr
TYPE_ENABLE	type_enable
CONF_ENABLE	conf_enable
CONF_PMC	conf_pmc
CONF_ESCR	conf_escr
CONF_CCCR	conf_cccr
COMMA	,
LBRACE  \{
RBRACE  \}
SEMI    ;
WS	[ \t]*
COMMENT	#[^\n]*\n
EMPTY	^[ \t]*\n
EOL	\n

%%

{STRING}	{ tokCount++; return STRING; }
{NUMBER}	{ tokCount++; return NUMBER; }
{HEXVAL}	{ tokCount++; return HEXVAL; }
{PMC_T}		{ tokCount++; return PMC_T;  }
{ESCR_T}	{ tokCount++; return ESCR_T; }
{CCCR_T}	{ tokCount++; return CCCR_T; }
{REG}		{ tokCount++; return REG;    }
{RSET}		{ tokCount++; return RSET;   }
{EVENT}		{ tokCount++; return EVENT;  }
{ESET}		{ tokCount++; return ESET;   }
{ARCH}		{ tokCount++; return ARCH;   }
{CTRSZ}		{ tokCount++; return CTRSZ;  }
{TYPE_NCTR}	{ tokCount++; return TYPE_NCTR; }
{TYPE_ENABLE}	{ tokCount++; return TYPE_ENABLE; }
{CONF_ENABLE}	{ tokCount++; return CONF_ENABLE; }
{CONF_PMC}	{ tokCount++; return CONF_PMC; }
{CONF_ESCR}	{ tokCount++; ; return CONF_ESCR; }
{CONF_CCCR}	{ tokCount++; return CONF_CCCR; }
{COMMA}		{ tokCount++; return COMMA;  }
{LBRACE}	{ tokCount++; return LBRACE; } 
{RBRACE}	{ tokCount++; return RBRACE; } 
{SEMI}		{ tokCount++; return SEMI;   } 
{COMMENT}	;
{EMPTY}		;
{EOL}		{ return EOL; }
{WS}		;
\r		;
.		;
%%
int main(void) {
   yylex();
   printf ("%d tokens\n", tokCount);
   return 0;
}

int
yywrap()
{
    return 1;
}

int
yywrap()
{
    return 1;
}
