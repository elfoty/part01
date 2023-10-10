#include "include/lexer.h"
#include "stdlib.h"

lexer_T* init_lexer(char* contents)
{
    lexer_T* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->contents = contents;
    lexer->i = 0;
    lexer->c = contents[lexer->i];

    return lexer;
}

void lexer_avanca(lexer_T* lexer)
{

}

void lexer_pulaws(lexer_T* lexer)
{

}

token_T* lexer_prox_token(lexer_T* lexer)
{

}

token_T* lexer_coleta_string(lexer_T lexer)
{

}

char* lexer_pega_char_atual_como_string(lexer_T* lexer)
{

}