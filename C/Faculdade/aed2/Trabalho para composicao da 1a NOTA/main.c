/*
   Curso: Sistemas de Informação
   Disciplina: Algoritmos e Estruturas de Dados 2
   Aluno(a): Beatriz Damasceno Fernandes;  Matrícula: 2115310003
   Aluno(a): Mateus Bastos Magalhães Mar;  Matrícula: 2215310063
   Aluno(a): Monike Freitas De Sousa;      Matrícula: 2115310040
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetores_aleatórios.h" // Importa os vetores em ordem aleatória
#include "vetores_crescentes.h" // Importa os vetores em ordem crescente

long unsigned int comparacoes = 0; // Contador de comparações
long unsigned int movimentacoes = 0; // Contador de movimentações
int operacao; // Operação escolhida pelo usuário no menu principal
int *pont_vetor; // Ponteiro para o vetor escolhido pelo usuário

void imprime_vetor(int *vetor, int n); // Função que imprime um vetor
int* copiar_vetor(int vetor_global[], int tam); // Função que copia o vetor global para um vetor local

void bubble_sort(int vetor[], int n); // Função para ordenar um vetor usando bubble sort
void selection_sort(int vetor[], int n); // Função para ordenar um vetor usando selection sort
void insertion_sort(int vetor[], int n); // Função para ordenar um vetor usando insertion sort
void shell_sort(int vetor[], int n); // Função para ordenar um vetor usando shell sort
void quick_sort(int vetor[], int inicio, int fim); // Função para ordenar um vetor usando quick sort
void heap_sort(int vetor[], int n); // Função para ordenar um vetor usando heap sort
void merge_sort(int vetor[], int inicio, int fim); // Função para ordenar um vetor usando merge sort


// Função para retornar o tipo de ordem desejado pelo usuário
int tipo_ordem(){
    int tipo;

    printf("\n \n");
	printf("************************************************** \n");
	printf("Escolha a ordem original do vetor: \n\n");
	printf("1 - Aleatório \n");
    printf("2 - Ordenado \n");
	printf("************************************************** \n \n");
	scanf("%d", &tipo);

    return tipo;
}

// Função que obtêm a referência do vetor escolhido pelo usuário e retorna o seu tamanho
int get_vetor(int tipo_ordem){
    int num_vetor, tamanho;

    if (tipo_ordem == 1) {

        do {
            printf("\n \n");
            printf("************************************************** \n");
            printf("Escolha o tamanho do vetor: \n\n");
            printf("1 - 100 \n");
            printf("2 - 1000 \n");
            printf("3 - 10000 \n");
            printf("4 - 100000 \n");
            printf("************************************************** \n \n");
            scanf("%d", &num_vetor);
        } while(num_vetor != 1 && num_vetor != 2 && num_vetor != 3 && num_vetor != 4);

        switch (num_vetor) {

            case 1: {
                pont_vetor = copiar_vetor(aleat_100, 100);
                tamanho = 100;
            }
                break;

            case 2: {
                pont_vetor = copiar_vetor(aleat_1000, 1000);
                tamanho = 1000;
            }
                break;

            case 3: {
                pont_vetor = copiar_vetor(aleat_10000, 10000);
                tamanho = 10000;
            }
                break;

            case 4: {
                pont_vetor = copiar_vetor(aleat_100000, 100000);
                tamanho = 100000;
            }
                break;
        }
    }

    else if (tipo_ordem == 2) {
        do {
            printf("\n \n");
            printf("************************************************** \n");
            printf("Escolha o tamanho do vetor: \n\n");
            printf("1 - 100 \n");
            printf("2 - 1000 \n");
            printf("3 - 10000 \n");
            printf("4 - 100000 \n");
            printf("************************************************** \n \n");
            scanf("%d", &num_vetor);
            } while(num_vetor != 1 && num_vetor != 2 && num_vetor != 3 && num_vetor != 4);

        switch (num_vetor) {

            case 1: {
                pont_vetor = copiar_vetor(orden_100, 100);
                tamanho = 100;
            }
                break;

            case 2: {
                pont_vetor = copiar_vetor(orden_1000, 1000);
                tamanho = 1000;
            }
                break;

            case 3: {
                pont_vetor = copiar_vetor(orden_10000, 10000);
                tamanho = 10000;
            }
                break;

            case 4: {
                pont_vetor = copiar_vetor(orden_100000, 100000);
                tamanho = 100000;
            }
                break;
        }
    }

    return tamanho;
}

// Função para executar um dos algoritmos de ordenação de acordo com a escolha do usuário
void executar_sort(int operacao, int tamanho){
    clock_t inicio, fim;

    double tempo;

    // Inicia a contagem do tempo
    inicio = clock();

    // Executa um dos algoritmos de ordenação a seguir de acordo com a escolha do usuário
    switch (operacao) {

        case 1: {
            // Ordena o vetor usando bubble sort
            bubble_sort(pont_vetor, tamanho);
        }
            break;

        case 2: {
            // Ordena o vetor usando selection sort
            selection_sort(pont_vetor, tamanho);
        }
            break;

        case 3: {
            // Ordena o vetor usando insertion sort
            insertion_sort(pont_vetor, tamanho);
        }
            break;

        case 4: {
            // Ordena o vetor usando shell sort
            shell_sort(pont_vetor, tamanho);
        }
            break;

        case 5: {
            // Ordena o vetor usando quick sort
            quick_sort(pont_vetor, 0, tamanho - 1);
        }
            break;

        case 6: {
            // Ordena o vetor usando heap sort
            heap_sort(pont_vetor, tamanho);
        }
            break;

        case 7: {
            // Ordena o vetor usando merge sort
            merge_sort(pont_vetor, 0, tamanho - 1);
        }
            break;
    }

    // Finaliza a contagem do tempo
    fim = clock();

    // Calcula o tempo em segundos
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // Imprime os resultados
    printf("Tempo de execução: %f segundos\n", tempo);
    printf("Número de comparações: %d\n", comparacoes);
    printf("Número de movimentações: %d\n", movimentacoes);
}

/* Função principal do programa, que pergunta do usuário qual algoritmo de ordenação deseja usar, pergunta o tipo de
 * ordem do vetor a ser ordenado, e se deseja imprimir o vetor antes e depois de executar o algoritmo de ordenação
*/
void menu_principal(){
	//operacao
	printf("\n \n");
	printf("************************************************** \n");
    printf("Escolha o operacao de ordenação: \n\n");
	printf("1 - BubbleSort \n");
	printf("2 - SelectSort \n");
    printf("3 - InsertSort \n");
    printf("4 - ShellSort \n");
    printf("5 - QuickSort \n");
    printf("6 - HeapSort  \n");
    printf("7 - MergeSort  \n");
	printf("************************************************** \n \n");
	scanf("%d", &operacao);

	switch(operacao)
	{
		case 1:
			{
				printf("Execucao do BubbleSort \n\n");

				int ordem = tipo_ordem();
                int tamanho = get_vetor(ordem);

                int imprimir;


                do{
                    printf("Deseja imprimir o vetor antes da operação? \n\n");
                    printf("1 - Sim \n");
	                printf("0 - Não \n\n");

                    scanf("%d", &imprimir);

                    if (imprimir != 0 && imprimir != 1) {
                        printf("Opção inválida \n");
                    }
                } while (imprimir != 0 && imprimir != 1);


                if (imprimir == 1){
                    imprime_vetor(pont_vetor, tamanho);
                }

                executar_sort(operacao, tamanho);

                do{
                    printf("Deseja imprimir o vetor depois da operação? \n\n");
                    printf("1 - Sim \n");
	                printf("0 - Não \n\n");

                    scanf("%d", &imprimir);

                    if (imprimir != 0 && imprimir != 1) {
                        printf("Opção inválida \n");
                    }
                } while (imprimir != 0 && imprimir != 1);


                if (imprimir == 1){
                    imprime_vetor(pont_vetor, tamanho);
                }

                comparacoes = 0;
                movimentacoes = 0;

                menu_principal();
			}
			break;

		case 2:
			{
				printf("Execucao do SelectSort \n\n");

                int ordem = tipo_ordem();
                int tamanho = get_vetor(ordem);

                int imprimir;


                do{
                    printf("Deseja imprimir o vetor antes da operação? \n\n");
                    printf("1 - Sim \n");
	                printf("0 - Não \n\n");

                    scanf("%d", &imprimir);

                    if (imprimir != 0 && imprimir != 1) {
                        printf("Opção inválida \n");
                    }
                } while (imprimir != 0 && imprimir != 1);


                if (imprimir == 1){
                    imprime_vetor(pont_vetor, tamanho);
                }

                executar_sort(operacao, tamanho);

                do{
                    printf("Deseja imprimir o vetor depois da operação? \n\n");
                    printf("1 - Sim \n");
	                printf("0 - Não \n\n");

                    scanf("%d", &imprimir);

                    if (imprimir != 0 && imprimir != 1) {
                        printf("Opção inválida \n");
                    }
                } while (imprimir != 0 && imprimir != 1);


                if (imprimir == 1){
                    imprime_vetor(pont_vetor, tamanho);
                }

                comparacoes = 0;
                movimentacoes = 0;

                menu_principal();
			}

			break;

        case 3:
			{
				printf("Execucao do InsertSort \n\n");

				int ordem = tipo_ordem();
                int tamanho = get_vetor(ordem);

                int imprimir;


                do{
                    printf("Deseja imprimir o vetor antes da operação? \n\n");
                    printf("1 - Sim \n");
	                printf("0 - Não \n\n");

                    scanf("%d", &imprimir);

                    if (imprimir != 0 && imprimir != 1) {
                        printf("Opção inválida \n");
                    }
                } while (imprimir != 0 && imprimir != 1);


                if (imprimir == 1){
                    imprime_vetor(pont_vetor, tamanho);
                }

                executar_sort(operacao, tamanho);

                do{
                    printf("Deseja imprimir o vetor depois da operação? \n\n");
                    printf("1 - Sim \n");
	                printf("0 - Não \n\n");

                    scanf("%d", &imprimir);

                    if (imprimir != 0 && imprimir != 1) {
                        printf("Opção inválida \n");
                    }
                } while (imprimir != 0 && imprimir != 1);


                if (imprimir == 1){
                    imprime_vetor(pont_vetor, tamanho);
                }

                comparacoes = 0;
                movimentacoes = 0;

                menu_principal();
			}
			break;

        case 4:
			{
				printf("Execucao do ShellSort \n\n");

				int ordem = tipo_ordem();
                int tamanho = get_vetor(ordem);

                int imprimir;


                do{
                    printf("Deseja imprimir o vetor antes da operação? \n\n");
                    printf("1 - Sim \n");
	                printf("0 - Não \n\n");

                    scanf("%d", &imprimir);

                    if (imprimir != 0 && imprimir != 1) {
                        printf("Opção inválida \n");
                    }
                } while (imprimir != 0 && imprimir != 1);


                if (imprimir == 1){
                    imprime_vetor(pont_vetor, tamanho);
                }

                executar_sort(operacao, tamanho);

                do{
                    printf("Deseja imprimir o vetor depois da operação? \n\n");
                    printf("1 - Sim \n");
	                printf("0 - Não \n\n");

                    scanf("%d", &imprimir);

                    if (imprimir != 0 && imprimir != 1) {
                        printf("Opção inválida \n");
                    }
                } while (imprimir != 0 && imprimir != 1);


                if (imprimir == 1){
                    imprime_vetor(pont_vetor, tamanho);
                }

                comparacoes = 0;
                movimentacoes = 0;

                menu_principal();
			}
			break;

        case 5:
			{
				printf("Execucao do QuickSort \n\n");

				int ordem = tipo_ordem();
                int tamanho = get_vetor(ordem);

                int imprimir;


                do{
                    printf("Deseja imprimir o vetor antes da operação? \n\n");
                    printf("1 - Sim \n");
	                printf("0 - Não \n\n");

                    scanf("%d", &imprimir);

                    if (imprimir != 0 && imprimir != 1) {
                        printf("Opção inválida \n");
                    }
                } while (imprimir != 0 && imprimir != 1);


                if (imprimir == 1){
                    imprime_vetor(pont_vetor, tamanho);
                }

                executar_sort(operacao, tamanho);

                do{
                    printf("Deseja imprimir o vetor depois da operação? \n\n");
                    printf("1 - Sim \n");
	                printf("0 - Não \n\n");

                    scanf("%d", &imprimir);

                    if (imprimir != 0 && imprimir != 1) {
                        printf("Opção inválida \n");
                    }
                } while (imprimir != 0 && imprimir != 1);


                if (imprimir == 1){
                    imprime_vetor(pont_vetor, tamanho);
                }

                comparacoes = 0;
                movimentacoes = 0;

                menu_principal();
			}
			break;

        case 6:
			{
				printf("Execucao do HeapSort  \n\n");

				int ordem = tipo_ordem();
                int tamanho = get_vetor(ordem);

                int imprimir;


                do{
                    printf("Deseja imprimir o vetor antes da operação? \n\n");
                    printf("1 - Sim \n");
	                printf("0 - Não \n\n");

                    scanf("%d", &imprimir);

                    if (imprimir != 0 && imprimir != 1) {
                        printf("Opção inválida \n");
                    }
                } while (imprimir != 0 && imprimir != 1);


                if (imprimir == 1){
                    imprime_vetor(pont_vetor, tamanho);
                }

                executar_sort(operacao, tamanho);

                do{
                    printf("Deseja imprimir o vetor depois da operação? \n\n");
                    printf("1 - Sim \n");
	                printf("0 - Não \n\n");

                    scanf("%d", &imprimir);

                    if (imprimir != 0 && imprimir != 1) {
                        printf("Opção inválida \n");
                    }
                } while (imprimir != 0 && imprimir != 1);


                if (imprimir == 1){
                    imprime_vetor(pont_vetor, tamanho);
                }

                comparacoes = 0;
                movimentacoes = 0;

                menu_principal();
			}
			break;

        case 7:
			{
				printf("Execucao do MergeSort  \n\n");

				int ordem = tipo_ordem();
                int tamanho = get_vetor(ordem);

                int imprimir;


                do{
                    printf("Deseja imprimir o vetor antes da operação? \n\n");
                    printf("1 - Sim \n");
	                printf("0 - Não \n\n");

                    scanf("%d", &imprimir);

                    if (imprimir != 0 && imprimir != 1) {
                        printf("Opção inválida \n");
                    }
                } while (imprimir != 0 && imprimir != 1);


                if (imprimir == 1){
                    imprime_vetor(pont_vetor, tamanho);
                }

                executar_sort(operacao, tamanho);

                do{
                    printf("Deseja imprimir o vetor depois da operação? \n\n");
                    printf("1 - Sim \n");
	                printf("0 - Não \n\n");

                    scanf("%d", &imprimir);

                    if (imprimir != 0 && imprimir != 1) {
                        printf("Opção inválida \n");
                    }
                } while (imprimir != 0 && imprimir != 1);


                if (imprimir == 1){
                    imprime_vetor(pont_vetor, tamanho);
                }

                comparacoes = 0;
                movimentacoes = 0;

                menu_principal();
			}
			break;

		default:
			{
				printf("Opcao invalida");
			}
			break;
	}


}


