#include <stdio.h>
#include <stdlib.h>

int** alocarMatriz(int l, int c) {

    int** matriz = (int**) malloc(l * sizeof(int*));
    if (matriz == NULL) {
        printf("Erro: Falha ao alocar memória para as linhas.\n");
        return NULL;
    }

    for (int i = 0; i < l; i++) {
        matriz[i] = (int*) malloc(c * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro: Falha ao alocar memória para as colunas da linha %d.\n", i);
            
            for (int k = 0; k < i; k++) {
                free(matriz[k]);
            }
            free(matriz);
            return NULL;
        }
    }

    printf("Matriz de %d x %d alocada com sucesso!\n", l, c);
    return matriz;
}

void liberarMatriz(int** matriz, int linhas) {
    if (matriz == NULL) return;

    // libera a memória de cada linha individualmente
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    // libera o ponteiro que apontava para as linhas
    free(matriz);
}

void preencherMatriz(int** matriz, int l, int c) {
    if (matriz == NULL) return;

    printf("\n--- Preenchimento da Matriz ---\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("Digite o valor para a posicao [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimirMatriz(int** matriz, int l, int c) {
     if (matriz == NULL) return;
    printf("\n--- Matriz ---\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void produtoVetorial(int** matriz1, int** matriz2, int** R, int l) {
    for (int i = 0; i < l; i++) {

        R[i][0] = (matriz1[i][1] * matriz2[i][2]) - (matriz1[i][2] * matriz2[i][1]);
        
        R[i][1] = (matriz1[i][2] * matriz2[i][0]) - (matriz1[i][0] * matriz2[i][2]);

        R[i][2] = (matriz1[i][0] * matriz2[i][1]) - (matriz1[i][1] * matriz2[i][0]);
    }
}



int main() {
    int linhas1, colunas1, linhas2, colunas2;
    int** matriz1 = NULL;
    int** matriz2 = NULL;
    int** matrizResultado = NULL;

    printf("--- Alocacao da Matriz A ---\n");
    printf("Digite o numero de linhas de A: ");
    scanf("%d", &linhas1);
    printf("Digite o numero de colunas de A: ");
    scanf("%d", &colunas1);
    matriz1 = alocarMatriz(linhas1, colunas1);
    if (matriz1 == NULL) return 1; 

    printf("\n--- Alocacao da Matriz B ---\n");
    printf("Digite o numero de linhas de B: ");
    scanf("%d", &linhas2);
    printf("Digite o numero de colunas de B: ");
    scanf("%d", &colunas2);
    matriz2 = alocarMatriz(linhas2, colunas2);
    if (matriz2 == NULL) {
        liberarMatriz(matriz1, linhas1); 
        return 1;
    }

    if (colunas1 != 3 || colunas2 != 3) {
        printf("\nERRO: O produto vetorial so e definido para vetores de 3 dimensoes (matrizes com 3 colunas).\n");
    } else if (linhas1 != linhas2) {
        printf("\nERRO: As matrizes devem ter o mesmo numero de linhas para esta operacao.\n");
    } else {

        printf("\nDimensoes validas para o produto vetorial!\n");

        preencherMatriz(matriz1, linhas1, colunas1);
        preencherMatriz(matriz2, linhas2, colunas2);


        matrizResultado = alocarMatriz(linhas1, 3);
        if (matrizResultado == NULL) { 
            liberarMatriz(matriz1, linhas1);
            liberarMatriz(matriz2, linhas2);
            return 1;
        }

        produtoVetorial(matriz1, matriz2, matrizResultado, linhas1);

        printf("\n-----------------------------------\n");
        imprimirMatriz(matriz1, linhas1, colunas1);
        imprimirMatriz(matriz2, linhas2, colunas2);
        printf("\n--- Resultado do Produto Vetorial ---\n");
        imprimirMatriz(matrizResultado, linhas1, 3);
    }

    liberarMatriz(matriz1, linhas1);
    liberarMatriz(matriz2, linhas2);
    if(matrizResultado != NULL) {
        liberarMatriz(matrizResultado, linhas1);
    }
    printf("\nMemoria de todas as matrizes liberada com sucesso.\n");

    return 0;
}