#ifndef RESISTANCE_CALCULATOR_H
#define RESISTANCE_CALCULATOR_H

// Fun��o para calcular a resist�ncia equivalente em s�rie
double calculate_series_resistance(int n, double resistors[]);

// Fun��o para calcular a resist�ncia equivalente em paralelo
double calculate_parallel_resistance(int n, double resistors[]);

// Fun��o para calcular a resist�ncia equivalente em misto
double calculate_mixed_resistance(int n, double resistors[], char types[]);

#endif // RESISTANCE_CALCULATOR_H
