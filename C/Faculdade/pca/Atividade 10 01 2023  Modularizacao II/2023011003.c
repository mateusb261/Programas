#include <stdio.h>
#include <math.h>

int obter_int_pos_x(){
    int n;
    do{
        printf("Digite um numero inteiro positivo para x: ");
        scanf("%d", & n);
        printf("\n");
        if(n <= 0){
            printf("Entrada invalida. Digite um numero inteiro positivo para x.");
            printf("\n");
        }
    } while(n <= 0);
    return n;
}

int obter_int_pos_y(){
    int n;
    do{
        printf("Digite um numero inteiro positivo para y: ");
        scanf("%d", & n);
        printf("\n");
        if(n <= 0){
            printf("Entrada invalida. Digite um numero inteiro positivo para y.");
            printf("\n");
        }
    } while(n <= 0);
    return n;
}


int ver_num(int x, int y){
    printf("x= %d, y= %d", x, y);
    printf("\n");
    int y2 = y;
    int exp = 0;
    while(y2 > 0){
        y2 /= 10;
        exp++;
    }
    int v = pow(10, exp);
    x = x % v;
    if(x == y){
        printf("Corresponde.");
    }
    else{
        printf("Nao corresponde.");
    }
}

int main(){
    int x = obter_int_pos_x();
    int y = obter_int_pos();
    ver_num(x, y);
    return 0;
}