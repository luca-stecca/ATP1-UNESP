#include <stdio.h>
#include <stdlib.h>

int main() {
    int l = 3;
    int c = 3;

    int *matriz = (int *) malloc(l * c * sizeof(int));
    if (matriz == NULL) {
        printf("Erro ao alocar memuria!\n");
        return 1;
    }

    for (int i = 0; i < l * c; i++) {
        matriz[i] = 0;
    }

    printf("Matriz 3x3:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", matriz[i * c + j]);
        }
        printf("\n");
    }

    free(matriz);

    return 0;
}