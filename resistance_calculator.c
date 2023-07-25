#include "resistance_calculator.h"

double calculate_series_resistance(int n, double resistors[]) {
    double total_resistance = 0.0;
    for (int i = 0; i < n; i++) {
        total_resistance += resistors[i];
    }
    return total_resistance;
}


double calculate_parallel_resistance(int n, double resistors[]) {
    double inv_total_resistance = 0.0;
    for (int i = 0; i < n; i++) {
        if (resistors[i] == 0) {
            printf("Erro: Divisão por zero na resistência (R%d)\n", i + 1);
            return -1;
        }
        inv_total_resistance += 1.0 / resistors[i];
    }
    return 1.0 / inv_total_resistance;
}


double calculate_mixed_resistance(int n, double resistors[], char types[]) {
    double total_resistance = 0.0;
    int i = 0;
    while (i < n) {
        int count_series = 0;
        int count_parallel = 0;
        double series_resistance = 0.0;
        double parallel_resistance = 0.0;

        // Loop para calcular a resistência equivalente em série
        while (i < n && types[i] == 'S') {
            series_resistance += resistors[i];
            count_series++;
            i++;
        }

        // Loop para calcular a resistência equivalente em paralelo
        while (i < n && types[i] == 'P') {
            parallel_resistance += resistors[i];
            count_parallel++;
            i++;
        }

        if (count_series > 0) {
            // Caso haja resistores em série, adiciona a resistência equivalente em série ao total
            total_resistance += calculate_series_resistance(count_series, &resistors[i - count_series]);
        }

        if (count_parallel > 0) {
            // Caso haja resistores em paralelo, adiciona a resistência equivalente em paralelo ao total
            total_resistance += calculate_parallel_resistance(count_parallel, &resistors[i - count_parallel]);
        }
    }
    return total_resistance;
}
