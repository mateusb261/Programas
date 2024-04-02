#include <stdio.h>
#include <string.h>

int main() {
    char equipes[2][3][120];
    int i, j;
    for (i = 0; i < 2; i++){
        for (j = 0; j < 3; j++){
            printf("Digite o nome do aluno %d da equipe %d: ", (j + 1), (i + 1));
            gets(equipes[i][j]);
        }
    }
    char nome[120];
    printf("Digite o nome de um dos integrantes de uma das equipes: ");
    gets(nome);
    char * achou;
    for (i = 0; i < 2; i++){
        for (j = 0; j < 3; j++){
            achou = strstr(equipes[i][j], nome);
            if (achou != NULL) {
                printf("O aluno '%s' esta na equipe %d", nome, (i + 1));
                j = 3;
            }
        }
        if (achou != NULL)
            i = 2;
    }
    return 0;
}