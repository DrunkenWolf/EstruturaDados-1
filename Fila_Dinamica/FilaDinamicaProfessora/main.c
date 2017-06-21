#include "FilaDinamica.h"

int main()
{
    FILA fila;
    REGISTRO reg;

    inicializarFila(&fila);

    reg.chave = 10;
    inserirElemFila(&fila, reg);

    reg.chave = 2;
    inserirElemFila(&fila, reg);

    reg.chave = 1;
    inserirElemFila(&fila, reg);

    printf("Quantidade de elementos: %d\n", contaElemFila(&fila));

    exibirElemFila(&fila);

    reinicializar(&fila);
    return 0;
}
