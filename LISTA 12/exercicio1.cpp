#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct notas {
    float p1;
    float p2;
    float ex;
};

float media(float p1, float p2, float ex){
    return ((p1*0.6+p2*0.4)*0.8+ex*0.2);
}

int main(){
    notas aluno1;
    float media;
    
    printf("Insira as notas do aluno - p1/p2/Ex -\n");
    scanf("%f",&aluno1.p1);
    scanf("%f",&aluno1.p2);
    scanf("%f",&aluno1.ex);

    m = media(aluno1.p1,aluno1.p2,aluno1.ex);

    printf("A media do aluno e: %.2f",m);

    return 0;
}