#include "funcion.h"
#include <cmath>
#include <sstream>
#include <iomanip>

// Constructor por defecto
FuncionMatematica::FuncionMatematica()
    : tipo_(TipoFuncion::LINEAL), a_(1.0), b_(0.0), c_(0.0) {}

FuncionMatematica::FuncionMatematica(TipoFuncion tipo, double a, double b, double c)
    : tipo_(tipo), a_(a), b_(b), c_(c) {}


double FuncionMatematica::evaluar(double x) const {
    switch (tipo_) {
        case TipoFuncion::LINEAL:
            return a_ * x + b_;

        case TipoFuncion::CUADRATICA:
            
            return a_ * motor.potencia(x, 2.0) + b_ * x + c_;

        case TipoFuncion::RAIZ:
            
            if (x < 0.0) return std::nan("");
            return a_ * motor.raiz_n(2.0, x) + b_;

        case TipoFuncion::LOGARITMO:
            
            if (x <= 0.0 || b_ <= 0.0 || b_ == 1.0) return std::nan("");
            return a_ * motor.logaritmo(b_, x) + c_;

        case TipoFuncion::EXPONENCIAL:
            
            if (b_ <= 0.0) return std::nan("");
            return a_ * motor.potencia(b_, x) + c_;
    }
    return std::nan("");
}

// Formateo para ceros
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
