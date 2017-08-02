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

int imprimirNNumerosCrescente(int n) // exerc�cio 2 - soma dos n primeiros n�meros
{
    if (n == 1){ // caso-base: 1 = 1.
        return 1;
    }
    else
    {
        return n + primeirosNNumeros(n - 1); // recorr�ncia: n + (n - 1) ...
    }
}
