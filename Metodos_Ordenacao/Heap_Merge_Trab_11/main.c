// Nome: Rafael dos Santos Braz

//RA: 120121

//Trabalho 11: atividade do dia 16/08/2017, m�todo de ordena��o HeapSort e MergeSort

#include "Recursoes.h"

int main()
{
    int x[11] = {5, 4, 10, 2, 3, 0, 1, 6, 7, 9, 8};
    //heapSort(&x, sizeof(x)/sizeof(int)); // chamada do m�todo de ordena��o HeapSort (endere�o do vetor, tamanho)
    mergeSort(&x, 0, sizeof(x)/sizeof(int) - 1); // chamada do m�todo de ordena��o HeapSort (endere�o do vetor, tamanho)
    int n;
    for (n = 0; n < sizeof(x)/sizeof(int); n++) // exibi��o do vetor ordenado por Merge ou heap Sort
    {
        printf("%d\n", x[n]);
    }
    return 0;
}
