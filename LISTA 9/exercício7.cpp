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


int main() {
    int l, c;

    printf("Digite o numero de linhas desejado: ");
    scanf("%d", &l);
    printf("Digite o numero de colunas desejado: ");
    scanf("%d", &c);


    int** resultado = alocarMatriz(l, c);

  
    if (resultado == NULL) {
        printf("Nao foi possivel continuar\n");
        return 1; 
    }


    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            resultado[i][j] = i + j;
        }
    }

        printf("\n--- Matriz ---\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", resultado[i][j]);
        }
        printf("\n");
    }

    liberarMatriz(resultado, l);
    printf("\nMemoria liberada com sucesso.\n");

    return 0;
}
