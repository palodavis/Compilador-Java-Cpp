
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

%token INT_TYPE STRING_TYPE FLOAT_TYPE DOUBLE_TYPE BOOLEAN_TYPE CHAR_TYPE ASSIGN EQUAL SEMICOLON IF_TYPE ELSE_TYPE ELSE_IF WHILE_TYPE FOR_TYPE LBRACE RBRACE LPARENTHESES RPARENTHESES PLUS_PLUS MINUS_MINUS 
%token DOT SYSTEM OUT PRINTLN
%token GREATER LESS GREATER_EQUAL LESS_EQUAL AND OR

%type <ystr> condition
%type <ystr> conditionWhile
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
    | STRING_TYPE IDENTIFIER ASSIGN STRING_LITERAL SEMICOLON {fprintf(output, "char %s[] = %s;", $2, $4); }
    | FLOAT_TYPE IDENTIFIER ASSIGN NUMBER_LITERAL SEMICOLON {fprintf(output, "float %s = %.1f;", $2, $4); } 
    | DOUBLE_TYPE IDENTIFIER ASSIGN NUMBER_LITERAL SEMICOLON {fprintf(output, "double %s = %.2f;", $2, $4); }
    | BOOLEAN_TYPE IDENTIFIER ASSIGN BOOLEAN_LITERAL SEMICOLON {fprintf(output, "boolean %s = %s;", $2, $4 ? "true" : "false;");}
    | CHAR_TYPE IDENTIFIER ASSIGN STRING_LITERAL SEMICOLON {fprintf(output, "char %s[] = %s;", $2, $4); }
    | IF_TYPE LPARENTHESES condition RPARENTHESES LBRACE declarations RBRACE {fprintf(output, "if (%s) {\n", $3); fprintf(output, "}"); }
    | ELSE_IF LPARENTHESES condition RPARENTHESES LBRACE declarations RBRACE  {fprintf(output, "else if (%s) {\n", $3);fprintf(output, "}"); }
    | ELSE_TYPE LBRACE RBRACE  {fprintf(output, "else {\n"); fprintf(output, "}");} 
    | WHILE_TYPE LPARENTHESES conditionWhile RPARENTHESES LBRACE declarations RBRACE { fprintf(output, "while (%s) {\n", $3);fprintf(output, "}"); } 
    | SYSTEM DOT OUT DOT PRINTLN LPARENTHESES STRING_LITERAL RPARENTHESES SEMICOLON {fprintf(output, "std::cout << %s << std::endl;\n", $7);}
    //| FOR_TYPE LPARENTHESES for_initialization condition SEMICOLON for_increment RPARENTHESES LBRACE declarations RBRACE { fprintf(output, "for (%s; %s; %s) {\n", $3, $5, $7);};
    //| if_declaration
;

//for_initialization:
//   declaration { $$ = $1; }  // Permite uma declaração como inicialização
//    | /* empty */ { $$ = ""; } // Permite inicialização vazia

//for_increment:
//    IDENTIFIER ASSIGN IDENTIFIER PLUS_PLUS { $$ = $1; } // Exemplo: i++
//    | IDENTIFIER ASSIGN IDENTIFIER MINUS_MINUS { $$ = $1; } // Exemplo: i--
//    | IDENTIFIER PLUS_PLUS { $$ = $1; } // Exemplo: i++
//    | IDENTIFIER MINUS_MINUS { $$ = $1; } // Exemplo: i--
//    | /* empty */ { $$ = ""; } // Permite incremento vazio

conditionWhile:
    IDENTIFIER EQUAL NUMBER_LITERAL {$$ = create_condition($1, "==", $3);}
    | IDENTIFIER GREATER NUMBER_LITERAL {$$ = create_condition($1, ">", $3);}
    | IDENTIFIER LESS NUMBER_LITERAL {$$ = create_condition($1, "<", $3);}
    | IDENTIFIER GREATER_EQUAL NUMBER_LITERAL {$$ = create_condition($1, ">=", $3);}
    | IDENTIFIER LESS_EQUAL NUMBER_LITERAL {$$ = create_condition($1, "<=", $3);}; 

condition:
    IDENTIFIER EQUAL NUMBER_LITERAL {$$ = create_condition($1, "==", $3);}
    | IDENTIFIER GREATER NUMBER_LITERAL {$$ = create_condition($1, ">", $3);}
    | IDENTIFIER LESS NUMBER_LITERAL {$$ = create_condition($1, "<", $3);}
    | IDENTIFIER GREATER_EQUAL NUMBER_LITERAL {$$ = create_condition($1, ">=", $3);}
    | IDENTIFIER LESS_EQUAL NUMBER_LITERAL {$$ = create_condition($1, "<=", $3);}
;


/* if_declaration: 
    IF_TYPE LPARENTHESES expressions RPARENTHESES LBRACE declarations RBRACE else_declaration {
        fprintf(output, "if (");
        fprintf(output, "%s", $3);  // Condição
        fprintf(output, ") {\n");
        fprintf(output, "%s", $6);  // Bloco de código
        fprintf(output, "}\n");
        fprintf(output, "%s", $7);  // Bloco else, se houver
    }
;

else_declaration:
    ELSE_TYPE LBRACE declarations RBRACE {
        fprintf(output, "else {\n");
        fprintf(output, "%s", $3);  // Bloco de código do else
        fprintf(output, "}\n");
    }
    | /* empty */
//;

/* expressions: 
    STRING_LITERAL { fprintf(output, "%s", $1); }
    | NUMBER_LITERAL { fprintf(output, "%d", $1); }
    | FLOAT_LITERAL { fprintf(output, "%.1f", $1); }
    | BOOLEAN_LITERAL { fprintf(output, "%s", $1); }
    | IDENTIFIER { fprintf(output, "%s", $1); }
    | IDENTIFIER EQUAL IDENTIFIER { fprintf(output, "%s == %s", $1, $3); }
    | IDENTIFIER GREATER IDENTIFIER { fprintf(output, "%s > %s", $1, $3); }
    | IDENTIFIER LESS IDENTIFIER { fprintf(output, "%s < %s", $1, $3); }
    | expressions LESS expressions { fprintf(output, "%s < %s", $1, $3); }
    | expressions GREATER expressions { fprintf(output, "%s > %s", $1, $3); }
    | expressions EQUAL expressions { fprintf(output, "%s == %s", $1, $3); }
    | expressions AND expressions { fprintf(output, "%s && %s", $1, $3); }
    | expressions OR expressions { fprintf(output, "%s || %s", $1, $3); }
    | LPARENTHESES expressions RPARENTHESES { fprintf(output, "(%s)", $2); }
;  */


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