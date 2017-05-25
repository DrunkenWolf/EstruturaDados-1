//IMPLEMENTAÇÃO DO TRABALHO SUPER BÔNUS  –  E.D.
//Nome : Rafael dos Santos Braz       RA: 120121

#include "Dinamica_Dupla.h"
#include <stdio.h>
#include <stdlib.h>

LISTA juntarListas(LISTA *l1, LISTA *l2, LISTA *l3){
    //Declaracoes
    LISTA l4;
    inicializarLista(&l4);
    PONT atualL1 = l1->inicio;
    PONT atualL2 = l2->fim;
    PONT atualL3 = l3->fim;
    while (atualL1 != NULL || atualL2 != NULL || atualL3 != NULL){ //percorre as 3 listas ao mesmo tempo, apenas uma passada separa/organiza ate 3 registros para ordenacao
        PONT ordem[3]; //indica os ponteiros que serao ordenados
        int n = 0; //quantidade de ponteiros
        // comeca a verificar as 3 listas ao mesmo tempo, mas em camadas de atualL1 ate atualL3. Guarda os ponteiros a serem ordenados e apaga os repetidos
        if (atualL1 != NULL){
            ordem[0] = atualL1;
            n++;
            atualL1 = atualL1->prox;
        }
        if (atualL2 != NULL){
            if (n == 0){
                ordem[0] = atualL2;
                n++;
                atualL2 = atualL2->ant;
            } else if (atualL2->reg.chave == ordem[0]->reg.chave){
                PONT apagar = atualL2;
                atualL2 = atualL2->ant;
                free(apagar);
            } else if (atualL2->reg.chave < ordem[0]->reg.chave){
                ordem[1] = ordem[0];
                ordem[0] = atualL2;
                n++;
                atualL2 = atualL2->ant;
            } else{
                ordem[1] = atualL2;
                n++;
                atualL2 = atualL2->ant;
            }
        }
        if (atualL3 != NULL){
            if (n == 0){
                ordem[0] = atualL3;
                n++;
                atualL3 = atualL3->ant;
            } else if (n == 1){
                if (atualL3->reg.chave == ordem[0]->reg.chave){
                    PONT apagar = atualL3;
                    atualL3 = atualL3->ant;
                    free(apagar);
                } else if (atualL3->reg.chave < ordem[0]->reg.chave){
                    ordem[1] = ordem[0];
                    ordem[0] = atualL3;
                    n++;
                    atualL3 = atualL3->ant;
                } else{
                    ordem[1] = atualL3;
                    n++;
                    atualL3 = atualL3->ant;
                }
            } else{
                if ((atualL3->reg.chave == ordem[0]->reg.chave) || (atualL3->reg.chave == ordem[1]->reg.chave)){
                    PONT apagar = atualL3;
                    atualL3 = atualL3->ant;
                    free(apagar);
                } else if (atualL3->reg.chave < ordem[0]->reg.chave){
                    ordem[2] = ordem[1];
                    ordem[1] = ordem[0];
                    ordem[0] = atualL3;
                    n++;
                    atualL3 = atualL3->ant;
                } else if (atualL3->reg.chave > ordem[1]->reg.chave){
                    ordem[2] = atualL3;
                    n++;
                    atualL3 = atualL3->ant;
                } else{
                    ordem[2] = ordem[1];
                    ordem[1] = atualL3;
                    n++;
                    atualL3 = atualL3->ant;
                }
            }
        }
        //fim da verificacao em camadas
        //comeca a modificar a lista 4
        int c;
        PONT marco = l4.inicio; //aponta para a posicao onde comeca/continua a leitura da lista 4, para que seja possível inserir ate 3 registros com uma unica passada na lista
        for (c = 0; c < n; c++){
            int inserido = 0; //variavel de controle como "bool"
            while (inserido == 0){
                if (l4.inicio == NULL){
                    l4.inicio = ordem[c];
                    l4.fim = ordem[c];
                    ordem[c]->prox = NULL;
                    ordem[c]->ant = NULL;
                    inserido = 1;
                    marco = ordem[c];
                } else{
                    while (marco != NULL && ordem[c]->reg.chave > marco->reg.chave){ //faz a verificacao apenas do marco para frente, assim comparando apenas com os elementos posteriores da lista
                        marco = marco->prox;
                    }
                    if (marco == NULL){
                        l4.fim->prox = ordem[c];
                        ordem[c]->prox = NULL;
                        ordem[c]->ant = l4.fim;
                        l4.fim = ordem[c];
                        inserido = 1;
                    } else{
                        marco->ant->prox = ordem[c];
                        ordem[c]->ant = marco->ant;
                        marco->ant = ordem[c];
                        ordem[c]->prox = marco;
                        marco = ordem[c];
                        inserido = 1;
                    }
                }
            }
        }
    }
    //reinicializa as listas recebidas por parametro
    l1->inicio = NULL;
    l1->fim = NULL;
    l2->inicio = NULL;
    l2->fim = NULL;
    l3->inicio = NULL;
    l3->fim = NULL;
    return l4;
}

