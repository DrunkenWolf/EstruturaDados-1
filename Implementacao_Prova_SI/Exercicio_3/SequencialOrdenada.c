#include "SequencialOrdenada.h"

void preencherLista3(LISTA *l1, LISTA *l2, LISTA_FINAL *l3){
    int c;
    for (c = 0; c < l1->numElem; c++){
        inserirElemListaOrdFinal(l3, l1->elementos[c]);
    }
    for (c = 0; c < l2->numElem; c++){
        inserirElemListaOrdFinal(l3, l2->elementos[c]);
    }
}


void inicializarLista(LISTA *l){
    l->numElem = 0;
}

void inicializarListaFinal(LISTA_FINAL *l){
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

void exibirListaFinal(LISTA_FINAL *l){
    int c;
    printf("LISTA FINAL: ");
    for (c = 0; c < l->numElem; c++){
        printf(" %d", l->elementos[c].elemento);
    }
    printf("\n");
}

int buscaSequencialOrd(LISTA *l, int elem){
    int c;
    for (c = 0; c < l->numElem; c++){
        if (l->elementos[c].elemento == elem){
            return c;
        }
        if (l->elementos[c].elemento > elem){
            return -1;
        }
    }
    return -1;
}

int inserirElemListaOrd(LISTA *l, REGISTRO reg){
    int c = l->numElem - 1;
    if (l->numElem == MAX || buscaSequencialOrd(l, reg.elemento) != -1){
        return -1;
    }
    while (l->elementos[c].elemento > reg.elemento){
        l->elementos[c + 1] = l->elementos[c];
        c--;
    }
    l->elementos[c + 1] = reg;
    l->numElem++;
    return 0;
}

int buscaSequencialOrdFinal(LISTA_FINAL *l, int elem){
    int c;
    for (c = 0; c < l->numElem; c++){
        if (l->elementos[c].elemento == elem){
            return c;
        }
        if (l->elementos[c].elemento > elem){
            return -1;
        }
    }
    return -1;
}

int inserirElemListaOrdFinal(LISTA_FINAL *l, REGISTRO reg){
    int c = l->numElem - 1;
    if (l->numElem == 2 * MAX || buscaSequencialOrdFinal(l, reg.elemento) != -1){
        return -1;
    }
    while (l->elementos[c].elemento > reg.elemento){
        l->elementos[c + 1] = l->elementos[c];
        c--;
    }
    l->elementos[c + 1] = reg;
    l->numElem++;
    return 0;
}

int excluirElemLista(LISTA *l, int elem){
    int c;
    int posicao = buscaSequencialOrd(l, elem);
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

int buscaBinaria(LISTA *l, int elem){
    int esq, dir, meio;
    if (l->numElem == 0){
        return -1;
    }
    esq = 0;
    dir = l->numElem - 1;
    while (esq <= dir){
        meio = (esq + dir) / 2;
        if (l->elementos[meio].elemento == elem){
            return meio;
        }
        if (l->elementos[meio].elemento > elem){
            dir = meio - 1;
        } else{
            esq = meio + 1;
        }
    }
    return -1;
}
