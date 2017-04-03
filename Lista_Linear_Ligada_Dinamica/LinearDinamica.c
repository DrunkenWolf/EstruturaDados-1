#include <stdio.h>
#include <stdlib.h>

typedef struct aux{
    int chave;
    struct aux *prox;
} ELEMENTO;

typedef struct{
    ELEMENTO *inicio;
} LISTA;

void inicializarLista(LISTA *l){
    l->inicio = NULL;
}

