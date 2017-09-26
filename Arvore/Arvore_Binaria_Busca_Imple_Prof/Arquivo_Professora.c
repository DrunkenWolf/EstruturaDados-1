#include <stdio.h>
#include <stdlib.h>

typedef struct no_arvore{
  struct no_arvore *esq;
  struct no_arvore *dir;
  int           info;
}NO, *pno;



void inserir(pno *t, int dado){
  // se t aponta para null, a inser��o � na raiz...
  pno novo=NULL;
  if (*t == NULL) {
    novo = (pno) malloc(sizeof(NO));
    if (novo == NULL){ printf("Meleca"); return;}
    novo->esq = NULL;
    novo->dir = NULL;
    novo->info = dado;
    *t=novo;
  }
  // Se o dado a ser inserido for menor que o n� atual, recursividade � esquerda
  else if (dado < (*t)->info) {
     inserir(&((*t)->esq), dado);
  }
  else{
    // Se o dado a ser inserido for menor que o n� atual, recursividade � direita
    if (dado > (*t)->info) {
       inserir(&((*t)->dir), dado);
    }
  }
}

void imprime_pre_ordem(pno *t){
    if((*t)==NULL) return;
    printf("\t%d", (*t)->info);
    imprime_pre_ordem(&(*t)->esq);
    imprime_pre_ordem(&(*t)->dir);
}


void imprime_em_ordem(pno *t){
    if((*t)==NULL) return;
    imprime_em_ordem(&(*t)->esq);
    printf("\t%d", (*t)->info);
    imprime_em_ordem(&(*t)->dir);
}


void imprime_pos_ordem(pno *t){
    if((*t)==NULL) return;
    imprime_pos_ordem(&(*t)->esq);
    imprime_pos_ordem(&(*t)->dir);
    printf("\t%d", (*t)->info);
}



void inicializa(pno *t){
   *t=NULL;
}


pno *minimo(pno *T){// procura o n� com valor m�nimo
    if(*T==NULL) return NULL;
    if((*T)->esq ==NULL ) return *T;
    return minimo(&(*T)->esq);
}

void remover(pno *raiz, int valor){
    pno aux;
    pno pai_aux=NULL;
    if(*raiz==NULL) return;
    // se o valor que ser� removido for menor que o n� atual,
    if(valor < (*raiz)->info){
      remover(&((*raiz)->esq), valor);
    }else if(valor > (*raiz)->info){ // se o valor que ser� removido for maior que o n� atual,
      remover(&((*raiz)->dir), valor);
    }else{ // encontrou
      // quando o n� a ser removido for encontrado,
      if( ((*raiz)->esq)!=NULL && ((*raiz)->dir)!=NULL ){
        // verificamos se os n�s filhos da esquerda e direita n�o s�o null.
        // se n�o forem null, buscamos o menor n� a partir do n� da direita.
        aux = minimo(&(*raiz)->dir);
        (*raiz)->info = (aux->info);
        remover(&(*raiz)->dir, aux->info);
      }else{
         // caso os n� da direita e/ou da esqueda, ou somente o da direita for null,
         // precisamos apenas remover
         aux = *raiz;
         // o n� atual e fazer ajustar os ponteiros
         if(((*raiz)->esq)==NULL){
            // se o n� da esquerda for vazio
            // o n� pai do atual, apontar� para o filho da direita do n� atual.
            *raiz = (*raiz)->dir;
          }
          else {
            // se o n� da esquerda n�o for vazio.
            // o n� pai do atual, apontar� para o filho da esquerda do n� atual.
            *raiz = (*raiz)->esq;
          }
          free(aux);
       }
    }
}


int main()
{
    pno Raiz;

    inicializa(&Raiz);
    inserir(&Raiz, 30);
    inserir(&Raiz, 10);
    inserir(&Raiz, 15);
    inserir(&Raiz,  5);
    inserir(&Raiz, 40);
    inserir(&Raiz, 13);
    inserir(&Raiz, 12);
    inserir(&Raiz, 210);
    inserir(&Raiz, 20);
    inserir(&Raiz, 25);
    inserir(&Raiz, 16);




    //remover(&Raiz, 30);
    printf("\n\n------em------\n\n");
    imprime_em_ordem(&Raiz);

    printf("\n\n-----pre-------\n\n");
    imprime_pre_ordem(&Raiz);

    printf("\n\n------pos------\n\n");
    imprime_pos_ordem(&Raiz);



    return 0;
}