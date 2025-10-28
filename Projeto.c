#include <stdio.h>

/* ================================
   Função recursiva para a Torre
   ================================
   A Torre move-se em linha reta.
   Aqui simulamos 5 casas para a direita.
   Cada chamada recursiva representa uma casa percorrida.
*/
void moverTorre(int casas) {
    if (casas == 0) return; // condição de parada
    printf("Direita\n");
    moverTorre(casas - 1); // chamada recursiva
}

/* ======================================
   Função recursiva para o Bispo (com loops)
   ======================================
   O Bispo move-se na diagonal.
   O loop externo controla o movimento vertical ("Cima"),
   e o loop interno controla o movimento horizontal ("Direita").
   Cada chamada recursiva reduz o número de movimentos restantes.
*/
void moverBispo(int casasVerticais, int casasHorizontais) {
    if (casasVerticais == 0 || casasHorizontais == 0) return; // condição de parada

    for (int i = 0; i < casasVerticais; i++) {      // movimento vertical
        for (int j = 0; j < casasHorizontais; j++) { // movimento horizontal
            printf("Cima, Direita\n");
        }
    }

    // chamada recursiva: reduz uma casa em cada direção
    moverBispo(casasVerticais - 1, casasHorizontais - 1);
}

/* ================================
   Função recursiva para a Rainha
   ================================
   A Rainha pode mover-se em qualquer direção.
   Aqui simulamos 8 casas para a esquerda.
*/
void moverRainha(int casas) {
    if (casas == 0) return; // condição de parada
    printf("Esquerda\n");
    moverRainha(casas - 1); // chamada recursiva
}

/* ======================================
   Função com loops complexos para o Cavalo
   ======================================
   O Cavalo move-se em "L": duas casas para cima e uma para a direita.
   Usamos loops aninhados com múltiplas variáveis, além de `break` e `continue`
   para controle de fluxo.
*/
void moverCavalo() {
    int movimentosVerticais = 2;
    int movimentosHorizontais = 1;

    printf("Movimento do Cavalo:\n");

    // Loop externo: controla movimento vertical (duas casas para cima)
    for (int i = 1, j = movimentosVerticais; i <= movimentosVerticais; i++, j--) {
        if (i == 1)
            printf("Cima\n");
        else if (i == 2)
            printf("Cima\n");

        // Condição especial: quando atinge o topo do "L", faz o movimento lateral
        if (i == movimentosVerticais) {
            int k = 0;
            while (k < movimentosHorizontais) {
                k++;
                if (k == 1) {
                    printf("Direita\n");
                } else {
                    // caso raro, não usado, mas serve para ilustrar o uso de continue
                    continue;
                }

                // se o cavalo completou o movimento em "L", sai do loop
                if (k >= movimentosHorizontais) {
                    break;
                }
            }
        }
    }
}

/* ===========================
   Função Principal
   ===========================
*/
int main() {
    // ===== Torre =====
    printf("Movimento da Torre:\n");
    moverTorre(5);
    printf("\n");

    // ===== Bispo =====
    printf("Movimento do Bispo:\n");
    moverBispo(3, 3);
    printf("\n");

    // ===== Rainha =====
    printf("Movimento da Rainha:\n");
    moverRainha(8);
    printf("\n");

    // ===== Cavalo =====
    moverCavalo();
    printf("\nFim da simulação!\n");

    return 0;
}
