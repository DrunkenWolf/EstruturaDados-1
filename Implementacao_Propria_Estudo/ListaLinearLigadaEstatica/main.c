#include "LinearEstatica.h"

int main()
{
    LISTA x;
    REGISTRO reg;

    inicializarLista(&x);

    reg.chave = 2;
    inserirElemLista(&x, reg);
    exibirLista(&x);

    reg.chave = 4;
    inserirElemLista(&x, reg);
    exibirLista(&x);

    reg.chave = 1;
    inserirElemLista(&x, reg);
    exibirLista(&x);
    return 0;
}

