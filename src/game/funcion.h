#ifndef definiciones_funcion
#define definiciones_funcion

#include <string>
#include "../calc.h"   // Reutilizamos el motor matematico calc_mate (Hito 2)

// Tipos de funcion que el juego ensenia a graficar (curriculum de secundaria)
enum class TipoFuncion {
    LINEAL,        // y = a*x + b
    CUADRATICA,    // y = a*x^2 + b*x + c
    RAIZ,          // y = a*raiz(x) + b
    LOGARITMO,     // y = a*log_b(x) + c
    EXPONENCIAL    // y = a*b^x + c
};

/*
 * FuncionMatematica
 * -----------------
 * Capa de aprendizaje que envuelve al motor calc_mate del Hito 2.
 * Aplica COMPOSICION: "tiene un" calc_mate y delega los calculos pesados
 * (potencia, logaritmo, raiz) en sus metodos, de modo que el juego reutiliza
 * el codigo del proyecto original en lugar de reimplementarlo.
 */
class FuncionMatematica {
private:
    TipoFuncion tipo_;
    double a_;
    double b_;
    double c_;
    mutable calc_mate motor;   // Composicion: motor de calculo reutilizado

public:
    FuncionMatematica();
    FuncionMatematica(TipoFuncion tipo, double a, double b, double c);

    // Evalua y = f(x). Devuelve NaN fuera del dominio (raiz/log).
    double evaluar(double x) const;

    // Expresion legible para mostrar en pantalla, ej: "y = 2x + 1"
    std::string expresion() const;

    // Texto corto del tipo, ej: "Recta", "Parabola"
    std::string nombreTipo() const;

    // Acceso / modificacion de coeficientes (usado por los sliders del juego)
    TipoFuncion tipo() const { return tipo_; }
    double a() const { return a_; }
    double b() const { return b_; }
    double c() const { return c_; }
    void setA(double v) { a_ = v; }
    void setB(double v) { b_ = v; }
    void setC(double v) { c_ = v; }
};

#endif
