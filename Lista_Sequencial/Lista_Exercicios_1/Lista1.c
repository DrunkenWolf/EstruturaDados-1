#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef int TIPOCHAVE;

typedef struct{
     TIPOCHAVE chave;
}REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int nroElem;
}LISTA;

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

/*------------- Exerc�cio 2 - Solu��o -------------------------------
	Quando se utiliza o m�todo de busca sequencial comum, utiliza-se um la�o de repeti��o para percorrer toda a lista. Isto � v�lido para o m�todo de busca sentinela, por�m, 
	na busca comum � necess�rio verificar a cada loop se o contador encontra-se dentro lo escopo da lista, caso contr�rio, poder�amos encontrar um erro de leitura/acesso.
	J� no busca sentinela, o valor que desejamos encontrar � adicionado na �ltima posi��o da lista e, portanto, sabe-se que o valor ser� sempre encontrado elimitando, assim,
	a verifica��o de escopo da lista. Por tal raz�o, eliminamos processamento adicional e o algor�tmo se torna mais eficiente.
	O problema de o sentinela ocupar a �ltima posi��o da lista poderia ser corrigido adicionando uma posi��o a mais do que o MAX � lista. Desta forma, seria garantido que
	haver� espa�o para o sentinela.
	
*/

int inserirElemListaCrescente(LISTA *l, REGISTRO reg){ //------------Exerc�cio 3 parte 1
   int j = 0;
   if (l->nroElem == MAX){
       return -1;
   }
   if (l->nroElem == 0){
	   l->A[0] = reg;
	   l->nroElem++;
   } else{   
	   int insercao = 0;	
	   for (; j < l->nroElem; j++){
		   if (l->A[j].chave > reg.chave){
			   int c = l->nroElem;
			   for (; c > j; c--){
				   l->A[c] = l->A[c - 1];
			   }
			   l->A[j] = reg;
			   l->nroElem++;
			   insercao = 1;
			   break;
		   }
	   }
	   if (insercao == 0){
		   l->A[l->nroElem] = reg;
		   l->nroElem++;
	   }
   }
   return 0;
}

int inserirElemListaDecrescente(LISTA *l, REGISTRO reg){ //------------Exerc�cio 3 parte 2
   int j = 0;
   if (l->nroElem == MAX){
       return -1;
   }
   if (l->nroElem == 0){
	   l->A[0] = reg;
	   l->nroElem++;
   } else{   
	   int insercao = 0;	
	   for (; j < l->nroElem; j++){
		   if (l->A[j].chave < reg.chave){
			   int c = l->nroElem;
			   for (; c > j; c--){
				   l->A[c] = l->A[c - 1];
			   }
			   l->A[j] = reg;
			   l->nroElem++;
			   insercao = 1;
			   break;
		   }
	   }
	   if (insercao == 0){
		   l->A[l->nroElem] = reg;
		   l->nroElem++;
	   }
   }
   return 0;
}

int buscaBinaria(LISTA *l, TIPOCHAVE ch){//Exerc�cio 4-----------------------
    if (l->nroElem == 0){
		return -1;
	}
	if ((l->nroElem == 1) || ((l->nroElem >= 1) && (l->A[0].chave == l->A[l->nroElem - 1].chave))){
		if (ch == l->A[0].chave){
			return 0;
		}
		return -1;
	}
	if (ch == l->A[0].chave){
		return 0;
	}
	if (ch == l->A[l->nroElem - 1].chave){
		return l->nroElem;
	}
	if (l->A[0].chave < l->A[l->nroElem - 1].chave){
		int esq = 0, dir = l->nroElem - 1, meio = -1;
		if ((ch < l->A[esq].chave) || (ch > l->A[dir].chave)){
			return -1;
		}
		int p, situacao = 0;
		while(meio != esq){
			meio = (esq + dir) / 2;
			if (meio != esq){
				if (ch == l->A[meio].chave){
					p = meio + 1;
					situacao = 1;
					break;
				}
				if (ch > l->A[meio].chave){
					esq = meio;
					meio = -1;
				} else{
					dir = meio;
					meio = -1;
				}
			}
		}
		if (situacao == 0){
			return -1;
		}
		return p;
	} else{
		int esq = 0, dir = l->nroElem - 1, meio = -1;
		if ((ch > l->A[esq].chave) || (ch < l->A[dir].chave)){
			return -1;
		}
		int p, situacao = 0;
		while(meio != esq){
			meio = (esq + dir) / 2;
			if (meio != esq){
				if (ch == l->A[meio].chave){
					p = meio + 1;
					situacao = 1;
					break;
				}
				if (ch < l->A[meio].chave){
					esq = meio;
					meio = -1;
				} else{
					dir = meio;
					meio = -1;
				}
			}
		}
		if (situacao == 0){
			return -1;
		}
		return p;
	}
}

