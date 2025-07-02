#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_NOTAS 3

typedef struct aluno {
    char nome[100];
    float notas[NUM_NOTAS];
    struct aluno *proximo;
} Aluno;

Aluno* iniciar() {
    Aluno *lista = (Aluno*)calloc(1, sizeof(Aluno));
    if (lista == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    lista->proximo = NULL; 
    return lista;
}

void liberar(Aluno *lista) {
    Aluno *atual = lista;
    while (atual != NULL) {
        Aluno *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

void adicionar_aluno(Aluno *lista, const char nome[100], float notas[NUM_NOTAS]) {
    if (lista->proximo == NULL && strlen(lista->nome) == 0) {
        strcpy(lista->nome, nome);
        for (int i = 0; i < NUM_NOTAS; i++) {
            lista->notas[i] = notas[i];
        }
        lista->proximo = iniciar();
    } else {
        adicionar_aluno(lista->proximo, nome, notas);
    }
}

void calcular_e_imprimir_medias(Aluno *lista) {
    Aluno *atual = lista;
    printf("MEDIA DOS ALUNOS\n");
    while (atual->proximo != NULL) {
        float media = ((atual->notas[0] * 0.6 + atual->notas[1] * 0.4) * 0.8 + atual->notas[2] * 0.2);
        printf("ALUNO: %-7s | MEDIA: %.2f\n", atual->nome, media);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    Aluno* lista_de_alunos = iniciar();
    if (lista_de_alunos == NULL) {
        printf("Erro ao inicializar a lista!\n");
        return 1; 
    }

    float notas1[] = {2.7, 10, 6.5};
    float notas2[] = {7, 4.5, 9};
    float notas3[] = {10, 6.5, 5};

    adicionar_aluno(lista_de_alunos, "aluno 1", notas1);
    adicionar_aluno(lista_de_alunos, "aluno 2", notas2);
    adicionar_aluno(lista_de_alunos, "aluno 3", notas3);

    calcular_e_imprimir_medias(lista_de_alunos);

    liberar(lista_de_alunos);

    return 0;
}