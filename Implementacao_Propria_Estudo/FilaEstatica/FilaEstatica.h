#ifndef FILAESTATICA_H_INCLUDED
#define FILAESTATICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct{
    int elemento;
} REGISTRO;

typedef struct{
    REGISTRO elementos[MAX];
    int numElem;
    int inicio;
} FILA;

#endif // FILAESTATICA_H_INCLUDED
