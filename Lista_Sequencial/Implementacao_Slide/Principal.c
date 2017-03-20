#include "Implementacao_Lista.c"

int main(){
    LISTA x;
    REGISTRO r;
    int pos;
    inicializaLista(&x);
    r.chave = 23;
    pos = 0;
    if (inserirElemLista(&x, r, pos) == - 1){
        printf("oi\n");
        return -1;
    }
    r.chave = 12;
    pos = 1;
    if (inserirElemLista(&x, r, pos) == - 1){
        return -1;
    }
    r.chave = 14;
    pos = 2;
    if (inserirElemLista(&x, r, pos) == - 1){
        return -1;
    }
    r.chave = 30;
    pos = 3;
    if (inserirElemLista(&x, r, pos) == - 1){
        return -1;
    }
    r.chave = 18;
    pos = 4;
    if (inserirElemLista(&x, r, pos) == - 1){
        return -1;
    }
    exibirLista(&x);
    if (pos = buscaSequencial(&x, 12) >= 0){
        printf("O elemento está na posição %d\n", pos);
    } else {
        printf("O elemento não está na Lista!");
    }
    if (pos = buscaSequencial(&x, 2) >= 0){
        printf("O elemento está na posição %d\n", pos);
    } else {
        printf("O elemento não está na Lista!\n");
    }
    if (excluirElemLista(12, &x) < 0){
        return -1;
    }
    return 0;
}