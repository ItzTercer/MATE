#include "calc.h"

double sumar(double a, double b) {
    return a + b;
}
double restar(double a, double b) {
    return a - b;
}
double multiplicar(double a, double b) {
    return a * b;
}
double dividir(double a, double b) {
    return a / b;
}
double potencia(double base, double exponente) {
    return pow(base, exponente);
}
double logaritmo(double base, double argumento) {
    return log(argumento) / log(base);
}
double raiz_n(double indice, double radicando) {
    int ind_int = (int)indice;
    if (indice == ind_int && ind_int % 2 != 0 && radicando < 0) {
        return -pow(-radicando, 1.0 / indice);
    }
    return pow(radicando, 1.0 / indice);
}

double simbolos_unicos() {
    char entrada_usuario[32];
    if (scanf("%s", entrada_usuario) != 1) {
        return 0;
    } 
    if (strcmp(entrada_usuario, "e") == 0) {
        return n_e;
    }
    if (strcmp(entrada_usuario, "pi") == 0) {
        return n_pi;
    }
    return atof(entrada_usuario);
}

void verificar_magnitud(double valor) {
    if (isinf(valor)) {
        printf("\n[ADVERTENCIA] Magnitud máxima excedida. El resultado tiende a Infinito.\n");
    }
}