#ifndef DINAMICA_DUPLA_H_INCLUDED
#define DINAMICA_DUPLA_H_INCLUDED

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux *prox, *ant;
} ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct {
    PONT inicio, fim;
} LISTA;

void exibirLista(LISTA *l);
PONT buscaSequencial(LISTA *l, TIPOCHAVE ch);
int inserirElemListaOrd(LISTA *l, REGISTRO reg);

#endif // DINAMICA_DUPLA_H_INCLUDED
