// Nome: Rafael dos Santos Braz

//RA: 120121

//Trabalho 11: atividade do dia 16/08/2017, m�todo de ordena��o HeapSort e MergeSort

#include "Recursoes.h"

int main()
{
    int x[] = {5, 4, 10, 2, 3, 0, 1, 6, 7, 9, 8};
    heapSort(&x, sizeof(x)/sizeof(int)); // chamada do m�todo de ordena��o HeapSort (endere�o do vetor, tamanho)
    int n;
    for (n = 0; n < sizeof(x)/sizeof(int); n++)
    {
        printf("%d\n", x[n]);
    }
    return 0;
}
