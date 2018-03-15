#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void bubbleSortDecrescente(int *v, int n)
{
    int i, j, aux, continua;
    i = n - 1;
    do
    {
        continua = 0;
        for (j = 0; j < i; j++)
        {
            if (v[j] < v[j + 1])
            {
                continua = j;
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                //é possível usar o algoritmo de XOR para substituir o aux
            }
        }
        i--;
    } while (continua != 0);
}

void ordenar(int *v, int n)
{
    int c = n - 1, i = 0;
    while (c > i)
    {
        if (v[i] == 1 && v[c] == 0)
        {
            v[i] = 0;
            v[c] = 1;
        }
        if (v[i] == 0)
        {
            i++;
        }
        if (v[c] == 1)
        {
            c--;
        }
    }
}

int main()
{
    int x[] = {1, 0, 0, 1, 0, 0, 1, 1, 0};
    ordenar(x, 9);
    int c;
    for (c = 0; c < 9; c++)
    {
        printf("%d\n", x[c]);
    }
    scanf("%d");
}
