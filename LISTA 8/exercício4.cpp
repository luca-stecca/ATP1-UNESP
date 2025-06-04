#include <stdio.h>
#include <stdlib.h>


int* pares(int *v, int n, int *M) {
    int *s = NULL;
    int p = 0;

    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {  
            int *Q = (int*) realloc(s, (p + 1) * sizeof(int));
            if (Q == NULL) {
                printf("Erro na alocacao de memoria\n");
                free(s);
                *M = 0;
                return NULL;
            }
            s = Q;
            s[p] = v[i];
            p++;
        }
    }

    *M = p;  
    return s;
}

int main() {
    int n;

    printf("Digite os valores inteiros que serao armazenados (-1 para parar): ");
    scanf("%d", &n);

    int *v = (int*) malloc(n * sizeof(int));
    if (v == NULL) {
        printf("Erro na alocacao de memoria\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nDigite o valor inteiro da %d posicao: ", i + 1);
        scanf("%d", &v[i]);
    }

    int M;
    int *s = pares(v, n, &M);

    printf("\nVetor com elementos pares:\n");
    for (int i = 0; i < M; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");

    free(v);
    free(s);

    return 0;
}