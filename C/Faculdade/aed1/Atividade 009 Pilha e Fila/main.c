#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define ESPACO '0'
#define PAREDE '1'
#define CAMINHO_PERCORRIDO '2'
#define CAMINHO_CORRETO '3'
#define BECO_SEM_SAIDA '4'

typedef struct {
    int x, y;
} Posicao;

typedef struct {
    Posicao *dados;
    int topo;
    int capacidade;
} Pilha;

Pilha *criarPilha(int capacidade) {
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->dados = (Posicao *)malloc(capacidade * sizeof(Posicao));
    pilha->topo = -1;
    pilha->capacidade = capacidade;
    return pilha;
}

void empilhar(Pilha *pilha, Posicao pos) {
    if (pilha->topo < pilha->capacidade - 1) {
        pilha->dados[++pilha->topo] = pos;
    }
}

Posicao desempilhar(Pilha *pilha) {
    if (pilha->topo >= 0) {
        return pilha->dados[pilha->topo--];
    }
    Posicao pos = {-1, -1}; // Retorna posição inválida para indicar erro
    return pos;
}

int resolverLabirinto(char labirinto[TAM][TAM], Posicao inicio, Posicao saida) {
    Pilha *pilha = criarPilha(TAM * TAM);
    empilhar(pilha, inicio);

    while (pilha->topo >= 0) {
        Posicao atual = desempilhar(pilha);

        if (atual.x == saida.x && atual.y == saida.y) {
            labirinto[atual.x][atual.y] = CAMINHO_CORRETO;
            return 1;
        }

        if (labirinto[atual.x][atual.y] == ESPACO) {
            labirinto[atual.x][atual.y] = CAMINHO_PERCORRIDO;

            // Movimento para cima
            if (atual.x - 1 >= 0 && labirinto[atual.x - 1][atual.y] == ESPACO) {
                Posicao proximo = {atual.x - 1, atual.y};
                empilhar(pilha, proximo);
            }
            // Movimento para baixo
            if (atual.x + 1 < TAM && labirinto[atual.x + 1][atual.y] == ESPACO) {
                Posicao proximo = {atual.x + 1, atual.y};
                empilhar(pilha, proximo);
            }
            // Movimento para a esquerda
            if (atual.y - 1 >= 0 && labirinto[atual.x][atual.y - 1] == ESPACO) {
                Posicao proximo = {atual.x, atual.y - 1};
                empilhar(pilha, proximo);
            }
            // Movimento para a direita
            if (atual.y + 1 < TAM && labirinto[atual.x][atual.y + 1] == ESPACO) {
                Posicao proximo = {atual.x, atual.y + 1};
                empilhar(pilha, proximo);
            }
        } else {
            labirinto[atual.x][atual.y] = BECO_SEM_SAIDA;
        }
    }

    return 0;
}

void imprimirLabirinto(char labirinto[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%c ", labirinto[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char labirinto[TAM][TAM] = {
        "1111111111",
        "0010000011",
        "1010111011",
        "1000000111",
        "1110110000",
        "1111111111",
        "1111111111",
        "1111111111",
        "1111111111",
        "1111111111"
    };

    Posicao inicio = {1, 0};
    Posicao saida = {1, TAM - 1};

    if (resolverLabirinto(labirinto, inicio, saida)) {
        printf("Labirinto resolvido:\n");
        imprimirLabirinto(labirinto);
    } else {
        printf("Não foi possível encontrar uma solução.\n");
    }

    return 0;
}
