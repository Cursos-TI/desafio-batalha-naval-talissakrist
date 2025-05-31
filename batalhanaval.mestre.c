#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval - Nível Mestre

#define TAM 10       // Tamanho do tabuleiro
#define TAM_HAB 5    // Tamanho das matrizes de habilidade

/**
 * Função para inicializar o tabuleiro com água (0)
 */
void inicializaTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;  // Água
        }
    }
}

/**
 * Função para posicionar um navio horizontalmente
 */
void posicionaNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (coluna + i < TAM) {
            tabuleiro[linha][coluna + i] = 3;  // Navio
        }
    }
}

/**
 * Função para posicionar um navio verticalmente
 */
void posicionaNavioVertical(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (linha + i < TAM) {
            tabuleiro[linha + i][coluna] = 3;  // Navio
        }
    }
}

/**
 * Função para posicionar um navio na diagonal principal
 */
void posicionaNavioDiagonalPrincipal(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (linha + i < TAM && coluna + i < TAM) {
            tabuleiro[linha + i][coluna + i] = 3;  // Navio
        }
    }
}

/**
 * Função para posicionar um navio na diagonal secundária
 */
void posicionaNavioDiagonalSecundaria(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (linha + i < TAM && coluna - i >= 0) {
            tabuleiro[linha + i][coluna - i] = 3;  // Navio
        }
    }
}

/**
 * Função para criar a matriz de habilidade Cone
 * O cone se expande a partir do topo para a base.
 */
void criaHabilidadeCone(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // A condição cria uma forma triangular simétrica (cone)
            if (abs(j - TAM_HAB / 2) <= i) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

/**
 * Função para criar a matriz de habilidade Cruz
 * Uma linha e uma coluna atravessam o centro.
 */
void criaHabilidadeCruz(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

/**
 * Função para criar a matriz de habilidade Octaedro
 * Visualmente parece um losango.
 */
void criaHabilidadeOctaedro(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

/**
 * Função para aplicar a habilidade sobre o tabuleiro
 * Centraliza a matriz de habilidade no ponto de origem.
 */
void aplicaHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    int offset = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linha = origemLinha + i - offset;
            int coluna = origemColuna + j - offset;

            // Garante que não sairá dos limites do tabuleiro
            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (habilidade[i][j] == 1) {
                    // Não sobrescreve navio
                    if (tabuleiro[linha][coluna] == 0) {
                        tabuleiro[linha][coluna] = 5;  // Área de efeito
                    }
                }
            }
        }
    }
}

/**
 * Função para exibir o tabuleiro
 * Utiliza diferentes caracteres para água, navio e área de habilidade.
 */
void exibeTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("~ ");  // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("N ");  // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("* ");  // Área de habilidade
            }
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    // Inicializa o tabuleiro
    inicializaTabuleiro(tabuleiro);

    // Posicionamento de 4 navios: 2 ortogonais, 2 diagonais
    posicionaNavioHorizontal(tabuleiro, 1, 1, 4);
    posicionaNavioVertical(tabuleiro, 3, 5, 4);
    posicionaNavioDiagonalPrincipal(tabuleiro, 5, 1, 3);
    posicionaNavioDiagonalSecundaria(tabuleiro, 6, 8, 3);

    // Criação das matrizes de habilidade
    criaHabilidadeCone(cone);
    criaHabilidadeCruz(cruz);
    criaHabilidadeOctaedro(octaedro);

    // Aplicação das habilidades no tabuleiro
    aplicaHabilidade(tabuleiro, cone, 2, 2);      // Origem do cone
    aplicaHabilidade(tabuleiro, cruz, 5, 5);      // Origem da cruz
    aplicaHabilidade(tabuleiro, octaedro, 7, 7);  // Origem do octaedro

    // Exibe o tabuleiro final
    exibeTabuleiro(tabuleiro);

    return 0;
}