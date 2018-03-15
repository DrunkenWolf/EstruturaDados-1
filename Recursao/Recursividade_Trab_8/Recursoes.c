#include "Recursoes.h"

int primeirosNCubos(int n) // exercício 1 - soma dos n primeiros cubos
{
    if (n == 1) // caso-base: 1^3 = 1.
    {
        return 1;
    }
    else
    {
        return pow(n, 3) + primeirosNCubos(n - 1); // recorrência: n^3 + (n-1)^3 ...
    }
}

int primeirosNNumeros(int n) // exercício 2 - soma dos n primeiros números
{
    if (n == 1){ // caso-base: 1 = 1.
        return 1;
    }
    else
    {
        return n + primeirosNNumeros(n - 1); // recorrência: n + (n - 1) ...
    }
}

void imprimirNNumerosCrescente(int n) // exercício 3 - imprimir números em ordem crescente
{
    if (n == 0){ // caso-base: 0 = imprimir o primeiro número.
        printf(" %d\n", 0);
    }
    else
    {
        imprimirNNumerosCrescente(n - 1); // recorrência: 0, 1, 2, ... , n-1, n --- chama-se invertido para que imprima primeiro o último a ser empilhado, ou seja, o zero.
        printf(" %d\n", n);
    }
}

void imprimirNNumerosDecrescente(int n) // exercício 4 - imprimir números em ordem decrescente
{
    if (n == 0){ // caso-base: 0 = imprimir o último número.
        printf(" %d\n", 0);
    }
    else
    {
        printf(" %d\n", n);
        imprimirNNumerosDecrescente(n - 1); // recorrência: n, n-1, ... , 2, 1, 0
    }
}

int somaElemVetor(int *v, int atual) // exercício 5 - soma dos valores de um vetor
{
    if (atual == 0){ // caso-base: 0 = primeiro elemento do vetor, retorna o próprio elemento
        return v[0];
    }
    else
    {
        return v[atual] + somaElemVetor(v, atual - 1); // recorrência: v[atual] + v[atual - 1] + .... + v[1] + v[0]
    }
}

double MediaElemVetor(int *v, int tam, int atual) // exercício 6 - média dos valores de um vetor
{
    if (atual == 0){ // caso-base: 0 = primeiro elemento do vetor, retorna o próprio elemento já com o "peso" (correção com o tamanho do vetor) na média
        return v[0] / (double)tam;
    }
    else
    {
        return v[atual] / (double)tam + MediaElemVetor(v, tam, atual - 1); // recorrência: v[atual]/tam + v[atual - 1]/tam + ... + v[1]/tam + v[0]/tam
    }
}

