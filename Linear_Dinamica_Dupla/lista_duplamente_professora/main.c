#include "duplamente.h"

int main()
{
    LISTA lista;
    REGISTRO reg;
    TIPOCHAVE chave;

    inicializarLista(&lista);

    reg.chave=3;
    inserirElemListaOrd(&lista, reg);

    reg.chave=19;
    inserirElemListaOrd(&lista, reg);

    reg.chave=2;
    inserirElemListaOrd(&lista, reg);

    reg.chave=5;
    inserirElemListaOrd(&lista, reg);

    exibirLista(&lista);

    chave=3;
    if(buscaSequencialOrd(&lista,chave)==-1) printf("\nO elemento 3 nao estah na lista");
    else printf("\nO elemento 3 estah na lista");

    chave=0;
    if(buscaSequencialOrd(&lista,chave)==-1) printf("\nO elemento 0 nao estah na lista");
    else printf("\nO elemento 0 nao estah na lista");

    if(excluiElemLista(&lista, 3)==-1) printf("\nO elemento 3 nao estah na lista");
    else printf("\nO elemento 3 foi excluído");

    reinicializaLista(&lista);
    return 0;
}
