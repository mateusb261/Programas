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

int obter_int_pos_y(int x){
    int n;
    do{
        printf("Digite um numero inteiro positivo para y: ");
        scanf("%d", & n);
        printf("\n");
        if(n <= 0 || n <= x){
            printf("Entrada invalida. Digite um numero inteiro positivo maior que x para y.");
            printf("\n");
        }
    } while(n <= 0 || n <= x);
    return n;
}


void ver_segmento(int x, int y){
    int fatores_x = 0, fatores_y = 0, y_fatores = y, x_fatores = x, fatores_y_red = 0, y_fat_red_esq = y, y_a_red_dir, fatores_y_loop_esq, fatores_y_loop_dir, y_quo_red_esq;
    int y_a_red_esq = y;
    int potencia;
    while(y_fatores > 0){
        y_fatores /= 10;
        fatores_y++;
    }
    while(x_fatores > 0){
        x_fatores /= 10;
        fatores_x++;
    }
    fatores_y_loop_esq = fatores_y;
    fatores_y_red = fatores_y;
    fatores_y_red--;
    y_fat_red_esq = y;
    y_a_red_esq = y;
    while(fatores_y_loop_esq > fatores_x){
        potencia = pow(10, fatores_y_red);
        y_fat_red_esq = y_a_red_esq / potencia;
        y_quo_red_esq = potencia;
        y_a_red_esq = y_a_red_esq % (y_fat_red_esq * y_quo_red_esq);
        fatores_y_red--;
        fatores_y_loop_esq--;
        fatores_y_loop_dir = fatores_y_loop_esq;
        y_a_red_dir = y_a_red_esq;
        while(fatores_y_loop_dir >= fatores_x){
            if(y_a_red_dir == x) {
                printf("%d e segmento de %d.", x, y);
                return;
            }
            y_a_red_dir /= 10;
            fatores_y_loop_dir--;
        }
    }
    if(1 != 0)
        printf("%d nao e segmento de %d.", x, y);
}

int main() {
    int x, y;
    x = obter_int_pos_x();
    y = obter_int_pos_y(x);
    ver_segmento(x, y);
    return 0;
}