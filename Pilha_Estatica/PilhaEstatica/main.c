#include "PilhaEstatica.h"

int main(){
    PILHA x;
    REGISTRO reg;

    inicializarLista(&x);

    reg.chave = 2;
    inserirElemPilha(&x, reg);
    exibirPilha(&x);

    reg.chave = 8;
    inserirElemPilha(&x, reg);
    exibirPilha(&x);

    excluirElemPilha(&x);
    exibirPilha(&x);

    excluirElemPilha(&x);
    exibirPilha(&x);

    excluirElemPilha(&x);
    exibirPilha(&x);
    return 0;
}
