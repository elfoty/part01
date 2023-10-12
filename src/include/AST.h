#ifndef AST_H
#define AST_H

typedef struct AST_STRUCT
{
    enum{
        AST_DEF_VAR,
        AST_VAR,
        AST_CHAMADA_FUN,
        ADT_STRING
    } type;

    //definicao de variavel
    char* var_def_name;
    struct AST_STRUCT* var_def_value;

    //variavel
    char* var_name;

    //chamada de funcao
    char* chamada_fun_nome;
    struct AST_STRUCT** chamda_fun_arg
} ast_T;
#endif