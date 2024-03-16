#include <stdio.h>
#include <math.h>

float obter_num(){
    float num;
    do{
        printf("Digite um numero real entre 0 e 1: ");
        scanf("%f", & num);
        printf("\n");
        if(num <= 0 || num >= 1)
            printf("Entrada invalida. \n");
    } while(num <= 0 || num >= 1);
    return num;
}

float arctan(float x){
    float expr;
    int exp = 1, cont = 1;
    float arct = x;
    const float v_cond = 0.0001;
    do{
        exp += 2;
        expr = pow(x, exp) / exp;
        if(cont % 2 != 0){
            arct -= expr;
        }
        else{
            arct += expr;
        }
        cont++;
    } while(expr >= v_cond);
    return arct;
}

void imprimir(float x, float arct){
    printf("O arco tangente do numero real %.2f e %.2f rad", x, arct);
}

int main(){
    float x = obter_num();
    float arct = arctan(x);
    imprimir(x, arct);
    return 0;
}
