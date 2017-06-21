#include "SequencialOrdenada.h"

void preencherLista3(LISTA *l1, LISTA *l2, LISTA_FINAL *l3){ //exercício 3
    int c, p1 = 0, p2 = 0;
    inicializarListaFinal(l3);
    for (c = 0; c < l1->numElem + l2->numElem; c++){
        if (p1 != l1->numElem && p2 != l2->numElem){
            if (l1->elementos[p1].elemento < l2->elementos[p2].elemento){
                l3->elementos[l3->numElem].elemento = l1->elementos[p1].elemento;
                p1++;
                l3->numElem++;
            } else if (l1->elementos[p1].elemento > l2->elementos[p2].elemento){
                l3->elementos[l3->numElem].elemento = l2->elementos[p2].elemento;
                p2++;
                l3->numElem++;
            } else{
                l3->elementos[l3->numElem].elemento = l1->elementos[p1].elemento;
                p1++;
                p2++;
                l3->numElem++;
            }
        } else if (p1 == l1->numElem && p2 != l2->numElem){
            l3->elementos[l3->numElem].elemento = l2->elementos[p2].elemento;
            p2++;
            l3->numElem++;
        } else if (p1 != l1->numElem && p2 == l2->numElem){
            l3->elementos[l3->numElem].elemento = l1->elementos[p1].elemento;
            p1++;
            l3->numElem++;
        }
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
    int c = l->numElem;
    if (c == MAX){
        return -1;
    }
    while (c > 0 && l->elementos[c - 1].elemento > reg.elemento){
        l->elementos[c] = l->elementos[c - 1];
        c--;
    }
    if (l->elementos[c].elemento != reg.elemento){
        l->elementos[c] = reg;
        l->numElem++;
    }
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
