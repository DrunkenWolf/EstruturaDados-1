#include <stdio.h>
#include <stdlib.h>
#include "FilaDinamica.h"

void inicializarFila(FILA *f){
    f->inicio = NULL;
    f->fim = NULL;
}

int contaElemFila(FILA *f){
    PONT aux = f->inicio;
    int cont = 0;
    while(aux != NULL){
        cont++;
        aux = aux->prox;
    }
    return cont;
}

void exibirElemFila(FILA *f){
    PONT aux = f->inicio;
    printf("\nElementos da minha fila: ");
    while(aux != NULL){
        printf("%d ", aux->reg.chave);
        aux = aux->prox;
    }
    printf("\n");
}

void inserirElemFila(FILA *f, REGISTRO reg){
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = NULL;
    if (f->inicio == NULL){
        f->inicio = novo;
        f->fim = novo;
    } else{
        f->fim->prox = novo;
        f->fim = novo;
    }
}

void excluirElemFila (FILA *f){
    if (f->inicio == NULL){
        printf("Não há elementos na fila a serem excluídos\n");
    } else{
        PONT apagar = f->inicio;
        f->inicio = f->inicio->prox;
        free(apagar);
        if (f->inicio == NULL){
            f->fim = NULL;
        }
    }
}

void reinicializar(FILA *f){
    while(f->inicio != NULL){
        excluirElemFila(f);
    }
}
