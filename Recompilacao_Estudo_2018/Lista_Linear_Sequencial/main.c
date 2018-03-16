#include "lista_sequencial.h"

int main()
{
    LISTA x;
    REGISTRO r;
    inicializar_lista(&x);
    (&x);
    r.chave = 2;
    inserir_elem(&x, r);
    r.chave = 42;
    inserir_elem(&x, r);
    r.chave = 4;
    inserir_elem(&x, r);
    r.chave = 100;
    inserir_elem(&x, r);
    eixbir_elem(&x);
    printf("Quanidade: %d\n", quant_elem(&x));
    excluir_elem(&x, 42);
    eixbir_elem(&x);
    printf("Quanidade: %d\n", quant_elem(&x));
    reinicializar(&x);
    eixbir_elem(&x);
    printf("Quanidade: %d\n", quant_elem(&x));
    return 0;
}
