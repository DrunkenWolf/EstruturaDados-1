#include "Recursoes.h"

void naturalBinario(int n) // exercício (i) - natural para binário
{
    //printf("%d --\n", n);
    if (n / 2 == 1) // caso-base: divisão de n por 2 = 1, mostra-se 1 seguido de 0
    {
        printf(" 1\n %d\n", n % 2);
    }
    else // Recorrência: uma nova divisão de (n / 2) seguida da exibição do resto da divisão (necessário para imprimir invertido)
    {
        naturalBinario(n / 2);
        printf(" %d\n", n % 2);
    }
}

int somaNumerosSeguidosUm(int n, int atual) // exercício (ii) ------------------------- imcomleto
{
    static int posi = 0;
    if (atual == n) // caso-base: divisão de n por 2 = 1, mostra-se 1 seguido de 0
    {
        return (10 * posi) + n;
    }
    else // Recorrência: uma nova divisão de (n / 2) seguida da exibição do resto da divisão (necessário para imprimir invertido)
    {
        return (10 * posi++) + somaNumerosSeguidosUm(n, atual + 1);
    }
}

void inverterString(char *palavra, int tam, char *invertido) // exercício (iii) - inverter um vetor de char recebido
{
    static int pos = 0;
    if (tam == 0) // caso-base: divisão de n por 2 = 1, mostra-se 1 seguido de 0
    {
        invertido[pos] = palavra[tam];
    }
    else // Recorrência: uma nova divisão de (n / 2) seguida da exibição do resto da divisão (necessário para imprimir invertido)
    {
        invertido[pos++] = palavra[tam];
        inverterString(palavra, tam - 1, invertido);
    }
}
