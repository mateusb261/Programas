/*
   Curso: Sistemas de Informação
   Disciplina: Algoritmos e Estruturas de Dados 2
   Aluno(a): Alexandre Bruno Mota Dos Santos;   Matrícula: 2015310001
   Aluno(a): Beatriz Damasceno Fernandes;       Matrícula: 2115310003
   Aluno(a): Mateus Bastos Magalhães Mar;       Matrícula: 2215310063
   Aluno(a): Monike Freitas De Sousa;           Matrícula: 2115310040
   Aluno(a): Sabrina Millane Oliveira Da Silva; Matrícula: 1815080041
*/

// Inclui as bibliotecas necessárias
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
#include <fstream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

// Define uma constante para representar o infinito
const int INF = INT_MAX;
// Declara uma variável global para armazenar o tabuleiro do jogo
vector<string> board;

// Define uma classe abstrata para representar uma entidade no jogo
class Entity {
public:
    // Atributos que guardam a posição da entidade
    int x, y;

    // Construtor que recebe a posição inicial da entidade
    Entity(int x_, int y_) : x(x_), y(y_) {}
};

// Define uma classe derivada para representar o jogador
class Player : public Entity {
public:
    // Construtor que recebe a posição inicial do jogador
    Player(int x_, int y_) : Entity(x_, y_) {}
};

// Define uma classe derivada para representar um fantasma
class Ghost : public Entity {
public:
    // Construtor que recebe a posição inicial do fantasma
    Ghost(int x_, int y_) : Entity(x_, y_) {}

    // Método que verifica se o fantasma está adjacente ao jogador
    bool isAdjacent(const Player& player) const {
        return abs(x - player.x) + abs(y - player.y) == 1;
    }

    // Método que move o fantasma pelo tabuleiro
    void move(const vector<vector<int>>& distances, const Player& player, const vector<string>& board) {
        // Se o fantasma estiver adjacente ao jogador, o jogo termina
        if (isAdjacent(player)) {
            cout << "You were caught by a ghost!" << endl;
            exit(0);
        }

        // Caso contrário, o fantasma se move aleatoriamente
        moveRandomly(board);
    }

private:
    // Método auxiliar que move o fantasma aleatoriamente
    void moveRandomly(const vector<string>& board) {
        // Define os possíveis deslocamentos nas quatro direções
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int newX, newY;

        // Escolhe uma direção aleatória que não seja uma parede
        do {
            int dir = rand() % 4;
            newX = x + dx[dir];
            newY = y + dy[dir];
        } while (newX < 0 || newY < 0 || newX >= board.size() || newY >= board[0].size() || board[newX][newY] == '#');

        // Atualiza a posição do fantasma
        x = newX;
        y = newY;
    }
};

// Define uma classe para representar o jogo
class Game {
public:
    // Construtor que inicializa o placar e o estado do jogo
    Game() : score(0), gameOver(false) {}

