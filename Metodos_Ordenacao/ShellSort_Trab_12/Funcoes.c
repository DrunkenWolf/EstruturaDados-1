#include "Funcoes.h"

// Obs1: para a codificação do algoritmo utilizei como base o já implementado InsertionSort e o modifiquei para se adequar ao intervalo h,
// utilixei o livro do Adam Drozdek, mas dessa forma considerei mais simples de entender (sem um segundo vetor real e uma equação h = h * 3 + 1);

//Obs2: a função strcmp utilizada no decorrer do código foi uma sugestão do Paulo, para não ser necessária uma comparação manual de caractere a caractere

void ShellSortInteiros(int *vetor, int tam) // Ordenação Shell apenas para números inteiros
{
    int h;
    for (h = tam / 2; h > 0; h--) // define o maior intervalo de h, sendo igual à metade do vetor
    {
        int pos;
        for (pos = 0; pos < tam; pos++) // percorre uma sequência de posições a partir da primeira, introduzindo h
        {
            int posComp = pos + h; // posição a ser comparada com a atual (soma-se o h)
            while (posComp < tam) // verifica se a posição solicitada não ultrapassa os limites do vetor
            {
                if (vetor[pos] > vetor[posComp]) // se a posição comparada for menos que a atual, serão trocadas de posição entre si
                {
                    int aux = vetor[pos];
                    vetor[pos] = vetor[posComp];
                    vetor[posComp] = aux;
                    pos--; // como ocorreu uma alteração de posições, deve-se verificar as posições anteriores desse mesmo h novamente para não quebrar a sequência
                    break;
                }
                posComp += h;
            }
        }
    }
}

void ShellSortPalavras(PALAVRA *vetor, int tam) // Ordenação Shell para "strings"
{
    int h;
    for (h = tam / 2; h > 0; h--) // define o maior intervalo de h, sendo igual à metade do vetor
    {
        int pos;
        for (pos = 0; pos < tam; pos++) // percorre uma sequência de posições a partir da primeira, introduzindo h
        {
            int posComp = pos + h; // posição a ser comparada com a atual (soma-se o h)
            while (posComp < tam) // verifica se a posição solicitada não ultrapassa os limites do vetor
            {
                if (strcmp(vetor[pos].elemento, vetor[posComp].elemento) > 0) // utiliza-se a função strcmp para verificar a precedência entre as palavras (ordem da tabela ASCII)
                {
                    PALAVRA aux = vetor[pos];
                    vetor[pos] = vetor[posComp];
                    vetor[posComp] = aux;
                    pos--; // como ocorreu uma alteração de posições, deve-se verificar as posições anteriores desse mesmo h novamente para não quebrar a sequência
                    break;
                }
                posComp += h;
            }
        }
    }
}
