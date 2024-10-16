/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h>
        #include <ctype.h>
        #include <stdbool.h>
        #include "sym.h"
        #define ASSERT(x,y) if(!(x)) printf("%s na linha %d\n",(y),yylineno)
        extern int yylineno;
        FILE * output;

        char identifierDefined[100];

        char* create_condition(const char *identifier, const char *operator, int value) {
            char *buffer = (char *)malloc(100);
            if (buffer) {
                snprintf(buffer, 100, "%s %s %d", identifier, operator, value);
            }
            return buffer;
        }

        char* remove_quotes(const char* str) {
            int len = strlen(str);
            char* result = (char*)malloc(len + 1);
            int i, j = 0;

            for (i = 0; i < len; i++) {  
                if (str[i] != '\"') {
                    result[j++] = str[i];
                }
            }

            result[j] = '\0';
            return result;
        }
    

#line 104 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    NUMBER_LITERAL = 259,
    STRING_LITERAL = 260,
    BOOLEAN_LITERAL = 261,
    FLOAT_LITERAL = 262,
    DOUBLE_LITERAL = 263,
    PUBLIC = 264,
    PRIVATE = 265,
    VOID = 266,
    CLASS = 267,
    INT_TYPE = 268,
    STRING_TYPE = 269,
    FLOAT_TYPE = 270,
    DOUBLE_TYPE = 271,
    BOOLEAN_TYPE = 272,
    CHAR_TYPE = 273,
    ASSIGN = 274,
    EQUAL = 275,
    COLON = 276,
    SEMICOLON = 277,
    IF_TYPE = 278,
    ELSE_TYPE = 279,
    ELSE_IF = 280,
    WHILE_TYPE = 281,
    FOR_TYPE = 282,
    LBRACE = 283,
    RBRACE = 284,
    LPARENTHESES = 285,
    RPARENTHESES = 286,
    PLUS_PLUS = 287,
    MINUS_MINUS = 288,
    DOT = 289,
    SYSTEM = 290,
    OUT = 291,
    PRINTLN = 292,
    COMMA = 293,
    PLUS = 294,
    PROTECTED = 295,
    GREATER = 296,
    LESS = 297,
    GREATER_EQUAL = 298,
    LESS_EQUAL = 299,
    AND = 300,
    OR = 301,
    QUESTION = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 38 "parser.y" /* yacc.c:355  */

        int yint;         // Para valores inteiros
        float yfloat;     // Para valores de ponto flutuante (float)
        double ydouble;   // Para valores de ponto flutuante (double)
        char *ystr;       // Para strings
        int ybool;        // Para booleanos (1 para true, 0 para false)
    

