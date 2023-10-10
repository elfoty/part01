#include "include/lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    if(lexer->c != '\0' && lexer->i < strlen(lexer->contents))
    {
        lexer->i+=1;
        lexer->c = lexer->contents[lexer->i];
    }
}

void lexer_pulaws(lexer_T* lexer)
{
    while(lexer->c == ' ' || lexer->c == 10)
    {
        lexer_avanca(lexer);
    }
}

token_T* lexer_prox_token(lexer_T* lexer)
{
    while(lexer->c != '\0' && lexer->i < strlen(lexer->contents))
    {
        if(lexer->c == ' ' || lexer->c == 10)
            lexer_pulaws(lexer);

        if(isalnum(lexer->c))
        {
            return lexer_coleta_id(lexer);
        }

        if(lexer->c == '"')
        {
            return lexer_coleta_string(lexer);
        }

        switch(lexer->c)
        {
            case '=': return lexer_avanca_com_token(lexer, init_token(TOKEN_EQUALS, lexer_pega_char_atual_como_string(lexer))); break;
            case ';': return lexer_avanca_com_token(lexer, init_token(TOKEN_PV, lexer_pega_char_atual_como_string(lexer))); break;
            case '(': return lexer_avanca_com_token(lexer, init_token(TOKEN_AP, lexer_pega_char_atual_como_string(lexer))); break;
            case ')': return lexer_avanca_com_token(lexer, init_token(TOKEN_FP, lexer_pega_char_atual_como_string(lexer))); break;
            case '{': return lexer_avanca_com_token(lexer, init_token(TOKEN_AC, lexer_pega_char_atual_como_string(lexer))); break;
            case '}': return lexer_avanca_com_token(lexer, init_token(TOKEN_FC, lexer_pega_char_atual_como_string(lexer))); break;
            case '+': return lexer_avanca_com_token(lexer, init_token(TOKEN_MAIS, lexer_pega_char_atual_como_string(lexer))); break;
            case '-': return lexer_avanca_com_token(lexer, init_token(TOKEN_MENOS, lexer_pega_char_atual_como_string(lexer))); break;
            case ',': return lexer_avanca_com_token(lexer, init_token(TOKEN_VIRG, lexer_pega_char_atual_como_string(lexer))); break;
        }
    }
    return (void*)0;
}

token_T* lexer_coleta_string(lexer_T* lexer)
{
    lexer_avanca(lexer);
    char* value =  calloc(1, sizeof(char));
    value[0] = '\0';

    while(lexer->c != '"'){
        char* s = lexer_pega_char_atual_como_string(lexer);
        value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
        strcat(value, s);
        lexer_avanca(lexer);
    }

    lexer_avanca(lexer);
    return init_token(TOKEN_STRING, value);
}

token_T* lexer_coleta_id(lexer_T* lexer)
{
    char* value =  calloc(1, sizeof(char));
    value[0] = '\0';
    while(isalnum(lexer->c))
    {
        char* s = lexer_pega_char_atual_como_string(lexer);
        value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
        strcat(value, s);
        lexer_avanca(lexer);
    }

    return init_token(TOKEN_ID, value);
}

token_T* lexer_avanca_com_token(lexer_T* lexer, token_T* token)
{
    lexer_avanca(lexer);
    return token;
}

char* lexer_pega_char_atual_como_string(lexer_T* lexer)
{
    char* str = calloc(2, sizeof(char));
    str[0] = lexer->c;
    str[1] = '\0';

    return str;
}