#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *v = NULL;

    printf("Digite a quantidade de valores (valor positivo): "); 
    scanf("%d", &n);

    v = (int*) calloc(n, sizeof(int));
    if (v == NULL) {
        printf("Erro na alocacao de memoria\n"); //verificação de erro
        return 1;
    }
    
    printf("\nVALORES SEQUENCIAIS:\n");
    for(int i = 0; i < n; i++) {

        v[i] = i + 1; //valores sequenciais
        printf("%d\n", v[i]); 

    }

    free(v); 
    getchar();
    return 0;

}