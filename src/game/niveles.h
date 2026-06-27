#ifndef definiciones_niveles
#define definiciones_niveles

#include <QString>
#include <QStringList>
#include <QVector>
#include "funcion.h"

/*
 * NivelDef: descripcion de un nivel del juego.
 * Sirve tanto para retos "Atrapa la Curva" (esQuiz=false) como para
 * preguntas "Adivina la Funcion" (esQuiz=true).
 */
struct NivelDef {
    int mundo = 1;            // 1=Rectas, 2=Parabolas, 3=Raices, 4=Log/Exp
    QString titulo;
    bool esQuiz = false;
    FuncionMatematica objetivo;

    // --- Reto "Atrapa la Curva": que coeficientes puede mover el jugador ---
    bool usaA = true, usaB = true, usaC = false;
    double minA = -5, maxA = 5;
    double minB = -5, maxB = 5;
    double minC = -5, maxC = 5;
    QString pista;            // ayuda educativa mostrada al jugador

    // --- Quiz "Adivina la Funcion" ---
    QStringList opciones;     // expresiones candidatas
    int correcta = 0;         // indice de la opcion correcta
};

// Genera todos los niveles del juego, agrupados por mundo (1..4)
QVector<NivelDef> construirNiveles();

#endif
