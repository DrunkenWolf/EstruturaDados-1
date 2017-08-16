// Nome: Rafael dos Santos Braz

//RA: 120121

//Trabalho 10: atividade do dia 15/08/2017, método de ordenação QuickSort

#include "Recursoes.h"

int main()
{
    int x[] = {5, 4, 2, 3, 0, 1, 6, 7, 10, 9};
    quicksort(&x, 0, sizeof(x)/sizeof(int) - 1); // chamada do método de ordenação QuickSort (endereço do vetor, início, fim)
    int n;
    for (n = 0; n < sizeof(x)/sizeof(int); n++)
    {
        printf("%d\n", x[n]);
    }
    return 0;
}
