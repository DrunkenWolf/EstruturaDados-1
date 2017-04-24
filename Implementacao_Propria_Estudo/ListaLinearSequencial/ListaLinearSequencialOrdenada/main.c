#include "SequencialOrdenada.h"

int main()
{
    LISTA x;
    REGISTRO reg;

    inicializarLista(&x);

    exibirLista(&x);


    reg.elemento = 2;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    reg.elemento = 3;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    reg.elemento = 4;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    reg.elemento = 4;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    reg.elemento = 1;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    //excluirElemLista(&x, 3);
    //exibirLista(&x);

    printf("%d\n", buscaBinaria(&x, 4));
    return 0;
}
