#include <stdio.h>
#include <stdlib.h>

int main() {
    int A[5];
    int B[5];

    printf("Digite 5 numeros inteiros para o vetor A:\n");
    for (int i = 0; i < 5; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    printf("Digite 5 numeros inteiros para o vetor B:\n");
    for (int i = 0; i < 5; i++) {
        printf("B[%d]: ", i);
        scanf("%d", &B[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf("%d, %d, ", A[i], B[i]);
    }

    getchar();
    return (0);
}