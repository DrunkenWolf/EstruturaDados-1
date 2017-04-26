#include "PilhaDinamica.h"

int main()
{
    PILHA x;
    REGISTRO reg;

    inicializarPilha(&x);

    reg.chave = 2;
    inserirElemPilha(&x, reg);
    exibirPilha(&x);

    reg.chave = 1;
    inserirElemPilha(&x, reg);
    exibirPilha(&x);

    reg.chave = 0;
    inserirElemPilha(&x, reg);
    exibirPilha(&x);

    reg.chave = 4;
    inserirElemPilha(&x, reg);
    exibirPilha(&x);

    reg.chave = 3;
    inserirElemPilha(&x, reg);
    exibirPilha(&x);

    excluirElemPilha(&x);
    exibirPilha(&x);

    excluirElemPilha(&x);
    exibirPilha(&x);
    return 0;
}

