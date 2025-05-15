#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define NAVIO 3
#define HABILIDADE 5

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0)
                printf("0 ");
            else if (tabuleiro[i][j] == NAVIO)
                printf("3 ");
            else if (tabuleiro[i][j] == HABILIDADE)
                printf("5 ");
        }
        printf("\n");
    }
}

int podePosicionar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    for (int i = 0; i < 3; i++) {
        int l = linha;
        int c = coluna;

        if (orientacao == 'H') c += i;
        else if (orientacao == 'V') l += i;
        else if (orientacao == 'D') { l += i; c += i; }
        else if (orientacao == 'I') { l += i; c -= i; }

        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO || tabuleiro[l][c] != 0)
            return 0;
    }
    return 1;
}

void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    for (int i = 0; i < 3; i++) {
        int l = linha;
        int c = coluna;

        if (orientacao == 'H') c += i;
        else if (orientacao == 'V') l += i;
        else if (orientacao == 'D') { l += i; c += i; }
        else if (orientacao == 'I') { l += i; c -= i; }

        tabuleiro[l][c] = NAVIO;
    }
}

void aplicarOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemLinha, int origemColuna) {
    int matriz[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    int centroLinha = 1;
    int centroColuna = 2;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (matriz[i][j] == 1) {
                int l = origemLinha + (i - centroLinha);
                int c = origemColuna + (j - centroColuna);
                if (l >= 0 && l < TAMANHO_TABULEIRO && c >= 0 && c < TAMANHO_TABULEIRO && tabuleiro[l][c] == 0)
                    tabuleiro[l][c] = HABILIDADE;
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posiciona navios
    if (podePosicionar(tabuleiro, 2, 3, 'H'))
        posicionarNavio(tabuleiro, 2, 3, 'H');
    if (podePosicionar(tabuleiro, 5, 6, 'V'))
        posicionarNavio(tabuleiro, 5, 6, 'V');
    if (podePosicionar(tabuleiro, 0, 0, 'D'))
        posicionarNavio(tabuleiro, 0, 0, 'D');
    if (podePosicionar(tabuleiro, 0, 9, 'I'))
        posicionarNavio(tabuleiro, 0, 9, 'I');

    // Aplica habilidade octaedro no ponto (5,3)
    aplicarOctaedro(tabuleiro, 5, 3);

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
