#include "LinearCircular.h"

void inicializarLista(LISTA *l){
    l->inicio = NULL;
}

void tamanhoLista(LISTA *l){
    int tam = 0;
    PONT atual = l->inicio;
    while (atual != NULL){
        atual = atual->prox;
        tam++;
    }
    return tam;
}

void exibirLista(LISTA *l){
    PONT atual = l->inicio;
    printf("LISTA: ");
    while (atual != NULL){
        printf(" %d", atual->reg.chave);
        atual = atual->prox;
    }
    printf("\n");
}

PONT buscaSequencialOrd(LISTA *l, int ch){
    PONT atual = l->inicio;
    while (atual != NULL && atual->reg.chave < ch){
        atual = atual->prox;
    }
    if (atual != NULL && atual->reg.chave == ch){
        return atual;
    }
    return NULL;
}

int inserirElemListaOrd(LISTA *l, REGISTRO reg){
    PONT atual = l->inicio;
    PONT ant = NULL;
    while(atual != NULL && atual->reg.chave < reg.chave){
        ant = atual;
        atual = atual->prox;
    }
    if (atual != NULL && atual->reg.chave == reg.chave){
        return -1;
    }
    atual = (PONT) malloc(sizeof(ELEMENTO));
    atual->reg = reg;
    if (ant == NULL){
        atual->prox = l->inicio;
        l->inicio = atual;
    } else{
        atual->prox = ant->prox;
        ant->prox = atual;
    }
    return 0;
}

int excluirElemListaOrd(LISTA *l, int ch){
    PONT atual = l->inicio;
    PONT ant = NULL;
    while (atual != NULL && atual->reg.chave < ch){
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL || atual->reg.chave != ch){
        return -1;
    }
    if (ant == NULL){
        l->inicio = atual->prox;
    } else{
        ant->prox = atual->prox;
    }
    free(atual);
    return 0;
}

void reinicializarLista(LISTA *l){
    PONT atual = l->inicio;
    while (atual != NULL){
        PONT apagar = atual;
        atual = atual->prox;
        free(apagar);
    }
    l->inicio = NULL;
}
