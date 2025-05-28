#include <stdio.h>
#include <stdlib.h>

void ambos(int A[], int B[], int T) {
    printf("Elementos presentes em ambos os vetores: ");
    for(int i = 0; i < T; i++) {
        for(int j = 0; j < T; j++) {
            if(A[i] == B[j]) {
                printf("%d ", A[i]); 
                break;
            }
        }
    }
    printf("\n");
}

int main() {
    int T = 5;
    int A[5], B[5];

    printf("Digite 5 elementos para A:\n");
    for(int i = 0; i < T; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    printf("Digite 5 elementos para B:\n");
    for(int i = 0; i < T; i++) {
        printf("B[%d]: ", i);
        scanf("%d", &B[i]);
    }

    ambos(A, B, T);

    return 0;
}