#include "funcion.h"
#include <cmath>
#include <sstream>
#include <iomanip>

// Constructor por defecto: recta identidad y = x
FuncionMatematica::FuncionMatematica()
    : tipo_(TipoFuncion::LINEAL), a_(1.0), b_(0.0), c_(0.0) {}

FuncionMatematica::FuncionMatematica(TipoFuncion tipo, double a, double b, double c)
    : tipo_(tipo), a_(a), b_(b), c_(c) {}

/*
 * Evaluacion de la funcion.
 * Se apoya en los metodos del motor calc_mate (potencia, raiz_n, logaritmo)
 * para reutilizar la logica matematica del Hito 2.
 */
double FuncionMatematica::evaluar(double x) const {
    switch (tipo_) {
        case TipoFuncion::LINEAL:
            return a_ * x + b_;

        case TipoFuncion::CUADRATICA:
            // a*x^2 + b*x + c, usando potencia() del motor
            return a_ * motor.potencia(x, 2.0) + b_ * x + c_;

        case TipoFuncion::RAIZ:
            // Dominio: x >= 0
            if (x < 0.0) return std::nan("");
            return a_ * motor.raiz_n(2.0, x) + b_;

        case TipoFuncion::LOGARITMO:
            // Dominio: x > 0, base b_ valida (>0 y distinta de 1)
            if (x <= 0.0 || b_ <= 0.0 || b_ == 1.0) return std::nan("");
            return a_ * motor.logaritmo(b_, x) + c_;

        case TipoFuncion::EXPONENCIAL:
            // a*b^x + c, con b_ > 0
            if (b_ <= 0.0) return std::nan("");
            return a_ * motor.potencia(b_, x) + c_;
    }
    return std::nan("");
}

// --- Auxiliar: formatea un numero quitando ceros sobrantes (2.0 -> "2") ---
static std::string fmt(double v) {
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(2) << v;
    std::string s = ss.str();
    // recorta ceros finales y el punto si queda colgando
    if (s.find('.') != std::string::npos) {
        while (s.back() == '0') s.pop_back();
        if (s.back() == '.') s.pop_back();
    }
    return s;
}

// --- Auxiliar: " + 3", " - 2", o "" si el termino es 0 ---
static std::string termino(double v) {
    if (v == 0.0) return "";
    if (v > 0.0) return " + " + fmt(v);
    return " - " + fmt(-v);
}

std::string FuncionMatematica::expresion() const {
    std::ostringstream ss;
    switch (tipo_) {
        case TipoFuncion::LINEAL:
            ss << "y = " << fmt(a_) << "x" << termino(b_);
            break;
        case TipoFuncion::CUADRATICA:
            ss << "y = " << fmt(a_) << "x²";
            if (b_ != 0.0) ss << termino(b_) << "x";
            ss << termino(c_);
            break;
        case TipoFuncion::RAIZ:
            ss << "y = " << fmt(a_) << "√x" << termino(b_);
            break;
        case TipoFuncion::LOGARITMO:
            ss << "y = " << fmt(a_) << "·log_" << fmt(b_) << "(x)" << termino(c_);
            break;
        case TipoFuncion::EXPONENCIAL:
            ss << "y = " << fmt(a_) << "·" << fmt(b_) << "^x" << termino(c_);
            break;
    }
    return ss.str();
}

std::string FuncionMatematica::nombreTipo() const {
    switch (tipo_) {
        case TipoFuncion::LINEAL:     return "Recta";
        case TipoFuncion::CUADRATICA: return "Parabola";
        case TipoFuncion::RAIZ:       return "Raiz cuadrada";
        case TipoFuncion::LOGARITMO:  return "Logaritmo";
        case TipoFuncion::EXPONENCIAL:return "Exponencial";
    }
    return "Funcion";
}
