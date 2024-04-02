#include <stdio.h>

void gerar_vetor(int vetor[], int *tam, int *i){
    *i = 0;
    int v_i = *i, v_tam = *tam;
    for(; v_i < v_tam; v_i++){
        printf("Digite a coordenada %d do vetor: ", (v_i + 1));
        scanf("%d", & vetor[v_i]);
    }
    printf("\n");
}

int soma_vet(int vetor1[], int vetor2[], int *tam1, int *tam2){
    int v_tam1 = *tam1, v_tam2 = *tam2;

    if(v_tam1 != v_tam2)
        return 0;
    else{
        int vetor_soma[v_tam1], soma, *pont_v = &vetor_soma[0], *pont_f = &vetor_soma[v_tam1], *pont_v1 = &vetor1[0], *pont_v2 = &vetor2[0];
        while(pont_v < pont_f) {
            soma = *pont_v1 + *pont_v2;
            *pont_v = soma;
            pont_v1++;
            pont_v2++;
            pont_v++;
        }
        return 1;
    }
}

int main() {
    int i, tam1, tam2;
    printf("Digite o tamanho do primeiro vetor: ");
    scanf("%d", &tam1);
    printf("\n");

    int vetor1[tam1];
    gerar_vetor(vetor1, &tam1, &i);

    printf("Digite o tamanho do segundo vetor: ");
    scanf("%d", &tam2);
    printf("\n");
    int vetor2[tam2];
    gerar_vetor(vetor2, &tam2, &i);

    soma_vet(vetor1, vetor2, &tam1, &tam2);
    return 0;
}
