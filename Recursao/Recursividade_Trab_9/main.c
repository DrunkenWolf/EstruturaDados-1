// Nome: Rafael dos Santos Braz

//RA: 120121

//Trabalho 9: atividade do dia 08/08/2017

#include "Recursoes.h"

int main()
{
    printf("Exerc�cio (i): \n");
    naturalBinario(42); // exerc�cio (i). Fun��o: sem retorno, recebe um n�mero inteiro n para ser convertido
    printf("ws %d\n", somaNumerosSeguidosUm(5, 0));
    printf("Exerc�cio (iii): \n");
    char original[] = "Rafael";
    char novo[sizeof(original)/sizeof(char)];
    inverterString(original, sizeof(original)/sizeof(char) - 1, novo);
    int c;
    for (c = 0; c < sizeof(original)/sizeof(char); c++)
    {
        printf("%c", novo[c]);
    }
    return 0;
}
