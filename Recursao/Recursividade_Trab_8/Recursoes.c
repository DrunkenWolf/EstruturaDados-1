#include "Recursoes.h"

long long int primeirosNCubos(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return (n * n * n) + primeirosNCubos(n - 1);
    }
}