// Função para ordenar um vetor usando bubble sort
void bubble_sort(int vetor[], int n) {
  int i, j, aux;
  // Percorre o vetor n - 1 vezes
  for (i = 0; i < n - 1; i++) {
    // Compara cada elemento com o seu sucessor
    for (j = i + 1; j < n; j++) {
      // Incrementa o número de comparações
      comparacoes++;
      // Se o elemento atual for maior que o próximo, troca de posição
      if (vetor[i] > vetor[j]) {
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
        // Incrementa o número de movimentações
        movimentacoes++;
      }
    }
  }
}

// Função para ordenar um vetor usando selection sort
void selection_sort(int vetor[], int n) {
  int i, j, min, aux;
  // Percorre o vetor da primeira até a penúltima posição
  for (i = 0; i < n - 1; i++) {
    // Assume que o elemento atual é o menor
    min = i;
    // Procura o menor elemento nas posições restantes
    for (j = i + 1; j < n; j++) {
      // Incrementa o número de comparações
      comparacoes++;
      // Se encontrar um elemento menor que o atual, atualiza o índice do menor
      if (vetor[j] < vetor[min]) {
        min = j;
      }
    }
    // Se o índice do menor for diferente do atual, troca de posição
    if (min != i) {
      aux = vetor[min];
      vetor[min] = vetor[i];
      vetor[i] = aux;
      // Incrementa o número de movimentações
      movimentacoes++;
    }
  }
}

