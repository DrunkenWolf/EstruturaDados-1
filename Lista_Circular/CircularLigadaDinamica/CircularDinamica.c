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
        printf("%d ", end->reg.chave);
        end = end->prox;
    }
    printf("\"");
}

PONT buscaSentinela(LISTA *l, TIPOCHAVE ch){
    PONT pos = l->cabeca->prox;
    l->cabeca->reg.chave = ch;
    while (pos->reg.chave != ch){
        pos = pos->prox;
    }
    if (pos != l->cabeca) return pos;
    return NULL;
}

PONT buscaSentinelaOrd(LISTA *l, TIPOCHAVE ch){
    PONT pos = l->cabeca->prox;
    l->cabeca->reg.chave = ch;
    while (pos->reg.chave < ch){
        pos = pos->prox;
    }
    if (pos != l->cabeca && pos->reg.chave == ch) return pos;
    return NULL;
}

PONT buscaSeqExec(LISTA *l, TIPOCHAVE ch, PONT *ant){
    *ant = l->cabeca;
    PONT atual = l->cabeca->prox;
    l->cabeca->reg.chave = ch;
    while (atual->reg.chave < ch){
        *ant = atual;
        atual = atual->prox;
    }
    if (atual != l->cabeca && atual->reg.chave == ch){
        return atual;
    }
    return NULL;
}

int inserirElemLista(LISTA *l, REGISTRO reg){
    PONT ant, i;
    i = buscaSeqExec(l, reg.chave, &ant);
    if (i != NULL){
        return -1;
    }
    i = (PONT) malloc(sizeof(ELEMENTO));
    i->reg = reg;
    i->prox = ant->prox;
    ant->prox = i;
    return 0;
}

int excluirElemLista(LISTA *l, TIPOCHAVE ch){
    PONT ant, i;
    i = buscaSeqExec(l, ch, &ant);
    if (i == NULL){
        return -1;
    }
    ant->prox = i->prox;
    free(i);
    return 0;
}

void reinicializarLista(LISTA *l){
    PONT end = l->cabeca->prox;
    while (end != l->cabeca){
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    l->cabeca->prox = l->cabeca;
}
