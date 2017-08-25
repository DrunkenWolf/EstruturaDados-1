#include "Funcoes.h"

// Obs1: para a codifica��o do algoritmo utilizei como base o j� implementado InsertionSort e o modifiquei para se adequar ao intervalo h,
// utilixei o livro do Adam Drozdek, mas dessa forma considerei mais simples de entender (sem um segundo vetor real e uma equa��o h = h * 3 + 1);

//Obs2: a fun��o strcmp utilizada no decorrer do c�digo foi uma sugest�o do Paulo, para n�o ser necess�ria uma compara��o manual de caractere a caractere

void ShellSortInteiros(int *vetor, int tam) // Ordena��o Shell apenas para n�meros inteiros
{
    int h;
    for (h = tam / 2; h > 0; h--) // define o maior intervalo de h, sendo igual � metade do vetor
    {
        int pos;
        for (pos = 0; pos < tam; pos++) // percorre uma sequ�ncia de posi��es a partir da primeira, introduzindo h
        {
            int posComp = pos + h; // posi��o a ser comparada com a atual (soma-se o h)
            while (posComp < tam) // verifica se a posi��o solicitada n�o ultrapassa os limites do vetor
            {
                if (vetor[pos] > vetor[posComp]) // se a posi��o comparada for menos que a atual, ser�o trocadas de posi��o entre si
                {
                    int aux = vetor[pos];
                    vetor[pos] = vetor[posComp];
                    vetor[posComp] = aux;
                    pos--; // como ocorreu uma altera��o de posi��es, deve-se verificar as posi��es anteriores desse mesmo h novamente para n�o quebrar a sequ�ncia
                    break;
                }
                posComp += h;
            }
        }
    }
}

void ShellSortPalavras(PALAVRA *vetor, int tam) // Ordena��o Shell para "strings"
{
    int h;
    for (h = tam / 2; h > 0; h--) // define o maior intervalo de h, sendo igual � metade do vetor
    {
        int pos;
        for (pos = 0; pos < tam; pos++) // percorre uma sequ�ncia de posi��es a partir da primeira, introduzindo h
        {
            int posComp = pos + h; // posi��o a ser comparada com a atual (soma-se o h)
            while (posComp < tam) // verifica se a posi��o solicitada n�o ultrapassa os limites do vetor
            {
                if (strcmp(vetor[pos].elemento, vetor[posComp].elemento) > 0) // utiliza-se a fun��o strcmp para verificar a preced�ncia entre as palavras (ordem da tabela ASCII)
                {
                    PALAVRA aux = vetor[pos];
                    vetor[pos] = vetor[posComp];
                    vetor[posComp] = aux;
                    pos--; // como ocorreu uma altera��o de posi��es, deve-se verificar as posi��es anteriores desse mesmo h novamente para n�o quebrar a sequ�ncia
                    break;
                }
                posComp += h;
            }
        }
    }
}
