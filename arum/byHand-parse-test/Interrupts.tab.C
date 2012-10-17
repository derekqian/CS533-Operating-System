/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with Interrupts_ or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum Interrupts_tokentype {
     NAME = 258,
     STRING = 259,
     COLON = 260,
     COMMA = 261,
     EOL = 262
   };
#endif
/* Tokens.  */
#define NAME 258
#define STRING 259
#define COLON 260
#define COMMA 261
#define EOL 262




/* Copy the first part of user declarations.  */
#line 1 "Interrupts.tab.y"



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 4 "Interrupts.tab.y"
typedef union YYSTYPE {
    char* stri;
} YYSTYPE;
/* Line 196 of yacc.c.  */
#line 106 "Interrupts.tab.y"
# define Interrupts_stype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 118 "Interrupts.tab.y"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#if ! defined (Interrupts_overflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (Interrupts_overflow) || YYERROR_VERBOSE */


#if (! defined (Interrupts_overflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union Interrupts_alloc
{
  short int Interrupts_ss;
  YYSTYPE Interrupts_vs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union Interrupts_alloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T Interrupts_i;				\
	  for (Interrupts_i = 0; Interrupts_i < (Count); Interrupts_i++)	\
	    (To)[Interrupts_i] = (From)[Interrupts_i];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T Interrupts_newbytes;						\
	YYCOPY (&Interrupts_ptr->Stack, Stack, Interrupts_size);				\
	Stack = &Interrupts_ptr->Stack;						\
	Interrupts_newbytes = Interrupts_stacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	Interrupts_ptr += Interrupts_newbytes / sizeof (*Interrupts_ptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char Interrupts_signed_char;
#else
   typedef short int Interrupts_signed_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   19

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  8
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  11
/* YYNRULES -- Number of rules. */
#define YYNRULES  19
/* YYNRULES -- Number of states. */
#define YYNSTATES  27

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   262

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? Interrupts_translate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char Interrupts_translate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned char Interrupts_prhs[] =
{
       0,     0,     3,     5,     6,     9,    11,    22,    32,    34,
      36,    38,    39,    41,    42,    44,    45,    49,    51,    53
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const Interrupts_signed_char Interrupts_rhs[] =
{
       9,     0,    -1,    10,    -1,    -1,    10,    11,    -1,    11,
      -1,    12,     5,    13,     5,    14,     5,    15,     5,    16,
       7,    -1,    12,     5,    13,     5,    14,     5,    15,     5,
       7,    -1,    17,    -1,    17,    -1,    18,    -1,    -1,    17,
      -1,    -1,    18,    -1,    -1,    16,     6,    16,    -1,    17,
      -1,     3,    -1,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned char Interrupts_rline[] =
{
       0,    18,    18,    22,    26,    29,    34,    37,    42,    47,
      50,    54,    58,    62,    66,    70,    74,    77,    82,    89
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const Interrupts_tname[] =
{
  "$end", "error", "$undefined", "NAME", "STRING", "COLON", "COMMA",
  "EOL", "$accept", "start", "user_list", "user", "user_id", "password",
  "capability", "location", "name_list", "name", "string", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int Interrupts_toknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char Interrupts_r1[] =
{
       0,     8,     9,     9,    10,    10,    11,    11,    12,    13,
      13,    13,    14,    14,    15,    15,    16,    16,    17,    18
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char Interrupts_r2[] =
{
       0,     2,     1,     0,     2,     1,    10,     9,     1,     1,
       1,     0,     1,     0,     1,     0,     3,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char Interrupts_defact[] =
{
       3,    18,     0,     2,     5,     0,     8,     1,     4,    11,
      19,     0,     9,    10,    13,     0,    12,    15,     0,    14,
       0,     7,     0,    17,     0,     6,    16
};

/* YYDEFGOTO[NTERM-NUM]. */
static const Interrupts_signed_char Interrupts_defgoto[] =
{
      -1,     2,     3,     4,     5,    11,    15,    18,    22,     6,
      13
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -10
static const Interrupts_signed_char Interrupts_pact[] =
{
      -2,   -10,     9,    -2,   -10,     5,   -10,   -10,   -10,     0,
     -10,     7,   -10,   -10,    -2,     8,   -10,    10,    11,   -10,
      -1,   -10,     1,   -10,    -2,   -10,   -10
};

/* YYPGOTO[NTERM-NUM].  */
static const Interrupts_signed_char Interrupts_pgoto[] =
{
     -10,   -10,   -10,    14,   -10,   -10,   -10,   -10,    -6,    -9,
       2
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned char Interrupts_table[] =
{
      12,     1,     1,     1,    10,    16,    21,    24,    25,     7,
       9,    23,    14,    17,    10,    23,    20,     8,    26,    19
};

static const unsigned char Interrupts_check[] =
{
       9,     3,     3,     3,     4,    14,     7,     6,     7,     0,
       5,    20,     5,     5,     4,    24,     5,     3,    24,    17
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char Interrupts_stos[] =
{
       0,     3,     9,    10,    11,    12,    17,     0,    11,     5,
       4,    13,    17,    18,     5,    14,    17,     5,    15,    18,
       5,     7,    16,    17,     6,     7,    16
};

#define Interrupts_errok		(Interrupts_errstatus = 0)
#define Interrupts_clearin	(Interrupts_char = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto Interrupts_acceptlab
#define YYABORT		goto Interrupts_abortlab
#define YYERROR		goto Interrupts_errorlab


/* Like YYERROR except do call Interrupts_error.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto Interrupts_errlab

#define YYRECOVERING()  (!!Interrupts_errstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (Interrupts_char == YYEMPTY && Interrupts_len == 1)				\
    {								\
      Interrupts_char = (Token);						\
      Interrupts_lval = (Value);						\
      Interrupts_token = YYTRANSLATE (Interrupts_char);				\
      YYPOPSTACK;						\
      goto Interrupts_backup;						\
    }								\
  else								\
    {								\
      Interrupts_error (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
              (Loc).first_line, (Loc).first_column,	\
              (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `Interrupts_lex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX Interrupts_lex (YYLEX_PARAM)
#else
# define YYLEX Interrupts_lex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (Interrupts_debug)					\
    YYFPRINTF Args;				\
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (Interrupts_debug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      Interrupts_symprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| Interrupts__stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
Interrupts__stack_print (short int *bottom, short int *top)
#else
static void
Interrupts__stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (Interrupts_debug)							\
    Interrupts__stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
Interrupts__reduce_print (int Interrupts_rule)
#else
static void
Interrupts__reduce_print (Interrupts_rule)
    int Interrupts_rule;
#endif
{
  int Interrupts_i;
  unsigned long int Interrupts_lno = Interrupts_rline[Interrupts_rule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             Interrupts_rule - 1, Interrupts_lno);
  /* Print the symbols being reduced, and their result.  */
  for (Interrupts_i = Interrupts_prhs[Interrupts_rule]; 0 <= Interrupts_rhs[Interrupts_i]; Interrupts_i++)
    YYFPRINTF (stderr, "%s ", Interrupts_tname[Interrupts_rhs[Interrupts_i]]);
  YYFPRINTF (stderr, "-> %s\n", Interrupts_tname[Interrupts_r1[Interrupts_rule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (Interrupts_debug)				\
    Interrupts__reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int Interrupts_debug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef Interrupts_strlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define Interrupts_strlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
Interrupts_strlen (const char *Interrupts_str)
#   else
Interrupts_strlen (Interrupts_str)
     const char *Interrupts_str;
#   endif
{
  const char *Interrupts_s = Interrupts_str;

  while (*Interrupts_s++ != '\0')
    continue;

  return Interrupts_s - Interrupts_str - 1;
}
#  endif
# endif

# ifndef Interrupts_stpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define Interrupts_stpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
Interrupts_stpcpy (char *Interrupts_dest, const char *Interrupts_src)
#   else
Interrupts_stpcpy (Interrupts_dest, Interrupts_src)
     char *Interrupts_dest;
     const char *Interrupts_src;
#   endif
{
  char *Interrupts_d = Interrupts_dest;
  const char *Interrupts_s = Interrupts_src;

  while ((*Interrupts_d++ = *Interrupts_s++) != '\0')
    continue;

  return Interrupts_d - 1;
}
#  endif
# endif

# ifndef Interrupts_tnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for Interrupts_error.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from Interrupts_tname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
Interrupts_tnamerr (char *Interrupts_res, const char *Interrupts_str)
{
  if (*Interrupts_str == '"')
    {
      size_t Interrupts_n = 0;
      char const *Interrupts_p = Interrupts_str;

      for (;;)
	switch (*++Interrupts_p)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++Interrupts_p != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (Interrupts_res)
	      Interrupts_res[Interrupts_n] = *Interrupts_p;
	    Interrupts_n++;
	    break;

	  case '"':
	    if (Interrupts_res)
	      Interrupts_res[Interrupts_n] = '\0';
	    return Interrupts_n;
	  }
    do_not_strip_quotes: ;
    }

  if (! Interrupts_res)
    return Interrupts_strlen (Interrupts_str);

  return Interrupts_stpcpy (Interrupts_res, Interrupts_str) - Interrupts_res;
}
# endif

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
Interrupts_symprint (FILE *Interrupts_output, int Interrupts_type, YYSTYPE *Interrupts_valuep)
#else
static void
Interrupts_symprint (Interrupts_output, Interrupts_type, Interrupts_valuep)
    FILE *Interrupts_output;
    int Interrupts_type;
    YYSTYPE *Interrupts_valuep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) Interrupts_valuep;

  if (Interrupts_type < YYNTOKENS)
    YYFPRINTF (Interrupts_output, "token %s (", Interrupts_tname[Interrupts_type]);
  else
    YYFPRINTF (Interrupts_output, "nterm %s (", Interrupts_tname[Interrupts_type]);


# ifdef YYPRINT
  if (Interrupts_type < YYNTOKENS)
    YYPRINT (Interrupts_output, Interrupts_toknum[Interrupts_type], *Interrupts_valuep);
# endif
  switch (Interrupts_type)
    {
      default:
        break;
    }
  YYFPRINTF (Interrupts_output, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
Interrupts_destruct (const char *Interrupts_msg, int Interrupts_type, YYSTYPE *Interrupts_valuep)
#else
static void
Interrupts_destruct (Interrupts_msg, Interrupts_type, Interrupts_valuep)
    const char *Interrupts_msg;
    int Interrupts_type;
    YYSTYPE *Interrupts_valuep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) Interrupts_valuep;

  if (!Interrupts_msg)
    Interrupts_msg = "Deleting";
  YY_SYMBOL_PRINT (Interrupts_msg, Interrupts_type, Interrupts_valuep, Interrupts_locationp);

  switch (Interrupts_type)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int Interrupts_parse (void *YYPARSE_PARAM);
# else
int Interrupts_parse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int Interrupts_parse (void);
#else
int Interrupts_parse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int Interrupts_char;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE Interrupts_lval;

/* Number of syntax errors so far.  */
int Interrupts_nerrs;



/*----------.
| Interrupts_parse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int Interrupts_parse (void *YYPARSE_PARAM)
# else
int Interrupts_parse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
Interrupts_parse (void)
#else
int
Interrupts_parse ()
    ;
#endif
#endif
{
  
  int Interrupts_state;
  int Interrupts_n;
  int Interrupts_result;
  /* Number of tokens to shift before error messages enabled.  */
  int Interrupts_errstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int Interrupts_token = 0;

  /* Three stacks and their tools:
     `Interrupts_ss': related to states,
     `Interrupts_vs': related to semantic values,
     `Interrupts_ls': related to locations.

     Refer to the stacks thru separate pointers, to allow Interrupts_overflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int Interrupts_ssa[YYINITDEPTH];
  short int *Interrupts_ss = Interrupts_ssa;
  short int *Interrupts_ssp;

  /* The semantic value stack.  */
  YYSTYPE Interrupts_vsa[YYINITDEPTH];
  YYSTYPE *Interrupts_vs = Interrupts_vsa;
  YYSTYPE *Interrupts_vsp;



#define YYPOPSTACK   (Interrupts_vsp--, Interrupts_ssp--)

  YYSIZE_T Interrupts_stacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE Interrupts_val;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int Interrupts_len;

  YYDPRINTF ((stderr, "Starting parse\n"));

  Interrupts_state = 0;
  Interrupts_errstatus = 0;
  Interrupts_nerrs = 0;
  Interrupts_char = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  Interrupts_ssp = Interrupts_ss;
  Interrupts_vsp = Interrupts_vs;

  goto Interrupts_setstate;

/*------------------------------------------------------------.
| Interrupts_newstate -- Push a new state, which is found in Interrupts_state.  |
`------------------------------------------------------------*/
 Interrupts_newstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  Interrupts_ssp++;

 Interrupts_setstate:
  *Interrupts_ssp = Interrupts_state;

  if (Interrupts_ss + Interrupts_stacksize - 1 <= Interrupts_ssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T Interrupts_size = Interrupts_ssp - Interrupts_ss + 1;

#ifdef Interrupts_overflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *Interrupts_vs1 = Interrupts_vs;
	short int *Interrupts_ss1 = Interrupts_ss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if Interrupts_overflow is a macro.  */
	Interrupts_overflow (YY_("memory exhausted"),
		    &Interrupts_ss1, Interrupts_size * sizeof (*Interrupts_ssp),
		    &Interrupts_vs1, Interrupts_size * sizeof (*Interrupts_vsp),

		    &Interrupts_stacksize);

	Interrupts_ss = Interrupts_ss1;
	Interrupts_vs = Interrupts_vs1;
      }
#else /* no Interrupts_overflow */
# ifndef YYSTACK_RELOCATE
      goto Interrupts_exhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= Interrupts_stacksize)
	goto Interrupts_exhaustedlab;
      Interrupts_stacksize *= 2;
      if (YYMAXDEPTH < Interrupts_stacksize)
	Interrupts_stacksize = YYMAXDEPTH;

      {
	short int *Interrupts_ss1 = Interrupts_ss;
	union Interrupts_alloc *Interrupts_ptr =
	  (union Interrupts_alloc *) YYSTACK_ALLOC (YYSTACK_BYTES (Interrupts_stacksize));
	if (! Interrupts_ptr)
	  goto Interrupts_exhaustedlab;
	YYSTACK_RELOCATE (Interrupts_ss);
	YYSTACK_RELOCATE (Interrupts_vs);

#  undef YYSTACK_RELOCATE
	if (Interrupts_ss1 != Interrupts_ssa)
	  YYSTACK_FREE (Interrupts_ss1);
      }
# endif
#endif /* no Interrupts_overflow */

      Interrupts_ssp = Interrupts_ss + Interrupts_size - 1;
      Interrupts_vsp = Interrupts_vs + Interrupts_size - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) Interrupts_stacksize));

      if (Interrupts_ss + Interrupts_stacksize - 1 <= Interrupts_ssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", Interrupts_state));

  goto Interrupts_backup;

/*-----------.
| Interrupts_backup.  |
`-----------*/
Interrupts_backup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* Interrupts_resume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  Interrupts_n = Interrupts_pact[Interrupts_state];
  if (Interrupts_n == YYPACT_NINF)
    goto Interrupts_default;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (Interrupts_char == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      Interrupts_char = YYLEX;
    }

  if (Interrupts_char <= YYEOF)
    {
      Interrupts_char = Interrupts_token = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      Interrupts_token = YYTRANSLATE (Interrupts_char);
      YY_SYMBOL_PRINT ("Next token is", Interrupts_token, &Interrupts_lval, &Interrupts_lloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  Interrupts_n += Interrupts_token;
  if (Interrupts_n < 0 || YYLAST < Interrupts_n || Interrupts_check[Interrupts_n] != Interrupts_token)
    goto Interrupts_default;
  Interrupts_n = Interrupts_table[Interrupts_n];
  if (Interrupts_n <= 0)
    {
      if (Interrupts_n == 0 || Interrupts_n == YYTABLE_NINF)
	goto Interrupts_errlab;
      Interrupts_n = -Interrupts_n;
      goto Interrupts_reduce;
    }

  if (Interrupts_n == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", Interrupts_token, &Interrupts_lval, &Interrupts_lloc);

  /* Discard the token being shifted unless it is eof.  */
  if (Interrupts_char != YYEOF)
    Interrupts_char = YYEMPTY;

  *++Interrupts_vsp = Interrupts_lval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (Interrupts_errstatus)
    Interrupts_errstatus--;

  Interrupts_state = Interrupts_n;
  goto Interrupts_newstate;


/*-----------------------------------------------------------.
| Interrupts_default -- do the default action for the current state.  |
`-----------------------------------------------------------*/
Interrupts_default:
  Interrupts_n = Interrupts_defact[Interrupts_state];
  if (Interrupts_n == 0)
    goto Interrupts_errlab;
  goto Interrupts_reduce;


/*-----------------------------.
| Interrupts_reduce -- Do a reduction.  |
`-----------------------------*/
Interrupts_reduce:
  /* Interrupts_n is the number of a rule to reduce with.  */
  Interrupts_len = Interrupts_r2[Interrupts_n];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  Interrupts_val = Interrupts_vsp[1-Interrupts_len];


  YY_REDUCE_PRINT (Interrupts_n);
  switch (Interrupts_n)
    {
        case 2:
#line 19 "Interrupts.tab.y"
    { 
		}
    break;

  case 3:
#line 22 "Interrupts.tab.y"
    { 
		}
    break;

  case 4:
#line 27 "Interrupts.tab.y"
    { 
		}
    break;

  case 5:
#line 30 "Interrupts.tab.y"
    { 
		}
    break;

  case 6:
#line 35 "Interrupts.tab.y"
    { 
		}
    break;

  case 7:
#line 38 "Interrupts.tab.y"
    { 
		}
    break;

  case 8:
#line 43 "Interrupts.tab.y"
    {
		}
    break;

  case 9:
#line 48 "Interrupts.tab.y"
    {
		}
    break;

  case 10:
#line 51 "Interrupts.tab.y"
    {
		}
    break;

  case 11:
#line 54 "Interrupts.tab.y"
    {
		}
    break;

  case 12:
#line 59 "Interrupts.tab.y"
    {
		}
    break;

  case 13:
#line 62 "Interrupts.tab.y"
    {
		}
    break;

  case 14:
#line 67 "Interrupts.tab.y"
    {
		}
    break;

  case 15:
#line 70 "Interrupts.tab.y"
    {
		}
    break;

  case 16:
#line 75 "Interrupts.tab.y"
    { 
		}
    break;

  case 17:
#line 78 "Interrupts.tab.y"
    { 
		}
    break;

  case 18:
#line 83 "Interrupts.tab.y"
    {
		    (Interrupts_val.stri) = new char[ strlen(Interrupts_text)+1 ];
		    strcpy( (Interrupts_val.stri), Interrupts_text );
		}
    break;

  case 19:
#line 90 "Interrupts.tab.y"
    {
		    int len = strlen(Interrupts_text) - 2;
		    (Interrupts_val.stri) = new char[ len+1 ];
		    strncpy( (Interrupts_val.stri), Interrupts_text+1, len );
		    (Interrupts_val.stri)[len] = '\0';
		}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 1226 "Interrupts.tab.y"

  Interrupts_vsp -= Interrupts_len;
  Interrupts_ssp -= Interrupts_len;


  YY_STACK_PRINT (Interrupts_ss, Interrupts_ssp);

  *++Interrupts_vsp = Interrupts_val;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  Interrupts_n = Interrupts_r1[Interrupts_n];

  Interrupts_state = Interrupts_pgoto[Interrupts_n - YYNTOKENS] + *Interrupts_ssp;
  if (0 <= Interrupts_state && Interrupts_state <= YYLAST && Interrupts_check[Interrupts_state] == *Interrupts_ssp)
    Interrupts_state = Interrupts_table[Interrupts_state];
  else
    Interrupts_state = Interrupts_defgoto[Interrupts_n - YYNTOKENS];

  goto Interrupts_newstate;


/*------------------------------------.
| Interrupts_errlab -- here on detecting error |
`------------------------------------*/
Interrupts_errlab:
  /* If not already recovering from an error, report this error.  */
  if (!Interrupts_errstatus)
    {
      ++Interrupts_nerrs;
#if YYERROR_VERBOSE
      Interrupts_n = Interrupts_pact[Interrupts_state];

      if (YYPACT_NINF < Interrupts_n && Interrupts_n < YYLAST)
	{
	  int Interrupts_type = YYTRANSLATE (Interrupts_char);
	  YYSIZE_T Interrupts_size0 = Interrupts_tnamerr (0, Interrupts_tname[Interrupts_type]);
	  YYSIZE_T Interrupts_size = Interrupts_size0;
	  YYSIZE_T Interrupts_size1;
	  int Interrupts_size_overflow = 0;
	  char *Interrupts_msg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *Interrupts_arg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int Interrupts_x;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
	  char *Interrupts_fmt;
	  char const *Interrupts_f;
	  static char const Interrupts_unexpected[] = "syntax error, unexpected %s";
	  static char const Interrupts_expecting[] = ", expecting %s";
	  static char const Interrupts_or[] = " or %s";
	  char Interrupts_format[sizeof Interrupts_unexpected
			+ sizeof Interrupts_expecting - 1
			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
			   * (sizeof Interrupts_or - 1))];
	  char const *Interrupts_prefix = Interrupts_expecting;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int Interrupts_xbegin = Interrupts_n < 0 ? -Interrupts_n : 0;

	  /* Stay within bounds of both Interrupts_check and Interrupts_tname.  */
	  int Interrupts_checklim = YYLAST - Interrupts_n;
	  int Interrupts_xend = Interrupts_checklim < YYNTOKENS ? Interrupts_checklim : YYNTOKENS;
	  int Interrupts_count = 1;

	  Interrupts_arg[0] = Interrupts_tname[Interrupts_type];
	  Interrupts_fmt = Interrupts_stpcpy (Interrupts_format, Interrupts_unexpected);

	  for (Interrupts_x = Interrupts_xbegin; Interrupts_x < Interrupts_xend; ++Interrupts_x)
	    if (Interrupts_check[Interrupts_x + Interrupts_n] == Interrupts_x && Interrupts_x != YYTERROR)
	      {
		if (Interrupts_count == YYERROR_VERBOSE_ARGS_MAXIMUM)
		  {
		    Interrupts_count = 1;
		    Interrupts_size = Interrupts_size0;
		    Interrupts_format[sizeof Interrupts_unexpected - 1] = '\0';
		    break;
		  }
		Interrupts_arg[Interrupts_count++] = Interrupts_tname[Interrupts_x];
		Interrupts_size1 = Interrupts_size + Interrupts_tnamerr (0, Interrupts_tname[Interrupts_x]);
		Interrupts_size_overflow |= Interrupts_size1 < Interrupts_size;
		Interrupts_size = Interrupts_size1;
		Interrupts_fmt = Interrupts_stpcpy (Interrupts_fmt, Interrupts_prefix);
		Interrupts_prefix = Interrupts_or;
	      }

	  Interrupts_f = YY_(Interrupts_format);
	  Interrupts_size1 = Interrupts_size + Interrupts_strlen (Interrupts_f);
	  Interrupts_size_overflow |= Interrupts_size1 < Interrupts_size;
	  Interrupts_size = Interrupts_size1;

	  if (!Interrupts_size_overflow && Interrupts_size <= YYSTACK_ALLOC_MAXIMUM)
	    Interrupts_msg = (char *) YYSTACK_ALLOC (Interrupts_size);
	  if (Interrupts_msg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *Interrupts_p = Interrupts_msg;
	      int Interrupts_i = 0;
	      while ((*Interrupts_p = *Interrupts_f))
		{
		  if (*Interrupts_p == '%' && Interrupts_f[1] == 's' && Interrupts_i < Interrupts_count)
		    {
		      Interrupts_p += Interrupts_tnamerr (Interrupts_p, Interrupts_arg[Interrupts_i++]);
		      Interrupts_f += 2;
		    }
		  else
		    {
		      Interrupts_p++;
		      Interrupts_f++;
		    }
		}
	      Interrupts_error (Interrupts_msg);
	      YYSTACK_FREE (Interrupts_msg);
	    }
	  else
	    {
	      Interrupts_error (YY_("syntax error"));
	      goto Interrupts_exhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	Interrupts_error (YY_("syntax error"));
    }



  if (Interrupts_errstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (Interrupts_char <= YYEOF)
        {
	  /* Return failure if at end of input.  */
	  if (Interrupts_char == YYEOF)
	    YYABORT;
        }
      else
	{
	  Interrupts_destruct ("Error: discarding", Interrupts_token, &Interrupts_lval);
	  Interrupts_char = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto Interrupts_errlab1;


/*---------------------------------------------------.
| Interrupts_errorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
Interrupts_errorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label Interrupts_errorlab therefore never appears in user
     code.  */
  if (0)
     goto Interrupts_errorlab;

Interrupts_vsp -= Interrupts_len;
  Interrupts_ssp -= Interrupts_len;
  Interrupts_state = *Interrupts_ssp;
  goto Interrupts_errlab1;


/*-------------------------------------------------------------.
| Interrupts_errlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
Interrupts_errlab1:
  Interrupts_errstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      Interrupts_n = Interrupts_pact[Interrupts_state];
      if (Interrupts_n != YYPACT_NINF)
	{
	  Interrupts_n += YYTERROR;
	  if (0 <= Interrupts_n && Interrupts_n <= YYLAST && Interrupts_check[Interrupts_n] == YYTERROR)
	    {
	      Interrupts_n = Interrupts_table[Interrupts_n];
	      if (0 < Interrupts_n)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (Interrupts_ssp == Interrupts_ss)
	YYABORT;


      Interrupts_destruct ("Error: popping", Interrupts_stos[Interrupts_state], Interrupts_vsp);
      YYPOPSTACK;
      Interrupts_state = *Interrupts_ssp;
      YY_STACK_PRINT (Interrupts_ss, Interrupts_ssp);
    }

  if (Interrupts_n == YYFINAL)
    YYACCEPT;

  *++Interrupts_vsp = Interrupts_lval;


  /* Shift the error token. */
  YY_SYMBOL_PRINT ("Shifting", Interrupts_stos[Interrupts_n], Interrupts_vsp, Interrupts_lsp);

  Interrupts_state = Interrupts_n;
  goto Interrupts_newstate;


/*-------------------------------------.
| Interrupts_acceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
Interrupts_acceptlab:
  Interrupts_result = 0;
  goto Interrupts_return;

/*-----------------------------------.
| Interrupts_abortlab -- YYABORT comes here.  |
`-----------------------------------*/
Interrupts_abortlab:
  Interrupts_result = 1;
  goto Interrupts_return;

#ifndef Interrupts_overflow
/*-------------------------------------------------.
| Interrupts_exhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
Interrupts_exhaustedlab:
  Interrupts_error (YY_("memory exhausted"));
  Interrupts_result = 2;
  /* Fall through.  */
#endif

Interrupts_return:
  if (Interrupts_char != YYEOF && Interrupts_char != YYEMPTY)
     Interrupts_destruct ("Cleanup: discarding lookahead",
		 Interrupts_token, &Interrupts_lval);
  while (Interrupts_ssp != Interrupts_ss)
    {
      Interrupts_destruct ("Cleanup: popping",
		  Interrupts_stos[*Interrupts_ssp], Interrupts_vsp);
      YYPOPSTACK;
    }
#ifndef Interrupts_overflow
  if (Interrupts_ss != Interrupts_ssa)
    YYSTACK_FREE (Interrupts_ss);
#endif
  return Interrupts_result;
}


#line 97 "Interrupts.tab.y"


#include <stdio.h>
#include <string.h>
#include "Interrupts.lex.h"

void
Interrupts_error( char* msg )
{
    printf("%s\n", msg);
}


#if defined(UNDEFINED)
#define BOB  "accounts.alf"

int Interrupts_parse();

extern FILE* Interrupts_in;

int
main( int ac, char *av[] )
{
    Interrupts_in = fopen(BOB, "r");
    Interrupts_parse();

    return 0;
}
#endif


