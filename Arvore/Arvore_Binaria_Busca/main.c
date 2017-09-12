#include"Arvore.h"

int main()
{
    tree raiz;
    define(&raiz);
    cria_raiz(&raiz, 'b');
    busca_insere('j', &raiz);
    busca_insere('a', &raiz);
    busca_insere('m', &raiz);
    busca_insere('k', &raiz);
    exibirArvore(raiz);

    return 0;
}
