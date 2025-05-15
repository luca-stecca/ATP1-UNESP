#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){

 srand(time(NULL)); 

 printf("Numero aleatorio: %d\n", (rand()%11) + 2); // numero aleatorio entre 0 e 10 + 2, ou seja, entre 2 e 12
getchar();
return 0;

}

