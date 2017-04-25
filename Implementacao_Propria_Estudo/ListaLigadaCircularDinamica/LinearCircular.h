#ifndef LINEARCIRCULAR_H_INCLUDED
#define LINEARCIRCULAR_H_INCLUDED

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
    PONT inicio;
} LISTA;



#endif // LINEARCIRCULAR_H_INCLUDED
