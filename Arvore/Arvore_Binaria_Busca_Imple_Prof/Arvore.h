#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct no_arvore
{
    int info;
    struct no_arvore *esq;
    struct no_arvore *dir;
} NO, *pno;



#endif // ARVORE_H_INCLUDED
