#include "SequencialOrdenada.h"

int main()
{
    LISTA x, y;
    LISTA_FINAL z;
    REGISTRO reg;

    inicializarLista(&x);
    inicializarLista(&y);
    inicializarListaFinal(&z);

    reg.elemento = 2;
    inserirElemListaOrd(&x, reg);

    reg.elemento = 3;
    inserirElemListaOrd(&x, reg);

    reg.elemento = 4;
    inserirElemListaOrd(&x, reg);

    reg.elemento = 4;
    inserirElemListaOrd(&x, reg);

    reg.elemento = 1;
    inserirElemListaOrd(&x, reg);

    exibirLista(&x);

    preencherLista3(&x, &y, &z);
    exibirListaFinal(&z);
    return 0;
}
