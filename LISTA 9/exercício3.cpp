#include <stdio.h>
#include <stdlib.h>

int verificacao(int matriz[3][3], int n, int *linha, int *coluna){

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

        if (matriz[i][j] == n){
          *linha = i;
          *coluna = j;
          return 1;
        }

        }
    }

    return 0;
} 


int main() {

    int v;
    int linhaE, colunaE;
    
    int matriz[3][3] = {

        {5,54,21},
        {102,92,11},
        {31,3,77}

    };

    printf("DIGITE O NUMERO QUE POSSA ESTAR NA MATRIZ 3x3: ");
    scanf("%d", &v);

    if (verificacao(matriz, v, &linhaE, &colunaE) == 1){
        printf("O numero %d foi encontrado na posicao: linha = [%d] e coluna = [%d]\n",v, linhaE+1, colunaE+1); //foi somado 1 ao resultado para condizer com algo menos abstrato
    } else {
        printf("O numero %d nao foi encontrado\n", v);
    }

    getchar();
    return 0;
}