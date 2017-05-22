//IMPLEMENTAÇÃO DO TRABALHO SUPER BÔNUS  –  E.D.
//Nome : Rafael dos Santos Braz       RA: 120121

#ifndef DINAMICA_DUPLA_H_INCLUDED
#define DINAMICA_DUPLA_H_INCLUDED

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux *prox;
    struct aux *ant;
} ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct{
    PONT inicio;
    PONT fim;
} LISTA;

LISTA juntarListas(LISTA *, LISTA *, LISTA *);
void inicializarLista(LISTA *);
int tamanhoLista(LISTA *);
void exibirLista(LISTA *);
PONT buscaSequencial(LISTA *, TIPOCHAVE);
int inserirElemListaOrd(LISTA *, REGISTRO);
int inserirElemListaOrdDecre(LISTA *, REGISTRO);
int excluirElemLista(LISTA *, TIPOCHAVE);
void reinicializarLista(LISTA *);

#endif // DINAMICA_DUPLA_H_INCLUDED
