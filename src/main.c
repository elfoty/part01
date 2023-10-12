#include <stdio.h>
#include "include/lexer.h"

int main(int argc, char* argv[])
{
    lexer_T* lexer = init_lexer(
        "float name = \"jonh doe\";\n"
        "print(name)\n;"
        "print((10))"
        "var a = 12.36 + 30 - 40;"
        "se(aaa){ }"
        "sara;"
        "int semp = 10;"
    );
    FILE *arq;
    arq = fopen("saida.txt", "w");
    if(arq == NULL){
        printf("erro ao abrir arquivo");
    }

    token_T* token = (void*)0;

    while((token = lexer_prox_token(lexer)) != (void*)0){
        printf("TOKEN(%d, %s)\n", token->type, token->value);
        fprintf(arq, "TOKEN(%d, %s)\n", token->type, token->value);
    }
    return 0;
}
