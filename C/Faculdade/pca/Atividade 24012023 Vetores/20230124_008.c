#include <stdio.h>

int i, tam, n_vet = 1;

void gerar_vetores(int vetor[]){
    for(i = 0; i < tam; i++){
        printf("Digite a coordenada %d do vetor %d: ", (i + 1), n_vet);
        scanf("%d", & vetor[i]);
        printf("\n");
    }
}

void obter_prod(int vetor1[], int vetor2[]){
    i = 0;
    int prod_esc = 0;
    for(; i < tam; i++){
        prod_esc += vetor1[i] * vetor2[i];
    }
    printf("O produto escalar dos vetores e %d", prod_esc);
}

int main(){

    printf("Digite a dimensão dos vetores: ");
    scanf("%d", & tam);
    int vetor1[tam];
    int vetor2[tam];
    gerar_vetores(vetor1);
    n_vet++;
    gerar_vetores(vetor2);
    obter_prod(vetor1, vetor2);
    return 0;
}