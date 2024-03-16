#include <stdio.h>

void conv_dec_bin(int x_dec){
    int x_bin_var = 0, x_div_2 = x_dec;
    while(x_div_2 > 0){
        x_bin_var = x_div_2 % 2;
        x_div_2 /= 2;
        printf("%d", x_bin_var);
    }
    printf(" e o numero %d em binario", x_dec);
}


int main() {
    int x_bin, x_dec;
    printf("Digite um numero decimal: ");
    scanf("%d", & x_dec);
    conv_dec_bin(x_dec);

    return 0;
}