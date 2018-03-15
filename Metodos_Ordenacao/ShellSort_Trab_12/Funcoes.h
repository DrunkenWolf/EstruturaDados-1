#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 6

typedef struct // estrutura PALAVRA criada para representar cada "string" do vetor (apenas organiza��o)
{
    char *elemento; // cada vetor de char de tamanho din�mico do vetor
} PALAVRA;

void ShellSortInteiros(int*, int); // ordena��o de inteiros
void ShellSortPalavras(PALAVRA*, int); // ordena��o de "strings"

#endif // FUNCOES_H_INCLUDED
