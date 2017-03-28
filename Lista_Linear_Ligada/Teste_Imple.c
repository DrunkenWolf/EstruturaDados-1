#include "Implementacao_Professora.c"

int main(){
    LISTA x;
    REGISTRO r;
    
    r.chave = 42;
    inicializarLista(&x);
    exibirLista(&x);

    inserirElemListaOrd(&x, r);
    exibirLista(&x);

    r.chave = 50;
    inserirElemListaOrd(&x, r);
    exibirLista(&x);

    r.chave = 12;
    inserirElemListaOrd(&x, r);
    exibirLista(&x);

    r.chave = 5;
    inserirElemListaOrd(&x, r);
    exibirLista(&x);

    //printf("%d %d %d\n", x.inicio, x.A[3].reg.chave, x.A[x.A[3].prox].reg.chave);
    printf("%d\n", buscaSequencialOrd(&x, 12));

    printf("%d\n", tamanho(&x));

    printf("%d\n", excluirElemLista(&x, 12));
    exibirLista(&x);

    reinicializar(&x);
    exibirLista(&x);

    return 0;
}