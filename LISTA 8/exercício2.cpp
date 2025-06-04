#include <stdio.h>  
#include <stdlib.h> 

int main() {

        int *v = NULL;
        int n;
        
    printf("Digite a quantidade de valores que deseja armazenar (valor positivo): ");
    scanf("%d", &n);

    if (n == 0){
    printf("\nNenhum valor armazenado");
    }

    if (n != 0){
    v = (int*) calloc(n, sizeof(int));

    if (v == NULL) {
        printf("\nErro na alocacao de memoria\n");
        return 1;
    }

    for (int i = 0; i < n; i++){
        printf("\nDigite o valor inteiro da %d posicao: ", i+1);
        scanf("%d", &v[i]);
    }

    printf("\nOs valores armazenados do vetor passado sao:\n");
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }

    free(v);
}

    getchar();
    return 0;
}
