#include <stdio.h>

int obter_num(){
    int n =0;
    printf("digite um numero inteiro e positivo: ");
    scanf("%d", &n);
    while(n <= 0){
        printf("entrada invalida. digite um numero inteiro e positivo: ");
        scanf("%d", &n);
    }
    return n;
}

void ver_perfeito(int *n){
    int divisor = 1;
    int soma = 0;
    int n2= *n;
    while(divisor < n2){
        int resto = n2 % divisor;
        if(resto == 0){
            soma+=divisor;
        }
        divisor++;
    }
    if(soma == n2){
        printf("o numero %d e perfeito", n2);
    }
    else{
        printf("o numero %d nao e perfeito", n2);
    }
}

int main(){
    int num = obter_num();
    ver_perfeito(&num);
    return 0;
}