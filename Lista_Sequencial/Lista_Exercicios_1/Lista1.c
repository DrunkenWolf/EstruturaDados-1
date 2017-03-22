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

/*------------- Exercício 2 - Solução -------------------------------
	Quando se utiliza o método de busca sequencial comum, utiliza-se um laço de repetição para percorrer toda a lista. Isto é válido para o método de busca sentinela, porém, 
	na busca comum é necessário verificar a cada loop se o contador encontra-se dentro lo escopo da lista, caso contrário, poderíamos encontrar um erro de leitura/acesso.
	Já no busca sentinela, o valor que desejamos encontrar é adicionado na última posição da lista e, portanto, sabe-se que o valor será sempre encontrado elimitando, assim,
	a verificação de escopo da lista. Por tal razão, eliminamos processamento adicional e o algorítmo se torna mais eficiente.
	O problema de o sentinela ocupar a última posição da lista poderia ser corrigido adicionando uma posição a mais do que o MAX à lista. Desta forma, seria garantido que
	haverá espaço para o sentinela.
	
*/

int inserirElemListaCrescente(LISTA *l, REGISTRO reg){ //------------Exercício 3 parte 1
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

int inserirElemListaDecrescente(LISTA *l, REGISTRO reg){ //------------Exercício 3 parte 2
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

int buscaBinaria(LISTA *l, TIPOCHAVE ch){//Exercício 4-----------------------
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

int buscaBinariaRecursiva(LISTA *l, TIPOCHAVE ch, int e, int d){//Exercício 5-----------------------
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

int main(){ //Testes no próprio arquivo ------------------------------ descomente as seções de teste que deseja utilizar
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

