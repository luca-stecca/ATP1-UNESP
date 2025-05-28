#include <stdio.h>
#include <stdlib.h>

int verificacao(int A[], int T, int x) {
    for(int i = 0; i < T; i++) {
        if(A[i] == x) {
            return 1;  
        }
    }
    return 0;  
}

int main() {
    int A[5] = {23, 37, 49, 54, 68};
    int x;

    printf("Digite o elemento que deseja buscar: ");
    scanf("%d", &x);

    if(verificacao(A, 5, x) == 1) {
        printf("O elemento %d esta presente no vetor.\n", x);
    } else {
        printf("O elemento %d NAO esta presente no vetor.\n", x);
    }

    return 0;
}