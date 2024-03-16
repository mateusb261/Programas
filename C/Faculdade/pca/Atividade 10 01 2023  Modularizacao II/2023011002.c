#include <stdio.h>

void ver_perm(int x, int y){
    int cont_perm = 0, x2 = x, y2 = y, x_fatores = x, y_fatores = y, resto_x, resto_y, fatores_x = 0, fatores_y = 0;
    while(x_fatores > 0){
        x_fatores /= 10;
        fatores_x++;
    }
    x_fatores = fatores_x;
    while(y_fatores > 0){
        y_fatores /= 10;
        fatores_y++;
    }
    y_fatores = fatores_y;
    while(fatores_x > 0){
        resto_x = x2 % 10;
        x2 /= 10;
        while(fatores_y > 0){
            resto_y = y2 % 10;
            y2 /= 10;
            if(resto_x == resto_y) {
                cont_perm++;
                break;
            }
            fatores_y--;
        }
        fatores_y = y_fatores;
        y2 = y;
        fatores_x--;
    }

    if((cont_perm == x_fatores) && (cont_perm == y_fatores)) {
        printf("%d e permutacao de %d", x, y);
    }
    else {
        printf("%d nao e permutacao de %d", x, y);
    }
}

int main() {
    int x, y;
    printf("Digite dois inteiros: ");
    scanf("%d %d", & x, & y);
    ver_perm(x, y);
    return 0;
}