int buscaBinariaRecursiva(LISTA *l, TIPOCHAVE ch, int e, int d){//Exerc�cio 5-----------------------
    if (l->nroElem == 0){
		return -1;
	}
	if ((l->nroElem == 1) || ((l->nroElem >= 1) && (l->A[0].chave == l->A[l->nroElem - 1].chave))){
		if (ch == l->A[0].chave){
			return 0;
		}
		return -1;
	}
	if (ch == l->A[0].chave){
		return 0;
	}
	if (ch == l->A[l->nroElem - 1].chave){
		return l->nroElem;
	}
	if (l->A[0].chave < l->A[l->nroElem - 1].chave){
		int esq = e, dir = d, meio = -1;
		if ((ch < l->A[esq].chave) || (ch > l->A[dir].chave)){
			return -1;
		}
		int p, situacao = 0;
		while(meio != esq){
			meio = (esq + dir) / 2;
			if (meio != esq){
				if (ch == l->A[meio].chave){
					p = meio + 1;
					situacao = 1;
					break;
				}
				if (ch > l->A[meio].chave){
					esq = meio;
					meio = -1;
					p = buscaBinariaRecursiva(l, ch, esq, dir);
				} else{
					dir = meio;
					meio = -1;
					p = buscaBinariaRecursiva(l, ch, esq, dir);
				}
			}
		}
		if (situacao == 0){
			return -1;
		}
		return p;
	} else{
		int esq = e, dir = d, meio = -1;
		if ((ch > l->A[esq].chave) || (ch < l->A[dir].chave)){
			return -1;
		}
		int p, situacao = 0;
		while(meio != esq){
			meio = (esq + dir) / 2;
			if (meio != esq){
				if (ch == l->A[meio].chave){
					p = meio + 1;
					situacao = 1;
					break;
				}
				if (ch < l->A[meio].chave){
					esq = meio;
					meio = -1;
					p = buscaBinariaRecursiva(l, ch, esq, dir);
				} else{
					dir = meio;
					meio = -1;
					p = buscaBinariaRecursiva(l, ch, esq, dir);
				}
			}
		}
		if (situacao == 0){
			return -1;
		}
		return p;
	}
}

int main(){ //Testes no pr�prio arquivo ------------------------------ descomente as se��es de teste que deseja utilizar
	//exercicio1();
	
	/*----------------------------------- Teste exercicio 3 - parte 1 
	LISTA x;
	REGISTRO r;
	int c = 0;
	r.chave = 2;
	x.nroElem = 0;
	printf("%i\n", inserirElemListaCrescente(&x, r));
	r.chave = 4;
	printf("%i\n", inserirElemListaCrescente(&x, r));
	r.chave = 6;
	printf("%i\n", inserirElemListaCrescente(&x, r));
	r.chave = 3;
	printf("%i\n", inserirElemListaCrescente(&x, r));
	r.chave = -1;
	printf("%i\n", inserirElemListaCrescente(&x, r));
	r.chave = 9;
	printf("%i\n", inserirElemListaCrescente(&x, r));
	printf("Numero Elementos %i\n", x.nroElem);
	for (; c < x.nroElem; c++){
		printf("||%i\n", x.A[c].chave);
	}
	*/
	
	/*----------------------------------- Teste exercicio 3 - parte 2
	LISTA x;
	REGISTRO r;
	int c = 0;
	r.chave = 2;
	x.nroElem = 0;
	printf("%i\n", inserirElemListaDecrescente(&x, r));
	r.chave = 4;
	printf("%i\n", inserirElemListaDecrescente(&x, r));
	r.chave = 6;
	printf("%i\n", inserirElemListaDecrescente(&x, r));
	r.chave = 3;
	printf("%i\n", inserirElemListaDecrescente(&x, r));
	r.chave = -1;
	printf("%i\n", inserirElemListaDecrescente(&x, r));
	r.chave = 9;
	printf("%i\n", inserirElemListaDecrescente(&x, r));
	printf("Numero Elementos %i\n", x.nroElem);
	for (; c < x.nroElem; c++){
		printf("||%i\n", x.A[c].chave);
	}
	*/
	
	/*------------------------------------------------Teste exercicio 4 
	printf("Elemento da Busca: %i\n", buscaBinaria(&x, 4));
	printf("Elemento da Busca: %i\n", buscaBinaria(&x, 7));
	printf("Elemento da Busca: %i\n", buscaBinaria(&x, 50));
	*/
	
	/*----------------------------------------------------------------------------- Teste exercicio 5
	printf("Elemento da Busca Recursiva: %i\n", buscaBinariaRecursiva(&x, 6, 0, x.nroElem));
	*/
	return 0;	
}

