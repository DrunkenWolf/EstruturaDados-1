#include "LinearEstatica.h"

void inicializarLista(LISTA *l){ // ---------------------------- i
    int c;
    l->inicio = -1;
    l->dispo = 0;
    for (c = 0; c < MAX - 1; c++){
        l->elementos[c].prox = c + 1;
    }
    l->elementos[MAX - 1].prox = -1;
}

void exibirMenorQuantElemValidos(LISTA *l){ // ---------------------------- ii
    if (l->inicio == -1){
        printf("Menor Elemento: Não há elementos! \n Quantidade de Elementos Válidos: 0\n");
    } else{
        int tam = 0;
        int atual = l->inicio;
        while (atual != -1){
            tam++;
            atual = l->elementos[atual].prox;
        }
        printf("Menor Elemento: %d \n Quantidade de Elementos Válidos: %d\n", l->elementos[l->inicio].reg.chave, tam);
    }
}

int excluirMaiorElem(LISTA *l){ // ---------------------------- iii
    int ant = -1;
    int atual = l->inicio;
    int pos = l->dispo;
    if (pos == -1){
        return -1;
    }
    while (atual != -1){
        ant = atual;
        atual = l->elementos[atual].prox;
    }
    return excluirElemListaOrd(l, l->elementos[ant].reg.chave);
}

int tamanhoLista(LISTA *l){
    int tam = 0;
    int atual = l->inicio;
    while (atual != -1){
        tam++;
        atual = l->elementos[atual].prox;
    }
    return tam;
}

void exibirLista(LISTA *l){
    int atual = l->inicio;
    printf("LISTA: ");
    while (atual != -1){
        printf(" %d", l->elementos[atual].reg.chave);
        atual = l->elementos[atual].prox;
    }
    printf("\n");
}

int buscaSequencial(LISTA *l, int ch){
    int atual = l->inicio;
    while (atual != -1 && l->elementos[atual].reg.chave != ch){
        atual = l->elementos[atual].prox;
    }
    return atual;
}

int buscaSequencialOrd(LISTA *l, int ch){
    int atual = l->inicio;
    while (atual != -1 && l->elementos[atual].reg.chave < ch){
        atual = l->elementos[atual].prox;
    }
    if (atual != -1 && l->elementos[atual].reg.chave == ch){
        return atual;
    }
    return -1;
}

int inserirElemLista(LISTA *l, REGISTRO reg){
    int pos = l->dispo;
    if (buscaSequencial(l, reg.chave) != -1 || pos == -1){
        return -1;
    }
    l->dispo = l->elementos[pos].prox;
    l->elementos[pos].prox = l->inicio;
    l->inicio = pos;
    l->elementos[pos].reg = reg;
    return 0;
}

int inserirElemListaOrd(LISTA *l, REGISTRO reg){ // ---------------------------- iv
    int ant = -1;
    int atual = l->inicio;
    int pos = l->dispo;
    if (pos == -1){
        return -1;
    }
    while (atual != -1 && l->elementos[atual].reg.chave < reg.chave){
        ant = atual;
        atual = l->elementos[atual].prox;
    }
    if (atual != -1 && l->elementos[atual].reg.chave == reg.chave){
        return -1;
    }
    l->elementos[pos].reg = reg;
    l->dispo = l->elementos[pos].prox;
    if (ant == -1){
        l->elementos[pos].prox = l->inicio;
        l->inicio = pos;
    } else{
        l->elementos[pos].prox = l->elementos[ant].prox;
        l->elementos[ant].prox = pos;
    }
    return 0;
}

int excluirElemLista(LISTA *l, int ch){
    int ant = -1;
    int pos = buscaSequencial(l, ch);
    if (pos == -1){
        return -1;
    }
    int c = l->inicio;
    while (c != pos){
        ant = c;
        c = l->elementos[c].prox;
    }
    if (ant != -1){
        l->elementos[ant].prox = l->elementos[pos].prox;
    } else{
        l->inicio = l->elementos[pos].prox;
    }
    l->elementos[pos].prox = l->dispo;
    l->dispo = pos;
    return 0;
}

int excluirElemListaOrd(LISTA *l, int ch){
    int ant = -1;
    int pos = l->inicio;
    if (pos == -1){
        return -1;
    }
    while (pos != -1 && l->elementos[pos].reg.chave < ch){
        ant = pos;
        pos = l->elementos[pos].prox;
    }
    if (pos == -1 || l->elementos[pos].reg.chave != ch){
        return -1;
    }
    if (ant == -1){
        l->inicio = l->elementos[pos].prox;
    } else{
        l->elementos[ant].prox = l->elementos[pos].prox;
    }
    l->elementos[pos].prox = l->dispo;
    l->dispo = pos;
    return 0;
}

void reincializarLista (LISTA *l){
    inicializarLista(l);
}
