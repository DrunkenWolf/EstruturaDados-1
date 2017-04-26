#include "PilhaDinamica.h"

void inicializarPilha(PILHA *p){
    p->topo = NULL;
}

int tamanhoPilha(PILHA *p){
    PONT atual = p->topo;
    int tam = 0;
    while (atual != NULL){
        tam++;
        atual = atual->prox;
    }
    return tam;
}

int pilhaVazia(PILHA *p){
    if (p->topo == NULL){
        return 0;
    }
    return -1;
}

void exibirPilha(PILHA *p){
    PONT atual;
    printf("PILHA: ");
    while (atual != NULL){
        printf(" %d", atual->reg.chave);
        atual = atual->prox;
    }
    printf("\n");
}

PONT buscaSequencial(PILHA *p, int ch){
    PONT atual = p->topo;
    while (atual != NULL && atual->reg.chave != ch){
        atual = atual->prox;
    }
    return atual;
}

int inserirElemPilha(PILHA *p, REGISTRO reg){
    PONT atual = (PONT) malloc(sizeof(ELEMENTO));
    atual->reg = reg;
    atual->prox = p->topo;
    p->topo = atual;
    return 0;
}

int excluirElemPilha(PILHA *p){
    if (p->topo == NULL){
        return -1;
    }
    PONT apagar = p->topo;
    p->topo = p->topo->prox;
    free(apagar);
    return 0;
}

void reincializarPilha (PILHA *p){
    PONT atual = p->topo;
    while (atual != NULL){
        PONT apagar = atual;
        atual = atual->prox;
        free(apagar);
    }
    p->topo = NULL;
}
