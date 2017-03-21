#include <stdio.h>
#include <stdlib.h>

void exercicio1(){ //------------- Exerc�cio 1 - Solu��o -------------------------------
	int *p, *q;  //declara��o de dois ponteiros ("p" e "q") de n�meros inteiros (int)
    p = (int*) malloc (sizeof (int)); //o ponteiro "p" apontar�/armazenar� o endere�o onde 4 bytes (tamanho de um n�mero inteiro "int") de mem�ria ser�o alocados  atrav�s do "malloc"
   *p = 123; //o valor inteiro "123" ser� atribu�do ao local indicado pelo ponteiro "p", isto �, o n�mero 123 ser� armazenado no espa�o de mem�ria cujo seu endere�o consta gravado em "p" 
    q = (int*) malloc (sizeof (int)); //o ponteiro "q" apontar�/armazenar� o endere�o onde 4 bytes (tamanho de um n�mero inteiro "int") de mem�ria ser�o alocados atrav�s do "malloc"
   *q = *p; //o valor inteiro armazenado no espa�o de mem�ria cujo seu endere�o consta gravado em "q" (neste momento iquivalente a 123) ser� atribu�do ao espa�o de mem�ria cujo seu endere�o consta gravado em "p"
    q = p; //o valor de refer�ncia, ou seja, o endere�o armazenado no ponteiro, de "p" ser� atribu�do a "q", logo os dois ponteiros ("p" e "q") armazenar�o o mesmo endere�o de mem�ria (o endere�o gravado em "p")
    free (p); //opera��o para libera��o do espa�o de mem�ria (4 bytes) cujo seu endere�o consta gravado em "p"
    free (q); //opera��o para libera��o do espa�o de mem�ria (4 bytes) cujo seu endere�o consta gravado em "q", por�m "p" e "q" armazenam o mesmo endere�o de mem�ria. Portanto, est� a��o � reduntante, visto que j� aplicou-se "free(p)"
    q = NULL; //atribu�-se valor nulo ("NULL") ao ponteiro "q", isto �, "q" armazenar� um endere�o nulo e n�o mais apontar� para o endere�o contido em "p"
	//� v�lido ressaltar que ao final dessa execu��o o espa�o de mem�ria alocado inicialmente em "q = (int*) malloc (sizeof (int));" n�o � afetado pelo "free()", logo essa mem�ria n�o � desalocada devidamente causando ac�mulo e "lixo"
}

int main(){
	exercicio1();
	return 0;	
}

