#ifndef LEXER_H
#define LEXER_H
#include "token.h"

typedef struct LEXER_STRUCT
{
    char c;
    unsigned int i;
    char* contents;
} lexer_T;

lexer_T* init_lexer(char* contents);

void lexer_avanca(lexer_T* lexer);

void lexer_retorna(lexer_T* lexer);

void lexer_pulaws(lexer_T* lexer);

token_T* lexer_prox_token(lexer_T* lexer);

token_T* lexer_coleta_string(lexer_T* lexer);

token_T* lexer_coleta_id(lexer_T* lexer);

token_T* lexer_coleta_digito(lexer_T* lexer);

token_T* lexer_avanca_com_token(lexer_T* lexer, token_T* token);

char* lexer_pega_char_atual_como_string(lexer_T* lexer);
#endif
