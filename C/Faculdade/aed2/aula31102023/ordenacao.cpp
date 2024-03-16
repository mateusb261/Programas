#include <stdio.h>

void menu_app();
void bubble();	
void insert();
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
	printf("3 - Comparar algoritmos \n");
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
	for (indice = 1; indice < 25; indice++) {
		for (i = 0; i < 24; i++) {
			if (vet[i] > vet[i + 1]) {
				copia = vet[i];
				vet[i] = vet[i + 1];
				vet[i + 1] = copia;
				cont_bubble++;
			}
		}
	}	
}

void insert()
{
	//ordenar vetor
	for(j = 1; j < 25; j++){
		copia_insert = vet[j];
		indice_insert = j;
			
		while(indice_insert > 0 && vet[indice_insert - 1] < copia){
			vet[indice_insert] = vet[indice_insert - 1];
			indice_insert--;
			cont_insert++;
		}
		vet[indice_insert] = copia_insert;
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


main()
{	
	menu_app();
	
}
