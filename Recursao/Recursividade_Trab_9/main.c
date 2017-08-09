// Nome: Rafael dos Santos Braz

//RA: 120121

//Trabalho 9: atividade do dia 08/08/2017

#include "Recursoes.h"

int main()
{
    printf("Exerc�cio (i): \n");
    naturalBinario(42); // exerc�cio (i). Fun��o: sem retorno, recebe um n�mero inteiro n para ser convertido e exibe o bin�rio correspondente
    printf("soma 1N: %d\n", somaNumerosSeguidosUm(5)); // exerc�cio (ii). Fun��o: recebe um inteiro que indica o valor de N, retorna a soma dos 1N n�meros
    printf("Exerc�cio (iii): \n");
    char original[] = "Rafael";
    char novo[sizeof(original)/sizeof(char)];
    inverterString(original, sizeof(original)/sizeof(char) - 1, novo); // exerc�cio (iii). Fun��o: recebe o vetor de char original, o tamanho desse vetor e o ponteiro para onde a invers�o ser�
    //armazenada, retornando a "string" invertida
    int c;
    for (c = 0; c < sizeof(original)/sizeof(char); c++)
    {
        printf("%c", novo[c]);
    }
    printf("\nExerc�cio (iv): %d\n", sequenciaAckerman(3, 1)); // exerc�cio (iv). Fun��o: recebe os inteiros M e N, retorna o resultado da equa��o
    printf("Exerc�cio (v): %d\n", mdc(6, 12)); // exerc�cio (v). Fun��o: recebe os inteiros X e Y, retorna o um inteiro representando o m�ximo divisor comum entre eles
    printf("Exerc�cio (vi): %d\n", verificarPalindromo(original, 0, sizeof(original)/sizeof(char) - 1)); // exerc�cio (vi). Fun��o: recebe um vetor de char que cont�m a palavra a ser comparada
    //um inteiro com a posi��o inicial e um inteiro indicando o tamanho - 1 do vetor, retornando 0 se for um pal�ndromo e -1 se n�o o for
    printf("Exerc�cio (vii): %.2f\n", calculoSerie(4)); // exerc�cio (vii). Fun��o: recebe um inteiro N e retorna um double com o resultado da sequ�ncia
    return 0;
}
