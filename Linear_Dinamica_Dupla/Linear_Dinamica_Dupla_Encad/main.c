#include "Dinamica_Dupla.c"

int main(){
    LISTA x;
    inicializarLista(&x);
    exibirLista(&x);
    REGISTRO reg;
    reg.chave = 2;
    int a=inserirElemListaOrd(&x, reg);
    printf("%d\n", a);
    exibirLista(&x);
    reg.chave = 3;
    inserirElemListaOrd(&x, reg);
    exibirLista(&x);
    return 0;
}

