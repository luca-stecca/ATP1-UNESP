#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void arredondar(const char *valor_str, int casas) {
    char buffer[100];
    strncpy(buffer, valor_str, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    char *ponto = strchr(buffer, '.');
    if (!ponto || casas < 0) {
        printf("%s\n", buffer);
        return;
    }

    int pos_ponto = ponto - buffer;
    int cortar_em = pos_ponto + casas + 1;

    if (strlen(buffer) > cortar_em && buffer[cortar_em] >= '5') {
        buffer[cortar_em] = '\0';  
        for (int i = cortar_em - 1; i >= 0; i--) {
            if (buffer[i] == '.') continue;
            if (buffer[i] < '9') {
                buffer[i]++;
                break;
            } else {
                buffer[i] = '0';
            }
        }
        if (buffer[0] == '0') {
            printf("1%s\n", buffer);
            return;
        }
    } else {
        buffer[cortar_em] = '\0';
    }

    printf("%s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        printf("Uso: %s <valor> [casas]\n", argv[0]);
        return 1;
    }

    char *valor = argv[1];
    int casas = 0;

    if (argc == 3) {
        casas = atoi(argv[2]);
        if (casas < 0) casas = 0;
    }

    arredondar(valor, casas);
    return 0;
}