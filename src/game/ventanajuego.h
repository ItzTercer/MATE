#ifndef definiciones_ventanajuego
#define definiciones_ventanajuego

#include <QMainWindow>
#include <QSet>
#include <QVector>
#include "niveles.h"

class QStackedWidget;
class QLabel;


class VentanaJuego : public QMainWindow {
    Q_OBJECT
public:
    VentanaJuego();

private:
    QStackedWidget *stack_;
    QWidget *paginaDinamica_ = nullptr;   

    QVector<NivelDef> niveles_;
    QSet<int> completados_;
    int puntaje_ = 0;
    int vidas_ = 3;
    int mundoDesbloqueado_ = 1;

    static const int TOTAL_MUNDOS = 4;

    // Construccion de pantallas
    QWidget *crearMenu();
    QWidget *crearComoJugar();
    void mostrarMapa();
    void mostrarSelector(int mundo);
    void jugarNivel(int indice);
    void irADinamica(QWidget *w);

    // Estado
    QString textoHUD() const;
    int totalNivelesMundo(int mundo) const;
    int completadosMundo(int mundo) const;
    void registrarVictoria(int indice, int puntos);
    void perderVida(const QString &motivo);
    void reiniciar();
};

#endif
