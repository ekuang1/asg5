/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "parser.y"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "lyutils.h"
#include "astree.h"
#include "astree.rep.h"



/* Line 268 of yacc.c  */
#line 83 "yyparse.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 1
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_VOID = 258,
     TOK_BOOL = 259,
     TOK_CHAR = 260,
     TOK_INT = 261,
     TOK_STRING = 262,
     TOK_NEWSTRING = 263,
     TOK_IF = 264,
     TOK_ELSE = 265,
     TOK_WHILE = 266,
     TOK_RETURN = 267,
     TOK_STRUCT = 268,
     TOK_PARAMLIST = 269,
     TOK_FALSE = 270,
     TOK_TRUE = 271,
     TOK_NULL = 272,
     TOK_NEW = 273,
     TOK_ARRAY = 274,
     TOK_INDEX = 275,
     TOK_EQ = 276,
     TOK_NE = 277,
     TOK_LT = 278,
     TOK_LE = 279,
     TOK_GT = 280,
     TOK_GE = 281,
     TOK_IDENT = 282,
     TOK_INTCON = 283,
     TOK_CHARCON = 284,
     TOK_STRINGCON = 285,
     TOK_NOTIDENT = 286,
     TOK_BLOCK = 287,
     TOK_CALL = 288,
     TOK_IFELSE = 289,
     TOK_VARDECL = 290,
     TOK_DECLID = 291,
     TOK_POS = 292,
     TOK_NEG = 293,
     TOK_NEWARRAY = 294,
     TOK_TYPEID = 295,
     TOK_FIELD = 296,
     TOK_ORD = 297,
     TOK_CHR = 298,
     TOK_ROOT = 299,
     TOK_FUNC = 300,
     TOK_PROTOTYPE = 301,
     TOK_RETURNVOID = 302,
     ROOT = 303,
     NUMBER = 304,
     DIGIT = 305,
     FUNCTION = 306
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 176 "yyparse.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   566

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNRULES -- Number of states.  */
#define YYNSTATES  144

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,     2,     2,    57,     2,     2,
      61,    65,    55,    53,    66,    54,    60,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    63,
       2,    52,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    67,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,     2,    62,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    12,    16,    20,    21,    25,
      29,    32,    36,    39,    43,    46,    48,    50,    52,    54,
      56,    58,    61,    64,    66,    69,    72,    78,    86,    90,
      93,    99,   104,   107,   111,   114,   118,   122,   126,   130,
     134,   138,   142,   146,   150,   154,   158,   162,   166,   169,
     172,   175,   178,   181,   183,   185,   187,   189,   193,   198,
     204,   210,   212,   217,   221,   224,   228,   232,   235,   237,
     239,   241,   243,   245,   247,   249,   251,   253,   255,   257
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      69,     0,    -1,    69,    70,    -1,    69,    72,    -1,    69,
      75,    -1,    69,     1,    62,    -1,    69,     1,    63,    -1,
      -1,    13,    71,    62,    -1,    71,    83,    63,    -1,    27,
      64,    -1,    73,    65,    76,    -1,    82,    74,    -1,    74,
      66,    82,    -1,    61,    82,    -1,    61,    -1,    76,    -1,
      81,    -1,    80,    -1,    78,    -1,    79,    -1,    84,    63,
      -1,    77,    62,    -1,    63,    -1,    64,    75,    -1,    77,
      75,    -1,     9,    61,    84,    65,    75,    -1,     9,    61,
      84,    65,    75,    10,    75,    -1,    12,    84,    63,    -1,
      12,    63,    -1,    11,    61,    84,    65,    75,    -1,    82,
      52,    84,    63,    -1,    90,    27,    -1,    90,    19,    27,
      -1,    90,    27,    -1,    90,    19,    27,    -1,    84,    52,
      84,    -1,    84,    53,    84,    -1,    84,    54,    84,    -1,
      84,    55,    84,    -1,    84,    56,    84,    -1,    84,    57,
      84,    -1,    84,    21,    84,    -1,    84,    22,    84,    -1,
      84,    23,    84,    -1,    84,    24,    84,    -1,    84,    25,
      84,    -1,    84,    26,    84,    -1,    53,    84,    -1,    54,
      84,    -1,    58,    84,    -1,    42,    84,    -1,    43,    84,
      -1,    85,    -1,    87,    -1,    86,    -1,    89,    -1,    61,
      84,    65,    -1,    18,    27,    61,    65,    -1,    18,     7,
      61,    84,    65,    -1,    18,    90,    59,    84,    67,    -1,
      27,    -1,    84,    59,    84,    67,    -1,    84,    60,    27,
      -1,    88,    65,    -1,    88,    66,    84,    -1,    27,    61,
      84,    -1,    27,    61,    -1,    28,    -1,    29,    -1,    30,
      -1,    15,    -1,    16,    -1,    17,    -1,     3,    -1,     4,
      -1,     5,    -1,     6,    -1,     7,    -1,    27,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    44,    47,    48,    49,    50,    51,    52,    55,    58,
      59,    63,    70,    74,    75,    77,    82,    83,    84,    85,
      86,    87,    90,    91,    94,    96,    99,   101,   107,   108,
     113,   116,   121,   124,   129,   132,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   151,
     153,   154,   155,   156,   157,   158,   159,   160,   163,   166,
     169,   174,   175,   178,   183,   186,   187,   190,   194,   195,
     196,   197,   198,   199,   202,   203,   204,   205,   206,   207
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_VOID", "TOK_BOOL", "TOK_CHAR",
  "TOK_INT", "TOK_STRING", "TOK_NEWSTRING", "TOK_IF", "TOK_ELSE",
  "TOK_WHILE", "TOK_RETURN", "TOK_STRUCT", "TOK_PARAMLIST", "TOK_FALSE",
  "TOK_TRUE", "TOK_NULL", "TOK_NEW", "TOK_ARRAY", "TOK_INDEX", "TOK_EQ",
  "TOK_NE", "TOK_LT", "TOK_LE", "TOK_GT", "TOK_GE", "TOK_IDENT",
  "TOK_INTCON", "TOK_CHARCON", "TOK_STRINGCON", "TOK_NOTIDENT",
  "TOK_BLOCK", "TOK_CALL", "TOK_IFELSE", "TOK_VARDECL", "TOK_DECLID",
  "TOK_POS", "TOK_NEG", "TOK_NEWARRAY", "TOK_TYPEID", "TOK_FIELD",
  "TOK_ORD", "TOK_CHR", "TOK_ROOT", "TOK_FUNC", "TOK_PROTOTYPE",
  "TOK_RETURNVOID", "ROOT", "NUMBER", "DIGIT", "FUNCTION", "'='", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'!'", "'['", "'.'", "'('", "'}'", "';'",
  "'{'", "')'", "','", "']'", "$accept", "program", "structdef", "sd_list",
  "function", "functionhead", "paramlist", "stmt", "block", "stmt_list",
  "ifelse", "return", "while", "vardecl", "identdecl", "fielddecl", "expr",
  "allocator", "variable", "call", "call_list", "constant", "basetype", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    61,    43,    45,    42,    47,    37,    33,    91,
      46,    40,   125,    59,   123,    41,    44,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    69,    69,    69,    69,    69,    69,    70,    71,
      71,    72,    73,    74,    74,    74,    75,    75,    75,    75,
      75,    75,    76,    76,    77,    77,    78,    78,    79,    79,
      80,    81,    82,    82,    83,    83,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    85,    85,
      85,    86,    86,    86,    87,    88,    88,    88,    89,    89,
      89,    89,    89,    89,    90,    90,    90,    90,    90,    90
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     3,     3,     0,     3,     3,
       2,     3,     2,     3,     2,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     2,     2,     5,     7,     3,     2,
       5,     4,     2,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     3,     4,     5,
       5,     1,     4,     3,     2,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     1,     0,    74,    75,    76,    77,    78,     0,
       0,     0,     0,    71,    72,    73,     0,    61,    68,    69,
      70,     0,     0,     0,     0,     0,     0,    23,     0,     2,
       3,     0,     4,    16,     0,    19,    20,    18,    17,     0,
       0,    53,    55,    54,     0,    56,     0,     5,     6,     0,
       0,    61,    29,     0,     0,     0,    78,    79,     0,    67,
      51,    52,    48,    49,    50,     0,    24,     0,     0,    22,
      25,     0,    15,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,    64,
       0,     0,    32,     0,     0,    28,    10,    79,     8,     0,
       0,     0,     0,     0,    66,    57,    11,     0,    14,     0,
      42,    43,    44,    45,    46,    47,    36,    37,    38,    39,
      40,    41,     0,    63,    65,    33,     0,     0,     9,     0,
      34,     0,    58,     0,    31,    13,    62,    26,    30,    35,
      59,    60,     0,    27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    29,    55,    30,    31,    73,    32,    33,    34,
      35,    36,    37,    38,    67,    99,    40,    41,    42,    43,
      44,    45,    46
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -59
static const yytype_int16 yypact[] =
{
     -59,   112,   -59,   -58,   -59,   -59,   -59,   -59,   -59,   -54,
     -52,   253,    16,   -59,   -59,   -59,   129,   -16,   -59,   -59,
     -59,   351,   351,   351,   351,   351,   351,   -59,   236,   -59,
     -59,   -39,   -59,   -59,   174,   -59,   -59,   -59,   -59,   -44,
     479,   -59,   -59,   -59,   -47,   -59,     8,   -59,   -59,   351,
     351,   -17,   -59,   491,   -18,     9,    -6,     4,   -12,   351,
     -22,   -22,   -22,   -22,   -22,   361,   -59,    17,   -24,   -59,
     -59,   351,   140,     2,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,    65,   -59,   -59,
     351,    66,   -59,   375,   420,   -59,   -59,   -59,   -59,    32,
      15,   351,    29,   351,     7,   -59,   -59,   503,   -59,   140,
      -3,    -3,    -3,    -3,    -3,    -3,     7,    31,    31,   -22,
     -22,   -22,   296,   -59,     7,   -59,   236,   236,   -59,    69,
     -59,   434,   -59,   305,   -59,   -59,   -59,    87,   -59,   -59,
     -59,   -59,   236,   -59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -28,    33,   -59,
     -59,   -59,   -59,   -59,     0,   -59,    -1,   -59,   -59,   -59,
     -59,   -59,   -14
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -80
static const yytype_int16 yytable[] =
{
      66,    39,    58,   -79,    47,    48,    70,    49,    71,    50,
      53,   -79,     4,     5,     6,     7,     8,    72,    89,    90,
      60,    61,    62,    63,    64,    65,    68,    91,    74,    75,
      76,    77,    78,    79,   129,    92,    97,    86,    87,    27,
      28,   100,   130,    54,    59,    59,    96,   103,    93,    94,
      81,    82,    83,    84,    85,   101,    86,    87,   104,    80,
      81,    82,    83,    84,    85,   102,    86,    87,   109,    71,
     107,    98,   108,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    83,    84,    85,   124,
      86,    87,   123,   125,   132,   128,   139,   142,   137,   138,
     131,   106,   133,     0,     0,     0,     0,     0,     0,   135,
       0,     0,     2,     3,   143,     4,     5,     6,     7,     8,
       0,     9,     0,    10,    11,    12,     0,    13,    14,    15,
      16,     0,     4,     5,     6,     7,    56,     0,     0,    17,
      18,    19,    20,     4,     5,     6,     7,     8,     0,     0,
       0,     0,     0,     0,    21,    22,    57,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    24,    97,     0,     0,
      25,     0,     0,    26,     0,    27,    28,     4,     5,     6,
       7,     8,     0,     9,     0,    10,    11,     0,     0,    13,
      14,    15,    16,     0,     0,     0,     0,     0,     0,     0,
       0,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    24,     0,
       0,     0,    25,     0,     0,    26,    69,    27,    28,     4,
       5,     6,     7,     8,     0,     9,     0,    10,    11,     0,
       0,    13,    14,    15,    16,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    18,    19,    20,     0,    13,    14,
      15,    16,     0,     0,     0,     0,     0,     0,    21,    22,
      51,    18,    19,    20,     0,     0,     0,     0,     0,    23,
      24,     0,     0,     0,    25,    21,    22,    26,     0,    27,
      28,     0,     0,     0,     0,     0,    23,    24,     0,     0,
       0,    25,     0,     0,    26,     0,    52,    74,    75,    76,
      77,    78,    79,     0,     0,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,    81,
      82,    83,    84,    85,     0,    86,    87,    80,    81,    82,
      83,    84,    85,   136,    86,    87,    13,    14,    15,    16,
       0,     0,   141,     0,     0,     0,     0,     0,    51,    18,
      19,    20,    74,    75,    76,    77,    78,    79,     0,     0,
       0,     0,     0,    21,    22,     0,    74,    75,    76,    77,
      78,    79,     0,     0,    23,    24,     0,     0,     0,    25,
       0,     0,    26,    80,    81,    82,    83,    84,    85,     0,
      86,    87,     0,     0,     0,     0,   105,    80,    81,    82,
      83,    84,    85,     0,    86,    87,     0,     0,     0,     0,
     126,    74,    75,    76,    77,    78,    79,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    75,    76,    77,    78,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,    81,    82,    83,    84,    85,     0,    86,
      87,     0,     0,     0,     0,   127,    80,    81,    82,    83,
      84,    85,     0,    86,    87,     0,     0,     0,     0,   140,
      74,    75,    76,    77,    78,    79,     0,     0,     0,     0,
       0,     0,    74,    75,    76,    77,    78,    79,     0,     0,
       0,     0,     0,     0,    74,    75,    76,    77,    78,    79,
       0,    80,    81,    82,    83,    84,    85,     0,    86,    87,
       0,     0,    88,    80,    81,    82,    83,    84,    85,     0,
      86,    87,     0,     0,    95,    80,    81,    82,    83,    84,
      85,     0,    86,    87,     0,     0,   134
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-59))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      28,     1,    16,    19,    62,    63,    34,    61,    52,    61,
      11,    27,     3,     4,     5,     6,     7,    61,    65,    66,
      21,    22,    23,    24,    25,    26,    65,    19,    21,    22,
      23,    24,    25,    26,    19,    27,    27,    59,    60,    63,
      64,    55,    27,    27,    61,    61,    64,    59,    49,    50,
      53,    54,    55,    56,    57,    61,    59,    60,    59,    52,
      53,    54,    55,    56,    57,    61,    59,    60,    66,    52,
      71,    62,    72,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    55,    56,    57,    90,
      59,    60,    27,    27,    65,    63,    27,    10,   126,   127,
     101,    68,   103,    -1,    -1,    -1,    -1,    -1,    -1,   109,
      -1,    -1,     0,     1,   142,     3,     4,     5,     6,     7,
      -1,     9,    -1,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,     3,     4,     5,     6,     7,    -1,    -1,    27,
      28,    29,    30,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    27,    -1,    -1,
      58,    -1,    -1,    61,    -1,    63,    64,     3,     4,     5,
       6,     7,    -1,     9,    -1,    11,    12,    -1,    -1,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    -1,
      -1,    -1,    58,    -1,    -1,    61,    62,    63,    64,     3,
       4,     5,     6,     7,    -1,     9,    -1,    11,    12,    -1,
      -1,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    -1,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    53,
      54,    -1,    -1,    -1,    58,    42,    43,    61,    -1,    63,
      64,    -1,    -1,    -1,    -1,    -1,    53,    54,    -1,    -1,
      -1,    58,    -1,    -1,    61,    -1,    63,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,
      54,    55,    56,    57,    -1,    59,    60,    52,    53,    54,
      55,    56,    57,    67,    59,    60,    15,    16,    17,    18,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    21,    22,    23,    24,
      25,    26,    -1,    -1,    53,    54,    -1,    -1,    -1,    58,
      -1,    -1,    61,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    -1,    -1,    -1,    -1,    65,    52,    53,    54,
      55,    56,    57,    -1,    59,    60,    -1,    -1,    -1,    -1,
      65,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    -1,    59,
      60,    -1,    -1,    -1,    -1,    65,    52,    53,    54,    55,
      56,    57,    -1,    59,    60,    -1,    -1,    -1,    -1,    65,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
      -1,    52,    53,    54,    55,    56,    57,    -1,    59,    60,
      -1,    -1,    63,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    -1,    -1,    63,    52,    53,    54,    55,    56,
      57,    -1,    59,    60,    -1,    -1,    63
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    69,     0,     1,     3,     4,     5,     6,     7,     9,
      11,    12,    13,    15,    16,    17,    18,    27,    28,    29,
      30,    42,    43,    53,    54,    58,    61,    63,    64,    70,
      72,    73,    75,    76,    77,    78,    79,    80,    81,    82,
      84,    85,    86,    87,    88,    89,    90,    62,    63,    61,
      61,    27,    63,    84,    27,    71,     7,    27,    90,    61,
      84,    84,    84,    84,    84,    84,    75,    82,    65,    62,
      75,    52,    61,    74,    21,    22,    23,    24,    25,    26,
      52,    53,    54,    55,    56,    57,    59,    60,    63,    65,
      66,    19,    27,    84,    84,    63,    64,    27,    62,    83,
      90,    61,    61,    59,    84,    65,    76,    84,    82,    66,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    27,    84,    27,    65,    65,    63,    19,
      27,    84,    65,    84,    63,    82,    67,    75,    75,    27,
      65,    67,    10,    75
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
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
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
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

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 47 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 48 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 49 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 50 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 51 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 52 "parser.y"
    { (yyval) = new_parseroot (); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 55 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 58 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 59 "parser.y"
    { (yyvsp[(1) - (2)]) = changesym((yyvsp[(1) - (2)]), TOK_TYPEID);
                                        (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 63 "parser.y"
    { if (strcmp(peek_stringtable
                                            ((yyvsp[(3) - (3)])->lexinfo), ";") == 0)
                                        (yyvsp[(1) - (3)]) = changesym((yyvsp[(1) - (3)]), 
                                                       TOK_PROTOTYPE);
                                        (yyval) = adopt1((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 70 "parser.y"
    { (yyval) = adopt2(new_function(),
                                                    (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 74 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 75 "parser.y"
    { (yyval) = adopt1sym((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]),
                                                       TOK_PARAMLIST);}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 77 "parser.y"
    { (yyvsp[(1) - (1)]) = changesym((yyvsp[(1) - (1)]), 
                                                       TOK_PARAMLIST);
                                        (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 82 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 83 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 84 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 85 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 86 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 87 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 90 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 91 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 94 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), 
                                                        TOK_BLOCK); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 96 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 100 "parser.y"
    { (yyval) = adopt2((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 102 "parser.y"
    { (yyvsp[(1) - (7)]) = changesym((yyvsp[(1) - (7)]), TOK_IFELSE);
                                        (yyval) = adopt((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]), 
                                                   NULL); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 107 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 108 "parser.y"
    { (yyvsp[(1) - (2)]) = changesym((yyvsp[(1) - (2)]), 
                                                       TOK_RETURNVOID);
                                        (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 113 "parser.y"
    { (yyval) = adopt2((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 116 "parser.y"
    { (yyvsp[(2) - (4)]) = changesym((yyvsp[(2) - (4)]), 
                                                        TOK_VARDECL);
                                             (yyval) = adopt2((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 121 "parser.y"
    { (yyvsp[(2) - (2)]) = changesym((yyvsp[(2) - (2)]), 
                                                        TOK_DECLID);
                                             (yyval) = adopt1((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 124 "parser.y"
    { (yyvsp[(3) - (3)]) = changesym((yyvsp[(3) - (3)]), 
                                                         TOK_FIELD);
                                             (yyval) = adopt2((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 129 "parser.y"
    { (yyvsp[(2) - (2)]) = changesym((yyvsp[(2) - (2)]), 
                                                        TOK_FIELD);
                                             (yyval) = adopt1((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 132 "parser.y"
    { (yyvsp[(3) - (3)]) = changesym((yyvsp[(3) - (3)]), 
                                                         TOK_FIELD);
                                             (yyval) = adopt2((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 137 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 138 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 139 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 140 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 141 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 142 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 143 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 144 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 145 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 146 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 147 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 148 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(1) - (3)]));}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 149 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), 
                                                             TOK_POS);}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 151 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), 
                                                             TOK_NEG);}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 153 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 154 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 155 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 156 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 157 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 158 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 159 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 160 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 163 "parser.y"
    { (yyvsp[(2) - (4)]) = changesym((yyvsp[(2) - (4)]), 
                                                      TOK_TYPEID);
                                             (yyval) = adopt1((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)])); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 166 "parser.y"
    { (yyvsp[(1) - (5)]) = changesym((yyvsp[(1) - (5)]), 
                                                      TOK_NEWSTRING);
                                             (yyval) = adopt2((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(4) - (5)])); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 169 "parser.y"
    { (yyvsp[(1) - (5)]) = changesym((yyvsp[(1) - (5)]), 
                                                      TOK_NEWARRAY);
                                             (yyval) = adopt2((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(4) - (5)])); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 174 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 175 "parser.y"
    { (yyvsp[(2) - (4)]) = changesym((yyvsp[(2) - (4)]), 
                                                      TOK_INDEX);
                                             (yyval) = adopt2((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 178 "parser.y"
    { (yyvsp[(3) - (3)]) = changesym((yyvsp[(3) - (3)]), 
                                                      TOK_FIELD);
                                             (yyval) = adopt2((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 183 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 186 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 187 "parser.y"
    { (yyvsp[(2) - (3)]) = changesym((yyvsp[(2) - (3)]), 
                                                              TOK_CALL);
                                             (yyval) = adopt2((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 190 "parser.y"
    { (yyval) = adopt1sym((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]), 
                                                             TOK_CALL);}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 194 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 195 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 196 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 197 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 198 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 199 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 202 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 203 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 204 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 205 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 206 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 207 "parser.y"
    { (yyvsp[(1) - (1)]) = changesym((yyvsp[(1) - (1)]), 
                                                         TOK_TYPEID);
                                             (yyval) = (yyvsp[(1) - (1)]); }
    break;



/* Line 1806 of yacc.c  */
#line 2207 "yyparse.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 213 "parser.y"


const char *get_yytname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}





