#ifndef definiciones_niveles
#define definiciones_niveles

#include <QString>
#include <QStringList>
#include <QVector>
#include "funcion.h"


struct NivelDef {
    int mundo = 1; // 1=Rectas, 2=Parabolas, 3=Raices, 4=Log/Exp
    QString titulo;
    bool esQuiz = false;
    FuncionMatematica objetivo;

    
    bool usaA = true, usaB = true, usaC = false;
    double minA = -5, maxA = 5;
    double minB = -5, maxB = 5;
    double minC = -5, maxC = 5;
    QString pista; // ayuda al jugador

    
    QStringList opciones;     
    int correcta = 0;         
};

// Genera todos los niveles del juego
QVector<NivelDef> construirNiveles();

#endif
