#include <stdio.h>
#include <string.h>
#include <math.h>

int ver_palindromo(char frase[]) {

    int frase_orig_s_esp[100], tam_orig = strlen(frase), i1 = 0, i2 = 0;
    while (i1 <= tam_orig) {
        if ((i1 < tam_orig) && (frase[i1] != ' ')) {
            frase_orig_s_esp[i2] = frase[i1];
            i2++;
        }
        if (i1 == tam_orig) {
            frase_orig_s_esp[i2] = '\0';
        }
        i1++;
    }

    int frase_inv_s_esp[100];
    i1 = strlen(frase) - 1;
    i2 = 0;
    while (i1 >= 0) {
        if ((i1 >= 0) && (frase[i1] != ' ')) {
            frase_inv_s_esp[i2] = frase[i1];
            i2++;
        }
        if (i1 == 0) {
            frase_inv_s_esp[i2] = '\0';
        }
        i1--;
    }

    int len_s_esp = strlen(frase_orig_s_esp), cont_carac_ig = 0;
    i1 = 0;
    int equiv;
    while(i1 < len_s_esp){
        equiv = frase_orig_s_esp[i1] - frase_inv_s_esp[i1];
        equiv = fabs(equiv);
        if((frase_orig_s_esp[i1] == frase_inv_s_esp[i1]) || (equiv == 32))
            cont_carac_ig++;
        i1++;
    }
    int ret;
    (cont_carac_ig == len_s_esp)? (ret = 1): (ret = 0);
    return ret;
}

int main(){
    char frase[100];
    printf("Digite uma frase: ");
    gets(frase);
    int res_palindromo = ver_palindromo(frase);
    (res_palindromo == 1)? printf("A frase fornecida e um palindromo") : printf("A frase fornecida nao e um palindromo");
    return 0;
}
