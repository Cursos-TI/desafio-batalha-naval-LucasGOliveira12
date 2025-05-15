#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para imprimir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se é possível posicionar um navio (horizontal, vertical ou diagonal)
int podePosicionar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha;
        int c = coluna;

        if (orientacao == 'H') {
            c += i;
        } else if (orientacao == 'V') {
            l += i;
        } else if (orientacao == 'D') {
            l += i;
            c += i;
        } else if (orientacao == 'I') { // Diagonal inversa (descendo à esquerda)
            l += i;
            c -= i;
        }

        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO || tabuleiro[l][c] != 0) {
            return 0; // Fora dos limites ou sobreposição
        }
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha;
        int c = coluna;

        if (orientacao == 'H') {
            c += i;
        } else if (orientacao == 'V') {
            l += i;
        } else if (orientacao == 'D') {
            l += i;
            c += i;
        } else if (orientacao == 'I') {
            l += i;
            c -= i;
        }

        tabuleiro[l][c] = 3; // 3 representa uma parte do navio
    }
}

int main() {
    // Inicializa o tabuleiro com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Dados dos quatro navios
    // Navio 1: Horizontal
    int linha1 = 2, coluna1 = 3;
    char orient1 = 'H';

    // Navio 2: Vertical
    int linha2 = 5, coluna2 = 6;
    char orient2 = 'V';

    // Navio 3: Diagonal principal (↘)
    int linha3 = 0, coluna3 = 0;
    char orient3 = 'D';

    // Navio 4: Diagonal inversa (↙)
    int linha4 = 0, coluna4 = 9;
    char orient4 = 'I';

    // Tenta posicionar os navios
    if (podePosicionar(tabuleiro, linha1, coluna1, orient1)) {
        posicionarNavio(tabuleiro, linha1, coluna1, orient1);
    } else {
        printf("Erro ao posicionar o navio 1.\n");
    }

    if (podePosicionar(tabuleiro, linha2, coluna2, orient2)) {
        posicionarNavio(tabuleiro, linha2, coluna2, orient2);
    } else {
        printf("Erro ao posicionar o navio 2.\n");
    }

    if (podePosicionar(tabuleiro, linha3, coluna3, orient3)) {
        posicionarNavio(tabuleiro, linha3, coluna3, orient3);
    } else {
        printf("Erro ao posicionar o navio 3 (diagonal).\n");
    }

    if (podePosicionar(tabuleiro, linha4, coluna4, orient4)) {
        posicionarNavio(tabuleiro, linha4, coluna4, orient4);
    } else {
        printf("Erro ao posicionar o navio 4 (diagonal inversa).\n");
    }

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    
    return 0;
}
