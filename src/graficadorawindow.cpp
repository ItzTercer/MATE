#include "graficadorawindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPainter>
#include <cmath>

// --- Implementación del lienzo de dibujo ---
CanvasGraficadora::CanvasGraficadora(QWidget *parent)
    : QWidget(parent), x_actual_(-10.0) {
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

double CanvasGraficadora::evaluarFuncion(double x) const {
    switch (tipo_) {
    case TipoGrafica::Lineal:      return x;
    case TipoGrafica::Cuadratica:  return x * x;
    case TipoGrafica::Raiz:        return x >= 0.0 ? std::sqrt(x) : std::nan("");
    case TipoGrafica::Logaritmo:   return x > 0.0 ? std::log10(x) : std::nan("");
    case TipoGrafica::Exponencial: return std::exp(x);
    case TipoGrafica::Seno:        return std::sin(x);
    case TipoGrafica::Coseno:      return std::cos(x);
    case TipoGrafica::Tangente:    return std::tan(x);
    }
    return 0.0;
}

QPointF CanvasGraficadora::aPixel(double x, double y) const {
    double px = (x - x_min_) / (x_max_ - x_min_) * width();
    double py = height() - (y - y_min_) / (y_max_ - y_min_) * height();
    return QPointF(px, py);
}

void CanvasGraficadora::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.fillRect(rect(), QColor("#1F1F1F"));

    // Cuadrícula perimetral
    QPen penGrid(QColor("#2C3242"), 1);
    p.setPen(penGrid);
    for (int i = (int)x_min_; i <= (int)x_max_; ++i) {
        p.drawLine(aPixel(i, y_min_), aPixel(i, y_max_));
        p.drawLine(aPixel(x_min_, i), aPixel(x_max_, i));
    }

    // Ejes ortogonales
    QPen penEjes(QColor("#96A0B4"), 2);
    p.setPen(penEjes);
    p.drawLine(aPixel(x_min_, 0), aPixel(x_max_, 0));
    p.drawLine(aPixel(0, y_min_), aPixel(0, y_max_));

    // Renderizado de números en los ejes
    p.setPen(QColor("#788296"));
    QFont fontEjes = p.font();
    fontEjes.setPointSize(8);
    p.setFont(fontEjes);

    for (int x = (int)std::ceil(x_min_); x <= (int)std::floor(x_max_); ++x) {
        if (x == 0) continue;
        QPointF pt = aPixel(x, 0);
        p.drawText(QPointF(pt.x() + 2, pt.y() + 12), QString::number(x));
    }
    for (int y = (int)std::ceil(y_min_); y <= (int)std::floor(y_max_); ++y) {
        if (y == 0) continue;
        QPointF pt = aPixel(0, y);
        p.drawText(QPointF(pt.x() + 4, pt.y() - 2), QString::number(y));
    }

    // Curva matemática progresiva
    QPen penCurva(QColor("#56e68c"), 3);
    p.setPen(penCurva);

    bool primerPunto = true;
    QPointF puntoPrevio;
    double paso = 0.02;

    for (double x = x_min_; x <= x_actual_; x += paso) {
        double y = evaluarFuncion(x);

        if (!std::isfinite(y) || std::abs(y) > 50.0) {
            primerPunto = true;
            continue;
        }

        QPointF puntoActual = aPixel(x, y);

        if (!primerPunto) {
            p.drawLine(puntoPrevio, puntoActual);
        } else {
            primerPunto = false;
        }
        puntoPrevio = puntoActual;
    }
}

// --- Implementación de la ventana contenedora ---
GraficadoraWindow::GraficadoraWindow(QWidget *parent)
    : QWidget(parent), x_actual_(-10.0) {
    setWindowTitle("Graficadora Interactiva");
    resize(550, 600);
    setStyleSheet("background-color: #202020; color: white;");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(12, 12, 12, 12);

    QHBoxLayout *topLayout = new QHBoxLayout();
    QLabel *lbl = new QLabel("Función:", this);
    lbl->setStyleSheet("font-weight: bold; font-size: 14px; color: #7fd1ff;");

    comboFunciones_ = new QComboBox(this);
    comboFunciones_->addItems({
        "Lineal (y = x)",
        "Cuadrática (y = x²)",
        "Raíz Cuadrada (y = √x)",
        "Logarítmica (y = log(x))",
        "Exponencial (y = e^x)",
        "Trig. Seno (y = sen(x))",
        "Trig. Coseno (y = cos(x))",
        "Trig. Tangente (y = tan(x))"
    });
    comboFunciones_->setStyleSheet(
        "QComboBox { background-color: #3a3a3a; color: white; border: 1px solid #242424; border-radius: 5px; padding: 6px; padding-left: 10px; min-width: 220px; font-size: 13px; }"
        "QComboBox QAbstractItemView { background-color: #2a2a2a; color: white; selection-background-color: #0096c7; }"
        );

    topLayout->addWidget(lbl);
    topLayout->addWidget(comboFunciones_);
    topLayout->addStretch();

    canvas_ = new CanvasGraficadora(this);

    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(canvas_, 1);

    timer_ = new QTimer(this);
    connect(timer_, &QTimer::timeout, this, &GraficadoraWindow::avanzarTrazo);
    connect(comboFunciones_, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &GraficadoraWindow::cambioFuncion);
}

void GraficadoraWindow::iniciarAnimacion() {
    timer_->stop();
    x_actual_ = x_min_;
    canvas_->reiniciar(x_min_);
    timer_->start(16);
}

void GraficadoraWindow::avanzarTrazo() {
    if (x_actual_ >= x_max_) {
        timer_->stop();
        return;
    }
    x_actual_ += 0.15;
    if (x_actual_ > x_max_) x_actual_ = x_max_;
    canvas_->setXActual(x_actual_);
}

void GraficadoraWindow::cambioFuncion(int index) {
    canvas_->setTipo(static_cast<TipoGrafica>(index));
    iniciarAnimacion();
}