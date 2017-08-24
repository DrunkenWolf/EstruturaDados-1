#include "Funcoes.h"


void ShellSortInteiros(int *vetor, int tam)
{
    int h;
    for (h = tam / 2; h > 0; h--)
    {
        int pos;
        for (pos = 0; pos < tam; pos++)
        {
            int posComp = pos + h;
            while (posComp < tam)
            {
                if (vetor[pos] > vetor[posComp])
                {
                    int aux = vetor[pos];
                    vetor[pos] = vetor[posComp];
                    vetor[posComp] = aux;
                    pos--;
                    break;
                }
                posComp += h;
            }
        }
    }
}

void ShellSortPalavras(char* vetor, int tam)
{
    int h;
    for (h = tam / 2; h > 0; h--)
    {
        int pos;
        for (pos = 0; pos < tam; pos++)
        {
            int posComp = pos + h;
            while (posComp < tam)
            {
                if (strcmp(vetor[pos], vetor[posComp]) > 0)
                {
                    char *aux = vetor[pos];
                    vetor[pos] = vetor[posComp];
                    vetor[posComp] = aux;
                    pos--;
                    break;
                }
                posComp += h;
            }
        }
    }
}
