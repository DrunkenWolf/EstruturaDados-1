#include "matrizEsparsa.h"

int main()
{
    MATRIZ M1, M2, M3;

    inicializarMatriz(&M1, 300, 1000);
    inicializarMatriz(&M2, 1000, 300);
    inicializarMatriz(&M3, 1, 1);

    inserirElemMatriz(&M1, 0, 0, 1);
    inserirElemMatriz(&M1, 1, 1, 2);
    inserirElemMatriz(&M1, 2, 2, 3);
    inserirElemMatriz(&M1, 0, 2, -1);

    inserirElemMatriz(&M2, 0, 0, 4);
    inserirElemMatriz(&M2, 1, 1, 5);
    inserirElemMatriz(&M2, 2, 2, 6);
    inserirElemMatriz(&M2, 0, 2, 11);
    inserirElemMatriz(&M2, 20, 2, 42);

    exibirMatriz(&M1);
    exibirMatriz(&M2);

    printf("Resultado: %d\n", multiplicarMatrizes(&M1, &M2, &M3));

    exibirMatriz(&M3);

    reinicializarMatriz(&M1);
    reinicializarMatriz(&M2);
    reinicializarMatriz(&M3);
    return 0;
}