#line 201 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 218 "parser.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   257

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  187

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    72,    72,    76,    76,    77,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      98,   104,   105,   106,   107,   108,   109,   110,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   135,   141,   142,   143,   147,
     148,   149,   156,   160,   164,   168,   172,   179,   180,   181,
     188,   192
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "NUMBER_LITERAL",
  "STRING_LITERAL", "BOOLEAN_LITERAL", "FLOAT_LITERAL", "DOUBLE_LITERAL",
  "PUBLIC", "PRIVATE", "VOID", "CLASS", "INT_TYPE", "STRING_TYPE",
  "FLOAT_TYPE", "DOUBLE_TYPE", "BOOLEAN_TYPE", "CHAR_TYPE", "ASSIGN",
  "EQUAL", "COLON", "SEMICOLON", "IF_TYPE", "ELSE_TYPE", "ELSE_IF",
  "WHILE_TYPE", "FOR_TYPE", "LBRACE", "RBRACE", "LPARENTHESES",
  "RPARENTHESES", "PLUS_PLUS", "MINUS_MINUS", "DOT", "SYSTEM", "OUT",
  "PRINTLN", "COMMA", "PLUS", "PROTECTED", "GREATER", "LESS",
  "GREATER_EQUAL", "LESS_EQUAL", "AND", "OR", "QUESTION", "$accept",
  "program", "declarations", "$@1", "declaration", "for_loop", "condition",
  "expression", "method_definition", "access_modifier", "parameters",
  "parameter", "method_body", "statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF -154

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-154)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      96,  -154,  -154,    12,    22,    31,    34,    35,    36,    39,
      14,    18,    27,    28,    29,    42,  -154,    68,  -154,  -154,
    -154,  -154,    74,    58,    69,    70,    71,    72,    75,    76,
      90,    96,    90,    90,    83,    79,  -154,    96,   123,    96,
      95,   102,   109,   120,   126,   125,   142,    97,   100,   139,
     140,   170,   147,  -154,   152,   160,   171,  -154,  -154,  -154,
    -154,  -154,    95,   -15,   169,   172,   173,   174,   175,   188,
     189,   194,   195,   196,   197,   198,   176,  -154,   177,   178,
     184,   179,   124,  -154,    95,   104,    95,  -154,    95,    95,
      95,    95,    95,    95,    95,    95,  -154,  -154,  -154,  -154,
    -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,    96,    96,
      96,   203,   180,   205,   206,   208,   209,   210,     2,  -154,
     133,  -154,   133,   133,   133,   133,   133,   133,   133,   133,
     113,   185,   186,   190,   199,   212,  -154,  -154,  -154,  -154,
    -154,   192,   124,    95,  -154,  -154,  -154,    90,   187,    57,
    -154,   133,   200,   201,   191,  -154,   122,     6,  -154,   221,
    -154,   193,  -154,  -154,   202,  -154,   207,   204,   211,   213,
     214,   215,   217,   216,   218,    13,   222,   220,   219,   223,
     225,  -154,   230,   226,  -154,   231,  -154
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    46,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,     0,     2,     3,
      19,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     0,     0,     0,     0,     1,     5,     0,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     0,     0,    29,    28,    30,    33,
      31,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,    49,     6,     0,     0,     0,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     9,    10,    11,
      12,    21,    22,    23,    24,    25,    26,    27,     5,     5,
       5,     0,     0,     0,     0,     0,     0,     0,     0,    50,
      34,    35,    39,    44,    37,    38,    40,    41,    42,    43,
       0,     0,     0,     0,     0,     0,    52,    53,    54,    55,
      56,     0,     0,     0,    13,    14,    16,     0,     0,     5,
      51,    36,     0,     0,     0,    57,     0,     0,    58,     0,
      17,     0,    60,    45,     0,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,     0,     0,    17,     0,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -154,  -154,   -31,  -154,  -154,  -154,   -30,   -39,  -154,  -154,
    -154,    84,  -154,  -153
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    37,    19,    20,    47,   156,    21,    22,
     118,   119,   157,   158
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      48,    63,    49,    50,   165,    86,    53,    87,    55,    56,
      57,    58,    59,    60,    61,    23,    56,    57,    58,    59,
      60,    61,   178,    85,    88,    24,    89,    90,    91,    92,
      93,    94,    95,   141,    25,   163,    62,    26,    27,    28,
     142,   164,    29,    62,    30,   120,    31,   122,   164,   123,
     124,   125,   126,   127,   128,   129,   130,    32,    33,    34,
      56,    57,    58,    59,    60,    61,     1,     2,    36,     3,
       4,     5,     6,     7,     8,     9,    35,   131,   132,   133,
      10,    11,    12,    13,    14,    38,    39,    62,    40,    41,
      42,    43,   154,    46,    44,    45,    51,    16,    56,    57,
      58,    59,    60,    61,   151,     1,     2,    64,     3,     4,
       5,     6,     7,     8,     9,    52,    65,   152,   155,    10,
      11,    12,    13,    14,    86,    62,    54,    66,    76,    77,
      68,    15,    67,    86,   143,   121,    16,   113,   114,   115,
     116,   117,    86,    88,   162,    89,    90,    91,    92,    93,
      94,    95,    88,    86,    89,    90,    91,    92,    93,    94,
      95,    88,    69,    89,    90,    91,    92,    93,    94,    95,
      78,    79,    88,    80,    89,    90,    91,    92,    93,    94,
      95,    81,    82,    70,    71,    72,    73,    74,    75,    83,
      84,    96,   101,   102,    97,    98,    99,   100,   103,   104,
     105,   106,   107,   111,   108,   109,   110,   134,   136,   137,
     135,   138,   139,   140,   144,   145,   112,   148,   153,   146,
     149,   147,   159,   160,   166,   161,   150,   179,     0,   167,
     183,     0,     0,     0,     0,     0,   168,     0,   170,   169,
       0,     0,     0,     0,   172,   175,   176,   171,   181,   174,
     180,   173,   184,   186,   182,   177,     0,   185
};

