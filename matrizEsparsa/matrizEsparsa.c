#include "matrizEsparsa.h"

void inicializarMatriz(MATRIZ *m, int numLinhas, int numColunas)
{
    m->numLinhas = numLinhas;
    m->numColunas = numColunas;
    m->ALinha = (PONT *)malloc(numLinhas * sizeof(ELEMENTO));
    m->AColuna = (PONT *)malloc(numColunas * sizeof(ELEMENTO));
    int c;
    for (c = 0; c < numLinhas; c++)
    {
        m->ALinha[c] = NULL;
    }
    for (c = 0; c < numColunas; c++)
    {
        m->AColuna[c] = NULL;
    }
}

void reinicializarMatriz(MATRIZ *m)
{
    int c;
    for (c = 0; c < m->numLinhas; c++)
    {
        PONT atual = m->ALinha[c];
        while (atual != NULL)
        {
            PONT apagar = atual;
            atual = atual->proxLinha;
            free(apagar);
        }
    }
    free(m->ALinha);
    free(m->AColuna);
    m->ALinha = NULL;
    m->AColuna = NULL;
    m->numColunas = 0;
    m->numLinhas = 0;
}

void exibirMatriz(MATRIZ *m)
{
    int c;
    PONT aux;
    for (c = 0; c < m->numLinhas; c++)
    {
        aux = m->ALinha[c];
        while (aux != NULL)
        {
            printf("[%d][%d]: %d\n", aux->linha, aux->coluna, aux->valor);
            aux = aux->proxLinha;
        }
    }
}

int inserirElemMatriz(MATRIZ *m, int linha, int coluna, int valor)
{
    if ((linha <= 0 || linha > m->numLinhas) || (coluna <= 0 || coluna > m->numColunas))
    {
        return -1;
    }
    PONT atual = m->ALinha[linha - 1];
    PONT anterior = NULL;
    while (atual != NULL && atual->coluna < coluna)
    {
        anterior = atual;
        atual = atual->proxLinha;
    }
    if (atual != NULL && atual->coluna == coluna)
    {
        atual->valor = valor;
        return 0;
    }
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    novo->coluna = coluna;
    novo
