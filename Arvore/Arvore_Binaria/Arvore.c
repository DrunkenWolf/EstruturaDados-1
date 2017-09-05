#include"Arvore.h"

void define(tree t) // "inicializa a árvore como vazia - nó raiz vazio
{
    t = NULL;
}

void cria_raiz(tree t, tipo_elem item) // reserva memória para o nó raiz e configura as definições iniciais da árvore
{
    pno no = malloc(sizeof(NO));
    no->esq = NULL;
    no->dir = NULL;
    no->info = item;
    t = no;
}

int altura(tree r) // calcula a altura de uma árvore - recursivamente
{
    if (r == NULL) // se não possui elementos, possui altura 0
    {
        return 0;
    }
    int altE = altura(r->esq); // chamada para cálculo da altura da subárvore à esquerda
    int altD = altura(r->dir); // chamada para cálculo da altura da subárvore à direita
    if (altE > altD) // como a altura da árvore é definida pela nó de maior altura pertencente à árvore, o maior valor (esquerda ou direita) é retornado
    {
        return altE + 1; // soma-se 1 ao valor por considerar um nó NULL como altura 0
    }
    return altD + 1;
}

int numeroNos(tree r) // calcula quantos nós uma árvore possui - recursivamente
{
    if (r == NULL) // se o nó não existe, equivale à 0
    {
        return 0;
    }
    int nE = numeroNos(r->esq); // calcula quantos nós existem à esquerda
    int nR = numeroNos(r->dir); // calcula quantos nós existem à direita
    return nE + nR + 1; // soma-se a quantidade de nós à direita e esquerda e soma-se 1 para correção de nó NULL = 0
}

int inserirNo(tree r, tipo_elem item, int direc)
{
    pno no = malloc(sizeof(NO));
    no->esq = NULL;
    no->dir = NULL;
    if (direc == 0)
    {
        if (r->esq == NULL)
        {
            r->esq = no;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        if (r->dir == NULL)
        {
            r->dir = no;
        }
        else
        {
            return -1;
        }
    }
    return 0;
}
