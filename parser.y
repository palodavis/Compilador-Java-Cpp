    %{
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
    %}

    %union {
        int yint;         // Para valores inteiros
        float yfloat;     // Para valores de ponto flutuante (float)
        double ydouble;   // Para valores de ponto flutuante (double)
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
    %token <ystr> PUBLIC 
    %token <ystr> PRIVATE
    %token <ystr> VOID 


    %token CLASS INT_TYPE STRING_TYPE FLOAT_TYPE DOUBLE_TYPE BOOLEAN_TYPE CHAR_TYPE ASSIGN EQUAL COLON SEMICOLON IF_TYPE ELSE_TYPE ELSE_IF WHILE_TYPE FOR_TYPE LBRACE RBRACE LPARENTHESES RPARENTHESES PLUS_PLUS MINUS_MINUS 
    %token DOT SYSTEM OUT PRINTLN COMMA PLUS PROTECTED
    %token GREATER LESS GREATER_EQUAL LESS_EQUAL AND OR QUESTION

    %type <ystr> condition
    %type <ystr> declarations
    %type <ystr> expression
    %type <ystr> access_modifier parameters parameter method_body statement 
    %type <ystr> method_definition
    %type <ystr> for_loop
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
        CLASS IDENTIFIER LBRACE declarations RBRACE {fprintf(output, "class %s {\n", $2); fprintf(output, "%s", $4); fprintf(output, "};\n"); }
        | INT_TYPE IDENTIFIER ASSIGN expression SEMICOLON { fprintf(output, "int %s = %s;\n", $2, $4); }
        | STRING_TYPE IDENTIFIER ASSIGN STRING_LITERAL SEMICOLON { fprintf(output, "char %s[] = %s;\n", $2, $4); }
        | FLOAT_TYPE IDENTIFIER ASSIGN FLOAT_LITERAL SEMICOLON { fprintf(output, "float %s = %.1f;\n", $2, $4); } 
        | DOUBLE_TYPE IDENTIFIER ASSIGN FLOAT_LITERAL SEMICOLON { fprintf(output, "double %s = %.2f;\n", $2, $4); }
        | BOOLEAN_TYPE IDENTIFIER ASSIGN BOOLEAN_LITERAL SEMICOLON { fprintf(output, "boolean %s = %s;\n", $2, $4 ? "true" : "false"); }
        | CHAR_TYPE IDENTIFIER ASSIGN STRING_LITERAL SEMICOLON { fprintf(output, "char %s[] = %s;\n", $2, $4); }
        | IF_TYPE LPARENTHESES condition RPARENTHESES LBRACE declarations RBRACE { fprintf(output, "if (%s) {\n", $3); fprintf(output, "}"); }
        | ELSE_IF LPARENTHESES condition RPARENTHESES LBRACE declarations RBRACE  { fprintf(output, "else if (%s) {\n", $3); fprintf(output, "}"); }
        | ELSE_TYPE LBRACE declarations RBRACE  { fprintf(output, "else {\n"); fprintf(output, "}"); } 
        | WHILE_TYPE LPARENTHESES condition RPARENTHESES LBRACE declarations RBRACE { fprintf(output, "while (%s) {\n", $3); fprintf(output, "}"); } 
        | SYSTEM DOT OUT DOT PRINTLN LPARENTHESES STRING_LITERAL RPARENTHESES SEMICOLON { fprintf(output, "std::cout << %s << std::endl;\n", $7); }
        | method_definition   
        | for_loop
    ;

    for_loop:
        FOR_TYPE LPARENTHESES INT_TYPE IDENTIFIER ASSIGN NUMBER_LITERAL SEMICOLON condition SEMICOLON IDENTIFIER PLUS_PLUS RPARENTHESES LBRACE statement RBRACE {
            fprintf(output, "for (int %s = %d; %s; %s++) {\n%s\n}", $4, $6, $8, $10, $14);
        }
        ;

    condition:
        IDENTIFIER EQUAL NUMBER_LITERAL { $$ = create_condition($1, "==", $3); }
        | IDENTIFIER GREATER NUMBER_LITERAL { $$ = create_condition($1, ">", $3); }
        | IDENTIFIER LESS NUMBER_LITERAL { $$ = create_condition($1, "<", $3); }
        | IDENTIFIER GREATER_EQUAL NUMBER_LITERAL { $$ = create_condition($1, ">=", $3); }
        | IDENTIFIER LESS_EQUAL NUMBER_LITERAL { $$ = create_condition($1, "<=", $3); }
        | IDENTIFIER AND NUMBER_LITERAL { $$ = create_condition($1, "&&", $3); }
        | IDENTIFIER OR NUMBER_LITERAL { $$ = create_condition($1, "||", $3); }
    ;

    expression:
        NUMBER_LITERAL { $$ = (char *)malloc(20);snprintf($$, 20, "%d", $1);}
        | IDENTIFIER { $$ = strdup($1); }    
        | STRING_LITERAL { $$ = strdup($1); }
        | FLOAT_LITERAL { $$ = (char *)malloc(20); snprintf($$, 20, "%.1f", $1); }
        | DOUBLE_LITERAL { $$ = (char *)malloc(20); snprintf($$, 20, "%.2f", $1); }
        | BOOLEAN_LITERAL { $$ = strdup($1); }
        | IDENTIFIER ASSIGN expression { fprintf(output, "%s = %s;\n", $1, $3); $$ = strdup($1);}  
        | LPARENTHESES expression RPARENTHESES { $$ = (char *)malloc(100); snprintf($$, 100, "(%s)", $2);}
        | expression QUESTION expression COLON expression { $$ = (char *)malloc(100);  snprintf($$, 100, "(%s ? %s : %s)", $1, $3, $5); }  
        | expression GREATER expression { $$ = (char *)malloc(100);snprintf($$, 100, "%s > %s", $1, $3);}
        | expression LESS expression {$$ = (char *)malloc(100); snprintf($$, 100, "%s < %s", $1, $3);}
        | expression EQUAL expression {$$ = (char *)malloc(100);snprintf($$, 100, "%s == %s", $1, $3);}
        | expression GREATER_EQUAL expression {$$ = (char *)malloc(100); snprintf($$, 100, "%s >= %s", $1, $3);}
        | expression LESS_EQUAL expression {$$ = (char *)malloc(100);snprintf($$, 100, "%s <= %s", $1, $3);}
        | expression AND expression {$$ = (char *)malloc(100);snprintf($$, 100, "%s && %s", $1, $3);}
        | expression OR expression {$$ = (char *)malloc(100);snprintf($$, 100, "%s || %s", $1, $3);}
        | expression PLUS expression { $$ = (char *)malloc(100); snprintf($$, 100, "%s + %s", $1, $3);
}
    ;

    method_definition:
        access_modifier VOID IDENTIFIER LPARENTHESES parameters RPARENTHESES LBRACE method_body RBRACE { 
            fprintf(output, "%s void %s(%s) {\n%s\n}\n", $1, $3, $5, $8);
        }
    ;

    access_modifier:
        PUBLIC { $$ = strdup("public"); }
        | PRIVATE { $$ = strdup("private"); }
        | PROTECTED { $$ = strdup("protected"); }
    ;

    parameters:
        /* empty */ { $$ = strdup(""); }
        | parameter { $$ = $1; }
        | parameters COMMA parameter { 
            $$ = (char *)malloc(strlen($1) + strlen($3) + 3);
            sprintf($$, "%s, %s", $1, $3);
        }
    ;

    parameter:
        INT_TYPE IDENTIFIER { 
            $$ = (char *)malloc(strlen("int ") + strlen($2) + 1);
            sprintf($$, "int %s", $2);
        }
        | STRING_TYPE IDENTIFIER { 
            $$ = (char *)malloc(strlen("char* ") + strlen($2) + 1);
            sprintf($$, "char* %s", $2);
        }
        | FLOAT_TYPE IDENTIFIER { 
            $$ = (char *)malloc(strlen("float ") + strlen($2) + 1);
            sprintf($$, "float %s", $2);
        }
        | DOUBLE_TYPE IDENTIFIER { 
            $$ = (char *)malloc(strlen("double ") + strlen($2) + 1);
            sprintf($$, "double %s", $2);
        }
        | BOOLEAN_TYPE IDENTIFIER { 
            $$ = (char *)malloc(strlen("bool ") + strlen($2) + 1);
            sprintf($$, "bool %s", $2);
        }
    ;

    method_body:
        declarations { $$ = $1; }
        | statement { $$ = $1; }
        | method_body statement { 
            $$ = (char *)malloc(strlen($1) + strlen($2) + 1);
            sprintf($$, "%s%s", $1, $2);
        }
    ;

    statement:
        expression SEMICOLON { 
            $$ = (char *)malloc(strlen($1) + 2);
            sprintf($$, "%s;\n", $1);
        }
        | SYSTEM DOT OUT DOT PRINTLN LPARENTHESES STRING_LITERAL RPARENTHESES SEMICOLON {
            $$ = (char *)malloc(strlen("std::cout << ") + strlen($7) + strlen(" << std::endl;\n") + 1);
            sprintf($$, "std::cout << %s << std::endl;\n", $7);
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
