#include "FilaEstatica.h"

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
    return 0;
}
