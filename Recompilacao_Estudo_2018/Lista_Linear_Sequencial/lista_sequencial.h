#ifndef LISTA_SEQUENCIAL_H_INCLUDED
#define LISTA_SEQUENCIAL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
} REGISTRO;

// lista sequencial
typedef struct
{
    REGISTRO A[MAX];
    int nroElem;
} LISTA;

void inicializar_lista(LISTA*);
int quant_elem(LISTA*);
void eixbir_elem(LISTA*);
int busca_elem(LISTA*, TIPOCHAVE);
int inserir_elem(LISTA*, REGISTRO);
int excluir_elem(LISTA*, TIPOCHAVE);
void reinicializar(LISTA*);

#endif // LISTA_SEQUENCIAL_H_INCLUDED