void inicializarLista(LISTA *l){
    l->inicio = NULL;
    l->fim = NULL;
}

int tamanhoLista(LISTA *l){
    PONT atual = l->inicio;
    int tam = 0;
    while (atual != NULL){
        tam++;
        atual = atual->prox;
    }
    return tam;
}

void exibirLista(LISTA *l){
    PONT end = l->inicio;
    printf("Lista: \"");
    while (end != NULL){
        printf("%d ", end->reg.chave);
        end = end->prox;
    }
    printf("\"\n");
}

PONT buscaSequencial(LISTA *l, TIPOCHAVE ch){
    PONT pos = l->inicio;
    while (pos != NULL && pos->reg.chave < ch){
        pos = pos->prox;
    }
    if (pos != NULL && pos->reg.chave == ch){
        return pos;
    }
    return NULL;
}

PONT buscaSequencialDecre(LISTA *l, TIPOCHAVE ch){
    PONT pos = l->inicio;
    while (pos != NULL && pos->reg.chave > ch){
        pos = pos->prox;
    }
    if (pos != NULL && pos->reg.chave == ch){
        return pos;
    }
    return NULL;
}

int inserirElemListaOrd(LISTA *l, REGISTRO reg){
    TIPOCHAVE ch = reg.chave;
    PONT i;
    if (buscaSequencial(l, ch) == NULL){
        PONT pos = l->inicio;
        PONT a = NULL;
        i = (PONT)malloc(sizeof(ELEMENTO));
        i->reg = reg;
        while (pos != NULL && pos->reg.chave < ch){
            a = pos;
            pos = pos->prox;
        }
        if (tamanhoLista(l) == 0){
            l->inicio = l->fim = i;
            i->ant = i->prox = NULL;
        } else if (a != NULL){
            i->ant = a;
            i->prox = a->prox;
            if (a->prox == NULL){
                a->prox = i;
                l->fim = i;
            } else{
                a->prox->ant = i;
                a->prox = i;
            }
        } else{
            i->ant = NULL;
            i->prox = l->inicio;
            l->inicio->ant = i;
            l->inicio = i;
        }
        return 0;
    }
    return -1;
}

int inserirElemListaOrdDecre(LISTA *l, REGISTRO reg){
    TIPOCHAVE ch = reg.chave;
    PONT i;
    if (buscaSequencialDecre(l, ch) == NULL){
        PONT pos = l->inicio;
        PONT a = NULL;
        i = (PONT)malloc(sizeof(ELEMENTO));
        i->reg = reg;
        while (pos != NULL && pos->reg.chave > ch){
            a = pos;
            pos = pos->prox;
        }
        if (tamanhoLista(l) == 0){
            l->inicio = l->fim = i;
            i->ant = i->prox = NULL;
        } else if (a != NULL){
            i->ant = a;
            i->prox = a->prox;
            if (a->prox == NULL){
                a->prox = i;
                l->fim = i;
            } else{
                a->prox->ant = i;
                a->prox = i;
            }
        } else{
            i->ant = NULL;
            i->prox = l->inicio;
            l->inicio->ant = i;
            l->inicio = i;
        }
        return 0;
    }
    return -1;
}

int excluirElemLista(LISTA *l, TIPOCHAVE ch){
    PONT i = buscaSequencial(l, ch);
    if (i == NULL){
        return -1;
    }
    if (i->ant == NULL){
        l->inicio = i->prox;
        l->inicio->ant = NULL;
    } else if (i->prox == NULL){
        i->ant->prox = NULL;
        l->fim = i->ant;
    } else{
        i->prox->ant = i->ant;
        i->ant->prox = i->prox;
    }
    free(i);
    return 0;
}

void reinicializarLista(LISTA *l){
    PONT end = l->inicio;
    while (end != NULL){
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    l->inicio = NULL;
    l->fim = NULL;
}
