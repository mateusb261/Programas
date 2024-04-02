#include <stdio.h>

int matriz[][100], tam_conj[100];

int main() {
    int n, cont1 = 0, cont2 = 0, tam;
    printf("Digite o numero de conjuntos de numeros inteiros: ");
    scanf("%d", & n);
    printf("\n");

    while (cont1 < n){

        printf("Digite o numero de elementos do conjunto: ");
        scanf("%d", & tam);
        tam_conj[cont1] = tam;
        printf("\n");

        while (cont2 < tam){

            printf("Digite o valor %d do conjunto %d: ", (cont2 + 1), (cont1 + 1));
            scanf("%d", & matriz[cont1][cont2]);
            cont2++;
        }
        printf("\n");
        cont2 = 0;
        cont1++;
    }

    int m_inter[100], cont_m1, cont_elem_ig = 0, i_m_inter = 0, tam_conj1 = tam_conj[0], tam_conj_var, elem_m1, elem_var, n_m = n - 1, cont_ig = 0, n_elem_v_inter = 0;

    for (cont_m1 = 0; cont_m1 < tam_conj1; cont_m1++){

        elem_m1 = matriz[0][cont_m1];

        for (cont1 = 1; cont1 < n; cont1++){

            tam_conj_var = tam_conj[cont1];
            for (cont2 = 0; cont2 < tam_conj_var; cont2++){

                elem_var = matriz[cont1][cont2];
                if (elem_m1 == elem_var && (cont_ig < 1)){

                    cont_elem_ig++;
                    cont_ig++;
                }
                if (cont_elem_ig == n_m) {

                    m_inter[i_m_inter] = matriz[0][cont_m1];
                    i_m_inter++;
                    cont2 = tam_conj_var;
                    n_elem_v_inter++;
                }
            }
            cont_ig = 0;
        }
        cont_elem_ig = 0;
    }

    printf("O vetor interseccao dos conjuntos fornecidos e: ");

    for (cont1 = 0; cont1 < n_elem_v_inter; cont1++){

        printf("%d", m_inter[cont1]);
    }
    return 0;
}
