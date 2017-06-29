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

void bubbleSort(int *v, int n)
{
    int i, j, aux, continua;
    i = n - 1;
    do
    {
        continua = 0;
        for (j = 0; j < i; j++)
        {
            if (v[j] > v[j + 1])
            {
                continua = j;
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                //é possível usar o algoritmo de XOR para substituir o aux
            }
        }
        i--;
    }
    while (continua != 0);
}

int main()
{
    int x;
    scanf("%d", &x);
    time_t inicio = time(NULL), fim;
    FILE *arquivo;
    if (x == 0)
    {
        srand(time(NULL));
        int n;
        scanf("%d", &n);
        int vet[n];
        int c;
        arquivo = fopen("original.txt", "w");
        fprintf(arquivo, "%d", n);
        for (c = 0; c < n; c++)
        {
            
            //srand(time(NULL));
            int x = rand() % 10000000 + 1;
            srand(x);
            vet[c] = rand() % 10000000 + 1;
            fprintf(arquivo, "\n%d", vet[c]);
        }
    }
    else if (x == 1)
    {
        int n;
        arquivo = fopen("original.txt", "rt");
        fscanf(arquivo, "%d", &n);
        printf("%d\n", n);
        int vet[n];
        int c;
        for (c = 0; c < n; c++)
        {
            fscanf(arquivo, "%d", &vet[c]);
        }
        insertionSort(vet, n);
        printf("INSERTION:\n\n");
        int x = 1;
        for (c = 0; c < n; c++)
        {
            printf("%d | %d\n", vet[c], x);
            x++;
        }
        printf("\n");
    }
    else if (x == 2)
    {
        int n;
        arquivo = fopen("original.txt", "rt");
        fscanf(arquivo, "%d", &n);
        printf("%d\n", n);
        int vet[n];
        int c;
        for (c = 0; c < n; c++)
        {
            fscanf(arquivo, "%d", &vet[c]);
        }
        selectionSort(vet, n);
        printf("SELECTION:\n\n");
    }
    else if (x == 3)
    {
        int n;
        arquivo = fopen("original.txt", "rt");
        fscanf(arquivo, "%d", &n);
        printf("%d\n", n);
        int vet[n];
        int c;
        for (c = 0; c < n; c++)
        {
            fscanf(arquivo, "%d", &vet[c]);
        }
        bubbleSort(vet, n);
        printf("BUBBLE:\n\n");
    }
    fim = time(NULL);
    printf("TEMPO: %f\n", difftime(fim, inicio));
    return 0;
}
