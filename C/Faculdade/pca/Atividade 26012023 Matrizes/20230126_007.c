#include <stdio.h>

int i, j, n_cidades;

void gerar_matriz(int matriz[i][j]){
    int lin, col;
    for(lin = 0; lin < i; lin++){
        for(col = 0; col < j; col++) {
            printf("Digite o valor da linha %d e coluna %d: ", (lin + 1), (col + 1));
            scanf("%d", & matriz[lin][col]);
            printf("\n");
        }
    }
}

void gerar_vetor(int vetor[n_cidades]){
    for(i = 0; i < n_cidades; i++){
        printf("Digite o %d° valor: ", (i + 1));
        scanf("%d", & vetor[i]);
    }
}

void calc_itin(int matriz[i][j]){
    printf("Digite o numero de cidades do itinerario: ");
    scanf("%d", & n_cidades);
    int itinerario[n_cidades];
    printf("Digite os valores do itinerario: ");
    printf("\n");
    gerar_vetor(itinerario);
    int ind1 = 0, ind2 = 1;
    int ant = itinerario[ind1], prox = itinerario[ind2], soma = 0;
    while(ind2 < n_cidades){
        soma += matriz[ant][prox];
        ant = prox;
        ind1++;
        ind2++;
        prox = itinerario[ind2];
    }
    printf("O custo do itinerario e: %d", soma);
}

int main() {
    printf("Digite a ordem da matriz: ");
    scanf("%d", & i);
    j = i;
    printf("\n");
    int matrizA[i][j];
    gerar_matriz(matrizA);
    calc_itin(matrizA);
    return 0;
}