// Função para ordenar um vetor usando insertion sort
void insertion_sort(int vetor[], int n) {
  int i, j, k, aux;
  // Percorre o vetor da segunda posição até a última
  for (i = 1; i < n; i++) {
    aux = vetor[i]; // Guarda o elemento atual
    // Procura a posição correta para inserir o elemento atual
    for (j = 0; j < i; j++) {
      // Incrementa o número de comparações
      comparacoes++;
      // Se o elemento atual for menor que o elemento da posição j, interrompe o loop
      if (aux < vetor[j]) {
        break;
      }
    }
    // Move os elementos maiores que o elemento atual para a direita
    for (k = i; k > j; k--) {
      vetor[k] = vetor[k - 1];
      // Incrementa o número de movimentações
      movimentacoes++;
    }
    // Insere o elemento atual na posição correta
    vetor[j] = aux;
  }
}

// Função para ordenar um vetor usando shell sort
void shell_sort(int vetor[], int n) {
  int i, j, k, h, aux;
  // Define o intervalo inicial como metade do tamanho do vetor
  h = n / 2;
  // Repete o processo até que o intervalo seja menor que 1
  while (h > 0) {
    // Percorre o vetor da posição h até a última
    for (i = h; i < n; i++) {
      aux = vetor[i]; // Guarda o elemento atual
      // Compara o elemento atual com os elementos do intervalo
      for (j = i; j >= h && aux < vetor[j - h]; j -= h) {
        // Incrementa o número de comparações
        comparacoes++;
        // Move o elemento maior para a direita
        vetor[j] = vetor[j - h];
        // Incrementa o número de movimentações
        movimentacoes++;
      }
      // Coloca o elemento atual na posição correta
      vetor[j] = aux;
    }
    // Reduz o intervalo pela metade
    h = h / 2;
  }
}

