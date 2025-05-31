#include <stdio.h>

// Desafio Batalha Naval - Nível novato

int main(){

    int tabuleiro [10][10];
    // Inicializando o tabuleiro com 0 (água)

    for(int i= 0; i < 10; i++){
        for(int j= 0; j < 10; j++){
            tabuleiro [i][j] = 0;
        }
    }
    printf("Exibindo o tabuleiro\n");
    
      for(int i= 0; i < 10; i++){
        for(int j= 0; j < 10; j++){
            printf("%d", tabuleiro [i][j]);
        }
        printf("\n");
    }

    // Declarando os navios com 3 posições cada
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    // Escolhendo coordenadas iniciais
    int linhaNavioH = 2; // linha inicial para o navio horizontal
    int colunaNavioH = 4; // coluna inicial

    int linhaNavioV = 6; // linha inicial para o navio vertical
    int colunaNavioV = 1; // coluna inicial

    // Posicionando navio horizontal (garantindo que caiba no tabuleiro)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaNavioH][colunaNavioH + i] = navioHorizontal[i];
    }

    // Posicionando navio vertical (garantindo que caiba no tabuleiro)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaNavioV + i][colunaNavioV] = navioVertical[i];
    }

    // Exibindo o tabuleiro
    printf("Tabuleiro Batalha Naval com Navios:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    // Exibindo o tabuleiro
    printf("Tabuleiro Batalha Naval:\n\n");

    // Imprimindo cabeçalho das colunas
    printf("   ");
    for (int j = 0; j < 10; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    // Imprimindo linha separadora
    printf("  +");
    for (int j = 0; j < 10; j++) {
        printf("---");
    }
    printf("+\n");

    // Imprimindo o tabuleiro com índice das linhas
    for (int i = 0; i < 10; i++) {
        printf("%2d|", i);
        for (int j = 0; j < 10; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("|\n");
    }

    // Imprimindo linha separadora inferior
    printf("  +");
    for (int j = 0; j < 10; j++) {
        printf("---");
    }
    printf("+\n");

    

    return 0;
}