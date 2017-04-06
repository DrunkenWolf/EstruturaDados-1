#include "Dinamica_Dupla.h"

int main(){
    LISTA x;
    REGISTRO reg;

    inicializarLista(&x);
    exibirLista(&x);

    reg.chave = 2;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    reg.chave = 3;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    reg.chave = 4;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    reg.chave = 5;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    reg.chave = 1;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);
    return 0;
}

