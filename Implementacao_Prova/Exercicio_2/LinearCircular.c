#include "LinearCircular.h"

void inicializarLista(LISTA *l){ // ---------------------------------- a
    l->cabeca = (PONT) malloc(sizeof(ELEMENTO));
    l->cabeca->prox = l->cabeca;
}

int tamanhoLista(LISTA *l){
    int tam = 0;
    PONT atual = l->cabeca->prox;
    while (atual != l->cabeca){ //não há NULL, ele finaliza na cabeça
        tam++;
        atual = atual->prox;
    }
    return tam;
}

void exibirLista(LISTA *l){
    PONT atual = l->cabeca->prox;
    printf("LISTA: ");
    while (atual != l->cabeca){
        printf(" %d", atual->reg.chave);
        atual = atual->prox;
    }
    printf("\n");
}

int tamanhoExibirLista(LISTA *l){ // ---------------------------------- b
    PONT atual = l->cabeca->prox;
    int tam = 0;
    printf("LISTA: ");
    while (atual != l->cabeca){
        printf(" %d", atual->reg.chave);
        atual = atual->prox;
        tam++;
    }
    printf("\n");
    return tam;
}

PONT buscaSentinela(LISTA *l, int ch){
    PONT atual = l->cabeca->prox;
    l->cabeca->reg.chave = ch;
    while (l->cabeca->reg.chave != ch){
        atual = atual->prox;
    }
    if (atual == l->cabeca){
        return NULL;
    }
    return atual;
}

PONT buscaSequencialOrd(LISTA *l, int ch){
    PONT atual = l->cabeca->prox;
    while (atual != l->cabeca && atual->reg.chave < ch){
        atual = atual->prox;
    }
    if (atual != l->cabeca && atual->reg.chave == ch){
        return atual;
    }
    return NULL;
}

int inserirElemListaOrd(LISTA *l, REGISTRO reg){
    PONT atual = l->cabeca->prox;
    PONT ant = NULL;
    while (atual != l->cabeca && atual->reg.chave < reg.chave){
        ant = atual;
        atual = atual->prox;
    }
    if (atual != l->cabeca && atual->reg.chave == reg.chave){
        return -1;
    }
    atual = (PONT) malloc(sizeof(ELEMENTO));
    atual->reg = reg;
    if (ant == NULL){
        atual->prox = l->cabeca->prox;
        l->cabeca->prox = atual;
    } else{
        atual->prox = ant->prox;
        ant->prox = atual;
    }
    return 0;
}

int excluirElemListaOrd(LISTA *l, int ch){
    PONT atual = l->cabeca->prox;
    PONT ant = NULL;
    while (atual != l->cabeca && atual->reg.chave < ch){
        ant = atual;
        atual = atual->prox;
    }
    if (atual == l->cabeca || atual->reg.chave != ch){
        return -1;
    }
    if (ant == NULL){
        l->cabeca->prox = atual->prox;
    } else{
        ant->prox = atual->prox;
    }
    free(atual);
    return 0;
}

void reinicializarLista(LISTA *l){
    PONT atual = l->cabeca;
    while (atual != l->cabeca){
        PONT apagar = atual;
        atual = atual->prox;
        free(apagar);
    }
    l->cabeca->prox= l->cabeca;
}
