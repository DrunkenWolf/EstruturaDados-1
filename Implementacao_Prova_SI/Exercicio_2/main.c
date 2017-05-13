#include "Dinamica_Dupla.h"

int main()
{
    LISTA x;
    REGISTRO reg;

    //inicializa��o
    inicializarLista(&x);//exercício 2a
    exibirLista(&x);

    //inser��o
    reg.chave = 2;
    inserirElemListaOrd(&x, reg); //exercício 2d
    exibirLista(&x);

    int quant = quantidadeExibirElemLista(&x); //exercício 2b

    remocaoMaiorElemLista(&x); //exercício 2c

    reg.chave = 4;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    reg.chave = 5;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    quant = quantidadeExibirMaiorElemLista(&x); //exercício 2e

    remocaoMaiorElemLista(&x);

    reg.chave = 1;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    reg.chave = 6;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    reg.chave = 2;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    reg.chave = 1;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    reg.chave = 7;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);

    //exclusao

    excluirElemLista(&x, 1);
    exibirLista(&x);

    excluirElemLista(&x, 4);
    exibirLista(&x);

    excluirElemLista(&x, 7);
    exibirLista(&x);

    //reinicializa��o
    reinicializarLista(&x);
    exibirLista(&x);

    return 0;
}
