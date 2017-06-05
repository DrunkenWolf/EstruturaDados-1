#ifndef MATRIZESPARSA_H_INCLUDED
#define MATRIZESPARSA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct aux
{
    int linha;
    int coluna;
    int valor;
    struct aux *proxLinha;
    struct aux *proxColuna;
} ELEMENTO, *PONT;

typedef struct
{
    int numLinhas;
    int numColunas;
    PONT *ALinha;
    PONT *AColuna;
} MATRIZ;

void inicializarMatriz(MATRIZ *, int, int);
void reinicializarMatriz(MATRIZ *);
void exibirMatriz(MATRIZ *);

#endif // MATRIZESPARSA_H_INCLUDED
