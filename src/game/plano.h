#ifndef definiciones_plano
#define definiciones_plano

#include <QWidget>
#include <QVector>
#include <QPointF>
#include "funcion.h"


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

    
    QPointF aPixel(double x, double y) const;
    void dibujarCurva(QPainter &p, const FuncionMatematica &f, const QColor &color,
                      int grosor, bool punteada);
};

#endif
