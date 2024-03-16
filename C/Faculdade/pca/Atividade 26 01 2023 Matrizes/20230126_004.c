#include <stdio.h>

int i = 3, j = 3;

void gerar_matriz(int matriz[i][j]){
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++) {
            printf("Digite o valor da linha %d e coluna %d: ", (i + 1), (j + 1));
            scanf("%d", & matriz[i][j]);
            printf("\n");
        }
    }
}

void pesq_valor(int matriz1[i][j], int pesquisar){
    int val_variavel;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            val_variavel = matriz1[i][j];
            if(val_variavel == pesquisar) {
                printf("O valor %d foi encontrado na linha %d e coluna %d da matriz", pesquisar, (i + 1), (j + 1));
                return;
            }
        }
    }
    printf("não encontrado");
}

int main() {
    int matrizA[3][3], pesquisar;
    gerar_matriz(matrizA);
    printf("Digite um valor a procurar na matriz fornecida: ");
    scanf("%d", & pesquisar);
    pesq_valor(matrizA, pesquisar);
    return 0;
}