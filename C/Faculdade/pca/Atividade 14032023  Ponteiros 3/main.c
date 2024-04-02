#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mediaDesvio(float pont_vetor[], int num_elem_vetor, float *media_alunos, float *desvio_padrao){
    int i = 0;
    float *pont_variavel = pont_vetor, soma = 0, media, desvio, soma_desvio = 0, base_pot;
    while (i < num_elem_vetor){
        soma += *pont_variavel;
        pont_variavel++;
        i++;
    }

    media = soma / num_elem_vetor;
    *media_alunos = media;

    i = 1;
    pont_variavel = pont_vetor;
    while (i <= num_elem_vetor){
        base_pot = (*pont_variavel - media);
        soma_desvio += pow(base_pot, 2);
        pont_variavel++;
        i++;
    }
    soma_desvio /= num_elem_vetor;
    desvio = sqrt(soma_desvio);
    *desvio_padrao = desvio;
}

int main(){
    int num_alunos;
    float *notas_alunos, *media_alunos, *desvio_padrao;
    printf("Digite o numero de alunos: ");
    scanf("%d", &num_alunos);
    notas_alunos = (float *) malloc(num_alunos * sizeof(float));

    int i;
    for (i = 0; i < num_alunos; i++){
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &notas_alunos[i]);
    }

    mediaDesvio(notas_alunos, num_alunos, media_alunos, desvio_padrao);
    return 0;
}