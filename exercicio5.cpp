#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    float preco;
    int quantidade;
} Produto;

typedef struct {
    Produto* produtos;
    int num_produtos;
    int capacidade;
} Menu;

Produto inicializar_produto(const char* nome, float preco, int quantidade) {
    Produto p;
    strcpy(p.nome, nome);
    p.preco = preco;
    p.quantidade = quantidade;
    return p;
}

void inicializar_menu(Menu* menu) {
    menu->capacidade = 10;
    menu->num_produtos = 0;

    menu->produtos = (Produto*)calloc(1,menu->capacidade * sizeof(Produto));
    if (menu->produtos == NULL) {
        printf("Erro ao alocar memória para o menu!\n");
        exit(1);
    }
}


void adicionar_produto_ao_menu(Menu* menu, Produto produto) {
    if (menu->num_produtos == menu->capacidade) {
        menu->capacidade *= 2;
        menu->produtos = (Produto*)realloc(menu->produtos, menu->capacidade * sizeof(Produto));
        if (menu->produtos == NULL) {
            printf("Erro ao realocar memória para o menu!\n");
            exit(1);
        }
    }
    menu->produtos[menu->num_produtos] = produto;
    menu->num_produtos++;
}

void liberar_menu(Menu* menu) {
    free(menu->produtos);
    menu->produtos = NULL;
    menu->num_produtos = 0;
    menu->capacidade = 0;
}

int main() {
    Menu menu;
    inicializar_menu(&menu);

    FILE* stream_menu;
    
    stream_menu = fopen("menu.txt", "r");
    if (stream_menu == NULL) {
        printf("Erro ao abrir o menu.txt.\n");
        printf("Verifique se o arquivo esta na mesma pasta do programa.\n");
        liberar_menu(&menu);
        return 1;
    }

    char linha[200];
    fgets(linha, sizeof(linha), stream_menu); 

    while (fgets(linha, sizeof(linha), stream_menu) != NULL) {
        char nome_temp[100];
        float preco_temp;
        int qtd_temp;

        if (sscanf(linha, "%s %f %d", nome_temp, &preco_temp, &qtd_temp) == 3) {
            Produto p = inicializar_produto(nome_temp, preco_temp, qtd_temp);
            adicionar_produto_ao_menu(&menu, p);
        }
    }
    fclose(stream_menu);
    printf("Menu carregado com %d produtos.\n", menu.num_produtos);

    FILE* stream_boleto = fopen("boleto.txt", "w");
    if (stream_boleto == NULL) {
        printf("Erro ao criar o boleto.txt.\n");
        liberar_menu(&menu);
        return 1;
    }

    fprintf(stream_boleto, "======================= Boleto =======================\n");
    float soma_total = 0;

    for (int i = 0; i < menu.num_produtos; i++) {
        Produto p_atual = menu.produtos[i];
        float total_produto = p_atual.preco * p_atual.quantidade;
        fprintf(stream_boleto, "Produto: %-10s | Quantidade: %-5d | Total: R$ %.2f\n", 
                p_atual.nome, p_atual.quantidade, total_produto);
        soma_total += total_produto;
    }

    fprintf(stream_boleto, "======================================================\n");
    fprintf(stream_boleto, "O valor total da conta: R$ %.2f\n", soma_total);
    fclose(stream_boleto);

    liberar_menu(&menu);
    printf("Boleto gerado com sucesso!\n");

    return 0;
}