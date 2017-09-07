#include"Arvore.h"

void define(tree t) // "inicializa a �rvore como vazia - n� raiz vazio
{
    t = NULL;
}

void cria_raiz(tree t, tipo_elem item) // reserva mem�ria para o n� raiz e configura as defini��es iniciais da �rvore
{
    pno no = malloc(sizeof(no));
    no->esq = NULL;
    no->dir = NULL;
    no->info = item;
    t = no;
}

int altura(tree r) // calcula a altura de uma �rvore - recursivamente
{
    if (r == NULL) // se n�o possui elementos, possui altura 0
    {
        return 0;
    }
    int altE = altura(r->esq); // chamada para c�lculo da altura da sub�rvore � esquerda
    int altD = altura(r->dir); // chamada para c�lculo da altura da sub�rvore � direita
    if (altE > altD) // como a altura da �rvore � definida pela n� de maior altura pertencente � �rvore, o maior valor (esquerda ou direita) � retornado
    {
        return altE + 1; // soma-se 1 ao valor por considerar um n� NULL como altura 0
    }
    return altD + 1;
}

int numeroNos(tree r) // calcula quantos n�s uma �rvore possui - recursivamente
{
    if (r == NULL) // se o n� n�o existe, equivale � 0
    {
        return 0;
    }
    int nE = numeroNos(r->esq); // calcula quantos n�s existem � esquerda
    int nR = numeroNos(r->dir); // calcula quantos n�s existem � direita
    return nE + nR + 1; // soma-se a quantidade de n�s � direita e esquerda e soma-se 1 para corre��o de n� NULL = 0
}

int inserirNo(tree r, tipo_elem item, int direc) // cria um novo n� no local indicado pelo n� pai e a direc��o (o - esquerda, !0 - direita), se n�o for poss�vel ser� retornado valor -1
{
    pno no = malloc(sizeof(no)); // aloca e inicializa o novo n� com os padr�es iniciais
    no->esq = NULL;
    no->dir = NULL;
    no->info = item;
    printf("%p %p", &r->esq, &r->dir);
    if (direc == 0) // se a dire��o for esquerda e houver espa�o dispon�vel para aloca��o, o n� ser� inserido
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
    else // se a dire��o for direita e houver espa�o dispon�vel para aloca��o, o n� ser� inserido
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
