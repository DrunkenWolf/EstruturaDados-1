#include"Arvore.h"

void define(tree t) // "inicializa a �rvore como vazia - n� raiz vazio
{
    t = NULL;
}

void cria_raiz(tree t, tipo_elem item) // reserva mem�ria para o n� raiz e configura as defini��es iniciais da �rvore
{
    pno no = malloc(sizeof(NO));
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

pno busca (tree raiz, tipo_elem valor) // busca de um valor na �rvore - recursivamente
{
    if (raiz == NULL) // quando n�o h� n�, n�o h� valor
    {
        return NULL;
    }
    if (raiz->info == valor) // valor encontrado, retorna-se o pr�prio n�
    {
        return raiz;
    }
    if (valor < raiz->info) // se for menor, busca-se na sub�rvore � esquerda. Sen�o, busca-se � direita
    {
        return busca(raiz->esq, valor);
    }
    else
    {
        return busca(raiz->esq, valor);
    }
}

pno busca_insere(tipo_elem x, tree raiz) // realiza a inser��o de um elemento na �rvore, mas tamb�m realiza busca caso o elemento j� exista
{
    if (raiz == NULL) // se n�o existir elemento, cria-se e o insere como nessa posi��o - raiz da �rvore ou sub�rvore
    {
        raiz = malloc(sizeof(tree));
        raiz->info = x;
        raiz->esq = NULL;
        raiz->dir = NULL;
        return raiz;
    }
    if (x < raiz->info) // se o valor for menor, ser� inserido na sub�rvore � esquerda
    {
        return busca_insere(x, raiz->esq);
    }
    if (x > raiz->info) // se o valor for maior, ser� inserido na sub�rvore � direita
    {
        return busca_insere(x, raiz->dir);
    }
    return raiz; // se o elemento a ser inserido j� estiver na �rvore, apenas retorna-se seu endere�o
}
