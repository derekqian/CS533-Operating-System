%{
%}

%union {
    int number;
    char * str;
    unsigned unsVal;
}

%type <stri> name string capability location password
%type <user> user_id


%token STRING NUMBER HEXVAL PMC_T ESCR_T CCCR_T REG RSET EVENT ESET ARCH CTRSZ
       TYPE_NCTR TYPE_ENABLE CONF_ENABLE CONF_PMC CONF_ESCR CONF_CCCR COLON 
       COMMA LBRACE RBRACE SEMI EOL

%left COMMA

%start arches

%%
arches		:
		|
		arches arch_desc SEMI
		;

arch_desc	:
		ARCH STRING STRING NUMBER NUMBER
user_list:	user_list user
		{ 
		}
	|	user
		{ 
		}
	;

user	:	user_id COLON password COLON capability COLON location COLON name_list EOL
		{ 
		}
	|	user_id COLON password COLON capability COLON location COLON EOL
		{ 
		}
	;

user_id:	name
		{
		}
	;

password:	name
		{
		}
	|	string
		{
		}
	|
		{
		}
	;

capability:	name
		{
		}
	|
		{
		}
	;

location:	string
		{
		}
	|
		{
		}
	;

name_list:	name_list COMMA name_list
		{ 
		}
	|	name
		{ 
		}
	;

name:		NAME
		{
		    $$ = new char[ strlen(yytext)+1 ];
		    strcpy( $$, yytext );
		}
	;

string:		STRING
		{
		    int len = strlen(yytext) - 2;
		    $$ = new char[ len+1 ];
		    strncpy( $$, yytext+1, len );
		    $$[len] = '\0';
		}
	;
%%

#include <stdio.h>
#include <string.h>
#include "Interrupts.lex.h"

void
yyerror( char* msg )
{
    printf("%s\n", msg);
}


#if defined(UNDEFINED)
#define BOB  "accounts.alf"

int yyparse();

extern FILE* yyin;

int
main( int ac, char *av[] )
{
    yyin = fopen(BOB, "r");
    yyparse();

    return 0;
}
#endif
