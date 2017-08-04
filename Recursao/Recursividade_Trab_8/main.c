// Nome: Rafael dos Santos Braz

//RA: 120121

//Trabalho 8: exerc�cios dos slides sobre Recursividade

#include "Recursoes.h"

int main()
{
    printf("Exercicio 1: %d\n", primeirosNCubos(4)); // chamada do exerc�cio 1. Fun��o: retorna um inteiro com a soma dos n cubos e recebe um inteiro n
    printf("Exercicio 2: %d\n", primeirosNNumeros(4)); // chamada do exerc�cio 2. Fun��o: retorna um inteiro com a soma dos n n�meros e recebe um
        //inteiro n
    printf("Ex 3---\n");
    imprimirNNumerosCrescente(4); // chamada do exerc�cio 3. Fun��o: n�o retorna valores, mas recebe um inteiro n
    printf("Ex 4---\n");
    imprimirNNumerosDecrescente(4); // chamada do exerc�cio 4. Fun��o: n�o retorna valores, mas recebe um inteiro n
    int v[] = {1, 2, 3, 4};
    printf("Exercicio 5: %d\n", somaElemVetor(&v, sizeof(v)/sizeof(int) - 1)); // chamada do exerc�cio 5. Fun��o: retorna um inteiro com a soma dos
        //elementos do vetor, recebe o endere�o do vetor e a posi��o do seu �ltimo elemento
    printf("Exercicio 6: %.2f\n", MediaElemVetor(&v, sizeof(v)/sizeof(int), sizeof(v)/sizeof(int) - 1)); // chamada do exerc�cio 6. Fun��o: retorna
        //um double com a m�dia dos elementos do vetor, recebe: o endere�o do vetor; o tamanho do vetor; e a posi��o do seu �ltimo elemento
    return 0;
}
