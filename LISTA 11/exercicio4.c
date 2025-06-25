#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHA 1024

// Função para alocar uma matriz n x n
int **alocar_matriz(int n) {
    int **matriz = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        matriz[i] = malloc(n * sizeof(int));
    return matriz;
}

// Função para liberar uma matriz n x n
void liberar_matriz(int **matriz, int n) {
    for (int i = 0; i < n; i++)
        free(matriz[i]);
    free(matriz);
}

// Função para ler uma matriz do arquivo
void ler_matriz(FILE *fp, int **matriz, int n) {
    char linha[MAX_LINHA];
    for (int i = 0; i < n; i++) {
        if (fgets(linha, sizeof(linha), fp) == NULL) {
            printf("Erro: Linhas insuficientes no arquivo.\n");
            exit(1);
        }
        char *token = strtok(linha, " \t\r\n");
        for (int j = 0; j < n; j++) {
            if (token == NULL) {
                printf("Erro: Faltam valores na linha %d.\n", i + 2);
                exit(1);
            }
            matriz[i][j] = atoi(token);
            token = strtok(NULL, " \t\r\n");
        }
    }
}

// Função para somar duas matrizes
void somar_matrizes(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Função para imprimir uma matriz
void imprimir_matriz(int **matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo_matriz.txt>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    char linha[MAX_LINHA];
    if (fgets(linha, sizeof(linha), fp) == NULL) {
        printf("Erro ao ler o tamanho da matriz.\n");
        fclose(fp);
        return 1;
    }

    int n = atoi(linha);
    if (n <= 0) {
        printf("Erro: valor inválido para dimensão da matriz.\n");
        fclose(fp);
        return 1;
    }

    int **A = alocar_matriz(n);
    int **B = alocar_matriz(n);
    int **C = alocar_matriz(n);

    ler_matriz(fp, A, n);
    ler_matriz(fp, B, n);
    fclose(fp);

    somar_matrizes(A, B, C, n);

    printf("Matriz resultante:\n");
    imprimir_matriz(C, n);

    liberar_matriz(A, n);
    liberar_matriz(B, n);
    liberar_matriz(C, n);

    return 0;
}