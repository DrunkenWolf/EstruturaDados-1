#include "SequencialNaoOrdenada.h"

void inicializarLista(LISTA *l){
    l->numElem = 0;
}

int tamanhoLista(LISTA *l){
    return l->numElem;
}

void exibirLista(LISTA *l){
    int c;
    printf("LISTA: ");
    for (c = 0; c < l->numElem; c++){
        printf(" %d", l->elementos[c].elemento);
    }
    printf("\n");
}

int buscaSequencial(LISTA *l, int elem){
    int c;
    for (c = 0; c < l->numElem; c++){
        if (l->elementos[c].elemento == elem){
            return c;
        }
    }
    return -1;
}

int inserirElemListaFinal(LISTA *l, REGISTRO reg){
    int c;
    if (l->numElem == MAX){
        return -1;
    }
    l->elementos[l->numElem] = reg;
    l->numElem++;
    return 0;
}

int inserirElemListaPosicao(LISTA *l, REGISTRO reg, int posicao){
    int c;
    if (posicao < 0 || posicao > l->numElem || l->numElem == MAX){
        return -1;
    }
    for (c = l->numElem; c > posicao; c--){
        l->elementos[c] = l->elementos[c - 1];
    }
    l->elementos[posicao] = reg;
    l->numElem++;
    return 0;
}

int excluirElemLista(LISTA *l, int elem){
    int c;
    int posicao = buscaSequencial(l, elem);
    if (posicao == -1){
        return -1;
    }
    for (c = posicao; c < l->numElem; c++){
        l->elementos[c] = l->elementos[c + 1];
    }
    l->numElem--;
    return 0;
}

void reinicializarLista(LISTA *l){
    inicializarLista(l);
}

int buscaSentinela(LISTA *l, int elem){
    int c = 0;
    l->elementos[l->numElem].elemento = elem;
    while (l->elementos[c].elemento != elem){
        c++;
    }
    if (c == l->numElem){
        return -1;
    }
    return c;
}
