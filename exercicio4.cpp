#include <stdio.h>
#include <stdlib.h> 

#define FATOR 10000

typedef struct {
    int valor; 
} Decimal;

Decimal criar(int parte_inteira, int parte_fracionaria) {
    Decimal n;
    n.valor = parte_inteira * FATOR + parte_fracionaria;
    return n;
}

void imprimir(Decimal n) {
    int parte_inteira = n.valor / FATOR;
    int parte_fracionaria = abs(n.valor % FATOR);

    if (n.valor < 0 && parte_inteira == 0) {
        printf("-");
    }
    printf("%d.%04d\n", parte_inteira, parte_fracionaria);
}

Decimal somar(Decimal a, Decimal b) {
    Decimal resultado;
    resultado.valor = a.valor + b.valor;
    return resultado;
}

Decimal subtrair(Decimal a, Decimal b) {
    Decimal resultado;
    resultado.valor = a.valor - b.valor;
    return resultado;
}

int main() {
    Decimal a = criar(-5, -507);
    Decimal b = criar(1, 485);

    Decimal soma = somar(a, b);
    printf("Soma (a + b): ");
    imprimir(soma);

    return 0;
}