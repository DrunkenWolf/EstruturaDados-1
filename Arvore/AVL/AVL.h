#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct no_arvore{
  struct no_arvore *esq;
  struct no_arvore *dir;
  int info;
  int altura;
}NO, *pno;

#endif // AVL_H_INCLUDED
