#include <stdio.h>
#include "resistance_calculator.h"




int main() {
    int choice, num_resistors;

    printf("Calculadora de Resistencias\n");
    printf("Escolha uma opcao:\n");
    printf("1. Calcular a resistencia equivalente em serie\n");
    printf("2. Calcular a resistencia equivalente em paralelo\n");
    printf("3. Calcular a resistencia equivalente em misto\n");
    printf("Digite o numero da opçao desejada: ");
    scanf("%d", &choice);

    if (choice == 1 || choice == 2 || choice == 3) {
        printf("Digite o numero de resistores: ");
        scanf("%d", &num_resistors);
        double resistors[num_resistors];
        char types[num_resistors];

        for (int i = 0; i < num_resistors; i++) {
            printf("Digite o valor da resistencia R%d (Ohms): ", i + 1);
            scanf("%lf", &resistors[i]);
            if (choice == 3) {
                printf("Digite o tipo da resistencia R%d ('S' para serie, 'P' para paralelo): ", i + 1);
                scanf(" %c", &types[i]);
            }
        }

        double resistance;
        switch (choice) {
            case 1:
                resistance = calculate_series_resistance(num_resistors, resistors);
                printf("Resistência Equivalente em Série: %.2lf Ohms\n", resistance);
                break;
            case 2:
                resistance = calculate_parallel_resistance(num_resistors, resistors);
                printf("Resistência Equivalente em Paralelo: %.2lf Ohms\n", resistance);
                break;
            case 3:
                resistance = calculate_mixed_resistance(num_resistors, resistors, types);
                printf("Resistência Equivalente em Misto: %.2lf Ohms\n", resistance);
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } else {
        printf("Opção inválida!\n");
    }

    return 0;
}
