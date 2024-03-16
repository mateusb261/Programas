#include <stdio.h>

void peso_semanas(int *peso, int *semanas){
    int peso_t = *peso;
    int semanas_t = *semanas;
    printf("digite o peso do feto em gramas: ");
    scanf("%d", & peso_t);
    printf("\n");
    printf("digite a quantidade de semanas da gestacao: ");
    scanf("%d", & semanas_t);
    printf("\n");
    *peso = peso_t;
    *semanas = semanas_t;
}

void ver_gestacao(int *peso, int *semanas){
    if(*peso<100 || *semanas<28){
        printf("Parto nao devera ser realizado, reavaliar clinicamente");
        return;
    }
    else{
        float meses = *semanas/4;
        if(*peso>2500 && meses>7){
            printf("Parto normal");
            return;
        }
        if(*peso>2500 && meses<=7){
            printf("Parto Cesariana");
            return;
        }
        if((*peso<=1500 || *peso>=2000) && meses>9){
            printf("Parto normal");
            return;
        }
        else{
            printf("Parto Cesariana");
            return;
        }
    }
}

int main(){
    int peso;
    int semanas;
    peso_semanas(&peso, &semanas);
    ver_gestacao(&peso, &semanas);
    return 0;
}