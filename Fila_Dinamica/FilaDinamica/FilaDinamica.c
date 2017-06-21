#include "FilaDinamica.h"

void inicializarFila(FILA *f){
    f->inicio = NULL;
    f->fim = NULL;
}

void exibirFila(FILA *f){
    PONT atual = f->inicio;
    printf("FILA: ");
    while (atual != NULL){
        printf("%d ", atual->reg.elemento);
        atual = atual->prox;
    }
    printf("\n");
}

int excluirElemFila(FILA *f){
    PONT atual = f->inicio;
    if (atual == NULL){
        return -1;
    }
    f->inicio = atual->prox;
    if (f->fim == atual){
        f->fim = atual->prox;
    }
    free(atual);
    return 0;
}

int inserirElemFila(FILA *f, REGISTRO reg){
    PONT atual = (PONT) malloc(sizeof(ELEMENTO));
    atual->reg = reg;
    atual->prox = NULL;
    if (f->fim == NULL){
        f->fim = atual;
        f->inicio = atual;
        return 0;
    }
    f->fim->prox = atual;
    f->fim = atual;
    return 0;
}

void reinicializarFila(FILA *f){
    PONT atual = f->inicio;
    while (atual != NULL){
        PONT apagar = atual;
        atual = atual->prox;
        free(apagar);
    }
    f->inicio = NULL;
    f->fim = NULL;
}

int tamanhoFila(FILA *f){
    PONT atual = f->inicio;
    int tam = 0;
    while (atual != NULL){
        tam++;
        atual = atual->prox;
    }
    return tam;
}

