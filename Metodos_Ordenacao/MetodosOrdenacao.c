#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void insertionSort(int *v, int n)
{
    int i, j, x;
    for (i = 1; i < n; i++) //percorre todo o vetor de 1 a n-1
    {
        x = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > x) //compara o atual com todos os elementos da esquerda e os desloca para a direita
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x; //insere o valor na posição correta
    }
}

void selectionSort(int *v, int n)
{
    int i, j, aux, min;
    for (i = 0; i < n - 1; i++) //percorre o vetor de 0 até o penúltimo elemento
    {
        min = i; // a posição do menor elemento recebe o próprio elemento da posição
        for (j = i + 1; j < n; j++) //percorre o vetor do próximo elemento da posição até o final
        {
            if (v[j] < v[min]) //compara o menor elemento atual com as posições do vetor
            {

                min = j; //troca o menor elemento, caso seja realmente menor
            }
        }
        //troca os elementos de posição, para inserir na posição ideal do momento
        aux = v[i];
        v[i] = v[min];
        v[min] = aux;
    }
}

int main()
{
    FILE *original, *novo;
    srand(time(NULL));
    int n = 10;
    int vet[n];
    int c;
    original = fopen("original.txt", "w");
    for (c = 0; c < n; c++)
    {
        vet[c] = rand() % 999 + 1;
        fprintf(original, " %d", vet[c]);
    }
    insertionSort(vet, n);
    printf("INSERTION:\n\n");
    for (c = 0; c < n; c++)
    {
        printf("%d ", vet[c]);
    }
    //printf("\n\n%f", difftime(inicial, time()));
    return 0;
}
