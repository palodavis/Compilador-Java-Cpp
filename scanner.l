%{
#include "parser.tab.h"
char *stringpool(char *);
extern FILE * output;
%}
%option noyywrap


NUMBER      [0-9]+(\.[0-9]+)?
ID [a-z][0-9a-zA-Z_]*
STRING_LITERAL_WITH_SINGLE_QUOTE \'[^\']*\'
STRING_LITERAL_WITH_DOUBLE_QUOTE \"[^"]*\"

%%


{NUMBER}        { printf("Reconhecido: NUMBER_LITERAL (%s)\n", yytext); yylval.yint = atoi(yytext); return(NUMBER_LITERAL);}
{STRING_LITERAL_WITH_SINGLE_QUOTE}    { printf("Reconhecido: STRING_LITERAL (%s)\n", yytext); yylval.ystr = stringpool(yytext); return (STRING_LITERAL);}
{STRING_LITERAL_WITH_DOUBLE_QUOTE}    { printf("Reconhecido: STRING_LITERAL (%s)\n", yytext); yylval.ystr = stringpool(yytext); return (STRING_LITERAL);}
"int"           {printf("Reconhecido: INT_TYPE\n"); return(INT_TYPE);}
"String"           {printf("Reconhecido: STRING_TYPE\n"); return(STRING_TYPE);}
"float"         {printf("Reconhecido: FLOAT_TYPE\n"); return(FLOAT_TYPE);}
"double"         {printf("Reconhecido: DOUBLE_TYPE\n"); return(DOUBLE_TYPE);}
"boolean"        {printf("Reconhecido: BOOLEAN_TYPE\n"); return(BOOLEAN_TYPE);}
"true"  { printf("Reconhecido: BOOLEAN_LITERAL (true)\n"); yylval.ybool = 1; return BOOLEAN_LITERAL; }
"false" { printf("Reconhecido: BOOLEAN_LITERAL (false)\n"); yylval.ybool = 0; return BOOLEAN_LITERAL; }
"char"           {printf("Reconhecido: CHAR_TYPE\n"); return(CHAR_TYPE);}
"="             {printf("Reconhecido: ASSIGN\n"); return(ASSIGN);}
";"             { printf("Reconhecido: SEMICOLON\n"); return (SEMICOLON); }
{ID}            { printf("Reconhecido: IDENTIFIER (%s)\n", yytext); yylval.ystr = stringpool(yytext); return(IDENTIFIER);}
[ \t]+          { /* ignora espaços em branco */ }
\n              { /* ignora novas linhas */ }
.               { printf("Reconhecido: caractere desconhecido (%c)\n", yytext[0]); return(yytext[0]); }


%%