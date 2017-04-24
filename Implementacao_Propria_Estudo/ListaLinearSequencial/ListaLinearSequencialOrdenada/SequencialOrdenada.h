#ifndef SEQUENCIALORDENADA_H_INCLUDED
#define SEQUENCIALORDENADA_H_INCLUDED

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
int buscaSequencialOrd(LISTA *, int);
int inserirElemListaOrd(LISTA*, REGISTRO);
int excluirElemLista(LISTA *, int);
void reinicializarLista(LISTA *);
int buscaSentinela(LISTA *, int);
int buscaBinaria(LISTA *, int);

#endif // SEQUENCIALORDENADA_H_INCLUDED
