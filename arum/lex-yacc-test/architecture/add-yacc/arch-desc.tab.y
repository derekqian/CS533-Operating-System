%{
#include <stdio.h>
#include <string.h>
/*#include "arch-desc.lex.h"*/
%}


%token STRING NUMBER HEXVAL PMC_T ESCR_T CCCR_T REG RSET EVENT ESET ARCH CTRSZ
       TYPE_NCTR TYPE_ENABLE CONF_ENABLE CONF_PMC CONF_ESCR CONF_CCCR COLON 
       COMMA LBRACE RBRACE SEMI EOL

%union {
    int number;
    char * str;
    unsigned unsVal;
}

%token <str> STRING
%token <number> NUMBER
%token <unsVal> HEXVAL

/** not sure if I need any %type decarlations */
/*
%type <number> name ...
%type <str> name ...
*/

%left COMMA

%start arches

%%
arches:
	arches arch_desc SEMI
	;

arch_desc:
	preamble general_info reg_stmt_list event_sets RBRACE
	;

preamble:
	ARCH internal_name vendor family model LBRACE
	;

internal_name:
	STRING
	;

vendor:
	STRING
	;

family:
	NUMBER
	;	

model:
	NUMBER
	;

general_info:
	size_stmt t_nonCtr_stmt_list t_enable_stmt c_enable_stmt
	;

size_stmt:
	CTRSZ NUMBER SEMI
	;

t_nonCtr_stmt_list:
	TYPE_NCTR nonCtr_list SEMI
	;

nonCtr_list:
        nonCtr_list COMMA nonCtr_list
	| nonCtrReg 
	;

nonCtrReg:
	ESCR_T
	| CCCR_T
	;

t_enable_stmt:
	TYPE_ENABLE nonCtrReg SEMI
	;

c_enable_stmt:
	CONF_ENABLE HEXVAL SEMI
	;

reg_stmt_list:
	reg_stmt
	| reg_stmt_list reg_stmt
	;

reg_stmt:
	REG STRING reg_type NUMBER HEXVAL SEMI

reg_type:
	nonCtrReg
	| PMC_T
	;

event_sets:
	eset_components
	| event_sets eset_components
	;

eset_components:
	ESET LBRACE regset_stmt_list event_stmt_list RBRACE
	;

regset_stmt_list:
	regset_stmt
	| regset_stmt_list regset_stmt
	;

regset_stmt:
	RSET reg_name_list SEMI
	;

reg_name_list:
	reg_name_list COMMA reg_name_list
	| reg_name 
        ;

reg_name:
	STRING
	;

event_stmt_list:
	event_stmt
	| event_stmt_list event_stmt
	;

event_stmt:
	EVENT event_name event_descr escr_config cccr_config counter_config SEMI
	;

event_name:
	STRING
	;

event_descr:
	STRING
	;

escr_config:
	| CONF_ESCR HEXVAL
	;

cccr_config:
	| CONF_CCCR HEXVAL
	;

counter_config:
	| CONF_PMC HEXVAL
	;
	
%%

void
yyerror( char* msg )
{
    printf("encounterd: %s\n", msg);
}

int yyparse();
extern FILE* yyin;

int
main( int ac, char *av[] )
{
    yyin = fopen("arch-desc.txt", "r");
    yyparse();
    return 0;
}
