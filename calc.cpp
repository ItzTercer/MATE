#include "calc.h"

//Constructor y destructor
calc_mate::calc_mate() {
    resultado_actual = 0.0;
    primer_valor = 0.0;
    segundo_valor = 0.0;
}

calc_mate::~calc_mate() {}

//Funcion suma
double calc_mate::sumar(double a, double b) {
    return a + b;
}

//Funcion resta
double calc_mate::restar(double a, double b) {
    return a - b;
}

//Funcion multiplicacion
double calc_mate::multiplicar(double a, double b) {
    return a * b;
}

//Funcion division
double calc_mate::dividir(double a, double b) {
    return a / b;
}

//Funcion potencia
double calc_mate::potencia(double base, double exponente) {
    return std::pow(base, exponente);
}

//Funcion logaritmo
double calc_mate::logaritmo(double base, double argumento) {
    return std::log(argumento) / std::log(base);
}

//Funcion raiz
double calc_mate::raiz_n(double indice, double radicando) {
    int parte_entera_indice = (int)indice;
    if (indice == parte_entera_indice && parte_entera_indice % 2 != 0 && radicando < 0) {
        return -std::pow(-radicando, 1.0 / indice);
    }
    return std::pow(radicando, 1.0 / indice);
}

//Verificador de constantes
double calc_mate::verificador_constantes() {
    std::string entrada;
    if (!(std::cin >> entrada)) {
        return 0;
    } 
    if (entrada == "e") {
        return constante_e;
    }
    if (entrada == "pi") {
        return constante_pi;
    }
    return std::stod(entrada);
}

//Verificador de infinito
void calc_mate::verificador_infinito(double verificador) {
    if (std::isinf(verificador)) {
        std::cout << "\n\033[1m\033[38;5;220m[ADVERTENCIA] Magnitud máxima excedida. El resultado tiende a Infinito.\033[0m\n";
    }
}