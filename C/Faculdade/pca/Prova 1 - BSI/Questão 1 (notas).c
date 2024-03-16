#include <stdio.h>

float obter_nota(){
    float nota;
    printf("Digite a nota final do aluno: ");
    scanf("%f", & nota);
    printf("\n");
    return nota;
}

int main(){
    float nota, nota_maior, nota_menor, media_turma, soma_notas = 0;
    int alunos = 1;
    nota = obter_nota();
    if(nota < 0){
        printf("Nenhuma nota foi inserida.");
    }
    while(nota >= 0){
        if(nota > nota_maior){
            nota_maior = nota;
        }
        if(nota < nota_menor || alunos == 1){
            nota_menor = nota;
        }
        soma_notas += nota;
        media_turma = soma_notas / alunos;
        alunos++;
        nota = obter_nota();
        if(nota < 0){
            printf("A maior nota e: %.2f \n", nota_maior);
            printf("A menor nota e: %.2f \n", nota_menor);
            printf("A media simples da turma e: %.2f", media_turma);
        }
    }
    return 0;
}
