/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 38 "parser.y" /* yacc.c:1909  */

        int yint;         // Para valores inteiros
        float yfloat;     // Para valores de ponto flutuante (float)
        double ydouble;   // Para valores de ponto flutuante (double)
        char *ystr;       // Para strings
        int ybool;        // Para booleanos (1 para true, 0 para false)
    

#line 111 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
