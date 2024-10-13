
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include <stdbool.h>
    #include "sym.h"
    #define ASSERT(x,y) if(!(x)) printf("%s na  linha %d\n",(y),yylineno)
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
%}

%union {
    int yint;         // Para valores inteiros
    float yfloat;     // Para valores de ponto flutuante (float)
    double ydouble;      // Para valores de ponto flutuante (double)
    char *ystr;       // Para strings
    int ybool;        // Para booleanos (1 para true, 0 para false)
};

%start program
%token <ystr> IDENTIFIER
%token <yint> NUMBER_LITERAL
%token <ystr> STRING_LITERAL
%token <ystr> BOOLEAN_LITERAL
%token <yfloat> FLOAT_LITERAL
%token <ydouble> DOUBLE_LITERAL

%token CLASS INT_TYPE STRING_TYPE FLOAT_TYPE DOUBLE_TYPE BOOLEAN_TYPE CHAR_TYPE ASSIGN EQUAL SEMICOLON IF_TYPE ELSE_TYPE ELSE_IF WHILE_TYPE FOR_TYPE LBRACE RBRACE LPARENTHESES RPARENTHESES PLUS_PLUS MINUS_MINUS 
%token DOT SYSTEM OUT PRINTLN
%token GREATER LESS GREATER_EQUAL LESS_EQUAL AND OR

%type <ystr> condition
//%type <ystr> conditionWhile
%type <ystr> declarations

/* %type <ystr> for_increment
%type <ystr> for_initialization */

%%

// Regra principal
program:
    declarations
    ;

declarations:
    declaration { fprintf(output, "\n"); } declarations
    | /* empty */
;

declaration:
    INT_TYPE IDENTIFIER ASSIGN NUMBER_LITERAL SEMICOLON {fprintf(output, "int %s = %d;", $2, $4); }
    | CLASS IDENTIFIER LBRACE declarations RBRACE {
        fprintf(output, "class %s {\n", $2);
        fprintf(output, "%s", $4);  // Atributos da classe
        fprintf(output, "};\n");
    }
    | STRING_TYPE IDENTIFIER ASSIGN STRING_LITERAL SEMICOLON {fprintf(output, "char %s[] = %s;", $2, $4); }
    | FLOAT_TYPE IDENTIFIER ASSIGN FLOAT_LITERAL SEMICOLON {fprintf(output, "float %s = %.1f;", $2, $4); } 
    | DOUBLE_TYPE IDENTIFIER ASSIGN FLOAT_LITERAL SEMICOLON {fprintf(output, "double %s = %.2f;", $2, $4); }
    | BOOLEAN_TYPE IDENTIFIER ASSIGN BOOLEAN_LITERAL SEMICOLON {fprintf(output, "boolean %s = %s;", $2, $4 ? "true" : "false;");}
    | CHAR_TYPE IDENTIFIER ASSIGN STRING_LITERAL SEMICOLON {fprintf(output, "char %s[] = %s;", $2, $4); }
    | IF_TYPE LPARENTHESES condition RPARENTHESES LBRACE declarations RBRACE {fprintf(output, "if (%s) {\n", $3);fprintf(output, "}"); }
    | ELSE_IF LPARENTHESES condition RPARENTHESES LBRACE declarations RBRACE  {fprintf(output, "else if (%s) {\n", $3); fprintf(output, "}"); }
    | ELSE_TYPE LBRACE declarations RBRACE  {fprintf(output, "else {\n"); fprintf(output, "}");} 
    | WHILE_TYPE LPARENTHESES condition RPARENTHESES LBRACE declarations RBRACE { fprintf(output, "while (%s) {\n", $3);fprintf(output, "}"); } 
    | SYSTEM DOT OUT DOT PRINTLN LPARENTHESES STRING_LITERAL RPARENTHESES SEMICOLON {fprintf(output, "std::cout << %s << std::endl;\n", $7);}
    //| IDENTIFIER ASSIGN ternary_expression SEMICOLON {fprintf(output, "%s = %s;", $1, $3);}
    //| FOR_TYPE LPARENTHESES for_initialization condition SEMICOLON for_increment RPARENTHESES LBRACE declarations RBRACE { fprintf(output, "for (%s; %s; %s) {\n", $3, $5, $7);};
    //| if_declaration
;

condition:
    IDENTIFIER EQUAL NUMBER_LITERAL {$$ = create_condition($1, "==", $3);}
    | IDENTIFIER GREATER NUMBER_LITERAL {$$ = create_condition($1, ">", $3);}
    | IDENTIFIER LESS NUMBER_LITERAL {$$ = create_condition($1, "<", $3);}
    | IDENTIFIER GREATER_EQUAL NUMBER_LITERAL {$$ = create_condition($1, ">=", $3);}
    | IDENTIFIER LESS_EQUAL NUMBER_LITERAL {$$ = create_condition($1, "<=", $3);}
;

expressions: 
    STRING_LITERAL { fprintf(output, "%s", $1); }
    | NUMBER_LITERAL { fprintf(output, "%d", $1); }
    | FLOAT_LITERAL { fprintf(output, "%.1f", $1); }
    | DOUBLE_LITERAL { fprintf(output, "%.2f", $1); }
    | BOOLEAN_LITERAL { fprintf(output, "%s", $1); }
    | expressions '<' { fprintf(output, "<"); } expressions
    | expressions '>' { fprintf(output, ">"); } expressions
    | LPARENTHESES { fprintf(output, "("); } expressions RPARENTHESES { fprintf(output, ")"); }
;


%% 

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