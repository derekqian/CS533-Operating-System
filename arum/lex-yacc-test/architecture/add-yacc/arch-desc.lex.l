%{
/*#include "arch-desc.tab.h"*/
#include "y.tab.h"
/*#include "arch-desc.lex.h"*/
#include <stdio.h>
#include <string.h>
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

{STRING}	{ yylval.str = strdup(yytext); return STRING; }
{NUMBER}	{ yylval.number=atoi(yytext); return NUMBER; }
{HEXVAL}	{ yylval.unsVal=(unsigned)atoi(yytext); return HEXVAL; }
{PMC_T}		{ return PMC_T;  }
{ESCR_T}	{ return ESCR_T; }
{CCCR_T}	{ return CCCR_T; }
{REG}		{ return REG;    }
{RSET}		{ return RSET;   }
{EVENT}		{ return EVENT;  }
{ESET}		{ return ESET;   }
{ARCH}		{ return ARCH;   }
{CTRSZ}		{ return CTRSZ;  }
{TYPE_NCTR}	{ return TYPE_NCTR; }
{TYPE_ENABLE}	{ return TYPE_ENABLE; }
{CONF_ENABLE}	{ return CONF_ENABLE; }
{CONF_PMC}	{ return CONF_PMC; }
{CONF_ESCR}	{ return CONF_ESCR; }
{CONF_CCCR}	{ return CONF_CCCR; }
{COMMA}		{ return COMMA;  }
{LBRACE}	{ return LBRACE; } 
{RBRACE}	{ return RBRACE; } 
{SEMI}		{ return SEMI;   } 
{COMMENT}	;
{EMPTY}		;
{EOL}		{ return EOL; }
{WS}		;
\r		;
.		;

%%
int
yywrap()
{
    return 1;
}

