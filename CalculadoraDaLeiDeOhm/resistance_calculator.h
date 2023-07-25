#ifndef RESISTANCE_CALCULATOR_H
#define RESISTANCE_CALCULATOR_H

double calculate_series_resistance(int n, double resistors[]);
double calculate_parallel_resistance(int n, double resistors[]);
double calculate_mixed_resistance(int n, double resistors[], char types[]);
double calculate_voltage(double current, double resistance);
double calculate_current(double voltage, double resistance);
double calculate_resistance(double voltage, double current);

#endif // RESISTANCE_CALCULATOR_H
