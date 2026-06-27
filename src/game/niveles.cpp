#include "niveles.h"


QVector<NivelDef> construirNiveles() {
    QVector<NivelDef> v;

    // Mundo 1
    {
        NivelDef n;
        n.mundo = 1; n.titulo = "Recta que sube";
        n.objetivo = FuncionMatematica(TipoFuncion::LINEAL, 1, 0, 0);
        n.usaA = true; n.usaB = true; n.usaC = false;
        n.pista = "La 'a' es la PENDIENTE (inclinacion). La 'b' mueve la recta arriba/abajo.";
        v.push_back(n);
    }
    {
        NivelDef n;
        n.mundo = 1; n.titulo = "Recta con altura";
        n.objetivo = FuncionMatematica(TipoFuncion::LINEAL, 2, -3, 0);
        n.usaA = true; n.usaB = true; n.usaC = false;
        n.pista = "Prueba a=2 (sube rapido) y baja la recta con b negativo.";
        v.push_back(n);
    }
    {
        NivelDef n;
        n.mundo = 1; n.titulo = "Adivina la recta"; n.esQuiz = true;
        n.objetivo = FuncionMatematica(TipoFuncion::LINEAL, -1, 2, 0);
        n.opciones = { "y = x + 2", "y = -x + 2", "y = -x - 2", "y = 2x" };
        n.correcta = 1;
        n.pista = "Si la recta BAJA de izquierda a derecha, la pendiente es negativa.";
        v.push_back(n);
    }

    // Mundo 2
    {
        NivelDef n;
        n.mundo = 2; n.titulo = "Parabola simple";
        n.objetivo = FuncionMatematica(TipoFuncion::CUADRATICA, 1, 0, 0);
        n.usaA = true; n.usaB = true; n.usaC = true;
        n.minA = -3; n.maxA = 3;
        n.pista = "La 'a' abre o cierra la parabola. Si a<0 se da vuelta (boca abajo).";
        v.push_back(n);
    }
    {
        NivelDef n;
        n.mundo = 2; n.titulo = "Parabola movida";
        n.objetivo = FuncionMatematica(TipoFuncion::CUADRATICA, 1, -2, -1);
        n.usaA = true; n.usaB = true; n.usaC = true;
        n.minA = -3; n.maxA = 3;
        n.pista = "La 'c' sube/baja la parabola. La 'b' la corre hacia los lados.";
        v.push_back(n);
    }
    {
        NivelDef n;
        n.mundo = 2; n.titulo = "Parabola al reves"; n.esQuiz = true;
        n.objetivo = FuncionMatematica(TipoFuncion::CUADRATICA, -1, 0, 3);
        n.opciones = { "y = x² + 3", "y = -x² + 3", "y = -x² - 3", "y = 3x²" };
        n.correcta = 1;
        n.pista = "Boca abajo => a negativo. Pasa por (0,3) => c = 3.";
        v.push_back(n);
    }

    // Mundo 3
    {
        NivelDef n;
        n.mundo = 3; n.titulo = "La raiz basica";
        n.objetivo = FuncionMatematica(TipoFuncion::RAIZ, 1, 0, 0);
        n.usaA = true; n.usaB = true; n.usaC = false;
        n.minA = -3; n.maxA = 3;
        n.pista = "La raiz solo existe para x >= 0 (mitad derecha del plano).";
        v.push_back(n);
    }
    {
        NivelDef n;
        n.mundo = 3; n.titulo = "Raiz estirada";
        n.objetivo = FuncionMatematica(TipoFuncion::RAIZ, 2, 1, 0);
        n.usaA = true; n.usaB = true; n.usaC = false;
        n.minA = -3; n.maxA = 3;
        n.pista = "Sube 'a' para estirar la curva y 'b' para levantarla.";
        v.push_back(n);
    }

    // Mundo 4
    {
        NivelDef n;
        n.mundo = 4; n.titulo = "Crecimiento exponencial";
        n.objetivo = FuncionMatematica(TipoFuncion::EXPONENCIAL, 1, 2, 0);
        n.usaA = true; n.usaB = false; n.usaC = true;   // base 2 dada
        n.minA = -3; n.maxA = 3;
        n.pista = "Con base 2, cada paso DUPLICA el valor: crece muy rapido.";
        v.push_back(n);
    }
    {
        NivelDef n;
        n.mundo = 4; n.titulo = "Adivina la curva"; n.esQuiz = true;
        n.objetivo = FuncionMatematica(TipoFuncion::LOGARITMO, 1, 2, 0);
        n.opciones = { "y = 2^x", "y = log_2(x)", "y = √x", "y = x²" };
        n.correcta = 1;
        n.pista = "El logaritmo crece muy lento y solo existe para x > 0.";
        v.push_back(n);
    }

    return v;
}
