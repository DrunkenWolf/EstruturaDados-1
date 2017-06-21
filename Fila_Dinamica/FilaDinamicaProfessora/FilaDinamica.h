#ifndef FILADINAMICA_H_INCLUDED
#define FILADINAMICA_H_INCLUDED

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux *prox;
}ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct{
    PONT inicio;
    PONT fim;
}FILA;

void inicializarFila(FILA *);
int contaElemFila(FILA *);
void exibirElemFila(FILA *);
void inserirElemFila(FILA *, REGISTRO);
void excluirElemFila (FILA *);
void reinicializar(FILA *);

#endif // FILADINAMICA_H_INCLUDED
