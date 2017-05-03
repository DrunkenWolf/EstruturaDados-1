#include "LinearEstatica.h"

int main()
{
    LISTA x;
    REGISTRO reg;

    inicializarLista(&x); // ---------------------------- i

    reg.chave = 2;
    inserirElemListaOrd(&x, reg); // ---------------------------- iv
    exibirLista(&x);

    reg.chave = 1;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    reg.chave = 0;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    reg.chave = 4;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    reg.chave = 3;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    excluirElemListaOrd(&x, 0);
    exibirLista(&x);

    excluirElemListaOrd(&x, 3);
    exibirLista(&x);

    exibirMenorQuantElemValidos(&x); // ---------------------------- ii

    excluirMaiorElem(&x); // ---------------------------- iii
    exibirLista(&x);

    reg.chave = 5;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);
    return 0;
}

