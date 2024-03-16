#include <stdio.h>

void menu_app();
void bubble();
void insert();
void selection();
void Quick_Sort(int Left, int Right);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void Quick_Sort(int Left, int Right);
void shellSort(int numbers[], int tamanho);
void countSort(int a[], int n);
void heapSort();
void imprimir();


int menu;
int i, j, indice, indice_insert, copia, copia_insert;
int cont_insert=0;
int cont_bubble=0;
int cont_comp=0, cont_troca=0;

int vet[10] = {78, 12, 35, 1, 17, 4, 43, 11, 17, 1};


void menu_app(){
	//menu
	printf("\n \n");
	printf("************************************************** \n");
	printf("1 - Bubble \n");
	printf("2 - Insert \n");
    printf("3 - Selection \n");
    printf("4 - Quick \n");
    printf("5 - Merge \n");
    printf("6 - Shell \n");
    printf("7 - Counting \n");
    printf("8 - Heap \n");
	printf("9 - Comparar algoritmos \n");
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

                printf("O número de comparações do Bubble é: %d\n", cont_comp);

                printf("O número de comparações do Bubble é: %d\n", cont_troca);

                cont_comp=0;
                cont_troca=0;

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

                printf("O número de comparações do Selection é: %d\n", cont_comp);

                cont_comp=0;

				menu_app();
			}
			break;

        case 4:
			{
				printf("Execucao do Quick \n");

				Quick_Sort(0, 24);

				imprimir();

				menu_app();
			}
			break;

        case 5:
			{
				printf("Execucao do Merge \n");

				mergeSort(vet, 0, 24);

				imprimir();

				menu_app();
			}
			break;

        case 6:
			{
				printf("Execucao do Shell \n");

				shellSort(vet, 25);

				imprimir();

				menu_app();
			}
			break;

        case 7:
			{
				printf("Execucao do Counting \n");

				countSort(vet, 25);

				imprimir();

				menu_app();
			}
			break;

        case 8:
			{
				printf("Execucao do Heap \n");

				heapSort();

				imprimir();

				menu_app();
			}
			break;

		case 9:
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
        if (vet[contador_pos] > vet[contador_pos + 1])
        {
            temp = vet[contador_pos];
            vet[contador_pos] = vet[contador_pos + 1];
            vet[contador_pos + 1] = temp;

            contador_mud++;

            cont_troca++;
        }

        cont_comp++;

        contador_pos++;

        if (contador_pos == 9)
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

    while (contador_pos <= 10)
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

        imprimir();

        contador_pos++;
        v_cont_pos = vet[contador_pos];
        v_cont_pos_ant = vet[contador_pos - 1];
    }
}

void selection()
{
    i = 0;
    int menor, achou_menor, temp, ind_menor;

    while (i < 9)
    {
        menor = vet[i];

        for (j = i + 1; j <= 9; j++)
        {
            if (vet[j] < menor)
            {
                menor = vet[j];
                ind_menor = j;
                achou_menor = 1;
            }

            cont_comp++;
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

void Quick_Sort(int Left, int Right) {

    int Aux, Pivor, L, R;

    L = Left;
    R = Right;
    Pivor = vet[(Left + Right) / 2];

    while(L <= R) {
        while(vet[L] < Pivor && L < Right) {
            L++;
        }
        while(vet[R] > Pivor && R > Left) {
            R--;
        }
        if(L <= R) {
            Aux = vet[L];
            vet[L] = vet[R];
            vet[R] = Aux;
            L++;
            R--;
        }
    }

    if(R > Left) {
        Quick_Sort(Left, R);
    }

    if(L < Right) {
        Quick_Sort(L, Right);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Criar vetores temporarios
    int L[n1], R[n2];

    // Copiar dados para vetores temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Mesclar os vetores temporários de volta em vet[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copie os elementos restantes de L[] se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copie os elementos restantes de R[] se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l é para o índice esquerdo e r é o índice direito do subvetor a ser ordenado
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        // Classifique a primeira e a segunda metades
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void shellSort(int numbers[], int array_size)
{
    int i, j, increment, temp;

    increment = 3;
    while (increment > 0)
    {
        for (i=0; i < array_size; i++)
        {
            j = i;
            temp = numbers[i];
            while ((j >= increment) && (numbers[j-increment] > temp))
            {
                numbers[j] = numbers[j - increment];
                j = j - increment;
            }
            numbers[j] = temp;
        }
        if (increment/2 != 0)
            increment = increment/2;
        else if (increment == 1)
            increment = 0;
        else
            increment = 1;
    }
}

int getMax(int a[], int n) {
   int max = a[0];
   for(int i = 1; i<n; i++) {
      if(a[i] > max)
         max = a[i];
   }
   return max; //maximum element from the array
}

void countSort(int a[], int n) // function to perform counting sort
{
   int output[n+1];
   int max = getMax(a, n);
   int count[max+1]; //create count array with size [max+1]


  for (int i = 0; i <= max; ++i)
  {
    count[i] = 0; // Initialize count array with all zeros
  }




  for (int i = 0; i < n; i++) // Store the count of each element
  {
    count[a[i]]++;

  }



   for(int i = 1; i<=max; i++)
	{

      count[i] += count[i-1]; //find cumulative frequency
	}

  /* This loop will find the index of each element of the original array in count array, and
   place the elements in output array*/
  for (int i = n - 1; i >= 0; i--) {
    output[count[a[i]] - 1] = a[i];
    count[a[i]]--; // decrease count for same numbers

  }



   for(int i = 0; i<n; i++) {
      a[i] = output[i]; //store the sorted elements into main array

   }



}

void heapify(int n, int i) {
      int temp;
      int largest = i;
      int l = 2 * i + 1;
      int r = 2 * i + 2;

      if (l < n && vet[l] > vet[largest])
         largest = l;

      if (r < n && vet[r] > vet[largest])
         largest = r;

      if (largest != i) {
         temp = vet[i];
         vet[i] = vet[largest];
         vet[largest] = temp;

 		 imprimir();

         heapify(n, largest);
      }
   }

void heapSort() {
   int temp;

   for (int i = 25 / 2 - 1; i >= 0; i--)
      heapify(25, i);

   for (int i = 25 - 1; i >= 0; i--) {
      temp = vet[0];
      vet[0] = vet[i];
      vet[i] = temp;

	  imprimir();

      heapify(i, 0);
   }
}

void imprimir()
{
	printf("\n");

	//imprimir
	printf("\n Elementos do array em ordem crescente: \n");
	for (i = 0; i < 10; i++) {
		printf("%4d", vet[i]);
	}

    printf("\n");
}


int main()
{
	menu_app();

}
