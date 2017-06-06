#include "matrizEsparsa.h"

int main()
{
    MATRIZ M1, M2, M3;

    inicializarMatriz(&M1, 3, 3);
    inicializarMatriz(&M2, 3, 3);
    inicializarMatriz(&M3, 3, 3);

    inserirElemMatriz(&M1, 0, 0, 1);
    inserirElemMatriz(&M1, 1, 1, 2);
    inserirElemMatriz(&M1, 2, 2, 3);
    inserirElemMatriz(&M1, 0, 2, -1);

    inserirElemMatriz(&M2, 0, 0, 4);
    inserirElemMatriz(&M2, 1, 1, 5);
    inserirElemMatriz(&M2, 2, 2, 6);
    inserirElemMatriz(&M2, 0, 2, 11);

    exibirMatriz(&M1);
    exibirMatriz(&M2);

    subtrairMatrizes(&M1, &M2, &M3);

    exibirMatriz(&M3);
    return 0;
}