static const yytype_int16 yycheck[] =
{
      31,    40,    32,    33,   157,    20,    37,    22,    39,     3,
       4,     5,     6,     7,     8,     3,     3,     4,     5,     6,
       7,     8,   175,    62,    39,     3,    41,    42,    43,    44,
      45,    46,    47,    31,     3,    29,    30,     3,     3,     3,
      38,    35,     3,    30,    30,    84,    28,    86,    35,    88,
      89,    90,    91,    92,    93,    94,    95,    30,    30,    30,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    12,
      13,    14,    15,    16,    17,    18,    34,   108,   109,   110,
      23,    24,    25,    26,    27,    11,    28,    30,    19,    19,
      19,    19,    35,     3,    19,    19,    13,    40,     3,     4,
       5,     6,     7,     8,   143,     9,    10,     5,    12,    13,
      14,    15,    16,    17,    18,    36,     7,   147,   149,    23,
      24,    25,    26,    27,    20,    30,     3,     7,    31,    29,
       5,    35,     6,    20,    21,    31,    40,    13,    14,    15,
      16,    17,    20,    39,    22,    41,    42,    43,    44,    45,
      46,    47,    39,    20,    41,    42,    43,    44,    45,    46,
      47,    39,    20,    41,    42,    43,    44,    45,    46,    47,
      31,    31,    39,     3,    41,    42,    43,    44,    45,    46,
      47,    34,    30,    41,    42,    43,    44,    45,    46,    29,
      19,    22,     4,     4,    22,    22,    22,    22,     4,     4,
       4,     4,     4,    19,    28,    28,    28,     4,     3,     3,
      30,     3,     3,     3,    29,    29,    37,     5,    31,    29,
      28,    22,    22,    22,     3,    34,   142,     5,    -1,    36,
       5,    -1,    -1,    -1,    -1,    -1,    34,    -1,    34,    32,
      -1,    -1,    -1,    -1,    31,    28,    30,    36,    29,    34,
      30,    37,    22,    22,    31,    37,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    10,    12,    13,    14,    15,    16,    17,    18,
      23,    24,    25,    26,    27,    35,    40,    49,    50,    52,
      53,    56,    57,     3,     3,     3,     3,     3,     3,     3,
      30,    28,    30,    30,    30,    34,     0,    51,    11,    28,
      19,    19,    19,    19,    19,    19,     3,    54,    50,    54,
      54,    13,    36,    50,     3,    50,     3,     4,     5,     6,
       7,     8,    30,    55,     5,     7,     7,     6,     5,    20,
      41,    42,    43,    44,    45,    46,    31,    29,    31,    31,
       3,    34,    30,    29,    19,    55,    20,    22,    39,    41,
      42,    43,    44,    45,    46,    47,    22,    22,    22,    22,
      22,     4,     4,     4,     4,     4,     4,     4,    28,    28,
      28,    19,    37,    13,    14,    15,    16,    17,    58,    59,
      55,    31,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    50,    50,    50,     4,    30,     3,     3,     3,     3,
       3,    31,    38,    21,    29,    29,    29,    22,     5,    28,
      59,    55,    54,    31,    35,    50,    55,    60,    61,    22,
      22,    34,    22,    29,    35,    61,     3,    36,    34,    32,
      34,    36,    31,    37,    34,    28,    30,    37,    61,     5,
      30,    29,    31,     5,    22,    31,    22
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    51,    50,    50,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      53,    54,    54,    54,    54,    54,    54,    54,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    56,    57,    57,    57,    58,
      58,    58,    59,    59,    59,    59,    59,    60,    60,    60,
      61,    61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     3,     0,     5,     5,     5,     5,
       5,     5,     5,     7,     7,     4,     7,     9,     1,     1,
      15,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     3,     3,     5,     3,     3,     3,
       3,     3,     3,     3,     3,     9,     1,     1,     1,     0,
       1,     3,     2,     2,     2,     2,     2,     1,     1,     2,
       2,     9
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 76 "parser.y" /* yacc.c:1646  */
    { fprintf(output, "\n"); }
#line 1426 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 81 "parser.y" /* yacc.c:1646  */
    {fprintf(output, "class %s {\n", (yyvsp[-3].ystr)); fprintf(output, "%s", (yyvsp[-1].ystr)); fprintf(output, "};\n"); }
#line 1432 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 82 "parser.y" /* yacc.c:1646  */
    { fprintf(output, "int %s = %s;\n", (yyvsp[-3].ystr), (yyvsp[-1].ystr)); }
#line 1438 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 83 "parser.y" /* yacc.c:1646  */
    { fprintf(output, "char %s[] = %s;\n", (yyvsp[-3].ystr), (yyvsp[-1].ystr)); }
#line 1444 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 84 "parser.y" /* yacc.c:1646  */
    { fprintf(output, "float %s = %.1f;\n", (yyvsp[-3].ystr), (yyvsp[-1].yfloat)); }
#line 1450 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 85 "parser.y" /* yacc.c:1646  */
    { fprintf(output, "double %s = %.2f;\n", (yyvsp[-3].ystr), (yyvsp[-1].yfloat)); }
#line 1456 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 86 "parser.y" /* yacc.c:1646  */
    { fprintf(output, "boolean %s = %s;\n", (yyvsp[-3].ystr), (yyvsp[-1].ystr) ? "true" : "false"); }
#line 1462 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 87 "parser.y" /* yacc.c:1646  */
    { fprintf(output, "char %s[] = %s;\n", (yyvsp[-3].ystr), (yyvsp[-1].ystr)); }
#line 1468 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 88 "parser.y" /* yacc.c:1646  */
    { fprintf(output, "if (%s) {\n", (yyvsp[-4].ystr)); fprintf(output, "}"); }
#line 1474 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 89 "parser.y" /* yacc.c:1646  */
    { fprintf(output, "else if (%s) {\n", (yyvsp[-4].ystr)); fprintf(output, "}"); }
#line 1480 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 90 "parser.y" /* yacc.c:1646  */
    { fprintf(output, "else {\n"); fprintf(output, "}"); }
#line 1486 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 91 "parser.y" /* yacc.c:1646  */
    { fprintf(output, "while (%s) {\n", (yyvsp[-4].ystr)); fprintf(output, "}"); }
#line 1492 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 92 "parser.y" /* yacc.c:1646  */
    { fprintf(output, "std::cout << %s << std::endl;\n", (yyvsp[-2].ystr)); }
#line 1498 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 98 "parser.y" /* yacc.c:1646  */
    {
            fprintf(output, "for (int %s = %d; %s; %s++) {\n%s\n}", (yyvsp[-11].ystr), (yyvsp[-9].yint), (yyvsp[-7].ystr), (yyvsp[-5].ystr), (yyvsp[-1].ystr));
        }
#line 1506 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 104 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = create_condition((yyvsp[-2].ystr), "==", (yyvsp[0].yint)); }
#line 1512 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 105 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = create_condition((yyvsp[-2].ystr), ">", (yyvsp[0].yint)); }
#line 1518 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 106 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = create_condition((yyvsp[-2].ystr), "<", (yyvsp[0].yint)); }
#line 1524 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 107 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = create_condition((yyvsp[-2].ystr), ">=", (yyvsp[0].yint)); }
#line 1530 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 108 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = create_condition((yyvsp[-2].ystr), "<=", (yyvsp[0].yint)); }
#line 1536 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 109 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = create_condition((yyvsp[-2].ystr), "&&", (yyvsp[0].yint)); }
#line 1542 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 110 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = create_condition((yyvsp[-2].ystr), "||", (yyvsp[0].yint)); }
#line 1548 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 114 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = (char *)malloc(20);snprintf((yyval.ystr), 20, "%d", (yyvsp[0].yint));}
#line 1554 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 115 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = strdup((yyvsp[0].ystr)); }
#line 1560 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = strdup((yyvsp[0].ystr)); }
#line 1566 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 117 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = (char *)malloc(20); snprintf((yyval.ystr), 20, "%.1f", (yyvsp[0].yfloat)); }
#line 1572 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 118 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = (char *)malloc(20); snprintf((yyval.ystr), 20, "%.2f", (yyvsp[0].ydouble)); }
#line 1578 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 119 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = strdup((yyvsp[0].ystr)); }
#line 1584 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 120 "parser.y" /* yacc.c:1646  */
    { fprintf(output, "%s = %s;\n", (yyvsp[-2].ystr), (yyvsp[0].ystr)); (yyval.ystr) = strdup((yyvsp[-2].ystr));}
#line 1590 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 121 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = (char *)malloc(100); snprintf((yyval.ystr), 100, "(%s)", (yyvsp[-1].ystr));}
#line 1596 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 122 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = (char *)malloc(100);  snprintf((yyval.ystr), 100, "(%s ? %s : %s)", (yyvsp[-4].ystr), (yyvsp[-2].ystr), (yyvsp[0].ystr)); }
#line 1602 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 123 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = (char *)malloc(100);snprintf((yyval.ystr), 100, "%s > %s", (yyvsp[-2].ystr), (yyvsp[0].ystr));}
#line 1608 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 124 "parser.y" /* yacc.c:1646  */
    {(yyval.ystr) = (char *)malloc(100); snprintf((yyval.ystr), 100, "%s < %s", (yyvsp[-2].ystr), (yyvsp[0].ystr));}
#line 1614 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 125 "parser.y" /* yacc.c:1646  */
    {(yyval.ystr) = (char *)malloc(100);snprintf((yyval.ystr), 100, "%s == %s", (yyvsp[-2].ystr), (yyvsp[0].ystr));}
#line 1620 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 126 "parser.y" /* yacc.c:1646  */
    {(yyval.ystr) = (char *)malloc(100); snprintf((yyval.ystr), 100, "%s >= %s", (yyvsp[-2].ystr), (yyvsp[0].ystr));}
#line 1626 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 127 "parser.y" /* yacc.c:1646  */
    {(yyval.ystr) = (char *)malloc(100);snprintf((yyval.ystr), 100, "%s <= %s", (yyvsp[-2].ystr), (yyvsp[0].ystr));}
#line 1632 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 128 "parser.y" /* yacc.c:1646  */
    {(yyval.ystr) = (char *)malloc(100);snprintf((yyval.ystr), 100, "%s && %s", (yyvsp[-2].ystr), (yyvsp[0].ystr));}
#line 1638 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 129 "parser.y" /* yacc.c:1646  */
    {(yyval.ystr) = (char *)malloc(100);snprintf((yyval.ystr), 100, "%s || %s", (yyvsp[-2].ystr), (yyvsp[0].ystr));}
#line 1644 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 130 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = (char *)malloc(100); snprintf((yyval.ystr), 100, "%s + %s", (yyvsp[-2].ystr), (yyvsp[0].ystr));
}
#line 1651 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 135 "parser.y" /* yacc.c:1646  */
    { 
            fprintf(output, "%s void %s(%s) {\n%s\n}\n", (yyvsp[-8].ystr), (yyvsp[-6].ystr), (yyvsp[-4].ystr), (yyvsp[-1].ystr));
        }
