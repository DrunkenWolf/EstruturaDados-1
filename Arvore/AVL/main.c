#include "AVL.h"

int main()
{
pno Raiz;

    inicializa(&Raiz);
    inserir(&Raiz, 30);
    AVL(&Raiz);

    inserir(&Raiz, 10);
    AVL(&Raiz);

    inserir(&Raiz, 15);
    AVL(&Raiz);

    inserir(&Raiz,  5);
    AVL(&Raiz);

    inserir(&Raiz, 40);
    AVL(&Raiz);

    inserir(&Raiz, 13);
    AVL(&Raiz);

    inserir(&Raiz, 12);
    AVL(&Raiz);

    inserir(&Raiz, 210);
    AVL(&Raiz);

    inserir(&Raiz, 20);
    AVL(&Raiz);

    inserir(&Raiz, 25);
    AVL(&Raiz);

    inserir(&Raiz, 16);
    AVL(&Raiz);


    //remover(&Raiz, 30);
    printf("\n\n------em------\n\n");
    imprime_em_ordem(&Raiz);

    printf("\n\n-----pre-------\n\n");
    imprime_pre_ordem(&Raiz);

    printf("\n\n------pos------\n\n");
    imprime_pos_ordem(&Raiz);
    return 0;
}
