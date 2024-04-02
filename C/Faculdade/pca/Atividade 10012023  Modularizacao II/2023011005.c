#include <stdio.h>
#include <math.h>

int conv_bin_dec(int x_bin){
    int x_dec = 0, x_bin_fat = 0, exp_fat = 0;

    while(x_bin > 0){
        x_bin_fat = x_bin % 10;
        x_bin/=10;
        x_dec += x_bin_fat * pow(2, exp_fat);
        exp_fat++;
    }
    return x_dec;
}


int main() {
    int x_bin, x_dec;
    printf("Digite um numero binario: ");
    scanf("%d", & x_bin);
    x_dec = conv_bin_dec(x_bin);
    printf("O numero binario %d em base decimal e %d", x_bin, x_dec);
    return 0;
}