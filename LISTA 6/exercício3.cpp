#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int resto(int n){

    if (n < 0){
        n = -n;
    } 
    else if (n < 10){
        return 1;
    }

    return 1 + resto(n / 10); // recursão para contar os dígitos do número

}

int main(){

    int n;
    printf("Digite um numero inteiro: ");
    scanf("%d", &n);
  
    printf("A quantidade de digitos de %d e: %d\n", n, resto(n));

    getchar();
    return 0;
}