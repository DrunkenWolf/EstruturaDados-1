#ifndef PILHAESTATICA_H_INCLUDED
#define PILHAESTATICA_H_INCLUDED

#define MAX 8

typedef int TIPOCHAVE;

typedef struct{
     TIPOCHAVE chave;
}REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int topoA;
    int topoB;
}PILHA;

//protótipos das funções

void inicializarPilha(PILHA *);
//int tamanho(PILHA *);
//void exibirPilha(PILHA *);
//int inserirElemPilha(PILHA *, REGISTRO);
//int excluirElemPilha(PILHA *);
//void reinicializacao(PILHA *);

#endif // PILHAESTATICA_H_INCLUDED
