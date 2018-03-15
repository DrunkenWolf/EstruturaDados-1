// Nome: Rafael dos Santos Braz

//RA: 120121

//Trabalho 12: atividade do dia 23/08/2017, aplicação do método de ordenação ShellSort com palavras

#include "Funcoes.h"

int main()
{

    /*int vet[] = {1, 3, 2, 0, 16, 11};
    ShellSortInteiros(&vet, 6); // teste do procedimento criado para ordenação Shell de inteiros
    int i;
    for (i = 0; i < 6; i++)
    {
     printf(" %d\n", vet[i]);
    } */
    // TAM é um Macro definido em Funcoes.h
    PALAVRA palavras[TAM]; // Vetor de palavras que serão ordenadas
    palavras[0].elemento = "casa";
    palavras[1].elemento = "lua";
    palavras[2].elemento = "cama";
    palavras[3].elemento = "dama";
    palavras[4].elemento = "rua";
    palavras[5].elemento = "chuva";
    ShellSortPalavras(palavras, TAM); // chamada da função de ordenação Shell. Não possui retorno e necessita de um vetor de palavras e seu tamanho como parâmetros
    int i, j;
    for (i = 0; i < TAM; i++)
    {
        for (j = 0; palavras[i].elemento[j] != '\0'; j++)
        {
            printf("%c", palavras[i].elemento[j]);
        }
        printf("\n");
    }
    return 0;
}
