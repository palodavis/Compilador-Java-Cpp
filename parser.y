%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include <stdbool.h>
    #include "sym.h"
    #define ASSERT(x,y) if(!(x)) printf("%s na linha %d\n",(y),yylineno)
    extern int yylineno;
    FILE *output;

    char identifierDefined[100];

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
    double ydbl;      // Para valores de ponto flutuante (double)
    char *ystr;       // Para strings
    int ybool;        // Para booleanos (1 para true, 0 para false)
};

%token <ystr> IDENTIFIER
%token <yint> NUMBER_LITERAL
%token <ystr> STRING_LITERAL
%token <ystr> BOOLEAN_LITERAL
%token <yfloat> FLOAT_LITERAL
%token <ydbl> DOUBLE_LITERAL

%token INT_TYPE STRING_TYPE FLOAT_TYPE DOUBLE_TYPE BOOLEAN_TYPE CHAR_TYPE ASSIGN EQUAL SEMICOLON IF_TYPE ELSE_TYPE ELSE_IF WHILE_TYPE LBRACE RBRACE LPARENTHESES RPARENTHESES
%token GREATER LESS GREATER_EQUAL LESS_EQUAL AND OR

%type <ystr> condition
%type <ystr> conditionWhile

%%

// Regra principal
program:
    declarations
    ;

declarations:
    declaration SEMICOLON { fprintf(output, ";\n"); } declarations
    | /* empty */
;

declaration:
    INT_TYPE IDENTIFIER ASSIGN NUMBER_LITERAL { fprintf(output, "int %s = %d", $2, $4); }
    | STRING_TYPE IDENTIFIER ASSIGN STRING_LITERAL { fprintf(output, "char %s[] = %s", $2, $4); }
    | FLOAT_TYPE IDENTIFIER ASSIGN NUMBER_LITERAL { fprintf(output, "float %s = %.1f", $2, $4); } 
    | DOUBLE_TYPE IDENTIFIER ASSIGN NUMBER_LITERAL { fprintf(output, "double %s = %.2f", $2, $4); }
    | BOOLEAN_TYPE IDENTIFIER ASSIGN BOOLEAN_LITERAL { 
          fprintf(output, "boolean %s = %s", $2, $4 ? "true" : "false");
      }
    | CHAR_TYPE IDENTIFIER ASSIGN STRING_LITERAL { fprintf(output, "char %s[] = %s", $2, $4); }
    | IF_TYPE LPARENTHESES condition RPARENTHESES LBRACE declarations RBRACE { 
        fprintf(output, "if (%s) {\n", $3); // Imprime a condição
        fprintf(output, "}"); // Adiciona o colchete de fechamento
    }
    | ELSE_IF LPARENTHESES condition RPARENTHESES LBRACE declarations RBRACE { 
        fprintf(output, "else if (%s) {\n", $3); // Imprime a condição
        fprintf(output, "}"); // Adiciona o colchete de fechamento
    }
    | ELSE_TYPE LBRACE RBRACE  {
        fprintf(output, "else {\n"); 
        fprintf(output, "}"); 
    } 
;

condition:
    IDENTIFIER EQUAL NUMBER_LITERAL { 
        fprintf($$, sizeof($$), "%s == %d", $1, $3);
    }
    | IDENTIFIER GREATER NUMBER_LITERAL {
        snprintf($$, sizeof($$), "%s > %d", $1, $3);
    }
    | IDENTIFIER LESS NUMBER_LITERAL {
        snprintf($$, sizeof($$), "%s < %d", $1, $3);
    }
    | IDENTIFIER GREATER_EQUAL NUMBER_LITERAL {
        snprintf($$, sizeof($$), "%s >= %d", $1, $3);
    }
    | IDENTIFIER LESS_EQUAL NUMBER_LITERAL {
        snprintf($$, sizeof($$), "%s <= %d", $1, $3);
    }
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
