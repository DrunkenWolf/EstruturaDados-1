#ifndef SEQUENCIALNAOORDENADA_H_INCLUDED
#define SEQUENCIALNAOORDENADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct{
    int elemento;
} REGISTRO;

typedef struct{
    REGISTRO elementos[MAX + 1];
    int numElem;
} LISTA;

void inicializarLista(LISTA *);
int tamanhoLista(LISTA *);
void exibirLista(LISTA *);
int buscaSequencial(LISTA *, int);
int inserirElemListaFinal(LISTA *, REGISTRO);
int inserirElemListaPosicao(LISTA *, REGISTRO, int);
int excluirElemLista(LISTA *, int);
void reinicializarLista(LISTA *);
int buscaSentinela(LISTA *, int);

#endif // SEQUENCIALNAOORDENADA_H_INCLUDED
