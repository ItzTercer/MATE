#ifndef definiciones_nivel
#define definiciones_nivel

#include <QWidget>
#include "niveles.h"
#include "plano.h"

class QSlider;
class QLabel;
class QPushButton;
class QProgressBar;

/*
 * NivelWidget — reto "Atrapa la Curva".
 * El jugador ve la curva objetivo (azul punteada) y mueve sliders de
 * coeficientes; su curva (verde) se redibuja en vivo. Cuando la precision
 * supera el umbral, gana el nivel.
 */
class NivelWidget : public QWidget {
    Q_OBJECT
public:
    explicit NivelWidget(const NivelDef &def, QWidget *parent = nullptr);

signals:
    void nivelGanado(int puntos);
    void volverAlMapa();

private slots:
    void alMoverSlider();
    void alComprobar();

private:
    NivelDef def_;
    FuncionMatematica jugador_;
    PlanoWidget *plano_;
    QSlider *sliderA_ = nullptr, *sliderB_ = nullptr, *sliderC_ = nullptr;
    QLabel *valorA_ = nullptr, *valorB_ = nullptr, *valorC_ = nullptr;
    QLabel *expr_;
    QLabel *mensaje_;
    QProgressBar *barra_;
    int intentos_ = 0;

    QSlider *crearFila(const QString &nombre, double minv, double maxv,
                       QLabel **etiquetaValor, class QVBoxLayout *layout);
    void actualizar();   // lee sliders -> actualiza funcion, grafico y barra
};

#endif
