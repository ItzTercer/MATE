#ifndef CALC_H
#define CALC_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define n_e 2.71828182845904523536
#define n_pi 3.14159265358979323846

#define OPCION_SUMA 1
#define OPCION_RESTA 2
#define OPCION_MULTIPLICAR 3
#define OPCION_DIVIDIR 4
#define OPCION_EXPONENTE 5
#define OPCION_LOGARITMO 6
#define OPCION_RAIZ 7
#define OPCION_SALIR 8

double sumar(double a, double b);
double restar(double a, double b);
double multiplicar(double a, double b);
double dividir(double a, double b);
double potencia(double base, double exponente);
double logaritmo(double base, double argumento);
double raiz_n(double indice, double radicando);
double simbolos_unicos();
void verificar_magnitud(double valor);

#endif