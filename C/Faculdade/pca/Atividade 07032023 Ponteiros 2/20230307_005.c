#include <stdio.h>

int impr_ord (int *v1, int *v2, int *v3){
    int vet[3] = {*v1, *v2, *v3}, i1, i2, menor, lim = 2, temp;

    for (i1 = 0; i1 < lim; i1++) {
        for (i2 = i1; i2 < 3; i2++) {
            if (vet[i2] < vet[i1]) {
                temp = vet[i1];
                menor = vet[i2];
                vet[i1] = menor;
                vet[i2] = temp;
            }
        }
    }

    int *pont_v = &vet[0], *pont_f = &vet[2];
    printf("Os valores fornecidos em ordem ascendente sao: ");
    for(; pont_v <= pont_f; pont_v++)
        printf("%d ", *pont_v);

    int v_retor;
    if ((vet[0] == vet[1]) && (vet[1] == vet[2]))
        v_retor = 1;
    else
        v_retor = 0;

    return v_retor;
}

int main() {
    int v1, v2, v3;
    printf("Digite um numero: ");
    scanf("%d", &v1);
    printf("\nDigite outro numero: ");
    scanf("%d", &v2);
    printf("\nDigite outro numero: ");
    scanf("%d", &v3);

    impr_ord(&v1, &v2, &v3);
    return 0;
}
