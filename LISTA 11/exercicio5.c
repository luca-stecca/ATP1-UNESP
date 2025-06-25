#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 100
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    float preco;
} Item;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <menu.txt> <boleto.txt>\n", argv[0]);
        return 1;
    }

    FILE *fmenu = fopen(argv[1], "r");
    if (!fmenu) {
        perror("Erro ao abrir menu");
        return 1;
    }

    int n_itens;
    if (fscanf(fmenu, "%d\n", &n_itens) != 1 || n_itens <= 0 || n_itens > MAX_ITENS) {
        printf("Arquivo menu inválido ou número de itens incorreto.\n");
        fclose(fmenu);
        return 1;
    }

    Item itens[MAX_ITENS];
    for (int i = 0; i < n_itens; i++) {
        if (fscanf(fmenu, "%s %f", itens[i].nome, &itens[i].preco) != 2) {
            printf("Erro ao ler item %d do menu.\n", i + 1);
            fclose(fmenu);
            return 1;
        }
    }

    fclose(fmenu);

    int quantidade[MAX_ITENS];
    memset(quantidade, 0, sizeof(quantidade));

    printf("=== MENU ===\n");
    for (int i = 0; i < n_itens; i++) {
        printf("%d) %s - R$ %.2f\n", i + 1, itens[i].nome, itens[i].preco);
    }
    printf("0) Finalizar pedido\n");

    int opcao;
    do {
        printf("Escolha o item (0 para finalizar): ");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida. Tente novamente.\n");
            while(getchar() != '\n'); // limpa buffer
            continue;
        }

        if (opcao < 0 || opcao > n_itens) {
            printf("Opção inválida. Tente novamente.\n");
            continue;
        }
        if (opcao == 0)
            break;

        int qtd;
        printf("Quantidade de %s: ", itens[opcao - 1].nome);
        if (scanf("%d", &qtd) != 1 || qtd <= 0) {
            printf("Quantidade inválida. Tente novamente.\n");
            while(getchar() != '\n'); // limpa buffer
            continue;
        }

        quantidade[opcao - 1] += qtd;

    } while (1);

    FILE *fboleto = fopen(argv[2], "w");
    if (!fboleto) {
        perror("Erro ao criar boleto");
        return 1;
    }

    fprintf(fboleto, "===== BOLETO DO PEDIDO =====\n\n");
    float total = 0.0f;
    for (int i = 0; i < n_itens; i++) {
        if (quantidade[i] > 0) {
            float subtotal = quantidade[i] * itens[i].preco;
            fprintf(fboleto, "%s x%d - R$ %.2f\n", itens[i].nome, quantidade[i], subtotal);
            total += subtotal;
        }
    }
    fprintf(fboleto, "\nTOTAL: R$ %.2f\n", total);
    fclose(fboleto);

    printf("Pedido finalizado. Boleto salvo em '%s'\n", argv[2]);
    return 0;
}