#include "lista_sequencial.h"

// inicializa a lista
void inicializar_lista(LISTA *l)
{
    l->nroElem = 0;
}

// retorna o número de elementos válidos
int quant_elem(LISTA *l)
{
    return l->nroElem;
}

// printa todos os elementos válidos da lista
void eixbir_elem(LISTA *l)
{
    int cont = 0;
    printf("Lista:");
    // percorrer toda a lista
    while (cont < l->nroElem)
    {
        printf(" %d", l->A[cont].chave);
        cont++;
    }
    printf("\n");
}

// busca um elemento sequencialmente na lista e retorna sua posição
int busca_elem(LISTA *l, TIPOCHAVE chave)
{
    int c = 0;
    // percorrer toda a lista
    while (c < l->nroElem)
    {
        // chave encontrada
        if (l->A[c].chave == chave)
        {
            return c;
        }
        else
        {
            c++;
        }
    }
    // elemento não encontrado
    return -1;
}

// insere um elemento de forma sequencial
int inserir_elem(LISTA *l, REGISTRO r)
{
    // número máximo de elementos atingido
    if (l->nroElem == MAX)
    {
        return -1;
    }
    else
    {
        // insere o elemnto e atualiza a contagem de elementos
        l->A[l->nroElem++] = r;
        return 0;
    }
}

// exclui um elemento informado pela chave
int excluir_elem(LISTA *l, TIPOCHAVE chave)
{
    // verifica se o elemento está na lista
    int aux = busca_elem(l, chave);
    // elemento não encontrado
    if (aux == -1)
    {
        return -1;
    }
    else
    {
        int cont = aux;
        // percorre a lista movendo os elementos para as primeiras posições
        for (; cont < l->nroElem - 1; cont++)
        {
            // move o elemento seguinte para a posição atual
            l->A[cont] = l->A[cont + 1];
        }
        // atualiza a contagem de elementos
        l->nroElem--;
        return 0;
    }
}

// reinicializa a lista
void reinicializar(LISTA *l)
{
    inicializar_lista(l);
}
