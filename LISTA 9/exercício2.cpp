#include <stdio.h>
#include <stdlib.h>

void matriz_transposta(int matriz[3][3], int transposta[3][3]){

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            transposta[i][j] = matriz[j][i];
        }
    }

}

int main() {

   int matriz[3][3] = {

         {1,2,3},
         {4,5,6},
         {7,8,9}

   };

   int transposta[3][3];

   matriz_transposta(matriz, transposta);

   printf("--- MATRIZ TRANSPOSTA ---\n");
   for (int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
        printf("%d ", transposta[i][j]);
    }
    printf("\n");
   }


    getchar();
    return 0;
}