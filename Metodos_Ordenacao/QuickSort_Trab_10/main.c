// Nome: Rafael dos Santos Braz

//RA: 120121

//Trabalho 10: atividade do dia 15/08/2017, método de ordenação QuickSort

#include "Recursoes.h"

int main()
{
    int x[] = {5, 4, 2, 3, 0, 1};
    quicksort(&x, 0, 5);
    int n;
    for (n = 0; n < 6; n++)
    {
        printf("%d\n", x[n]);
    }
    return 0;
}
