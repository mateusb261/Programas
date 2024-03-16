#include <stdio.h>

void menu_app();
void bubble();
void insert();
void selection();
void imprimir();


int menu;
int i, j, indice, indice_insert, copia, copia_insert;
int cont_insert=0;
int cont_bubble=0;


int vet[25] = {45,5,72,19,28,34,18,98,10,25,8,74,43,2,68,14,22,31,13,4,11,35,58,84,24};


void menu_app(){
	//menu
	printf("\n \n");
	printf("************************************************** \n");
	printf("1 - Bubble \n");
	printf("2 - Insert \n");
    printf("3 - Selection \n");
	printf("4 - Comparar algoritmos \n");
	printf("Faca a sua escolha \n");
	printf("************************************************** \n \n");
	scanf("%d", &menu);

	switch(menu)
	{
		case 1:
			{
				printf("Execucao do Bubble \n");

				bubble();

				imprimir();

				menu_app();
			}
			break;

		case 2:
			{
				printf("Execucao do Insert \n");

				insert();

			    imprimir();

				printf("\n");

				menu_app();
			}
			break;

        case 3:
			{
				printf("Execucao do Selection \n");

				selection();

				imprimir();

				menu_app();
			}
			break;

		case 4:
			{
				cont_bubble=0;
				cont_insert=0;
				printf("Execucao do comparativo \n");

				bubble();
				insert();

				printf("\n");
				printf("Foram realizadas %d trocas no bubble \n", cont_bubble);
				printf("Foram realizadas %d trocas no insert \n", cont_insert);


				menu_app();
			}
			break;

		default:
			{
				printf("Opcao invalida");
			}
			break;
	}


}

void bubble()
{
    int condicao = 1, temp, contador_pos = 0, contador_mud = 0;
    i = 0;

    while (condicao == 1)
    {
        if (vet[contador_pos] < vet[contador_pos + 1])
        {
            temp = vet[contador_pos];
            vet[contador_pos] = vet[contador_pos + 1];
            vet[contador_pos + 1] = temp;

            contador_mud++;
        }

        contador_pos++;

        if (contador_pos == 24)
        {
            if (contador_mud > 0)
            {
                contador_mud = 0;
            } else
            {
                condicao = 0;
            }

            contador_pos = 0;
        }
    }
}

void insert()
{
	//ordenar vetor
	int temp1, temp_primeiro, contador_pos = 1, contador_reatr, pos_var, v_cont_pos = vet[contador_pos], v_cont_pos_ant = vet[contador_pos - 1], v_pos_var;

    while (contador_pos <= 25)
    {

        if (v_cont_pos < v_cont_pos_ant)
        {
            pos_var = contador_pos;
            temp1 = vet[contador_pos];
            v_pos_var = vet[pos_var - 1];

            while (temp1 < v_pos_var && pos_var > 0) { pos_var--; v_pos_var = vet[pos_var - 1]; }

            contador_reatr = pos_var;

            while (contador_reatr <= contador_pos)
            {

                if (contador_reatr == pos_var){
                    temp_primeiro = vet[contador_reatr];
                    vet[contador_reatr] = temp1;
                }

                else {
                    temp1 = vet[contador_reatr];
                    vet[contador_reatr] = temp_primeiro;
                    temp_primeiro = temp1;
                }

                contador_reatr++;
            }
        }

        contador_pos++;
        v_cont_pos = vet[contador_pos];
        v_cont_pos_ant = vet[contador_pos - 1];
    }
}

void selection()
{
    i = 0;
    int menor, achou_menor, temp, ind_menor;

    while (i < 24)
    {
        menor = vet[i];

        for (j = i + 1; j <= 24; j++)
        {
            if (vet[j] < menor)
            {
                menor = vet[j];
                ind_menor = j;
                achou_menor = 1;
            }
        }

        if (achou_menor == 1)
        {
            temp = vet[i];
            vet[i] = menor;
            vet[ind_menor] = temp;

            achou_menor = 0;
        }

        i++;
    }
}

void imprimir()
{
	printf("\n");

	//imprimir
	printf("\n Elementos do array em ordem crescente: \n");
	for (i = 0; i < 25; i++) {
		printf("%4d", vet[i]);
	}
}


int main()
{
	menu_app();

}
