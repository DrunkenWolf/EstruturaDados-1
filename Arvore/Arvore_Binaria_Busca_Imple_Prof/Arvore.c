#include"Arvore.h"

void inserir(pno *t, int dado)
{
    pno aux;
    if (*t == NULL)
    {
        aux = (pno) malloc(sizeof(NO));
        aux->info = dado;
        aux->esq = NULL;
        aux->dir = NULL;
        *t = aux;
    }
    else if ((*t)->info < dado)
    {
        inserir(&(*t)->dir, dado);
    }
    else
    {
        inserir(&(*t)->esq, dado);
    }
}

void imprime_em_ordem(pno *t)
{
    if ((*t) == NULL)
    {
        return;
    }
    imprime_em_ordem(&(*t)->esq);
    printf("\t %d", (*t)->info);
    imprime_em_ordem(&(*t)->dir);
}

void imprime_pre_ordem(pno *t)
{
    if ((*t) == NULL)
    {
        return;
    }
    printf("\t %d", (*t)->info);
    imprime_pre_ordem(&(*t)->esq);
    imprime_pre_ordem(&(*t)->dir);
}

void imprime_pos_ordem(pno *t)
{
    if ((*t) == NULL)
    {
        return;
    }
    imprime_pre_ordem(&(*t)->esq);
    imprime_pre_ordem(&(*t)->dir);
    printf("\t %d", (*t)->info);
}


//excluir
