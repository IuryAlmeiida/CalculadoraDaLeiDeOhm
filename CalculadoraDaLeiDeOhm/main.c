#include <stdio.h>
#include "resistance_calculator.h"

int main() {
    int choice, num_resistors;

    printf("Calculadora de Resistencias\n");
    printf("Escolha uma opcao:\n");
    printf("1. Calcular a resistencia equivalente em serie\n");
    printf("2. Calcular a resistencia equivalente em paralelo\n");
    printf("3. Calcular a resistencia equivalente em misto\n");
    printf("4. Calcular a tensao usando a Lei de Ohm\n");
    printf("5. Calcular a corrente usando a Lei de Ohm\n");
    printf("6. Calcular a resistencia usando a Lei de Ohm\n");
    printf("Digite o numero da opcao desejada: ");
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
                printf("Resistencia Equivalente em Serie: %.2lf Ohms\n", resistance);
                break;
            case 2:
                resistance = calculate_parallel_resistance(num_resistors, resistors);
                printf("Resistencia Equivalente em Paralelo: %.2lf Ohms\n", resistance);
                break;
            case 3:
                resistance = calculate_mixed_resistance(num_resistors, resistors, types);
                printf("Resistencia Equivalente em Misto: %.2lf Ohms\n", resistance);
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        } } else if (choice == 4) {
        // Cálculo da tensão usando a Lei de Ohm
        double current, resistance;
        printf("Digite o valor da corrente (I) em Amperes: ");
        scanf("%lf", &current);
        printf("Digite o valor da resistencia (R) em Ohms: ");
        scanf("%lf", &resistance);

        double voltage = calculate_voltage(current, resistance);
        printf("Tensao (V) = %.2lf Volts\n", voltage);

    } else if (choice == 5) {
        // Cálculo da corrente usando a Lei de Ohm
        double voltage, resistance;
        printf("Digite o valor da tensao (V) em Volts: ");
        scanf("%lf", &voltage);
        printf("Digite o valor da resistencia (R) em Ohms: ");
        scanf("%lf", &resistance);

        double current = calculate_current(voltage, resistance);
        printf("Corrente (I) = %.2lf Amperes\n", current);

    } else if (choice == 6) {
        // Cálculo da resistência usando a Lei de Ohm
        double voltage, current;
        printf("Digite o valor da tensao (V) em Volts: ");
        scanf("%lf", &voltage);
        printf("Digite o valor da corrente (I) em Amperes: ");
        scanf("%lf", &current);

        double resistance = calculate_resistance(voltage, current);
        printf("Resistencia (R) = %.2lf Ohms\n", resistance);

    } else {
        printf("Opcao invalida!\n");
    }

    return 0;
}
