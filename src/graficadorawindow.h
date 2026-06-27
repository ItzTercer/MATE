#ifndef GRAFICADORAWINDOW_H
#define GRAFICADORAWINDOW_H

#include <QWidget>
#include <QTimer>
#include <QComboBox>

enum class TipoGrafica {
    Lineal,
    Cuadratica,
    Raiz,
    Logaritmo,
    Exponencial,
    Seno,
    Coseno,
    Tangente
};

class CanvasGraficadora : public QWidget {
    Q_OBJECT
public:
    explicit CanvasGraficadora(QWidget *parent = nullptr);
    void setXActual(double x) { x_actual_ = x; update(); }
    void setTipo(TipoGrafica tipo) { tipo_ = tipo; update(); }
    void reiniciar(double x_min) { x_actual_ = x_min; update(); }

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    double x_actual_;
    TipoGrafica tipo_ = TipoGrafica::Lineal;
    const double x_min_ = -10.0;
    const double x_max_ = 10.0;
    const double y_min_ = -10.0;
    const double y_max_ = 10.0;

    QPointF aPixel(double x, double y) const;
    double evaluarFuncion(double x) const;
};

class GraficadoraWindow : public QWidget {
    Q_OBJECT
public:
    explicit GraficadoraWindow(QWidget *parent = nullptr);
    void iniciarAnimacion();

private slots:
    void avanzarTrazo();
    void cambioFuncion(int index);

private:
    QTimer *timer_;
    QComboBox *comboFunciones_;
    CanvasGraficadora *canvas_;
    double x_actual_;
    const double x_min_ = -10.0;
    const double x_max_ = 10.0;
};

#endif 