#include <stdio.h>
#include <math.h>

int obter_num(){
    int num;
    do{
        printf("Digite um numero real positivo: ");
        scanf("%d", & num);
        printf("\n");
        if(num <= 0)
            printf("Entrada invalida. \n");
    } while(num <= 0);
    return num;
}

int hiperfatorial(int x){
    int n = 0, expr, h_fat = 1;
    while(n <= x){
        expr = pow(n, n);
        h_fat *= expr;
        n++;
    }
    return h_fat;
}

void imprimir(int x, int h_fat){
    printf("O hiperfatorial de %d e %d", x, h_fat);
}

int main(){
    int x = obter_num();
    imprimir(x, hiperfatorial(x));
    return 0;
}
