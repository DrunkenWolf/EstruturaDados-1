#include "Recursoes.h"

int primeirosNCubos(int n) // exerc�cio 1 - soma dos n primeiros cubos
{
    if (n == 1) // caso-base: 1^3 = 1.
    {
        return 1;
    }
    else
    {
        return pow(n, 3) + primeirosNCubos(n - 1); // recorr�ncia: n^3 + (n-1)^3 ...
    }
}

int primeirosNNumeros(int n) // exerc�cio 2 - soma dos n primeiros n�meros
{
    if (n == 1){ // caso-base: 1 = 1.
        return 1;
    }
    else
    {
        return n + primeirosNNumeros(n - 1); // recorr�ncia: n + (n - 1) ...
    }
}

void imprimirNNumerosCrescente(int n) // exerc�cio 3 - imprimir n�meros em ordem crescente
{
    if (n == 0){ // caso-base: 0 = imprimir o primeiro n�mero.
        printf(" %d\n", 0);
    }
    else
    {
        imprimirNNumerosCrescente(n - 1); // recorr�ncia: 0, 1, 2, ... , n-1, n --- chama-se invertido para que imprima primeiro o �ltimo a ser empilhado, ou seja, o zero.
        printf(" %d\n", n);
    }
}

void imprimirNNumerosDecrescente(int n) // exerc�cio 4 - imprimir n�meros em ordem decrescente
{
    if (n == 0){ // caso-base: 0 = imprimir o �ltimo n�mero.
        printf(" %d\n", 0);
    }
    else
    {
        printf(" %d\n", n);
        imprimirNNumerosDecrescente(n - 1); // recorr�ncia: n, n-1, ... , 2, 1, 0
    }
}

int somaElemVetor(int *v, int atual) // exerc�cio 5 - soma dos valores de um vetor
{
    if (atual == 0){ // caso-base: 0 = primeiro elemento do vetor, retorna o pr�prio elemento
        return v[0];
    }
    else
    {
        return v[atual] + somaElemVetor(v, atual - 1); // recorr�ncia: v[atual] + v[atual - 1] + .... + v[1] + v[0]
    }
}

double MediaElemVetor(int *v, int tam, int atual) // exerc�cio 6 - m�dia dos valores de um vetor
{
    if (atual == 0){ // caso-base: 0 = primeiro elemento do vetor, retorna o pr�prio elemento j� com o "peso" (corre��o com o tamanho do vetor) na m�dia
        return v[0] / (double)tam;
    }
    else
    {
        return v[atual] / (double)tam + MediaElemVetor(v, tam, atual - 1); // recorr�ncia: v[atual]/tam + v[atual - 1]/tam + ... + v[1]/tam + v[0]/tam
    }
}

