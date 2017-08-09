#include "Recursoes.h"

void naturalBinario(int n) // exerc�cio (i) - natural para bin�rio
{
    //printf("%d --\n", n);
    if (n / 2 == 1) // caso-base: divis�o de n por 2 = 1, mostra-se 1 seguido de 0
    {
        printf(" 1\n %d\n", n % 2);
    }
    else // Recorr�ncia: uma nova divis�o de (n / 2) seguida da exibi��o do resto da divis�o (necess�rio para imprimir invertido)
    {
        naturalBinario(n / 2);
        printf(" %d\n", n % 2);
    }
}

int somaNumerosSeguidosUm(int n, int atual) // exerc�cio (ii) ------------------------- imcomleto
{
    static int posi = 0;
    if (atual == n) // caso-base: divis�o de n por 2 = 1, mostra-se 1 seguido de 0
    {
        return (10 * posi) + n;
    }
    else // Recorr�ncia: uma nova divis�o de (n / 2) seguida da exibi��o do resto da divis�o (necess�rio para imprimir invertido)
    {
        return (10 * posi++) + somaNumerosSeguidosUm(n, atual + 1);
    }
}

void inverterString(char *palavra, int tam, char *invertido) // exerc�cio (iii) - inverter um vetor de char recebido
{
    static int pos = 0;
    if (tam == 0) // caso-base: divis�o de n por 2 = 1, mostra-se 1 seguido de 0
    {
        invertido[pos] = palavra[tam];
    }
    else // Recorr�ncia: uma nova divis�o de (n / 2) seguida da exibi��o do resto da divis�o (necess�rio para imprimir invertido)
    {
        invertido[pos++] = palavra[tam];
        inverterString(palavra, tam - 1, invertido);
    }
}
