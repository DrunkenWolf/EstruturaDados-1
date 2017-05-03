#ifndef LINEARESTATICA_H_INCLUDED
#define LINEARESTATICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct{
    int chave;
} REGISTRO;

typedef struct{
    REGISTRO reg;
    int prox;
}ELEMENTO;

typedef struct{
    ELEMENTO elementos[MAX];
    int inicio;
    int dispo;
} LISTA;

//protótipos das funções

#endif // LINEARESTATICA_H_INCLUDED
