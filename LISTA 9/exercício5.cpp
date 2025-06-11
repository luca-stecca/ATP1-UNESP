#include <stdio.h>
#include <stdlib.h>

void ProdutoVet(int matriz1[3][3], int matriz2[3][3], int resultado[3][3]) {

    for (int i = 0; i < 3; i++) {
        int* vetor1 = matriz1[i];
        int* vetor2 = matriz2[i];
        int* PVresultado = resultado[i];

        // é aplicada a fórmula do produto vetorial para a linha atual
        PVresultado[0] = (vetor1[1] * vetor2[2]) - (vetor1[2] * vetor2[1]);
        
        PVresultado[1] = (vetor1[2] * vetor2[0]) - (vetor1[0] * vetor2[2]);
        
        PVresultado[2] = (vetor1[0] * vetor2[1]) - (vetor1[1] * vetor2[0]);
    }
}

int main() {

    int matriz1[3][3] = {
        {1, 0, 0},  
        {0, 1, 0},  
        {0, 0, 1}   
    };

    int matriz2[3][3] = {
        {0, 1, 0},  
        {0, 0, 1},  
        {1, 0, 0}   
    };

 
    int PVresultado[3][3];


    printf("--- MATRIZ 1 ---\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", matriz1[i][j]);
        }
        printf("\n");
    }

    printf("--- MATRIZ 2 ---\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", matriz2[i][j]);
        }
        printf("\n");
    }

    ProdutoVet(matriz1, matriz2, PVresultado);

    printf("\n--- Resultado do Produto Vetorial ---\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", PVresultado[i][j]);
        }
        printf("\n");
    }

    getchar();
    return 0;
}

