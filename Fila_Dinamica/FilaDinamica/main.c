#include "FilaDinamica.h"

int main()
{
    FILA x;
    REGISTRO reg;

    inicializarFila(&x);

    reg.elemento = 2;
    inserirElemFila(&x, reg);
    exibirFila(&x);

    reg.elemento = 1;
    inserirElemFila(&x, reg);
    exibirFila(&x);

    reg.elemento = 9;
    inserirElemFila(&x, reg);
    exibirFila(&x);

    reg.elemento = 5;
    inserirElemFila(&x, reg);
    exibirFila(&x);

    reg.elemento = 7;
    inserirElemFila(&x, reg);
    exibirFila(&x);

    excluirElemFila(&x);
    exibirFila(&x);

    excluirElemFila(&x);
    exibirFila(&x);

    reg.elemento = 6;
    inserirElemFila(&x, reg);
    exibirFila(&x);

    printf("Tamanho: %d\n", tamanhoFila(&x));

    reinicializarFila(&x);
    exibirFila(&x);

    reg.elemento = 10;
    inserirElemFila(&x, reg);
    exibirFila(&x);
    return 0;
}
