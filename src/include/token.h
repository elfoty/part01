#ifndef TOKEN_H
#define TOKEN_H
typedef struct TOKEN_STRUCT
{
    enum
    {
        TOKEN_INICIO,
        TOKEN_FIM,
        TOKEN_ID,
        TOKEN_IGUAL,
        TOKEN_STRING,
        TOKEN_CHAR,
        TOKEN_CHARS,
        TOKEN_PV,
        TOKEN_AP,
        TOKEN_FP,
        TOKEN_AC,
        TOKEN_FC,
        TOKEN_MAIS,
        TOKEN_MENOS,
        TOKEN_MULT,
        TOKEN_DIV,
        TOKEN_MOD,
        TOKEN_VIRG,
        TOKEN_IF,
        TOKEN_FOR,
        TOKEN_WHILE,
        TOKEN_INT,
        TOKEN_FLOAT,
        TOKEN_RESERVADA,
        TOKEN_DIGIT,
        TOKEN_SEPARADOR,
        TOKEN_MENOR,
        TOKEN_MAIOR,
        TOKEN_MENORIGUAL,
        TOKEN_MAIORIGUAL,
        TOKEN_DIFERENTE,
        TOKEN_AND,
        TOKEN_OR,
        TOKEN_NOT
    } type;
    char* value;
} token_T;

token_T* init_token(int type, char* value);
#endif