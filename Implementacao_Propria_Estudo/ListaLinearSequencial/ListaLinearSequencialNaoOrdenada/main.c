#include "SequencialNaoOrdenada.h"

int main()
{
    LISTA x;
    REGISTRO reg;
    reg.elemento = 2;

    inicializarLista(&x);

    exibirLista(&x);

    inserirElemListaFinal(&x, reg);
    exibirLista(&x);

    reg.elemento = 4;
    inserirElemListaFinal(&x, reg);
    exibirLista(&x);

    reg.elemento = 5;
    inserirElemListaFinal(&x, reg);
    exibirLista(&x);

    reg.elemento = 3;
    inserirElemListaPosicao(&x, reg, 1);
    exibirLista(&x);

    excluirElemLista(&x, 3);
    exibirLista(&x);

    return 0;
}
