//#include "Dinamica_Dupla.h"
#include <stdio.h>
#include <stdlib.h>

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux *prox, *ant;
} ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct {
    PONT inicio, fim;
} LISTA;

void inicializarLista(LISTA *l) {
    l->inicio = l->fim = NULL;
}

int tamanhoLista(LISTA *l) {
    PONT atual = l->inicio;
    PONT f = l->fim;
    int tam = 0;
    while (atual != f) {
        tam++;
        atual = atual->prox;
    }
    return tam;
}

void exibirLista(LISTA *l) {
    PONT end = l->inicio;
    printf("Lista: \"");
    while (end != NULL) {
        printf("%d ", end->reg.chave);
        end = end->prox;
    }
    printf("\"\n");
}

PONT buscaSequencial(LISTA *l, TIPOCHAVE ch) {
    PONT pos = l->inicio;
    while (pos != NULL && pos->reg.chave < ch) {
        pos = pos->prox;
    }
    if (pos != NULL && pos->reg.chave == ch) {
        return pos;
    }
    return NULL;
}

int inserirElemListaOrd(LISTA *l, REGISTRO reg) {
    TIPOCHAVE ch = reg.chave;
    PONT ant, i;
    if (buscaSequencial(l, ch) == NULL){
        PONT pos = l->inicio;
        i = (PONT) malloc(sizeof (ELEMENTO));
        i->reg = reg;
        while (pos != NULL && pos->reg.chave < ch) {
            pos = pos->prox;
        }
        if (pos == NULL) {
            i->prox = NULL;
            i->ant = NULL;
            l->inicio = pos;
            l->fim = pos;
        } else{
            i->prox = pos->prox;
            pos->ant = i;
            i->ant = pos;
            pos->prox = i;
        }
        return 0;
    }
    return -1;
}
