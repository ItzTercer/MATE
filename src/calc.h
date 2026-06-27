#ifndef definiciones_calc
#define definiciones_calc

//Librerias
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include "formulario.h"

//Constantes
#define constante_e 2.71828182845904523536
#define constante_pi 3.14159265358979323846

//Opciones
#define eleccion_suma 1
#define eleccion_resta 2
#define eleccion_multiplicar 3
#define eleccion_dividir 4
#define eleccion_potencia 5
#define eleccion_logaritmo 6
#define eleccion_raiz 7
#define eleccion_formulario 8
#define eleccion_salir 9

//Class
class calc_mate {
private:
    //Variables Temporales
    double resultado_actual;
    double primer_valor;
    double segundo_valor;

    //Composición
    formulario_aprendizaje formulario;

    //Herramientas
    double verificador_constantes();
    void verificador_infinito(double verificador);

public:
    calc_mate();
    ~calc_mate();
    
    //Matematicas
    void iniciar();
    double sumar(double a, double b);
    double restar(double a, double b);
    double multiplicar(double a, double b);
    double dividir(double a, double b);
    double potencia(double base, double exponente);
    double logaritmo(double base, double argumento);
    double raiz_n(double indice, double radicando);
};

#endif