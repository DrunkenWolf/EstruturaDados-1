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

    reg.elemento = 5;
    inserirElemListaOrd(&x, reg);

    reg.elemento = 1;
    inserirElemListaOrd(&x, reg);

    reg.elemento = 10;
    inserirElemListaOrd(&x, reg);

    exibirLista(&x);

    reg.elemento = 7;
    inserirElemListaOrd(&y, reg);

    reg.elemento = 0;
    inserirElemListaOrd(&y, reg);

    reg.elemento = 4;
    inserirElemListaOrd(&y, reg);

    reg.elemento = 8;
    inserirElemListaOrd(&y, reg);

    reg.elemento = 9;
    inserirElemListaOrd(&y, reg);

    exibirLista(&y);

    preencherLista3(&x, &y, &z); //exercício 3

    exibirListaFinal(&z);
    return 0;
}
