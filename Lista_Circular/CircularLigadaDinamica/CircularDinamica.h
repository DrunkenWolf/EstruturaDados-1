#ifndef CIRCULARDINAMICA_H_INCLUDED
#define CIRCULARDINAMICA_H_INCLUDED

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct aux
{
    REGISTRO reg;
    struct aux *prox, *ant;
} ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct
{
    PONT cabeca;
} LISTA;

void inicializaLista(LISTA *l);
int tamanho(LISTA *l);
void exibirLista(LISTA *l);
PONT buscaSentinela(LISTA *l, TIPOCHAVE ch);
PONT buscaSentinelaOrd(LISTA *l, TIPOCHAVE ch);
PONT buscaSeqExec(LISTA *l, TIPOCHAVE ch, PONT *ant);
int inserirElemLista(LISTA *l, REGISTRO reg);
int excluirElemLista(LISTA *l, TIPOCHAVE ch);
void reinicializarLista(LISTA *l);

#endif // CIRCULARDINAMICA_H_INCLUDED
