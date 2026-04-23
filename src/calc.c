#include "calc.h"

double sumar(double a, double b) { return a + b; }
double restar(double a, double b) { return a - b; }
double multiplicar(double a, double b) { return a * b; }
double dividir(double a, double b) { return a / b; }
double potencia(double base, double exponente) { return pow(base, exponente); }
double logaritmo(double base, double argumento) { return log(argumento) / log(base); }
double raiz_n(double indice, double radicando) { return pow(radicando, 1.0 / indice); }

double simbolos_unicos() {
    char cad1[32];
    if (scanf("%s", cad1) != 1) return 0;
    if (strcmp(cad1, "e") == 0) return n_e;
    if (strcmp(cad1, "pi") == 0) return n_pi;
    return atof(cad1);
}