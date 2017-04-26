#include "PilhaEstatica.h"

void inicializarPilha(PILHA *p){
    p->topo = -1;
}

int tamanhoPilha(PILHA *p){
    return p->topo + 1;
}

void exibirPilha(PILHA *p){
    int atual;
    printf("PILHA: ");
    for (atual = p->topo; atual >= 0; atual--){
        printf(" %d", p->elementos[atual].reg.chave);
    }
    printf("\n");
}

int buscaSequencial(PILHA *p, int ch){
    int atual = p->topo;
    while (atual >= 0 && p->elementos[atual].reg.chave != ch){
        atual--;
    }
    return atual;
}

int inserirElemPilha(PILHA *p, REGISTRO reg){
    if (p->topo + 1 == MAX){
        return -1;
    }
    p->elementos[p->topo + 1].reg = reg;
    p->topo++;
    return 0;
}

int excluirElemPilha(PILHA *p){
    if (p->topo == -1){
        return -1;
    }
    p->topo--;
    return 0;
}

void reincializarPilha (PILHA *p){
    inicializarPilha(p);
}
