#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 5

int numero_unico(int usados[], int inicio, int fim) {
    int n;
    do {
        n = rand() % (fim - inicio + 1) + inicio;
    } while (usados[n - inicio]);  
    usados[n - inicio] = 1;
    return n;
}

void gerar_cartela(int cartela[TAM][TAM]) {
    int usados[75] = {0};

    for (int col = 0; col < TAM; col++) {
        int inicio = col * 15 + 1;
        int fim = inicio + 14;
        int usados_col[15] = {0};

        for (int lin = 0; lin < TAM; lin++) {
            if (col == 2 && lin == 2) {
                cartela[lin][col] = -1; 
            } else {
                cartela[lin][col] = numero_unico(usados_col, inicio, fim);
            }
        }
    }
}

void salvar_cartela_csv(FILE *fp, int cartela[TAM][TAM]) {
    for (int lin = 0; lin < TAM; lin++) {
        for (int col = 0; col < TAM; col++) {
            if (col > 0) fprintf(fp, ";");
            if (cartela[lin][col] == -1)
                fprintf(fp, "FREE");
            else
                fprintf(fp, "%d", cartela[lin][col]);
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n"); 
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <quantidade_cartelas>\n", argv[0]);
        return 1;
    }

    int qtd = atoi(argv[1]);
    if (qtd <= 0) {
        printf("Quantidade deve ser maior que 0.\n");
        return 1;
    }

    FILE *fp = fopen("cartelas.csv", "w");
    if (!fp) {
        perror("Erro ao abrir cartelas.csv");
        return 1;
    }

    srand(time(NULL)); 

    for (int i = 0; i < qtd; i++) {
        int cartela[TAM][TAM];
        gerar_cartela(cartela);
        salvar_cartela_csv(fp, cartela);
    }

    fclose(fp);
    printf("Geradas %d cartelas no arquivo 'cartelas.csv'\n", qtd);
    return 0;
}