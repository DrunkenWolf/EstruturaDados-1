#include"Arvore.h"

void exibirArvore(tree r) // exibe todos os elementos da árvore no padrão: atual, filho à esquerda e filho à direita
{
    if (r != NULL)
    {
        printf(" %c\n", r->info);
        exibirArvore(r->esq);
        exibirArvore(r->dir);
    }
}

void define(tree *t) // "inicializa a árvore como vazia - nó raiz vazio
{
    *t = NULL;
}

void cria_raiz(tree *t, tipo_elem item) // reserva memória para o nó raiz e configura as definições iniciais da árvore
{
    pno no = malloc(sizeof(NO));
    no->esq = NULL;
    no->dir = NULL;
    no->info = item;
    *t = no;
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

pno busca (tree raiz, tipo_elem valor) // busca de um valor na árvore - recursivamente
{
    if (raiz == NULL) // quando não há nó, não há valor
    {
        return NULL;
    }
    if (raiz->info == valor) // valor encontrado, retorna-se o próprio nó
    {
        return raiz;
    }
    if (valor < raiz->info) // se for menor, busca-se na subárvore à esquerda. Senão, busca-se à direita
    {
        return busca(raiz->esq, valor);
    }
    else
    {
        return busca(raiz->esq, valor);
    }
}

pno busca_insere(tipo_elem x, tree *raiz) // realiza a inserção de um elemento na árvore, mas também realiza busca caso o elemento já exista
{
    tree aux = *raiz;
    if (*raiz == NULL) // se não existir elemento, cria-se e o insere como nessa posição - raiz da árvore ou subárvore
    {
        tree i = malloc(sizeof(tree));
        i->info = x;
        i->esq = NULL;
        i->dir = NULL;
        *raiz = i;
        return *raiz;
    }
    if (x < aux->info) // se o valor for menor, será inserido na subárvore à esquerda
    {
        return busca_insere(x, &aux->esq);
    }
    if (x > aux->info) // se o valor for maior, será inserido na subárvore à direita
    {
        return busca_insere(x, &aux->dir);
    }
    return aux; // se o elemento a ser inserido já estiver na árvore, apenas retorna-se seu endereço
}

void substituimenoradireita(pno p, pno suc)
{
    pno q;
    if (suc->esq == NULL)
    {
        p->info = suc->info;
        q = suc;
        suc = suc->dir;
        free(q);
    }
    else
    {
        substituimenoradireita(p, suc->esq);
    }
}

void removerNo(pno p)
{
    pno q;
    if (p->esq == NULL)
    {
        q = p;
        p = p->dir;
        free(q);
    }
    else if (p->dir == NULL)
    {
        q = p;
        p = p->esq;
        free(q);
    }
    else
    {
        substituimenoradireita(p, p->dir);
    }
}

int busca_remove(tree *raiz, tipo_elem x)
{
    tree aux = *raiz;
    if (aux == NULL)
    {
        return -1;
    }
    if (aux->info == x)
    {
        removerNo(aux);
        return 0;
    }
    if (aux->info < x)
    {
        return busca_remove(&aux->esq, x);
    }
    else
    {
        return busca_remove(&aux->dir, x);
    }
}
