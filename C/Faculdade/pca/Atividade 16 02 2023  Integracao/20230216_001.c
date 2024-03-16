#include <stdio.h>

char jogadores[23][120] = {{"HUGO SOUZA"}, {"MATHEUS SOUZA"}, {"SANTOS"}, {"DAVID LUIZ"}, {"FABRICIO BRUNO"}, {"PABLO"}, {"MATHEUZINHO"}, {"VARELA"}, {"FELIPE LUIS"}, {"AYRTON LUCAS"}, {"ARTURO VIDAL"}, {"THIAGO MAIA"}, {"ERICK"}, {"GERSON"}, {"EVERTON RIBEIRO"}, {"DE ARRASCAETA"}, {"VICTOR HUGO"}, {"MATHEUS FRANÇA"}, {"GABI"}, {"BRUNO HENRIQUE"}, {"PEDRO"}, {"MARINHO"}, {"EVERTON"}};
char funcoes[23][120] = {{"Goleiro"}, {"Goleiro"}, {"Goleiro"}, {"Defesa"}, {"Defesa"}, {"Defesa"}, {"Defesa"}, {"Defesa"}, {"Defesa"}, {"Defesa"}, {"Meio Campo"}, {"Meio Campo"}, {"Meio Campo"}, {"Meio Campo"}, {"Meio Campo"}, {"Meio Campo"}, {"Meio Campo"}, {"Meio Campo"}, {"Atacante"}, {"Atacante"}, {"Atacante"}, {"Atacante"}, {"Atacante"}};
int avaliacoes[] = {9, 9, 10, 10, 9, 4, 5, 8, 6, 7, 9, 10, 4, 9, 8, 7, 5, 6, 10, 8,9, 7, 6};
int escalacao[11], i_esc = 0;


void formar_esc_inter(int inicio, int fim, int n_jog){

    int i_inicial = inicio, i_final = fim, maior, i_maior, menor = avaliacoes[0], elem_var;

    // encontra o menor elemento da lista de avaliações no intervalo dado:

    for (i_inicial = inicio; i_inicial < fim; i_inicial++){

        elem_var = avaliacoes[i_inicial];
        if (elem_var < menor)
            menor = avaliacoes[i_inicial];
    }

    // encontra o maior elemento da lista de avaliações no intervalo dado:

    maior = menor;

    for (i_inicial = inicio; i_inicial < fim; i_inicial++){

        elem_var = avaliacoes[i_inicial];
        if (elem_var > maior) {
            maior = avaliacoes[i_inicial];
            i_maior = i_inicial;
        }
    }

    /* por fim, adiciona na lista de escalação final os
     * jogadores com maior pontuação no intervalo dado: */

    escalacao[i_esc] = i_maior;
    maior = menor;
    int cont_carac = 0, var_contr = fim - 1, intervalo = fim - inicio, v_atual = escalacao[i_esc], cont_jog = 0, i_atual;

    while ((cont_carac < intervalo) && (cont_jog < n_jog)){

        i_inicial = inicio;
        while ((i_inicial < fim) && (cont_jog < n_jog)){

            elem_var = avaliacoes[i_inicial];
            i_atual = escalacao[i_esc];
            v_atual = avaliacoes[i_atual];

            if ((elem_var > maior) && (elem_var < v_atual)) {

                maior = avaliacoes[i_inicial];
                i_maior = i_inicial;
            }

            if (i_inicial == var_contr){

                i_esc++;
                escalacao[i_esc] = i_maior;
                i_inicial = fim;
                maior = menor;
                cont_jog++;
            }
            i_inicial++;
        }
        cont_carac++;
    }
}

void criar_e_impr_esc(){

    /* função para adicionar os melhores jogadores com suas
     * respectivas funções nos intervalos dados, com intervalo
     * fechado à esquerda e aberto à direita */

    formar_esc_inter(0, 3, 1);
    formar_esc_inter(3, 10, 4);
    formar_esc_inter(10, 18, 4);
    formar_esc_inter(18, 24, 2);

    int i_final = 0;

    for (i_esc = 0; i_esc < 11; i_esc++) {

        i_final = escalacao[i_esc];
        printf("%s - %s\n", jogadores[i_final], funcoes[i_final]);
    }
}

int main(){

    criar_e_impr_esc();
    return 0;
}