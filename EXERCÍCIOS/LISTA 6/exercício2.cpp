#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int soma(int n){

    if(n == 1){
        return 1;
    }

    return (n + soma(n-1)); // recursão para somar os números de 1 até n

}

int main(){

    int n;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    soma(n);

    printf("A soma de todos os números de 1 ate %d e: %d\n", n, soma(n));
    getchar();
    return 0;

}