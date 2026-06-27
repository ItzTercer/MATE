#include <QApplication>
#include "ventanajuego.h"

/*
 * Punto de entrada del juego "MATE: Aventura Grafica" (Hito 3).
 * Reutiliza el motor matematico calc_mate del Hito 2 dentro de una
 * interfaz grafica Qt enfocada en estudiantes de secundaria.
 */
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    VentanaJuego ventana;
    ventana.show();
    return app.exec();
}