#line 1659 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = strdup("public"); }
#line 1665 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = strdup("private"); }
#line 1671 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 143 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = strdup("protected"); }
#line 1677 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = strdup(""); }
#line 1683 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 148 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = (yyvsp[0].ystr); }
#line 1689 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 149 "parser.y" /* yacc.c:1646  */
    { 
            (yyval.ystr) = (char *)malloc(strlen((yyvsp[-2].ystr)) + strlen((yyvsp[0].ystr)) + 3);
            sprintf((yyval.ystr), "%s, %s", (yyvsp[-2].ystr), (yyvsp[0].ystr));
        }
#line 1698 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 156 "parser.y" /* yacc.c:1646  */
    { 
            (yyval.ystr) = (char *)malloc(strlen("int ") + strlen((yyvsp[0].ystr)) + 1);
            sprintf((yyval.ystr), "int %s", (yyvsp[0].ystr));
        }
#line 1707 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 160 "parser.y" /* yacc.c:1646  */
    { 
            (yyval.ystr) = (char *)malloc(strlen("char* ") + strlen((yyvsp[0].ystr)) + 1);
            sprintf((yyval.ystr), "char* %s", (yyvsp[0].ystr));
        }
#line 1716 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 164 "parser.y" /* yacc.c:1646  */
    { 
            (yyval.ystr) = (char *)malloc(strlen("float ") + strlen((yyvsp[0].ystr)) + 1);
            sprintf((yyval.ystr), "float %s", (yyvsp[0].ystr));
        }
