#include "FilaEstatica.h"

void inicializarFila(FILA *f){
    f->numElem = 0;
    f->inicio = 0;
}

int tamanhoFila(FILA *f){
    return f->numElem;
}

void exibirFila(FILA *f){
    int c;
    int pos = f->inicio;
    printf("FILA: ");
    for (c = 0; c < f->numElem; c++){
        printf(" %d", f->elementos[pos].elemento);
        pos = (++pos) % MAX;
    }
    printf("\n");
}

int buscaSequencial(FILA *l, int elem){ //não é necessário, pois ele só  opera no  início e fim da fila
    int c;
    for (c = 0; c < l->numElem; c++){
        if (l->elementos[c].elemento == elem){
            return c;
        }
    }
    return -1;
}

int inserirElemFila(FILA *f, REGISTRO reg){
    if (f->numElem == MAX){
        return -1;
    }
    int pos = (f->inicio + f->numElem) % MAX;
    f->elementos[pos] = reg;
    (f->numElem)++;
    return 0;
}

int excluirElemFila(FILA *f){
    if (f->numElem == 0){
        return -1;
    }
    (f->numElem)--;
    (f->inicio)++;
    if (f->inicio == MAX){
        f->inicio = 0;
    }
    return 0;
}

void reinicializarFila(FILA *f){
    inicializarFila(f);
}
