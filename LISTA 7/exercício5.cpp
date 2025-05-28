#include <stdio.h>
#include <stdlib.h>

int main() {

int A[5];
int *p = A;
int *q = A + 4;
int x;

printf("Digite os 5 valores do vetor A:\n");
for (int i; i < 5; i++){
    printf("A[%d]: ", i);
    scanf("%d", &A[i]);
}

    while(p < q) {
        x = *p;
        *p = *q;
        *q = x;

        p++;
        q--;
    }

        printf("vetor A invertido: \n");
    for(int i = 0; i < 5; i++) {
        printf("A[%d]: %d\n", i, A[i]);
    }


return 0;
}