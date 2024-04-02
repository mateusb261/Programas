#include <stdio.h>

int scanIntIntervalo(){
    int num;
    do{
        printf("digite um valor para x entre 0 e 1000: ");
        scanf("%d", &num);
        printf("\n");
        if(num<=0 || num>=1000){
            printf("entrada invalida. digite apenas um numero entre 0 e 1000");
            printf("\n");
        }
    } while(num<=0 || num>=1000);
    return num;
}

float percentual(float menor, float maior){
    float perc_menor = 100*(menor/maior);
    return perc_menor;
}

int absdif(int maior, int menor){
    int v_absoluto = maior - menor;
    return v_absoluto;
}

int main(){
    int x = scanIntIntervalo();
    int y = scanIntIntervalo();
    int maior;
    int menor;
    if(x > y){
        maior = x;
        menor = y;
    }
    else{
        maior = y;
        menor = x;
    }
    float perc_menor = percentual(menor, maior);
    printf("o percentual do menor em relacao ao maior e: %.2f \n", perc_menor);
    printf("\n");
    int modulo = absdif(maior,menor);
    printf("o modulo da diferenca entre o maior e o menor e igual a %d", modulo);
    return 0;
}
