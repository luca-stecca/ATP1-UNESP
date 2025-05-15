#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int exponenciacao(int base, int expoente){

    if (expoente == 0){
        return 1;
     } else {
        return base * exponenciacao(base, expoente - 1); // recursão para calcular a exponenciação
    }

}

int main(){

    int base, expoente;
    printf("Digite uma base inteiro: ");
    scanf("%d", &base);
    printf("Digite um expoente inteiro positivo: ");
    scanf("%d", &expoente);

    printf("O resultado da base %d elevada pelo expoente %d e: %d\n", base, expoente, exponenciacao(base, expoente));

    getchar();
    return 0;
}