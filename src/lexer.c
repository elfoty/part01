#include "include/lexer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

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

void lexer_retorna(lexer_T* lexer)
{
    if(lexer->c != '\0' && lexer->i < strlen(lexer->contents))
    {
        lexer->i-=1;
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
    char* value =  calloc(1, sizeof(char));
    while(lexer->c != '\0' && lexer->i < strlen(lexer->contents))
    {
        value[0] = '\0';

        //whitespace
        if(lexer->c == ' ' || lexer->c == 10)
            lexer_pulaws(lexer);

        //digito
        if(isdigit(lexer->c))
        {
            return lexer_coleta_digito(lexer);
        }

        //inicio
        if(lexer->c == 'i')
        {
            for(int i=0;i<6;i++)
            {
                if((i==0)||(i==1 && lexer->c=='n')||(i==2&&lexer->c=='i')||(i==3&&lexer->c=='c')||(i==4&&lexer->c=='i')||(i==5&&lexer->c=='o'))
                {
                    char* s = lexer_pega_char_atual_como_string(lexer);
                    value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
                    strcat(value, s);
                    lexer_avanca(lexer);
                    if(i==5)
                    {
                        if(lexer->c == ' ' || lexer->c == 10)
                        {
                            lexer_retorna(lexer);
                            return lexer_avanca_com_token(lexer, init_token(TOKEN_INICIO, value));
                        }else{
                            for(int i = 0; i<6;i++)
                            {
                                lexer_retorna(lexer);
                            }
                        }
                    }
                }
            }
        }

        //inicio
        if(lexer->c == 'i')
        {
            for(int i=0;i<3;i++)
            {
                if((i==0)||(i==1 && lexer->c=='i')||(i==2&&lexer->c=='m'))
                {
                    char* s = lexer_pega_char_atual_como_string(lexer);
                    value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
                    strcat(value, s);
                    lexer_avanca(lexer);
                    if(i==2)
                    {
                        if(lexer->c == ' ' || lexer->c == 10)
                        {
                            lexer_retorna(lexer);
                            return lexer_avanca_com_token(lexer, init_token(TOKEN_FIM, value));
                        }else{
                            for(int i = 0; i<3;i++)
                            {
                                lexer_retorna(lexer);
                            }
                        }
                    }
                }
            }
        }

        //reconhece int
        if(lexer->c == 'i')
        {
            for(int i = 0; i<3;i++)
            {
                if((i==0)||(i==1 && lexer->c=='n')||(i==2&&lexer->c=='t'))
                {
                    char* s = lexer_pega_char_atual_como_string(lexer);
                    value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
                    strcat(value, s);
                    lexer_avanca(lexer);
                    if(i==2)
                    {
                        if(lexer->c == ' ' || lexer->c == 10)
                        {
                            lexer_retorna(lexer);
                            return lexer_avanca_com_token(lexer, init_token(TOKEN_INT, value));
                        }else{
                            for(int i = 0; i<3;i++)
                            {
                                lexer_retorna(lexer);
                            }
                        }
                    }
                }
            }
        }

        //reconhece float
        if(lexer->c == 'f')
        {
            for(int i = 0; i<5;i++)
            {
                if((i==0)||(i==1 && lexer->c=='l')||(i==2&&lexer->c=='o')||(i==3&&lexer->c=='a')||(i==4&&lexer->c=='t'))
                {
                    printf("c: %c, i: %d", lexer->c, i);
                    char* s = lexer_pega_char_atual_como_string(lexer);
                    value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
                    strcat(value, s);
                    lexer_avanca(lexer);
                    if(i==4)
                    {
                        if(lexer->c == ' ' || lexer->c == 10)
                        {
                            lexer_retorna(lexer);
                            return lexer_avanca_com_token(lexer, init_token(TOKEN_FLOAT, value));
                        }else{
                            lexer_retorna(lexer);
                            return (void*)0;
                        }
                    }
                }
            }
        }

        //verifica char
        if(lexer->c == 'c')
        {
            char* s = lexer_pega_char_atual_como_string(lexer);
            value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
            strcat(value, s);
            lexer_avanca(lexer);
            if(lexer->c == 'h')
            {
                char* s = lexer_pega_char_atual_como_string(lexer);
                value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
                strcat(value, s);
                lexer_avanca(lexer);
                if(lexer->c == 'a')
                {
                    char* s = lexer_pega_char_atual_como_string(lexer);
                    value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
                    strcat(value, s);
                    lexer_avanca(lexer);
                    if(lexer->c == 'r')
                    {
                        char* s = lexer_pega_char_atual_como_string(lexer);
                        value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
                        strcat(value, s);
                        lexer_avanca(lexer);
                        //verifica se se trata de um identificador usando uma palavra reservada

                        if(lexer->c == ' ' || lexer->c == 10)
                        {
                            lexer_retorna(lexer);
                            return lexer_avanca_com_token(lexer, init_token(TOKEN_CHAR, value));
                        }else if(lexer->c == 's'){
                            lexer_retorna(lexer);
                            return lexer_avanca_com_token(lexer, init_token(TOKEN_CHARS, "chars"));
                        }
                        else{
                            lexer_retorna(lexer);
                            lexer_retorna(lexer);
                            lexer_retorna(lexer);
                        }
                    }else{
                        lexer_retorna(lexer);
                        lexer_retorna(lexer);
                        lexer_retorna(lexer);
                    };
                }else{
                    lexer_retorna(lexer);
                    lexer_retorna(lexer);
                }
            }else{
                lexer_retorna(lexer);
            }
        }

        //diferente e not
        if(lexer->c == '!')
        {
            lexer_avanca(lexer);
            if(lexer->c == '=')
            {
                return lexer_avanca_com_token(lexer, init_token(TOKEN_DIFERENTE, "!="));
            }else if(lexer->c == ' ' || lexer->c == 10){
                lexer_retorna(lexer);
                return lexer_avanca_com_token(lexer, init_token(TOKEN_NOT, "!"));
            }else{
                lexer_retorna(lexer);
            }
        }

        //and
        if(lexer->c == '_')
        {
            lexer_avanca(lexer);
            if(lexer->c == 'E')
            {
                return lexer_avanca_com_token(lexer, init_token(TOKEN_AND, "_E"));
            }else{
                lexer_retorna(lexer);
            }
        }

        //or
        if(lexer->c == '_')
        {
            if(lexer->c == 'O')
            {
                return lexer_avanca_com_token(lexer, init_token(TOKEN_OR, "_O"));
            }else{
                lexer_retorna(lexer);
            }
        }

        //pi
        if(isalnum(lexer->c))
        {
            if(lexer->c == 'p'){
                if(lexer->c =='i'){
                    return lexer_avanca_com_token(lexer, init_token(TOKEN_RESERVADA, "pi"));
                }
            }
            //verifica se - if
            if(lexer->c == 's'){
                char* s = lexer_pega_char_atual_como_string(lexer);
                value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
                strcat(value, s);
                lexer_avanca(lexer);
                if(lexer->c == 'e'){
                    char* s = lexer_pega_char_atual_como_string(lexer);
                    value = realloc(value, (strlen(value) + strlen(s) + 1) *  sizeof(char));
                    strcat(value, s);
                    lexer_avanca(lexer);
                    //verifica se se trata de um identificador usando uma palavra reservada
                    if(lexer->c == '(' || lexer->c == ')'){
                        lexer_retorna(lexer);
                        return lexer_avanca_com_token(lexer, init_token(TOKEN_IF, value));
                    }else{
                        lexer_retorna(lexer);
                        lexer_retorna(lexer);
                    }
                }else{
                    lexer_retorna(lexer);
                }
            }

            //verifica enq - while
            if(lexer->c == 'e')
            {
                char* s = lexer_pega_char_atual_como_string(lexer);
                value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
                strcat(value, s);
                lexer_avanca(lexer);
                if(lexer->c == 'n')
                {
                    char* s = lexer_pega_char_atual_como_string(lexer);
                    value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
                    strcat(value, s);
                    lexer_avanca(lexer);
                    if(lexer->c == 'q')
                    {
                        char* s = lexer_pega_char_atual_como_string(lexer);
                        value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
                        strcat(value, s);
                        lexer_avanca(lexer);
                        //verifica se se trata de um identificador usando uma palavra reservada
                        if(lexer->c == '(' || lexer->c == '}'){
                            lexer_retorna(lexer);
                            return lexer_avanca_com_token(lexer, init_token(TOKEN_WHILE, value));
                        }else{
                            lexer_retorna(lexer);
                            lexer_retorna(lexer);
                        }                    }
                    else{
                        lexer_retorna(lexer);
                        lexer_retorna(lexer);
                    }
                }else{
                    lexer_retorna(lexer);
                }
            }

            //verifica for - laco
            if(lexer->c == 'l')
            {
                char* s = lexer_pega_char_atual_como_string(lexer);
                value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
                strcat(value, s);
                lexer_avanca(lexer);
                if(lexer->c == 'a')
                {
                    char* s = lexer_pega_char_atual_como_string(lexer);
                    value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
                    strcat(value, s);
                    lexer_avanca(lexer);
                    if(lexer->c == 'c')
                    {
                        char* s = lexer_pega_char_atual_como_string(lexer);
                        value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
                        strcat(value, s);
                        lexer_avanca(lexer);
                        if(lexer->c == 'o')
                        {
                            char* s = lexer_pega_char_atual_como_string(lexer);
                            value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
                            strcat(value, s);
                            lexer_avanca(lexer);
                            //verifica se se trata de um identificador usando uma palavra reservada
                            if(lexer->c == '(' || lexer->c == '}'){
                                lexer_retorna(lexer);
                                return lexer_avanca_com_token(lexer, init_token(TOKEN_FOR, value));
                            }else{
                                lexer_retorna(lexer);
                                lexer_retorna(lexer);
                                lexer_retorna(lexer);
                            }
                        }else{
                            lexer_retorna(lexer);
                            lexer_retorna(lexer);
                            lexer_retorna(lexer);
                        };
                    }else{
                        lexer_retorna(lexer);
                        lexer_retorna(lexer);
                    }
                }else{
                    lexer_retorna(lexer);
                }
            }


            return lexer_coleta_id(lexer);
        }

        if(lexer->c == '"')
            return lexer_coleta_string(lexer);


        switch(lexer->c)
        {
            case '=': return lexer_avanca_com_token(lexer, init_token(TOKEN_IGUAL, lexer_pega_char_atual_como_string(lexer))); break;
            case ';': return lexer_avanca_com_token(lexer, init_token(TOKEN_PV, lexer_pega_char_atual_como_string(lexer))); break;
            case '(': return lexer_avanca_com_token(lexer, init_token(TOKEN_AP, lexer_pega_char_atual_como_string(lexer))); break;
            case ')': return lexer_avanca_com_token(lexer, init_token(TOKEN_FP, lexer_pega_char_atual_como_string(lexer))); break;
            case '{': return lexer_avanca_com_token(lexer, init_token(TOKEN_AC, lexer_pega_char_atual_como_string(lexer))); break;
            case '}': return lexer_avanca_com_token(lexer, init_token(TOKEN_FC, lexer_pega_char_atual_como_string(lexer))); break;
            case '+': return lexer_avanca_com_token(lexer, init_token(TOKEN_MAIS, lexer_pega_char_atual_como_string(lexer))); break;
            case '-': return lexer_avanca_com_token(lexer, init_token(TOKEN_MENOS, lexer_pega_char_atual_como_string(lexer))); break;
            case ',': return lexer_avanca_com_token(lexer, init_token(TOKEN_VIRG, lexer_pega_char_atual_como_string(lexer))); break;
            case '.': return lexer_avanca_com_token(lexer, init_token(TOKEN_SEPARADOR, lexer_pega_char_atual_como_string(lexer))); break;
            case '<':
                lexer_avanca(lexer);
                if(lexer->c=='=')
                {
                    return init_token(TOKEN_MENORIGUAL, "<=");
                }else{
                    return lexer_avanca_com_token(lexer, init_token(TOKEN_MENOR, lexer_pega_char_atual_como_string(lexer)));
                }
            case '>': lexer_avanca(lexer);
                if(lexer->c=='=')
                {
                    return init_token(TOKEN_MAIORIGUAL, ">=");
                }else {
                    return lexer_avanca_com_token(lexer,
                                                  init_token(TOKEN_MAIOR, lexer_pega_char_atual_como_string(lexer)));
                }
                break;
            case '/': return lexer_avanca_com_token(lexer, init_token(TOKEN_DIV, lexer_pega_char_atual_como_string(lexer))); break;
            case '%': return lexer_avanca_com_token(lexer, init_token(TOKEN_MOD, lexer_pega_char_atual_como_string(lexer))); break;
            case '*': return lexer_avanca_com_token(lexer, init_token(TOKEN_MULT, lexer_pega_char_atual_como_string(lexer))); break;
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

token_T* lexer_coleta_digito(lexer_T* lexer)
{
    return lexer_avanca_com_token(lexer, init_token(TOKEN_DIGIT, lexer_pega_char_atual_como_string(lexer)));
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