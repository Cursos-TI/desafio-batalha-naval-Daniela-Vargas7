#include <stdio.h>

int main() {
    // Criação do tabuleiro 10x10 com todas as posições inicializadas com 0 (água)
    int tabuleiro[10][10];

    // Inicializa o tabuleiro com água (valor 0)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Criação dos dois vetores (navios), cada um com 3 posições, valor 3 (representa parte do navio)
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    // Coordenadas iniciais pré-definidas dos navios
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 6;

    // Verifica se os navios cabem no tabuleiro sem ultrapassar os limites
    int posicao_valida_horizontal = (coluna_horizontal + 3 <= 10);
    int posicao_valida_vertical = (linha_vertical + 3 <= 10);

    int sobreposicao = 0; // Variável para detectar sobreposição de navios

    if (posicao_valida_horizontal && posicao_valida_vertical) {
        // Posiciona navio horizontal no tabuleiro
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
        }

        // Verifica se há sobreposição antes de posicionar o navio vertical
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // Posiciona navio vertical no tabuleiro
            for (int i = 0; i < 3; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
            }
        } else {
            printf("Erro: Sobreposição de navios detectada!\n");
            return 1;
        }

    } else {
        printf("Erro: As coordenadas dos navios ultrapassam os limites do tabuleiro!\n");
        return 1;
    }

    // Exibe o tabuleiro no console
    printf("Tabuleiro de Batalha Naval (0 = água, 3 = navio):\n\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
