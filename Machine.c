#include <stdio.h>
#include <string.h>

// Definição dos estados
typedef enum {
    Inicio,
    MoedaInserida,
    SelecionarBebida,
    Coffee,
    Tea,
    Glass
} State;

// Função para obter a próxima saída
const char* getOutput(State state) {
    switch (state) {
        case Inicio:
            return "Insira uma moeda de 1 real.";
        case MoedaInserida:
            return "Selecione a bebida (Digite 'Coffee' ou 'Tea').";
        case Coffee:
            return "Ativar Bomba 1 (Insira 'Glass' para continuar).";
        case Tea:
            return "Ativar Bomba 2 (Insira 'Glass' para continuar).";
        case Glass:
            return "Válvula contar até 250ml (Insira 'Inicio' para reiniciar).";
    }
    return "Nenhum";
}

int main() {
    State currentState = Inicio;
    int moedaInserida = 0;

    printf("Bem-vindo à máquina de bebidas!\n");

    char input[20];

    while (1) {
        printf("Insira uma ação: ");
        scanf("%s", input);

        const char* output = getOutput(currentState);
        printf("Estado Atual: %d, Entrada: %s, Saída: %s\n", currentState, input, output);

        // Atualiza o estado atual com base nas entradas
        switch (currentState) {
            case Inicio:
                if (strcmp(input, "Moeda1Real") == 0) {
                    moedaInserida = 1;
                    currentState = MoedaInserida;
                }
                break;
            case MoedaInserida:
                if (moedaInserida && (strcmp(input, "Coffee") == 0 || strcmp(input, "Tea") == 0)) {
                    currentState = strcmp(input, "Coffee") == 0 ? Coffee : Tea;
                }
                break;
            case Coffee:
                if (strcmp(input, "Glass") == 0) {
                    currentState = Glass;
                }
                break;
            case Tea:
                if (strcmp(input, "Glass") == 0) {
                    currentState = Glass;
                }
                break;
            case Glass:
                if (strcmp(input, "Inicio") == 0) {
                    moedaInserida = 0;
                    currentState = Inicio;
                }
                break;
        }
    }

    return 0;
}
