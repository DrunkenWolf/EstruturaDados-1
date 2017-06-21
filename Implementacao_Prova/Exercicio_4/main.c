#include "PilhaEstatica.h"

int main(){
    PILHA x;
    REGISTRO reg;

    inicializarPilha(&x); // ----------------------- a

    printf("pilha B vazia: %d\n", pilhaVaziaB(&x)); // ----------------------- b

    printf("pilhas cheias: %d\n", pilhasCheias(&x)); // ----------------------- c

    reg.chave = 2;
    empilhaA(&x, reg); // ----------------------- d

    reg.chave = 8;
    empilhaB(&x, reg); // ----------------------- e

    printf("pilha B vazia: %d\n", pilhaVaziaB(&x)); // ----------------------- b

    printf("pilha cheias: %d\n", pilhasCheias(&x)); // ----------------------- c

    desempilhaB(&x); // ----------------------- f

    return 0;
}
