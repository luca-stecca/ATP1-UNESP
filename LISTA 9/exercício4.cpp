#include <stdio.h>
#include <stdlib.h>

void diag(int matriz[3][3], int *diag_princ){

       for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            if (i == j){

                *diag_princ = *diag_princ + matriz[i][j];

            }
       
        }
    }

}



int main() {

    int diag_princ = 0;

    int matriz[3][3] = {

        {1,2,3},
        {4,5,6},
        {7,8,9}

    };

    printf("--- MATRIZ ---\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    diag(matriz, &diag_princ);

    printf("\nA SOMA DA DIAGONAL PRINCIPAL E: %d", diag_princ);


    getchar();
    return 0;
}