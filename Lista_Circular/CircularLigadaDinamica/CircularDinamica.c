#include "CircularDinamica.h"
#include <stdio.h>
#include <stdlib.h>

void inicializaLista(LISTA *l){
    l->cabeca = (PONT) malloc(sizeof(ELEMENTO));
    l->cabeca->prox = l->cabeca;
}

int tamanho(LISTA *l){
    PONT end = l->cabeca->prox;
    int tam = 0;
    while (end != l->cabeca){
        tam++;
        end = end->prox;
    }
    return tam;
}

void exibirLista(LISTA *l){
    PONT end = l->cabeca->prox;
    printf("Lista: \" ");
    while (end != l->cabeca){
        printf("%d ", end->reg-> achave);
        end = end->prox;
    }
    printf("\"");
}

PONT buscaSentinela(LISTA *l, TIPOCHAVE ch){
    PONT pos = l->cabeca->prox;
    l->cabeca->reg.chave = ch;
}
