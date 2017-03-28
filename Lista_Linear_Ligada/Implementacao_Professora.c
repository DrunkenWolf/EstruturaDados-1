#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef int TIPOCHAVE;

int INVALIDO = -1;

typedef struct{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct{
    REGISTRO reg;
    int prox;
} ELEMENTO;

typedef struct{
    ELEMENTO A[MAX];
    int inicio;
    int dispo;
} LISTA;

void inicializarLista (LISTA *l){
    int i;
    for (i = 0; i < MAX - 1; i++){
        l->A[i].prox = i + 1;
    }
    l->A[i].prox = INVALIDO;
    l->dispo = 0;
    l->inicio = INVALIDO;
}

int tamanho (LISTA *l){
    int i = l->inicio;
    int tam = 0;
    while (i != INVALIDO){
        tam++;
        i = l->A[i].prox;
    }
    return tam;
}

void exibirLista (LISTA *l){
    int i = l->inicio;
    printf("\nLista: \" ");
    while (i != INVALIDO){
        printf("%d ", l->A[i].reg.chave);
        i = l->A[i].prox;
    }
    printf(" \"\n"); //alteração para pular linha após exibição
}

int buscaSequencialOrd (LISTA *l, TIPOCHAVE ch){
    int i = l->inicio;
    while (i != INVALIDO && l->A[i].reg.chave < ch){
        i = l->A[i].prox;
    }
    if (i != INVALIDO && l->A[i].reg.chave == ch){
        return i;
    }
    return INVALIDO;
}

int obterNo (LISTA *l){
    int resultado = l->dispo;
    if (l->dispo != INVALIDO){
        l->dispo = l->A[l->dispo].prox; //alteração do Slide, pois "dispo" não existe sozinho
    }
    return resultado;
}

int inserirElemListaOrd (LISTA *l, REGISTRO reg){
    int ant = INVALIDO;
    int i = l->inicio;
    TIPOCHAVE ch = reg.chave;
    if (l->dispo == INVALIDO){
        return INVALIDO;
    }
    while (i != INVALIDO && l->A[i].reg.chave < ch){
        ant = i;
        i = l->A[i].prox;
    }
    if (i != INVALIDO && l->A[i].reg.chave == ch){
        return -1;
    }
    i = obterNo(l);
    l->A[i].reg = reg;
    if (ant == INVALIDO){
        l->A[i].prox = l->inicio;
        l->inicio = i;
    } else{
        l->A[i].prox = l->A[ant].prox;
        l->A[ant].prox = i;
    }
    return 0;
}

void devolverNo (LISTA *l, int i){
    l->A[i].prox = l->dispo;
    l->dispo = i;
}

int excluirElemLista (LISTA *l, TIPOCHAVE ch){
    int ant = INVALIDO;
    int i = l->inicio;
    if (l->dispo == INVALIDO){
        return INVALIDO;
    }
    while (i != INVALIDO && l->A[i].reg.chave < ch){
        ant = i;
        i = l->A[i].prox;
    }
    if (i == INVALIDO || l->A[i].reg.chave != ch){
        return INVALIDO;
    }
    if (ant == INVALIDO){
        l->inicio = l->A[i].prox;
    } else{
        l->A[ant].prox = l->A[i].prox;
    }
    devolverNo(l, i);
    return 0;
}

void reinicializar (LISTA *l){
    inicializarLista(l);
}