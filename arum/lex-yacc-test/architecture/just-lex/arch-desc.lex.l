%{
#include <stdio.h>
/*#include "arch-desc.tab.h"
#include "arch-desc.lex.h"*/
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
COMMA		,
LBRACE  	\{
RBRACE  	\}
SEMI    	;
WS		[ \t]*
COMMENT		#[^\n]*
EMPTY		^[ \t]*\n
EOL		\n

%%

{STRING}	{ printf ("STRING "); tokCount++;}
{NUMBER}	{ printf ("NUMBER "); tokCount++;}
{HEXVAL}	{ printf ("HEXVAL "); tokCount++;}
{PMC_T}		{ printf ("PMC_T ");  tokCount++;}
{ESCR_T}	{ printf ("ESCR_T "); tokCount++;}
{CCCR_T}	{ printf ("CCCR_T "); tokCount++;}
{REG}		{ printf ("REG ");    tokCount++;}
{RSET}		{ printf ("RSET ");   tokCount++;}
{EVENT}		{ printf ("EVENT ");  tokCount++;}
{ESET}		{ printf ("ESET ");   tokCount++;}
{ARCH}		{ printf ("ARCH ");   tokCount++;}
{CTRSZ}		{ printf ("CTRSZ ");  tokCount++;}
{TYPE_NCTR}	{ printf ("TYPE_NCTR "); tokCount++;}
{TYPE_ENABLE}	{ printf ("TYPE_ENABLE "); tokCount++;}
{CONF_ENABLE}	{ printf ("CONF_ENABLE "); tokCount++;}
{CONF_PMC}	{ printf ("CONF_PMC "); tokCount++;}
{CONF_ESCR}	{ printf ("CONF_ESCR "); tokCount++;}
{CONF_CCCR}	{ printf ("CONF_CCCR "); tokCount++;}
{COMMA}		{ printf ("COMMA ");  tokCount++;}
{LBRACE}	{ printf ("LBRACE "); tokCount++;} 
{RBRACE}	{ printf ("RBRACE "); tokCount++;} 
{SEMI}		{ printf ("SEMI ");   tokCount++;} 
{COMMENT}	{ printf ("COMMENT "); }
{EMPTY}		;
{EOL}		{ printf ("EOL\n"); }
{WS}		;
\r		;
.		;
%%
/*
#include <stdio.h>
#include <string.h>
*/

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
