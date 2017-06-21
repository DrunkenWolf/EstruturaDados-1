#ifndef LINEARDINAMICA_H_INCLUDED
#define LINEARDINAMICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux *prox;
} ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct {
    PONT inicio;
} LISTA;

//prot�tipos das fun��es

#endif // LINEARDINAMICA_H_INCLUDED