#line 1725 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 168 "parser.y" /* yacc.c:1646  */
    { 
            (yyval.ystr) = (char *)malloc(strlen("double ") + strlen((yyvsp[0].ystr)) + 1);
            sprintf((yyval.ystr), "double %s", (yyvsp[0].ystr));
        }
#line 1734 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 172 "parser.y" /* yacc.c:1646  */
    { 
            (yyval.ystr) = (char *)malloc(strlen("bool ") + strlen((yyvsp[0].ystr)) + 1);
            sprintf((yyval.ystr), "bool %s", (yyvsp[0].ystr));
        }
#line 1743 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = (yyvsp[0].ystr); }
#line 1749 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyval.ystr) = (yyvsp[0].ystr); }
#line 1755 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 181 "parser.y" /* yacc.c:1646  */
    { 
            (yyval.ystr) = (char *)malloc(strlen((yyvsp[-1].ystr)) + strlen((yyvsp[0].ystr)) + 1);
            sprintf((yyval.ystr), "%s%s", (yyvsp[-1].ystr), (yyvsp[0].ystr));
        }
#line 1764 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 188 "parser.y" /* yacc.c:1646  */
    { 
            (yyval.ystr) = (char *)malloc(strlen((yyvsp[-1].ystr)) + 2);
            sprintf((yyval.ystr), "%s;\n", (yyvsp[-1].ystr));
        }
#line 1773 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 192 "parser.y" /* yacc.c:1646  */
    {
            (yyval.ystr) = (char *)malloc(strlen("std::cout << ") + strlen((yyvsp[-2].ystr)) + strlen(" << std::endl;\n") + 1);
            sprintf((yyval.ystr), "std::cout << %s << std::endl;\n", (yyvsp[-2].ystr));
        }
#line 1782 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1786 "parser.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 198 "parser.y" /* yacc.c:1906  */
 

    int main(int argc, char *argv[])
    {
        init_stringpool(10000);
        output = fopen("output.cpp","w");
        if (output == NULL) {
            perror("Erro ao abrir o arquivo");
            exit(EXIT_FAILURE);
        }

        if (yyparse() == 0) printf("Código sem erros \n");
    }

    void yyerror(char *s) /* Called by yyparse on error */
    {
        printf("%s na linha %d\n", s, yylineno);
    }
