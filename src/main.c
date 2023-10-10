#include <stdio.h>
#include "include/lexer.h"

int main(int argc, char* argv[])
{
    lexer_T* lexer = init_lexer(
        "var name = \"jonh doe\";\n"
        "print(name)\n;"
        "print(10)"
        "var a = 12 + 30 - 40;"
    );

    token_T* token = (void*)0;

    while((token = lexer_prox_token(lexer)) != (void*)0){
        printf("TOKEN(%d, %s)\n", token->type, token->value);
    }
    return 0;
}
