#include <stdio.h>
#include <string.h>

int main() {
    char nomes[2][6][120] = {{"jorge", "marcos", "ana", "maria", "alice", "sara"}, {"clarice", "amanda", "guilherme", "josué", "francisco", "paulo"}};
    char sexo[2][6] = {{'m', 'm', 'f', 'f', 'f', 'f'}, {'f', 'f', 'm', 'm', 'm', 'm'}};
    int notas[2][6] = {{9, 10, 8, 10, 7, 6}, {10, 9, 7, 7, 8, 10}};
    char projeto[12][120];
    int i, j, nota_var, i_proj = 0, n_meninas = 0;
    char ver_sexo;

    for(i = 0; i < 2; i++){

        for(j = 0; j < 6; j++){

            nota_var = notas[i][j];
            strcpy(& ver_sexo, & sexo[i][j]);

            if((nota_var >= 8) && (ver_sexo == 'f')){

                printf("Digite o nome '%s' a seguir: ", nomes[i][j]);
                gets(projeto[i_proj]);
                i_proj++;
                n_meninas++;
            }
        }
    }

    return 0;
}
