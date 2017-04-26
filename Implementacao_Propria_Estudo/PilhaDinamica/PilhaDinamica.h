#ifndef PILHADINAMICA_H_INCLUDED
#define PILHADINAMICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int chave;
} REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux *prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
    PONT topo;
} PILHA;



#endif // PILHADINAMICA_H_INCLUDED
