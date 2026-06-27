#ifndef definiciones_funcion
#define definiciones_funcion

#include <string>
#include "../calc.h"  


enum class TipoFuncion {
    LINEAL,        
    CUADRATICA,    
    RAIZ,          
    LOGARITMO,     
    EXPONENCIAL    
};


class FuncionMatematica {
private:
    TipoFuncion tipo_;
    double a_;
    double b_;
    double c_;
    mutable calc_mate motor;   // procede del hito 2

public:
    FuncionMatematica();
    FuncionMatematica(TipoFuncion tipo, double a, double b, double c);

    
    double evaluar(double x) const;

    
    std::string expresion() const;

    //Texto corto
    std::string nombreTipo() const;

    TipoFuncion tipo() const { return tipo_; }
    double a() const { return a_; }
    double b() const { return b_; }
    double c() const { return c_; }
    void setA(double v) { a_ = v; }
    void setB(double v) { b_ = v; }
    void setC(double v) { c_ = v; }
};

#endif
