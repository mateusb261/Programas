#include <stdio.h>

//recebe apenas um numero natural do usuario

int num_nat(){
    int n;
    do{
        printf("Digite um numero natural: ");
        scanf("%d", & n);
        printf("\n");
        if(n<0){
            printf("Entrada invalida. Digite apenas numeros naturais.");
            printf("\n");
        }
    } while(n<0);
    return n;
}

//Recebe n como parâmetro e retorna n!

int fat(int n) {
    int fat = n;
    if(n==0 || n==1){
        return 1;
    }
    else{
        n--;
        while(n>=1){
            fat*=n;
            n--;
        }
        return fat;
    }
}

int main(){
    int n = num_nat();
    int fatorial = fat(n);
    printf("O fatorial de %d e %d", n, fatorial);
    return 0;
}