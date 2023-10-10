#ifndef TOKEN_H
#define TOKEN_H
typedef struct TOKEN_STRUCT
{
    enum
    {
        TOKEN_ID,
        TOKEN_EQUALS,
        TOKEN_STRING,
        TOKEN_PV,
        TOKEN_AP,
        TOKEN_FP,
        TOKEN_AC,
        TOKEN_FC,
        TOKEN_MAIS,
        TOKEN_MENOS,
        TOKEN_VIRG
    } type;
    char* value;
} token_T;

token_T* init_token(int type, char* value);
#endif