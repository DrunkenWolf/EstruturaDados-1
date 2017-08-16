#include "Recursoes.h"

void troca(int *x, int i, int j) // troca os dois elementos (menor e maior que o pivô) de posição, ordenando-os
{
    int aux;
    aux = x[i];
    x[i] = x[j];
    x[j] = aux;
}

int particao(int *x, int p, int r) // subdivide o vetor em duas partes (esquerda e direita) a partir de um pivô
{
    int pivo, i, j;
    pivo = x[(p + r) / 2]; // pivô é sempre o "centro" do vetor
    i = p - 1;
    j = r + 1;
    while (i < j) // enquanto os "ponteiros" da esquerda e direita não se encontrarem, deve ser feito o algoritmo
    {
        do
        {
            j = j - 1;
        } while (x[j] > pivo); // faz a procura por um número que seja menor que o pivô à sua direita --- aqui estava o erro de interpretação do agoritmo do livro ---
        do
        {
            i = i + 1;
        } while (x[i] < pivo); // faz a procura por um número que seja maior que o pivô à sua esquerda --- aqui estava o erro de interpretação do agoritmo do livro ---
        if (i < j)
        {
            troca(x, i, j); // caso eles não estejam na mesma posição, haverá a troca dos valores dessas posições para que fiquem ordenados corretamente
        }
    }
    return j;
}

void quicksort(int *x, int p, int r) // função inicial e recursiva da ordenação
{
    int q;
    if (p < r) // verifica a posição inicial não encontrou a final, pois assim a ordenação estará completa
    {
        q = particao(x, p, r); // particiona o vetor
        //realiza o QuickSort para cada uma das partes
        quicksort(x, p, q);
        quicksort(x, q + 1, r);
    }
}
