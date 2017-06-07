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
    printf("Exibindo Matriz\n");
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
    if ((linha < 0 || linha >= m->numLinhas) || (coluna < 0 || coluna >= m->numColunas))
    {
        return -1;
    }
    PONT atual = m->ALinha[linha];
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
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    novo->coluna = coluna;
    novo->linha = linha;
    novo->valor = valor;
    if (anterior == NULL)
    {
        novo->proxLinha = m->ALinha[linha];
        m->ALinha[linha] = novo;
    }
    else
    {
        novo->proxLinha = anterior->proxLinha;
        anterior->proxLinha = novo;
    }
    atual = m->AColuna[coluna];
    anterior = NULL;
    while (atual != NULL && atual->linha < linha)
    {
        anterior = atual;
        atual = atual->proxColuna;
    }
    if (anterior == NULL)
    {
        novo->proxColuna = m->AColuna[coluna];
        m->AColuna[coluna] = novo;
    }
    else
    {
        novo->proxColuna = anterior->proxColuna;
        anterior->proxColuna = novo;
    }
    return 0;
}

int somarMatrizes(MATRIZ *m1, MATRIZ *m2, MATRIZ *result)
{
    if (m1->numColunas != m2->numColunas || m1->numLinhas != m2->numLinhas)
    {
        return -1;
    }
    reinicializarMatriz(result);
    inicializarMatriz(result, m1->numLinhas, m1->numColunas);
    int c;
    for (c = 0; c < m1->numLinhas; c++)
    {
        PONT atual = m1->ALinha[c];
        PONT atualM2 = m2->ALinha[c];
        while (atual != NULL)
        {
            while (atualM2 != NULL && atualM2->coluna < atual->coluna)
            {
                atualM2 = atualM2->proxLinha;
            }
            if (atualM2 != NULL && atualM2->coluna == atual->coluna)
            {
                inserirElemMatriz(result, c, atual->coluna, atual->valor + atualM2->valor);
            }
            else
            {
                inserirElemMatriz(result, c, atual->coluna, atual->valor);
            }
            atual = atual->proxLinha;
        }
    }
    for (c = 0; c < m2->numLinhas; c++)
    {
        PONT atual = m2->ALinha[c];
        PONT atualM2 = m1->ALinha[c];
        while (atual != NULL)
        {
            while (atualM2 != NULL && atualM2->coluna < atual->coluna)
            {
                atualM2 = atualM2->proxLinha;
            }
            if (atualM2 != NULL && atualM2->coluna == atual->coluna)
            {
                inserirElemMatriz(result, c, atual->coluna, atual->valor + atualM2->valor);
            }
            else
            {
                inserirElemMatriz(result, c, atual->coluna, atual->valor);
            }
            atual = atual->proxLinha;
        }
    }
    return 0;
}

int subtrairMatrizes(MATRIZ *m1, MATRIZ *m2, MATRIZ *result)
{
    if (m1->numColunas != m2->numColunas || m1->numLinhas != m2->numLinhas)
    {
        return -1;
    }
    int c;
    for (c = 0; c < m2->numLinhas; c++)
    {
        PONT atual = m2->ALinha[c];
        while (atual != NULL)
        {
            atual->valor = atual->valor * -1;
            atual = atual->proxLinha;
        }
    }
    return somarMatrizes(m1, m2, result);
}

int multiplicarMatrizes(MATRIZ *m1, MATRIZ *m2, MATRIZ *result)
{
    if (m1->numColunas != m2->numLinhas)
    {
        return -1;
    }
    reinicializarMatriz(result);
    inicializarMatriz(result, m1->numLinhas, m2->numColunas);
    int c;
    for (c = 0; c < m1->numLinhas; c++)
    {
        int i;
        for (i = 0; i < m2->numColunas; i++)
        {
            int valor = 0;
            PONT atual = m1->ALinha[c];
            PONT atualM2 = m2->AColuna[i];
            while (atual != NULL)
            {
                while (atualM2 != NULL && atualM2->linha < atual->coluna)
                {
                    atualM2 = atualM2->proxColuna;
                }
                if (atualM2 != NULL && atualM2->linha == atual->coluna)
                {
                    valor += atual->valor * atualM2->valor;
                }
                atual = atual->proxLinha;
                atualM2 = m2->AColuna[i];
            }
            if (valor != 0)
            {
                inserirElemMatriz(result, c, i, valor);
            }
        }
    }
    return 0;
}
