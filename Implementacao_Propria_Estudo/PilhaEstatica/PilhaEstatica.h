#ifndef PILHAESTATICA_H_INCLUDED
#define PILHAESTATICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct{
    int chave;
} REGISTRO;

typedef struct{
    REGISTRO reg;
}ELEMENTO;

typedef struct{
    ELEMENTO elementos[MAX];
    int topo;
} PILHA;



#endif // PILHAESTATICA_H_INCLUDED
