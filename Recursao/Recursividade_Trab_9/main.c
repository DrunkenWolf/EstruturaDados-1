// Nome: Rafael dos Santos Braz

//RA: 120121

//Trabalho 9: atividade do dia 08/08/2017

#include "Recursoes.h"

int main()
{
    printf("Exercício (i): \n");
    naturalBinario(42); // exercício (i). Função: sem retorno, recebe um número inteiro n para ser convertido e exibe o binário correspondente
    printf("soma 1N: %d\n", somaNumerosSeguidosUm(5)); // exercício (ii). Função: recebe um inteiro que indica o valor de N, retorna a soma dos 1N números
    printf("Exercício (iii): \n");
    char original[] = "Rafael";
    char novo[sizeof(original)/sizeof(char)];
    inverterString(original, sizeof(original)/sizeof(char) - 1, novo); // exercício (iii). Função: recebe o vetor de char original, o tamanho desse vetor e o ponteiro para onde a inversão será
    //armazenada, retornando a "string" invertida
    int c;
    for (c = 0; c < sizeof(original)/sizeof(char); c++)
    {
        printf("%c", novo[c]);
    }
    printf("\nExercício (iv): %d\n", sequenciaAckerman(3, 1)); // exercício (iv). Função: recebe os inteiros M e N, retorna o resultado da equação
    printf("Exercício (v): %d\n", mdc(6, 12)); // exercício (v). Função: recebe os inteiros X e Y, retorna o um inteiro representando o máximo divisor comum entre eles
    printf("Exercício (vi): %d\n", verificarPalindromo(original, 0, sizeof(original)/sizeof(char) - 1)); // exercício (vi). Função: recebe um vetor de char que contém a palavra a ser comparada
    //um inteiro com a posição inicial e um inteiro indicando o tamanho - 1 do vetor, retornando 0 se for um palíndromo e -1 se não o for
    printf("Exercício (vii): %.2f\n", calculoSerie(4)); // exercício (vii). Função: recebe um inteiro N e retorna um double com o resultado da sequência
    return 0;
}
