#include <stdio.h>
#include <stdlib.h>

typedef struct matriz{
    int linha;
    int coluna;
    int** matriz;
    struct matriz *proximo; 
}Matriz;

int main(){
    return 0;
}