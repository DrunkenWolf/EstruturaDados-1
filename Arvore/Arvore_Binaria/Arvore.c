#include"Arvore.h"

void define(tree t) // "inicializa a árvore como vazia - nó raiz vazio
{
    t = NULL;
}

void cria_raiz(tree t, tipo_elem item) // reserva memória para o nó raiz e configura as definições iniciais da árvore
{
    pno no = malloc(sizeof(no));
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

int inserirNo(tree r, tipo_elem item, int direc) // cria um novo nó no local indicado pelo nó pai e a direcção (o - esquerda, !0 - direita), se não for possível será retornado valor -1
{
    pno no = malloc(sizeof(no)); // aloca e inicializa o novo nó com os padrões iniciais
    no->esq = NULL;
    no->dir = NULL;
    no->info = item;
    printf("%p %p", &r->esq, &r->dir);
    if (direc == 0) // se a direção for esquerda e houver espaço disponível para alocação, o nó será inserido
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
    else // se a direção for direita e houver espaço disponível para alocação, o nó será inserido
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

void exibirArvore(tree r)
{
    if (r != NULL)
    {
        printf(" %c\n", r->info);
        exibirArvore(r->esq);
        exibirArvore(r->dir);
    }
}
