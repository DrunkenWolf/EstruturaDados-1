#include "Dinamica_Dupla.h"
#include <stdio.h>
#include <stdlib.h>


void inicializarLista(LISTA *l) {
    l->inicio = l->fim = NULL;
}

int tamanhoLista(LISTA *l) {
    PONT atual = l->inicio;
    int tam = 0;
    while (atual != NULL) {
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
        PONT a = NULL;
        i = (PONT) malloc(sizeof (ELEMENTO));
        i->reg = reg;
        while (pos != NULL && pos->reg.chave < ch) {
            a = pos;
            pos = pos->prox;
        }
        if (tamanhoLista(l) == 0) {
            l->inicio = l->fim = i;
            i->ant = i->prox = NULL;
        } else{
            if (a->prox == NULL){
                i->ant = a;
                i->prox = a->prox;
                a->prox = i;
                l->fim = i;
            }
        }
        return 0;
    }
    return -1;
}
