#ifndef RESISTANCE_CALCULATOR_H
#define RESISTANCE_CALCULATOR_H

// Função para calcular a resistência equivalente em série
double calculate_series_resistance(int n, double resistors[]);

// Função para calcular a resistência equivalente em paralelo
double calculate_parallel_resistance(int n, double resistors[]);

// Função para calcular a resistência equivalente em misto
double calculate_mixed_resistance(int n, double resistors[], char types[]);

#endif // RESISTANCE_CALCULATOR_H
