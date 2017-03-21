#include <stdio.h>
#include <stdlib.h>

void exercicio1(){ //------------- Exercício 1 - Solução -------------------------------
	int *p, *q;  //declaração de dois ponteiros ("p" e "q") de números inteiros (int)
    p = (int*) malloc (sizeof (int)); //o ponteiro "p" apontará/armazenará o endereço onde 4 bytes (tamanho de um número inteiro "int") de memória serão alocados  através do "malloc"
   *p = 123; //o valor inteiro "123" será atribuído ao local indicado pelo ponteiro "p", isto é, o número 123 será armazenado no espaço de memória cujo seu endereço consta gravado em "p" 
    q = (int*) malloc (sizeof (int)); //o ponteiro "q" apontará/armazenará o endereço onde 4 bytes (tamanho de um número inteiro "int") de memória serão alocados através do "malloc"
   *q = *p; //o valor inteiro armazenado no espaço de memória cujo seu endereço consta gravado em "q" (neste momento iquivalente a 123) será atribuído ao espaço de memória cujo seu endereço consta gravado em "p"
    q = p; //o valor de referência, ou seja, o endereço armazenado no ponteiro, de "p" será atribuído a "q", logo os dois ponteiros ("p" e "q") armazenarão o mesmo endereço de memória (o endereço gravado em "p")
    free (p); //operação para liberação do espaço de memória (4 bytes) cujo seu endereço consta gravado em "p"
    free (q); //operação para liberação do espaço de memória (4 bytes) cujo seu endereço consta gravado em "q", porém "p" e "q" armazenam o mesmo endereço de memória. Portanto, está ação é reduntante, visto que já aplicou-se "free(p)"
    q = NULL; //atribuí-se valor nulo ("NULL") ao ponteiro "q", isto é, "q" armazenará um endereço nulo e não mais apontará para o endereço contido em "p"
	//É válido ressaltar que ao final dessa execução o espaço de memória alocado inicialmente em "q = (int*) malloc (sizeof (int));" não é afetado pelo "free()", logo essa memória não é desalocada devidamente causando acúmulo e "lixo"
}

int main(){
	exercicio1();
	return 0;	
}

