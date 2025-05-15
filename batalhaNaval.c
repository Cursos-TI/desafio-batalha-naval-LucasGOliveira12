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

// Função para verificar se é possível posicionar o navio
int podePosicionar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + (orientacao == 'V' ? i : 0);
        int c = coluna + (orientacao == 'H' ? i : 0);

        if (l >= TAMANHO_TABULEIRO || c >= TAMANHO_TABULEIRO || tabuleiro[l][c] != 0) {
            return 0; // Fora do tabuleiro ou já ocupado
        }
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + (orientacao == 'V' ? i : 0);
        int c = coluna + (orientacao == 'H' ? i : 0);
        tabuleiro[l][c] = 3; // 3 representa uma parte do navio
    }
}

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    // Inicializa o tabuleiro com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas definidas no código
    int linhaNavio1 = 2, colunaNavio1 = 3; // Navio horizontal
    int linhaNavio2 = 5, colunaNavio2 = 6; // Navio vertical

    // Verifica e posiciona o navio horizontal
    if (podePosicionar(tabuleiro, linhaNavio1, colunaNavio1, 'H')) {
        posicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, 'H');
    } else {
        printf("Erro ao posicionar o navio horizontal.\n");
    }

    // Verifica e posiciona o navio vertical
    if (podePosicionar(tabuleiro, linhaNavio2, colunaNavio2, 'V')) {
        posicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, 'V');
    } else {
        printf("Erro ao posicionar o navio vertical.\n");
    }

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
