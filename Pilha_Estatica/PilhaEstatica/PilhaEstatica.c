#include "PilhaEstatica.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarLista(PILHA *p){
    p->topo = -1;
}

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

void reinicializacao(PILHA *p){
    p->topo = -1;
}
