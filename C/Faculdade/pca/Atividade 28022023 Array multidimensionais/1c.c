#include <stdio.h>
#include <string.h>

int main() {
    char nomes[2][6][120] = {{"jorge", "marcos", "ana", "maria", "alice", "sara"}, {"clarice", "amanda", "guilherme", "josué", "francisco", "paulo"}};
    char sexo[2][6] = {{'m', 'm', 'f', 'f', 'f', 'f'}, {'f', 'f', 'm', 'm', 'm', 'm'}};
    int notas[2][6] = {{9, 10, 8, 10, 7, 6}, {10, 9, 7, 7, 8, 10}};
    int i, cont_meni1 = 0, cont_meni2 = 0;
    char carac_alea;

    for(i = 0; i < 6; i++){

        strcpy(& carac_alea, & sexo[0][i]);

        if(carac_alea == 'f'){

            cont_meni1++;
        }
    }

    for(i = 0; i < 6; i++){

        strcpy(& carac_alea, & sexo[1][i]);

        if(carac_alea == 'f'){

            cont_meni2++;
        }
    }

    if(cont_meni1 > cont_meni2)

        printf("A equipe 1 tem a maior quantidade de alunas");

    if(cont_meni1 < cont_meni2)

        printf("A equipe 2 tem a maior quantidade de alunas");

    return 0;
}
