#include <stdio.h>

void imprime_vetor(float vet[], float *i_vet, float *f_vet){
    for(; i_vet <= f_vet; i_vet++){
        printf("%.1f\n", *i_vet);
    }
    printf("\n");
}

int main() {
    float vet1[] = { 1.1, 2.2, 3.3,4.4};
    float vet2[] = {5.5,6.6,7.7};
    float vet3[] = {8.8, 9.9};

    float *i_vet1 = &vet1[0];
    float *f_vet1 = &vet1[3];
    float *i_vet2 = &vet2[0];
    float *f_vet2 = &vet2[2];
    float *i_vet3 = &vet3[0];
    float *f_vet3 = &vet3[1];

    imprime_vetor(vet1, i_vet1, f_vet1);
    imprime_vetor(vet2, i_vet2, f_vet2);
    imprime_vetor(vet3, i_vet3, f_vet3);
    return 0;
}
