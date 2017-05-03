#include "PilhaEstatica.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarPilha(PILHA *p){ // ----------------------- a
    p->topoA = -1;
    p->topoB = MAX;
}

int pilhaVaziaB(PILHA *p){ // ----------------------- b
    if (p->topoB == MAX){
        return 0; //vazia
    }
    return -1; //com elementos
}

int pilhasCheias(PILHA *p){ // ----------------------- c
    if (p->topoA + 1 == p->topoB){
        return 0; //cheias
    }
    return -1; //com espaços disponíveis
}

int empilhaA(PILHA *p, REGISTRO reg){ // ----------------------- d
    if (pilhasCheias(p) == 0){
        return -1; //sem espaço disponível
    }
    p->topoA++;
    p->A[p->topoA] = reg;
    return 0; //ok
}

int empilhaB(PILHA *p, REGISTRO reg){ // ----------------------- e
    if (pilhasCheias(p) == 0){
        return -1; //sem espaço disponível
    }
    p->topoB--;
    p->A[p->topoB] = reg;
    return 0; //ok
}

int desempilhaB(PILHA *p){ // ----------------------- f
    if (pilhaVaziaB(p) == 0){
        return -1; //não tem elementos
    }
    p->topoB++;
    return 0; //ok
}

/*
int tamanho(PILHA *p){
    return p->topo + 1;
}

void exibirPilha(PILHA *p){
    int i;
    printf("PILHA: \" ");
    for (i = p->topo; i >= 0; i--){
        printf("%i ", p->A[i].chave);
    }
    printf("\"\n");
}

int inserirElemPilha(PILHA *p, REGISTRO reg){
    if (p->topo >= MAX - 1){
        return -1;
    }
    p->topo++;
    p->A[p->topo] = reg;
    return 0;
}

int excluirElemPilha(PILHA *p){
    if (p->topo == -1){
        return -1;
    }
    p->topo--;
    return 0;
}
*/
