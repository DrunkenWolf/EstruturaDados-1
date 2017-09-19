#include"Arvore.h"

int main()
{
    pno Raiz = NULL;
    inserir(&Raiz, 30);
    inserir(&Raiz, 3);
    inserir(&Raiz, 40);
    imprime_pos_ordem(&Raiz);
    return 0;
}
