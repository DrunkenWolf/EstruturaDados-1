//IMPLEMENTAÇÃO DO TRABALHO SUPER BÔNUS  –  E.D.
//Nome : Rafael dos Santos Braz       RA: 120121

#include "Dinamica_Dupla.h"
#include <stdio.h>
#include <stdlib.h>

LISTA juntarListas(LISTA *l1, LISTA *l2, LISTA *l3){
    LISTA l4;
    inicializarLista(&l4);
    PONT atualL1 = l1->inicio;
    PONT atualL2 = l2->fim;
    PONT atualL3 = l3->fim;
    while (atualL1 != NULL){

    }
    while (atualL1 != NULL || atualL2 != NULL || atualL3 != NULL){
        if ()
    }
    return l4;
}

void inicializarLista(LISTA *l){
    l->inicio = NULL;
    l->fim = NULL;
}

int tamanhoLista(LISTA *l){
    PONT atual = l->inicio;
    int tam = 0;
    while (atual != NULL){
        tam++;
        atual = atual->prox;
    }
    return tam;
}

void exibirLista(LISTA *l){
    PONT end = l->inicio;
    printf("Lista: \"");
    while (end != NULL){
        printf("%d ", end->reg.chave);
        end = end->prox;
    }
    printf("\"\n");
}

PONT buscaSequencial(LISTA *l, TIPOCHAVE ch){
    PONT pos = l->inicio;
    while (pos != NULL && pos->reg.chave < ch){
        pos = pos->prox;
    }
    if (pos != NULL && pos->reg.chave == ch){
        return pos;
    }
    return NULL;
}

int inserirElemListaOrd(LISTA *l, REGISTRO reg){
    TIPOCHAVE ch = reg.chave;
    PONT i;
    if (buscaSequencial(l, ch) == NULL){
        PONT pos = l->inicio;
        PONT a = NULL;
        i = (PONT)malloc(sizeof(ELEMENTO));
        i->reg = reg;
        while (pos != NULL && pos->reg.chave < ch){
            a = pos;
            pos = pos->prox;
        }
        if (tamanhoLista(l) == 0){
            l->inicio = l->fim = i;
            i->ant = i->prox = NULL;
        } else if (a != NULL){
            i->ant = a;
            i->prox = a->prox;
            if (a->prox == NULL){
                a->prox = i;
                l->fim = i;
            } else{
                a->prox->ant = i;
                a->prox = i;
            }
        } else{
            i->ant = NULL;
            i->prox = l->inicio;
            l->inicio->ant = i;
            l->inicio = i;
        }
        return 0;
    }
    return -1;
}

int inserirElemListaOrdDecre(LISTA *l, REGISTRO reg){
    TIPOCHAVE ch = reg.chave;
    PONT i;
    if (buscaSequencial(l, ch) == NULL){
        PONT pos = l->inicio;
        PONT a = NULL;
        i = (PONT)malloc(sizeof(ELEMENTO));
        i->reg = reg;
        while (pos != NULL && pos->reg.chave > ch){
            a = pos;
            pos = pos->prox;
        }
        if (tamanhoLista(l) == 0){
            l->inicio = l->fim = i;
            i->ant = i->prox = NULL;
        } else if (a != NULL){
            i->ant = a;
            i->prox = a->prox;
            if (a->prox == NULL){
                a->prox = i;
                l->fim = i;
            } else{
                a->prox->ant = i;
                a->prox = i;
            }
        } else{
            i->ant = NULL;
            i->prox = l->inicio;
            l->inicio->ant = i;
            l->inicio = i;
        }
        return 0;
    }
    return -1;
}

int excluirElemLista(LISTA *l, TIPOCHAVE ch){
    PONT i = buscaSequencial(l, ch);
    if (i == NULL){
        return -1;
    }
    if (i->ant == NULL){
        l->inicio = i->prox;
        l->inicio->ant = NULL;
    } else if (i->prox == NULL){
        i->ant->prox = NULL;
        l->fim = i->ant;
    } else{
        i->prox->ant = i->ant;
        i->ant->prox = i->prox;
    }
    free(i);
    return 0;
}

void reinicializarLista(LISTA *l){
    PONT end = l->inicio;
    while (end != NULL){
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    l->inicio = NULL;
    l->fim = NULL;
}
