#include <stdio.h>
#include <stdlib.h>

int main() {
    char palavra[100];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    printf("%s comeca com %c\n", palavra, palavra[0]);

    getchar();
    return (0);
}