#include "Recursoes.h"

void troca(int *x, int i, int j) // troca os dois elementos (menor e maior que o piv�) de posi��o, ordenando-os
{
    int aux;
    aux = x[i];
    x[i] = x[j];
    x[j] = aux;
}

int particao(int *x, int p, int r) // subdivide o vetor em duas partes (esquerda e direita) a partir de um piv�
{
    int pivo, i, j;
    pivo = x[(p + r) / 2]; // piv� � sempre o "centro" do vetor
    i = p - 1;
    j = r + 1;
    while (i < j) // enquanto os "ponteiros" da esquerda e direita n�o se encontrarem, deve ser feito o algoritmo
    {
        do
        {
            j = j - 1;
        } while (x[j] > pivo); // faz a procura por um n�mero que seja menor que o piv� � sua direita --- aqui estava o erro de interpreta��o do agoritmo do livro ---
        do
        {
            i = i + 1;
        } while (x[i] < pivo); // faz a procura por um n�mero que seja maior que o piv� � sua esquerda --- aqui estava o erro de interpreta��o do agoritmo do livro ---
        if (i < j)
        {
            troca(x, i, j); // caso eles n�o estejam na mesma posi��o, haver� a troca dos valores dessas posi��es para que fiquem ordenados corretamente
        }
    }
    return j;
}

void quicksort(int *x, int p, int r) // fun��o inicial e recursiva da ordena��o
{
    int q;
    if (p < r) // verifica a posi��o inicial n�o encontrou a final, pois assim a ordena��o estar� completa
    {
        q = particao(x, p, r); // particiona o vetor
        //realiza o QuickSort para cada uma das partes
        quicksort(x, p, q);
        quicksort(x, q + 1, r);
    }
}