// Função para trocar dois elementos de um vetor
void troca(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Função para escolher um pivô aleatório
int escolhe_pivo(int inicio, int fim) {
  // Retorna um número entre fim (inclusive) e inicio (inclusive)
  return (rand() % (fim - inicio + 1)) + inicio;
}

// Função para ordenar um vetor usando quick sort
void quick_sort(int vetor[], int inicio, int fim) {
  if (inicio < fim) {
    // Escolhe um pivô aleatório
    int pivo_indice = escolhe_pivo(inicio, fim);
    // Coloca o pivô no fim do vetor
    troca(&vetor[pivo_indice], &vetor[fim]);
    // Define o pivô como o último elemento
    int pivo = vetor[fim];
    // Define o índice da posição inicial
    int i = inicio;
    // Percorre o vetor da posição inicial até a penúltima
    for (int j = inicio; j < fim; j++) {
      // Incrementa o número de comparações
      comparacoes++;
      // Se o elemento atual for menor ou igual ao pivô, troca de posição com o elemento da posição i
      if (vetor[j] <= pivo) {
        troca(&vetor[i], &vetor[j]);
        // Incrementa o número de movimentações
        movimentacoes++;
        // Incrementa o índice da posição i
        i++;
      }
    }
    // Coloca o pivô na posição correta
    troca(&vetor[i], &vetor[fim]);
    // Incrementa o número de movimentações
    movimentacoes++;
    // Ordena as partes esquerda e direita do pivô
    quick_sort(vetor, inicio, i - 1);
    quick_sort(vetor, i + 1, fim);
  }
}

// Função para ajustar o heap com raiz em 'i'
void ajusta_heap(int vetor[], int n, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    // Comparação com o filho da esquerda
    if (esquerda < n && vetor[esquerda] > vetor[maior]) {
        comparacoes++;
        maior = esquerda;
    }

    // Comparação com o filho da direita
    if (direita < n && vetor[direita] > vetor[maior]) {
        comparacoes++;
        maior = direita;
    }

    // Se o maior não é a raiz
    if (maior != i) {
        movimentacoes++;
        // Troca a raiz com o maior elemento
        troca(&vetor[i], &vetor[maior]);

        // Recursivamente ajusta o subárvore afetado
        ajusta_heap(vetor, n, maior);
    }
}

// Função principal que realiza o heap sort
void heap_sort(int vetor[], int n) {
    // Constrói o heap (reorganiza o array)
    for (int i = n / 2 - 1; i >= 0; i--)
        ajusta_heap(vetor, n, i);

    // Extrai elementos um por um do heap
    for (int i = n - 1; i > 0; i--) {
        movimentacoes++;
        // Move a raiz atual para o final
        troca(&vetor[0], &vetor[i]);

        // Chama ajusta_heap no heap reduzido
        ajusta_heap(vetor, i, 0);
    }
}

// Função para combinar dois vetores ordenados em um único vetor ordenado
void merge(int vetor[], int inicio, int meio, int fim) {
  int i = inicio; // Índice do primeiro elemento da primeira metade
  int j = meio + 1; // Índice do primeiro elemento da segunda metade
  int k = 0; // Índice do elemento a ser inserido no vetor auxiliar
  int *aux = malloc(sizeof(int) * (fim - inicio + 1)); // Aloca um vetor auxiliar
  // Percorre as duas metades do vetor, comparando e copiando os elementos em ordem
  while (i <= meio && j <= fim) {
    // Incrementa o número de comparações
    comparacoes++;
    // Se o elemento da primeira metade for menor ou igual ao da segunda, copia ele para o vetor auxiliar
    if (vetor[i] <= vetor[j]) {
      aux[k] = vetor[i];
      i++;
    }
    // Senão, copia o elemento da segunda metade para o vetor auxiliar
    else {
      aux[k] = vetor[j];
      j++;
    }
    // Incrementa o número de movimentações
    movimentacoes++;
    // Incrementa o índice do vetor auxiliar
    k++;
  }
  // Copia os elementos restantes da primeira metade, se houver
  while (i <= meio) {
    aux[k] = vetor[i];
    i++;
    k++;
    // Incrementa o número de movimentações
    movimentacoes++;
  }
  // Copia os elementos restantes da segunda metade, se houver
  while (j <= fim) {
    aux[k] = vetor[j];
    j++;
    k++;
    // Incrementa o número de movimentações
    movimentacoes++;
  }
  // Copia os elementos do vetor auxiliar de volta para o vetor original
  for (i = inicio; i <= fim; i++) {
    vetor[i] = aux[i - inicio];
    // Incrementa o número de movimentações
    movimentacoes++;
  }
  free(aux); // Libera a memória do vetor auxiliar
}

// Função para ordenar um vetor usando merge sort
void merge_sort(int vetor[], int inicio, int fim) {
  // Se o vetor tiver mais de um elemento
  if (inicio < fim) {
    // Calcula o índice do meio do vetor
    int meio = (inicio + fim) / 2;
    // Ordena a primeira metade do vetor
    merge_sort(vetor, inicio, meio);
    // Ordena a segunda metade do vetor
    merge_sort(vetor, meio + 1, fim);
    // Combina as duas metades ordenadas em um único vetor ordenado
    merge(vetor, inicio, meio, fim);
  }
}

// Função para imprimir um vetor
void imprime_vetor(int vetor[], int n) {
  int i;
  printf("[");
  for (i = 0; i < n; i++) {
    printf("%d", vetor[i]);
    if (i < n - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

// Função que copia o vetor global para um vetor local
int* copiar_vetor(int vetor_global[], int tam) {
  int* vetor_local = (int*) malloc(tam * sizeof(int)); //vetor local
  int i; //variável de controle do laço

  //copiando cada elemento do vetor global para o vetor local
  for (i = 0; i < tam; i++) {
    vetor_local[i] = vetor_global[i];
  }

    //retorna a referência do vetor local
    return vetor_local;
}

int main() {
    // Executa o menu principal
    menu_principal();

    return 0;
}
