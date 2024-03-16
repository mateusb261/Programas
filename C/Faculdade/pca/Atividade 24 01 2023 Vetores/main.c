#include <stdio.h>

void gerar_vetor(int vetor[], int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("Digite a coordenada %d do vetor: ", (i + 1));
        scanf("%d", & vetor[i]);
        printf("\n");
    }
}

void ord_vetor(int vetor[], int tam){
    int i1, i2, menor, lim = tam - 1, temp;
    for(i1 = 0; i1 < lim; i1++){
        for(i2 = i1; i2 < tam; i2++){
            if(vetor[i2] < vetor[i1]) {
                temp = vetor[i1];
                menor = vetor[i2];
                vetor[i1] = menor;
                vetor[i2] = temp;
            }
        }
    }
}

int main(){
    int i, tam;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", & tam);
    int vetor[tam];
    gerar_vetor(vetor, tam);
    ord_vetor(vetor, tam);
    printf("Os elementos do vetor fornecido em ordem ascendente sao: ");
    for(i = 0; i < tam; i++)
        printf("%d ", vetor[i]);
    return 0;
}
