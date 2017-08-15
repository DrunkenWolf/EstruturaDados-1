#include "Recursoes.h"

void troca(int *x, int i, int j)
{
    int aux;
    aux = x[i];
    x[i] = x[j];
    x[j] = aux;
}

int particao(int *x, int p, int r)
{
    int pivo, i, j;
    pivo = x[(p + r) / 2];
    i = p - 1;
    j = r + 1;
    while (i < j)
    {
        do
        {
            j = j - 1;
        } while (x[j] <= pivo);
        do
        {
            i = i + 1;
        } while (x[i] >= pivo);
        if (i < j)
        {
            troca(x, i, j);
        }
    }
    return j;
}

void quicksort(int *x, int p, int r)
{
    int q;
    if (p < r)
    {
        q = particao(x, p, r);
        quicksort(x, p, q);
        quicksort(x, q + 1, r);
    }
}
