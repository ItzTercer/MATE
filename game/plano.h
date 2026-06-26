#ifndef definiciones_plano
#define definiciones_plano

#include <QWidget>
#include <QVector>
#include <QPointF>
#include "funcion.h"

/*
 * PlanoWidget
 * -----------
 * Plano cartesiano dibujado con QPainter. Muestra:
 *   - cuadricula y ejes con numeros,
 *   - la curva OBJETIVO (gris/azul, lo que el alumno debe lograr),
 *   - la curva del JUGADOR (verde, se actualiza en vivo),
 *   - puntos/blancos opcionales (para retos tipo "pasa por estos puntos").
 * Tambien calcula que tan parecidas son ambas curvas (precision %).
 */
class PlanoWidget : public QWidget {
    Q_OBJECT
public:
    explicit PlanoWidget(QWidget *parent = nullptr);

    void setObjetivo(const FuncionMatematica &f);
    void setJugador(const FuncionMatematica &f);
    void setMostrarObjetivo(bool v);
    void setMostrarJugador(bool v);
    void setRango(double xmin, double xmax, double ymin, double ymax);
    void setPuntos(const QVector<QPointF> &puntos);   // blancos a destacar

    // % de coincidencia entre curva del jugador y objetivo (0-100)
    double precision() const;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    FuncionMatematica objetivo_;
    FuncionMatematica jugador_;
    bool mostrarObjetivo_ = true;
    bool mostrarJugador_ = true;
    QVector<QPointF> puntos_;

    double xmin_ = -10, xmax_ = 10, ymin_ = -10, ymax_ = 10;

    // Conversion coordenadas matematicas -> pixeles del widget
    QPointF aPixel(double x, double y) const;
    void dibujarCurva(QPainter &p, const FuncionMatematica &f, const QColor &color,
                      int grosor, bool punteada);
};

#endif
