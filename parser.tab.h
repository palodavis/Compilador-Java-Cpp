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
    INT_TYPE = 264,
    STRING_TYPE = 265,
    FLOAT_TYPE = 266,
    DOUBLE_TYPE = 267,
    BOOLEAN_TYPE = 268,
    CHAR_TYPE = 269,
    ASSIGN = 270,
    EQUAL = 271,
    SEMICOLON = 272,
    IF_TYPE = 273,
    ELSE_TYPE = 274,
    ELSE_IF = 275,
    WHILE_TYPE = 276,
    FOR_TYPE = 277,
    LBRACE = 278,
    RBRACE = 279,
    LPARENTHESES = 280,
    RPARENTHESES = 281,
    PLUS_PLUS = 282,
    MINUS_MINUS = 283,
    DOT = 284,
    SYSTEM = 285,
    OUT = 286,
    PRINTLN = 287,
    GREATER = 288,
    LESS = 289,
    GREATER_EQUAL = 290,
    LESS_EQUAL = 291,
    AND = 292,
    OR = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 39 "parser.y" /* yacc.c:1909  */

    int yint;         // Para valores inteiros
    float yfloat;     // Para valores de ponto flutuante (float)
    double ydbl;      // Para valores de ponto flutuante (double)
    char *ystr;       // Para strings
    int ybool;        // Para booleanos (1 para true, 0 para false)

#line 101 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
