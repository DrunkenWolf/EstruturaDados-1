#include "LinearCircular.h"

int main()
{
    LISTA x;
    REGISTRO reg;

    inicializarLista(&x); // ---------------------------------- a

    reg.chave = 2;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    reg.chave = 4;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    reg.chave = 1;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    reg.chave = 3;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    excluirElemListaOrd(&x, 4);
    exibirLista(&x);

    printf("-----\n");
    int resultado = tamanhoExibirLista(&x); // ---------------------------------- b
    printf("%d\n", resultado);
    return 0;
}

