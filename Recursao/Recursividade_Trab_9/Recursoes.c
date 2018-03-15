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

int somaNumerosSeguidosUm(int n) // exerc�cio (ii) - soma dos n�meros 1N
{
    if (n == 0) // caso-base: n = 0, onde soma-se apenas 1
    {
        return 1;
    }
    else // Recorr�ncia: realiza-se 1N + 1(N -1) + ... + 11 + 1
    {
        int i;
        for (i = 10; n / i != 0; i *= 10) {} // encontra-se qual � o valor de multiplica��o que corresponde ao 1 de 1N, pelo n�mero de algarismos de N
        return i + n + somaNumerosSeguidosUm(n - 1);
    }
}

void inverterString(char *palavra, int tam, char *invertido) // exerc�cio (iii) - inverter um vetor de char recebido
{
    static int pos = 0; // posi��o no vetor invertido
    if (tam == 0) // tamanho = 0, chaga-se a primeira posi��o do vetor
    {
        invertido[pos] = palavra[tam];
    }
    else // Recorr�ncia: chama-se a fun��o novamente com a posi��o anterior (tamanho - 1)
    {
        invertido[pos++] = palavra[tam];
        inverterString(palavra, tam - 1, invertido);
    }
}

int sequenciaAckerman(int m, int n) // exerc�cio (iv) - calcula a sequ�ncia de Ackerman
{
    if (m == 0) // caso-base: final da equa��o
    {
        return n + 1;
    }
    else if (m > 0 && n == 0) // caso de recorr�ncia
    {
        return sequenciaAckerman(m - 1, 1);
    }
    else // caso de recorr�ncia
    {
        return sequenciaAckerman(m - 1, sequenciaAckerman(m, n - 1));
    }
}

int mdc(int x, int y) // exerc�cio (v) - calculao m�ximo divisor comum
{
    if (x >= y && x % y == 0) // caso-base: retona o pr�prio Y
    {
        return y;
    }
    else if (x < y) // caso de recorr�ncia
    {
        return mdc(y, x);
    }
    else // caso de recorr�ncia
    {
        return mdc(y, x % y);
    }
}

int verificarPalindromo(char *palavra, int pos, int fim) // exerc�cio (vi) - verifica se a palavra indicada � um pal�ndromo
{
    if (pos >= fim) // caso-base: a palavra foi completamente verificada e constata-se que � um pal�dromo, retornando 0
    {
        return 0;
    }
    else if (palavra[pos] == palavra[fim]) // verifica-se a igualdade entre os caracteres, se forem iguais a fun��o � chamada novamente
    {
        return verificarPalindromo(palavra, pos + 1, fim - 1);
    }
    else // caso final onde verifica-se que n�o � um pal�ndromo, retorna-se -1
    {
        return -1;
    }
}

double calculoSerie(int n) // exerc�cio (vii) - calcula a s�rie
{
    if (n == 1) // caso-base: retorna o primeiro elemento da s�rie (2/4)
    {
        return 2.0 / 4.0;
    }
    else // caso de recorr�ncioa: (n^2 + 1) / (n + 3) + .... + 2/4
    {
        return (pow(n, 2) + 1) / (n + 3) + calculoSerie(n - 1);
    }
}

