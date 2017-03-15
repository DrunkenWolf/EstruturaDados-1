#include <stdio.h>

struct estrutura1{
	int peso; //medida em gramas - evitar float
	int altura; //medida em centímetros - evitar float
};

typedef struct{ //mesma estrutura para retirar a chamada "struct"
	int peso;
	int altura;
} estrutura2;

int main(){
	struct estrutura1 pessoa;
	estrutura2 pessoa2;
	pessoa.peso = 8500;
	pessoa.altura = 166;
	printf("Estrutura = %lu\n", sizeof(pessoa));
	printf("Peso = %i\n", pessoa.peso);
	printf("Altura = %i\n", pessoa.altura);
	return 0;
}
