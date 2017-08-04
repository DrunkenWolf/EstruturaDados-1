// Nome: Rafael dos Santos Braz

//RA: 120121

//Trabalho 8: exercícios dos slides sobre Recursividade

#include "Recursoes.h"

int main()
{
    printf("Exercicio 1: %d\n", primeirosNCubos(4)); // chamada do exercício 1. Função: retorna um inteiro com a soma dos n cubos e recebe um inteiro n
    printf("Exercicio 2: %d\n", primeirosNNumeros(4)); // chamada do exercício 2. Função: retorna um inteiro com a soma dos n números e recebe um
        //inteiro n
    printf("Ex 3---\n");
    imprimirNNumerosCrescente(4); // chamada do exercício 3. Função: não retorna valores, mas recebe um inteiro n
    printf("Ex 4---\n");
    imprimirNNumerosDecrescente(4); // chamada do exercício 4. Função: não retorna valores, mas recebe um inteiro n
    int v[] = {1, 2, 3, 4};
    printf("Exercicio 5: %d\n", somaElemVetor(&v, sizeof(v)/sizeof(int) - 1)); // chamada do exercício 5. Função: retorna um inteiro com a soma dos
        //elementos do vetor, recebe o endereço do vetor e a posição do seu último elemento
    printf("Exercicio 6: %.2f\n", MediaElemVetor(&v, sizeof(v)/sizeof(int), sizeof(v)/sizeof(int) - 1)); // chamada do exercício 6. Função: retorna
        //um double com a média dos elementos do vetor, recebe: o endereço do vetor; o tamanho do vetor; e a posição do seu último elemento
    return 0;
}
