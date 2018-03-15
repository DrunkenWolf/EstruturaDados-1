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

int somaNumerosSeguidosUm(int n) // exercício (ii) - soma dos números 1N
{
    if (n == 0) // caso-base: n = 0, onde soma-se apenas 1
    {
        return 1;
    }
    else // Recorrência: realiza-se 1N + 1(N -1) + ... + 11 + 1
    {
        int i;
        for (i = 10; n / i != 0; i *= 10) {} // encontra-se qual é o valor de multiplicação que corresponde ao 1 de 1N, pelo número de algarismos de N
        return i + n + somaNumerosSeguidosUm(n - 1);
    }
}

void inverterString(char *palavra, int tam, char *invertido) // exercício (iii) - inverter um vetor de char recebido
{
    static int pos = 0; // posição no vetor invertido
    if (tam == 0) // tamanho = 0, chaga-se a primeira posição do vetor
    {
        invertido[pos] = palavra[tam];
    }
    else // Recorrência: chama-se a função novamente com a posição anterior (tamanho - 1)
    {
        invertido[pos++] = palavra[tam];
        inverterString(palavra, tam - 1, invertido);
    }
}

int sequenciaAckerman(int m, int n) // exercício (iv) - calcula a sequência de Ackerman
{
    if (m == 0) // caso-base: final da equação
    {
        return n + 1;
    }
    else if (m > 0 && n == 0) // caso de recorrência
    {
        return sequenciaAckerman(m - 1, 1);
    }
    else // caso de recorrência
    {
        return sequenciaAckerman(m - 1, sequenciaAckerman(m, n - 1));
    }
}

int mdc(int x, int y) // exercício (v) - calculao máximo divisor comum
{
    if (x >= y && x % y == 0) // caso-base: retona o próprio Y
    {
        return y;
    }
    else if (x < y) // caso de recorrência
    {
        return mdc(y, x);
    }
    else // caso de recorrência
    {
        return mdc(y, x % y);
    }
}

int verificarPalindromo(char *palavra, int pos, int fim) // exercício (vi) - verifica se a palavra indicada é um palíndromo
{
    if (pos >= fim) // caso-base: a palavra foi completamente verificada e constata-se que é um palídromo, retornando 0
    {
        return 0;
    }
    else if (palavra[pos] == palavra[fim]) // verifica-se a igualdade entre os caracteres, se forem iguais a função é chamada novamente
    {
        return verificarPalindromo(palavra, pos + 1, fim - 1);
    }
    else // caso final onde verifica-se que não é um palíndromo, retorna-se -1
    {
        return -1;
    }
}

double calculoSerie(int n) // exercício (vii) - calcula a série
{
    if (n == 1) // caso-base: retorna o primeiro elemento da série (2/4)
    {
        return 2.0 / 4.0;
    }
    else // caso de recorrêncioa: (n^2 + 1) / (n + 3) + .... + 2/4
    {
        return (pow(n, 2) + 1) / (n + 3) + calculoSerie(n - 1);
    }
}

