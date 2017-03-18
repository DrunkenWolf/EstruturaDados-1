#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef int TIPOCHAVE;

typedef struct{ //struct LISTA
    TIPOCHAVE A[MAX];
    int numElem;
} LISTA;

void inicializarLista(LISTA *l){
    l->numElem = 0;
}

int tamanho(LISTA l){
    return l.numElem;
}

void exibirLista(LISTA l){
    int i;
    printf("LISTA:\" ");
    for (i = 0; i < l.numElem; i++){
        printf("%i ", l.A[i]);
    }
    printf("\"\n");
}

void inserirElementoLista(LISTA *l, TIPOCHAVE item){
    if (l->numElem < MAX - 1){
        l->numElem++;
        l->A[l->numElem - 1] = item;
    }
}

void excluirElementoLista(LISTA *l, int elemento){
    elemento--;
    if (elemento >= 0 && elemento < l->numElem - 1){
        int c;
        for (c = elemento; c < l->numElem; c++){
            printf("LISTA: %i ------- %i\n", l->A[elemento], l->A[elemento + 1]);
            l->A[elemento] = l->A[elemento];
        }
        l->numElem--;
    }
}
