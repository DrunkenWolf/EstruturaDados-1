#ifndef FILADINAMICA_H_INCLUDED
#define FILADINAMICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int elemento;
}REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux* prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
    PONT inicio;
    PONT fim;
}FILA;

//Protótipo das funções
void inicializarFila(FILA *);
void exibirFila(FILA *);
int excluirElemFila(FILA *);
int inserirElemFila(FILA *, REGISTRO);
void reinicializarFila(FILA *);
int tamanhoFila(FILA *);

#endif // FILADINAMICA_H_INCLUDED
