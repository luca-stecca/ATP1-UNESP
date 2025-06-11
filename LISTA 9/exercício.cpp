#include <stdio.h>
#include <stdlib.h>

void soma (int matriz1[3][3], int matriz2[3][3], int resultado[3][3]){

    for (int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

}

int main() {

    int matriz1[3][3] = {

        {1,2,3},
        {4,5,6},
        {7,8,9}

    };

        int matriz2[3][3] = {

        {10,11,12},
        {13,14,15},
        {16,17,18}

    };

    int resultado[3][3];

        printf("--- Matriz A ---\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", matriz1[i][j]); 
        }
        printf("\n");
    }

    printf("\n--- Matriz B ---\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", matriz2[i][j]); 
        }
        printf("\n");
    }

    soma(matriz1, matriz2, resultado);

    printf("\n--- Resultado da Soma ---\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", resultado[i][j]); 
        }
        printf("\n");
    }

    getchar();
    return 0;
}