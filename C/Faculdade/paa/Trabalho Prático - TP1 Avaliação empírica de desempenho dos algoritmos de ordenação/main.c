#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar um array de inteiros aleatórios
void geraArrayAleatorio(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        array[i] = rand() % 65536; // Números entre 0 e 65535
    }
}

// Implementação do Mergesort
void merge(int *array, int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    // Criação de arrays temporários
    int L[n1], R[n2];

    // Copia os dados para os arrays temporários L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = array[esquerda + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[meio + 1 + j];

    // Merge dos arrays temporários de volta para array[]
    int i = 0; // Índice inicial do primeiro subarray
    int j = 0; // Índice inicial do segundo subarray
    int k = esquerda; // Índice inicial do subarray mesclado

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver algum
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver algum
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int *array, int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        mergesort(array, esquerda, meio);
        mergesort(array, meio + 1, direita);
        merge(array, esquerda, meio, direita);
    }
}

// Implementação do Heapsort
void heapify(int *array, int tamanho, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    // Encontra o maior entre o pai e os filhos
    if (esquerda < tamanho && array[esquerda] > array[maior])
        maior = esquerda;
    if (direita < tamanho && array[direita] > array[maior])
        maior = direita;

    // Se o maior não for o pai, troca e chama heapify recursivamente
    if (maior != i) {
        int temp = array[i];
        array[i] = array[maior];
        array[maior] = temp;
        heapify(array, tamanho, maior);
    }
}

void heapsort(int *array, int tamanho) {
    // Constrói o heap (reorganiza o array)
    for (int i = tamanho / 2 - 1; i >= 0; i--)
        heapify(array, tamanho, i);

    // Extrai elementos do heap um por um
    for (int i = tamanho - 1; i > 0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        // Chama heapify na subárvore reduzida
        heapify(array, i, 0);
    }
}

// Implementação do Quicksort
int partition(int *array, int baixo, int alto) {
    int pivo = array[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (array[j] < pivo) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[alto];
    array[alto] = temp;

    return (i + 1);
}

void quicksort(int *array, int baixo, int alto) {
    if (baixo < alto) {
        int pi = partition(array, baixo, alto);
        quicksort(array, baixo, pi - 1);
        quicksort(array, pi + 1, alto);
    }
}

int main() {
    int tamanho = 1000000; // Exemplo de tamanho de entrada
    int *array = malloc(tamanho * sizeof(int));

    // Geração do array aleatório
    geraArrayAleatorio(array, tamanho);

    /*
    // Imprime o vetor gerado
    printf("Vetor gerado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
     */

    // Medição do tempo de execução do Quicksort
    clock_t inicioQuicksort = clock();
    quicksort(array, 0, tamanho - 1);
    clock_t fimQuicksort = clock();
    double tempoQuicksort = (double)(fimQuicksort - inicioQuicksort) / CLOCKS_PER_SEC;
    printf("Tempo de execução do Quicksort: %.6f segundos\n", tempoQuicksort);


    // Medição do tempo de execução do Mergesort
    clock_t inicioMergesort = clock();
    mergesort(array, 0, tamanho - 1);
    clock_t fimMergesort = clock();
    double tempoMergesort = (double)(fimMergesort - inicioMergesort) / CLOCKS_PER_SEC;
    printf("Tempo de execução do Mergesort: %.6f segundos\n", tempoMergesort);

    // Medição do tempo de execução do Heapsort
    clock_t inicioHeapsort = clock();
    heapsort(array, tamanho);
    clock_t fimHeapsort = clock();
    double tempoHeapsort = (double)(fimHeapsort - inicioHeapsort) / CLOCKS_PER_SEC;
    printf("Tempo de execução do Heapsort: %.6f segundos\n", tempoHeapsort);


    // Repetir para outros tamanhos de entrada e calcular médias e desvios padrão...

    free(array);
    return 0;
}