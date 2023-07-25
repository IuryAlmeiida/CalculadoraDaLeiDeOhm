#include "resistance_calculator.h"
double calculate_voltage(double current, double resistance) {
    return current * resistance;
}

double calculate_current(double voltage, double resistance) {
    if (resistance != 0) {
        return voltage / resistance;
    } else {
        printf("Erro: Divisão por zero na resistência (R).\n");
        return -1;
    }
}

double calculate_series_resistance(int n, double resistors[]) {
    double total_resistance = 0.0;
    for (int i = 0; i < n; i++) {
        total_resistance += resistors[i];
    }
    return total_resistance;
}
double calculate_resistance(double voltage, double current) {
    if (current != 0) {
        return voltage / current;
    } else {
        printf("Erro: Divisão por zero na corrente (I).\n");
        return -1;
    }
}

double calculate_parallel_resistance(int n, double resistors[]) {
    double inv_total_resistance = 0.0;
    for (int i = 0; i < n; i++) {
        if (resistors[i] == 0) {
            printf("Erro: Divisao por zero na resistencia (R%d)\n", i + 1);
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

        // Loop para calcular a resistencia equivalente em serie
        while (i < n && types[i] == 'S') {
            series_resistance += resistors[i];
            count_series++;
            i++;
        }

        // Loop para calcular a resistencia equivalente em paralelo
        while (i < n && types[i] == 'P') {
            parallel_resistance += resistors[i];
            count_parallel++;
            i++;
        }

        if (count_series > 0) {
            // Caso haja resistores em serie, adiciona a resistencia equivalente em serie ao total
            total_resistance += calculate_series_resistance(count_series, &resistors[i - count_series]);
        }

        if (count_parallel > 0) {
            // Caso haja resistores em paralelo, adiciona a resistencia equivalente em paralelo ao total
            total_resistance += calculate_parallel_resistance(count_parallel, &resistors[i - count_parallel]);
        }
    }
    return total_resistance;
}
