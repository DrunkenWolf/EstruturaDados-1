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

int imprimirNNumerosCrescente(int n) // exercício 2 - soma dos n primeiros números
{
    if (n == 1){ // caso-base: 1 = 1.
        return 1;
    }
    else
    {
        return n + primeirosNNumeros(n - 1); // recorrência: n + (n - 1) ...
    }
}
