#include "AVL.h"

void inserir(pno *t, int dado)
{
    // se t aponta para null, a inser��o � na raiz...
    pno novo=NULL;
    if (*t == NULL)
    {
        novo = (pno) malloc(sizeof(NO));
        if (novo == NULL)
        {
            printf("Meleca");
            return;
        }
        novo->esq = NULL;
        novo->dir = NULL;
        novo->info = dado;
        *t=novo;
    }
    // Se o dado a ser inserido for menor que o n� atual, recursividade � esquerda
    else if (dado < (*t)->info)
    {
        inserir(&((*t)->esq), dado);
    }
    else
    {
        // Se o dado a ser inserido for menor que o n� atual, recursividade � direita
        if (dado > (*t)->info)
        {
            inserir(&((*t)->dir), dado);
        }
    }
}

void imprime_pre_ordem(pno *t)
{
    if((*t)==NULL) return;
    printf("\t%d", (*t)->info);
    imprime_pre_ordem(&(*t)->esq);
    imprime_pre_ordem(&(*t)->dir);
}

void imprime_pre_ordem_altura(pno *t)
{
    if((*t)==NULL) return;
    printf("\t%d(h=%d)", (*t)->info, (*t)->altura);
    imprime_pre_ordem_altura(&(*t)->esq);
    imprime_pre_ordem_altura(&(*t)->dir);
}

void imprime_em_ordem(pno *t)
{
    if((*t)==NULL) return;
    imprime_em_ordem(&(*t)->esq);
    printf("\t%d", (*t)->info);
    imprime_em_ordem(&(*t)->dir);
}

void imprime_pos_ordem(pno *t)
{
    if((*t)==NULL) return;
    imprime_pos_ordem(&(*t)->esq);
    imprime_pos_ordem(&(*t)->dir);
    printf("\t%d", (*t)->info);
}

void inicializa(pno *t)
{
    *t=NULL;
}

pno *minimo(pno *T) // procura o n� com valor m�nimo
{
    if(*T==NULL) return NULL;
    if((*T)->esq ==NULL ) return *T;
    return minimo(&(*T)->esq);
}

void remover(pno *raiz, int valor)
{
    pno aux;
    pno pai_aux=NULL;
    if(*raiz==NULL) return;
    // se o valor que ser� removido for menor que o n� atual,
    if(valor < (*raiz)->info)
    {
        remover(&((*raiz)->esq), valor);
    }
    else if(valor > (*raiz)->info)   // se o valor que ser� removido for maior que o n� atual,
    {
        remover(&((*raiz)->dir), valor);
    }
    else   // encontrou
    {
        // quando o n� a ser removido for encontrado,
        if( ((*raiz)->esq)!=NULL && ((*raiz)->dir)!=NULL )
        {
            // verificamos se os n�s filhos da esquerda e direita n�o s�o null.
            // se n�o forem null, buscamos o menor n� a partir do n� da direita.
            aux = minimo(&(*raiz)->dir);
            (*raiz)->info = (aux->info);
            remover(&(*raiz)->dir, aux->info);
        }
        else
        {
            // caso os n� da direita e/ou da esqueda, ou somente o da direita for null,
            // precisamos apenas remover
            aux = *raiz;
            // o n� atual e fazer ajustar os ponteiros
            if(((*raiz)->esq)==NULL)
            {
                // se o n� da esquerda for vazio
                // o n� pai do atual, apontar� para o filho da direita do n� atual.
                *raiz = (*raiz)->dir;
            }
            else
            {
                // se o n� da esquerda n�o for vazio.
                // o n� pai do atual, apontar� para o filho da esquerda do n� atual.
                *raiz = (*raiz)->esq;
            }
            free(aux);
        }
    }
}

int calcula_altura(pno *t)
{
    if((*t) == NULL)
    {
        return 0;
    }
    int alt_esq = calcula_altura(&(*t)->esq);
    int alt_dir = calcula_altura(&(*t)->dir);
    (*t)->altura = alt_esq > alt_dir? alt_esq + 1: alt_dir + 1;
}

void RSD(pno *t)
{
    pno aux = (*t)->esq->dir;
    pno aux_t = (*t)->esq;
    (*t)->esq->dir = (*t);
    (*t)->esq = aux;
    (*t) = aux_t;
}

void RSE(pno *t)
{
    pno aux = (*t)->dir->esq;
    pno aux_t = (*t)->dir;
    (*t)->dir->esq = (*t);
    (*t)->dir = aux;
    (*t) = aux_t;
}

void balanceamento_AVL(pno *t)
{
    if ((*t)->fat_bal > 1) //subarvore esquerda
    {
        if ((*t)->esq->fat_bal > 0)
        {
            //rotacao simples direita
            RSD(&(*t));
        }
        else
        {
            //rotacao dupla direita
            RSE(&(*t)->esq);
            RSD(&(*t));
        }
    }
    else //subarvore direita
    {
        if ((*t)->dir->fat_bal < 0)
        {
            //rotacao simples esquerda
            RSE(&(*t));
        }
        else
        {
            //rotacao dupla esquerda
            RSD(&(*t)->dir);
            RSE(&(*t));
        }
    }
}

void atualiza_fator_balanceamento(pno *t)
{
    if ((*t) == NULL)
    {
        return;
    }
    if ((*t)->esq != NULL)
    {
        atualiza_fator_balanceamento(&(*t)->esq);
    }
    if ((*t)->dir != NULL)
    {
        atualiza_fator_balanceamento(&(*t)->dir);
    }
    if ((*t)->esq == NULL)
    {
        (*t)->fat_bal = 0;
    }
    else
    {
        (*t)->fat_bal = (*t)->esq->fat_bal;
    }
    if ((*t)->dir != NULL)
    {
        (*t)->fat_bal = (*t)->fat_bal - (*t)->dir->fat_bal;
    }
    if ((*t)->fat_bal > 1 || (*t)->fat_bal < -1)
    {
        balanceamento_AVL(&(*t));
        calcula_altura(&(*t));
    }
}

void AVL(pno *t)
{
    (*t)->altura = calcula_altura(&(*t));
    atualiza_fator_balanceamento(&(*t));
    imprime_pre_ordem_altura(&(*t));
    printf("\n");
    getchar();
}
