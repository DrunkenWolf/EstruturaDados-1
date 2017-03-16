#include <stdio.h>
#include <stdlib.h>

int main(){
    /*
    int x = 10;
    int y = -1;
    int b = 90;
    int k = -80;
    printf("x = %d, y = %d, b = %d, k = %d\n", x, y, b, k);
    x = y = b = k = 10;
    printf("* x = %d, y = %d, b = %d, k = %d\n", x, y, b, k);
    */

    //ponteiro
    /*
    int x = 10;
    int z = -8;
    int *y = &x;
    printf("x = %i, endereço(y) = %p, conteúdo(y) = %d", x, y, *y);
    */

    //pesquisar malloc, alloc e realoc

    //respeitar alocação e desalocação

    //alocação dinâmica
    /*
    int *y = malloc(sizeof(int));

    if (y == NULL){ //teste de alocação de memória e respota ao sistema
        printf("Não alocou memória corretamente\n");
        return 1;
    }

    free(y); //liberação de memória
    y = NULL; //boa prática
    */

    //preenchimento de memória
    /*
    int *y = malloc(sizeof(int));
    if (y == NULL){ //teste de alocação de memória e respota ao sistema
        printf("Não alocou memória corretamente\n");
        return 1;
    }
    *y = 20;
    printf("y = %d\n", *y);
    free(y); //liberação de memória
    y = NULL; //boa prática
    */


    return 0;
}
