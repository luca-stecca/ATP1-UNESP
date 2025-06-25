#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int primo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <inicio> <fim>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], argv[2]) == 0) {
        printf("Os valores de inicio e fim são iguais: %s\n", argv[1]);
        return 0;
    }

    int inicio = atoi(argv[1]);
    int fim = atoi(argv[2]);

    if (inicio > fim) {
        int temp = inicio;
        inicio = fim;
        fim = temp;
    }

    printf("Numeros primos entre %d e %d:\n", inicio, fim);
    for (int i = inicio; i <= fim; i++) {
        if (primo(i)) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}