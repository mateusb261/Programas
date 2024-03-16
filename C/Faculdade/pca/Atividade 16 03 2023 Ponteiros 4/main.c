#include <stdio.h>
#include <stdlib.h>

void gerar_vetor(int pont_vetor[], int *pont_tam){
    int i = 0;
    while (i < *pont_tam){
        printf("Digite a coordenada %d do vetor: ", (i + 1));
        scanf("%d", &pont_vetor[i]);
        i++;
    }
}

void maior_menor(int pont_vetor[], int *pont_tam){

    int i, v_maior_v = pont_vetor[0], v_menor_v = pont_vetor[0], v_valor_var;

    for (i = 0; i < *pont_tam; i++){
        v_valor_var = pont_vetor[i];
        if (v_valor_var < v_menor_v){
            v_menor_v = pont_vetor[i];
        }
    }

    for (i = 0; i < *pont_tam; i++){
        v_valor_var = pont_vetor[i];
        if (v_valor_var > v_maior_v){
            v_maior_v = pont_vetor[i];
        }
    }
    printf("O maior valor do vetor fornecido e: %d\n", v_maior_v);
    printf("O menor valor do vetor fornecido e: %d", v_menor_v);
}

int main() {
    int *pont_vetor, *pont_tam, num_elem;
    printf("Digite o numero de elementos do vetor: ");
    scanf("%d", &num_elem);
    printf("\n");
    pont_tam = &num_elem;
    pont_vetor = (int *) malloc(num_elem * sizeof(int));

    gerar_vetor(pont_vetor, pont_tam);

    maior_menor(pont_vetor, pont_tam);
    free(pont_vetor);
    return 0;
}
