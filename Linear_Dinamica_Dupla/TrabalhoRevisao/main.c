//IMPLEMENTAÇÃO DO TRABALHO SUPER BÔNUS  –  E.D.
//Nome : Rafael dos Santos Braz       RA: 120121

#include "Dinamica_Dupla.h"

int main(){
    LISTA l1, l2, l3;
    REGISTRO reg;

    inicializarLista(&l1);
    inicializarLista(&l2);
    inicializarLista(&l3);

    reg.chave = 2;
    inserirElemListaOrd(&l1, reg);
    reg.chave = 4;
    inserirElemListaOrd(&l1, reg);
    reg.chave = 5;
    inserirElemListaOrd(&l1, reg);
    reg.chave = 1;
    inserirElemListaOrd(&l1, reg);
    reg.chave = 12;
    inserirElemListaOrd(&l1, reg);

    exibirLista(&l1);

    reg.chave = 6;
    inserirElemListaOrdDecre(&l2, reg);
    reg.chave = 9;
    inserirElemListaOrdDecre(&l2, reg);
    reg.chave = 2;
    inserirElemListaOrdDecre(&l2, reg);
    reg.chave = 1;
    inserirElemListaOrdDecre(&l2, reg);
    reg.chave = 3;
    inserirElemListaOrdDecre(&l2, reg);

    exibirLista(&l2);

    reg.chave = 2;
    inserirElemListaOrdDecre(&l3, reg);
    reg.chave = 10;
    inserirElemListaOrdDecre(&l3, reg);
    reg.chave = 3;
    inserirElemListaOrdDecre(&l3, reg);
    reg.chave = 7;
    inserirElemListaOrdDecre(&l3, reg);
    reg.chave = 1;
    inserirElemListaOrdDecre(&l3, reg);
    reg.chave = 22;
    inserirElemListaOrdDecre(&l3, reg);

    exibirLista(&l3);

    LISTA l4 = juntarListas(&l1, &l2, &l3);

    exibirLista(&l4);
    return 0;
}