    // Método que lê o tabuleiro de um arquivo de texto
    void initializeBoard() {
        ifstream file("board.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                board.push_back(line);
            }
            file.close();
        } else {
            cout << "Não foi possível abrir o arquivo." << endl;
        }
    }

    // Método que imprime o tabuleiro na tela
    void printBoard() {
        systemClear();
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                bool ghostPresent = false;
                for (const Ghost& ghost : ghosts) {
                    if (ghost.x == i && ghost.y == j) {
                        cout << 'G';
                        ghostPresent = true;
                        break;
                    }
                }
                if (!ghostPresent) {
                    cout << board[i][j];
                }
            }
            cout << endl;
        }
        cout << "Score: " << score << endl;
    }

    // Método que move o jogador pelo tabuleiro
    void movePlayer(char direction) {
        // Define os possíveis deslocamentos nas quatro direções
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int newX, newY;

        // Calcula a nova posição do jogador de acordo com o comando
        if (direction == 'w') {
            newX = player.x - 1;
            newY = player.y;
        } else if (direction == 's') {
            newX = player.x + 1;
            newY = player.y;
        } else if (direction == 'a') {
            newX = player.x;
            newY = player.y - 1;
        } else if (direction == 'd') {
            newX = player.x;
            newY = player.y + 1;
        }

        // Se a nova posição não for uma parede, move o jogador
        if (board[newX][newY] != '#') {
            board[player.x][player.y] = ' ';
            player.x = newX;
            player.y = newY;
            // Se a nova posição for um fantasma, o jogo termina
            if (board[player.x][player.y] == 'G') {
                cout << "You were caught by a ghost!" << endl;
                gameOver = true;
            // Se a nova posição for um espaço vazio, aumenta o placar
            } else if (board[player.x][player.y] == ' ') {
                board[player.x][player.y] = 'P';
                score++;
            }
        }
    }

    // Método que move os fantasmas pelo tabuleiro
    void moveGhosts(const vector<vector<int>>& distances) {
        for (Ghost& ghost : ghosts) {
            ghost.move(distances, player, board);
        }
    }

    // Método que verifica se o jogo terminou
    bool isGameOver() const {
        return gameOver;
    }

    // Método que verifica se o jogador ganhou o jogo
    bool isGameWon() const {
        return score >= 25; // Define a pontuação necessária para vencer
    }

    // Método que usa o algoritmo de Floyd-Warshall para calcular as distâncias mais curtas entre todos os pares de vértices no labirinto
    vector<vector<int>> floydWarshall() {
        vector<vector<int>> dist(10, vector<int>(10, INF));
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (board[i][j] != '#') {
                    dist[i][j] = 0;
                }
            }
        }

        for (Ghost& ghost : ghosts) {
            dist[ghost.x][ghost.y] = INF;
        }

        for (int k = 0; k < 10; ++k) {
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        return dist;
    }

private:
    // Declara os atributos privados da classe Game
    vector<string> board;
    Player player{1, 1};
    vector<Ghost> ghosts{{1, 8}};
    int score;
    bool gameOver;

#ifdef _WIN32
    // Método que limpa a tela do terminal no Windows
    void systemClear() {
        system("cls");
    }
#else
    // Método que limpa a tela do terminal em outros sistemas operacionais
    void systemClear() {
        cout << "\033[2J\033[1;1H";
    }
#endif
};

// Função principal do programa
int main() {
    // Inicializa a semente do gerador de números aleatórios
    srand(time(0));
    // Cria um objeto da classe Game
    Game game;
    // Inicializa o tabuleiro do jogo
    game.initializeBoard();
    // Imprime o tabuleiro na tela
    game.printBoard();

    // Calcula as distâncias mais curtas entre os vértices do labirinto
    vector<vector<int>> distances = game.floydWarshall();

    // Declara uma variável para armazenar o comando do jogador
    char direction;

    // Enquanto o jogo não terminar, repete o seguinte
    while (!game.isGameOver() && !game.isGameWon()) {
        // Imprime uma mensagem pedindo o comando do jogador (w/a/s/d)
        cout << "Entre com comando (w/a/s/d): ";
        // Lê o comando do teclado e armazena na variável direction
        cin >> direction;

        // Move o jogador de acordo com o comando
        game.movePlayer(direction);
        // Move os fantasmas de acordo com as distâncias calculadas
        game.moveGhosts(distances);
        // Imprime o tabuleiro atualizado na tela
        game.printBoard();
#ifdef _WIN32
        // Aguarda 1 segundo entre cada movimento (no Windows)
        Sleep(1000);
#else
        // Aguarda 1 segundo entre cada movimento (em outros sistemas operacionais)
        usleep(1000000);
#endif
    }

    // Se o jogador ganhou o jogo, imprime uma mensagem de parabéns
    if (game.isGameWon()) {
        cout << "Congratulations! You won!" << endl;
    // Se o jogador perdeu o jogo, imprime uma mensagem de fim de jogo
    } else {
        cout << "Game over! You were caught by a ghost!" << endl;
    }

    // Retorna 0 para indicar que o programa terminou com sucesso
    return 0;
}
