#include <stdio.h>  
#include <stdlib.h> 

int main() {
 
        int *v = NULL;
        int n = 0;
        int valor;

    while (valor != -1){

    printf("Digite os valores inteiros que serao armazenados (-1 para parar): ");
    scanf("%d", &valor);

    if (valor == -1){
        printf("Parando...");
        break;
    }

    v = (int*) realloc(v, (n + 1) * sizeof(int));

    if (v == NULL) {
        printf("\nErro na alocacao de memoria\n");
        return 1;
    }

    v[n] = valor;
   n++;
  }

      if (n == 0){
    printf("\nNenhum valor armazenado");
    }

    if (n != 0){
    printf("\nOs valores armazenados do vetor passado sao:\n");
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
}
    free(v);
    getchar();
    return 0;
}