#include "plano.h"
#include <QPainter>
#include <QPaintEvent>
#include <cmath>

PlanoWidget::PlanoWidget(QWidget *parent) : QWidget(parent) {
    setMinimumSize(420, 420);
    setAutoFillBackground(true);
}

void PlanoWidget::setObjetivo(const FuncionMatematica &f) { objetivo_ = f; update(); }
void PlanoWidget::setJugador(const FuncionMatematica &f)  { jugador_  = f; update(); }
void PlanoWidget::setMostrarObjetivo(bool v) { mostrarObjetivo_ = v; update(); }
void PlanoWidget::setMostrarJugador(bool v)  { mostrarJugador_  = v; update(); }
void PlanoWidget::setPuntos(const QVector<QPointF> &puntos) { puntos_ = puntos; update(); }

void PlanoWidget::setRango(double xmin, double xmax, double ymin, double ymax) {
    xmin_ = xmin; xmax_ = xmax; ymin_ = ymin; ymax_ = ymax;
    update();
}

// Mapea coordenada matematica (x,y) a un punto en pixeles del widget
QPointF PlanoWidget::aPixel(double x, double y) const {
    double px = (x - xmin_) / (xmax_ - xmin_) * width();
    double py = height() - (y - ymin_) / (ymax_ - ymin_) * height();
    return QPointF(px, py);
}

/*
 * Precision: muestreamos muchos valores de x y contamos en cuantos la curva
 * del jugador queda "pegada" a la objetivo. La tolerancia es un 4% de la
 * altura visible, asi que el alumno debe ajustar bien los coeficientes.
 */
double PlanoWidget::precision() const {
    const int N = 200;
    double tol = (ymax_ - ymin_) * 0.04;
    int validos = 0, aciertos = 0;
    for (int i = 0; i <= N; ++i) {
        double x = xmin_ + (xmax_ - xmin_) * i / N;
        double yo = objetivo_.evaluar(x);
        double yj = jugador_.evaluar(x);
        if (!std::isfinite(yo) || !std::isfinite(yj)) continue;
        ++validos;
        if (std::fabs(yo - yj) <= tol) ++aciertos;
    }
    if (validos == 0) return 0.0;
    return 100.0 * aciertos / validos;
}

// Dibuja una curva muestreando x; corta la linea ante NaN/inf o saltos enormes
void PlanoWidget::dibujarCurva(QPainter &p, const FuncionMatematica &f,
                               const QColor &color, int grosor, bool punteada) {
    QPen pen(color);
    pen.setWidth(grosor);
    if (punteada) pen.setStyle(Qt::DashLine);
    p.setPen(pen);

    const int N = 600;
    bool hayPrevio = false;
    QPointF previo;

    for (int i = 0; i <= N; ++i) {
        double x = xmin_ + (xmax_ - xmin_) * i / N;
        double y = f.evaluar(x);
        // Fuera de dominio o valor desbordado: cortamos la linea
        if (!std::isfinite(y) || std::fabs(y) > 1e6) { hayPrevio = false; continue; }
        QPointF actual = aPixel(x, y);
        if (hayPrevio) p.drawLine(previo, actual);
        previo = actual;
        hayPrevio = true;
    }
}

void PlanoWidget::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);

    // Fondo
    p.fillRect(rect(), QColor(18, 22, 33));

    // --- Cuadricula ---
    QPen gridPen(QColor(40, 48, 66));
    gridPen.setWidth(1);
    p.setPen(gridPen);
    for (int x = (int)std::ceil(xmin_); x <= (int)std::floor(xmax_); ++x) {
        QPointF a = aPixel(x, ymin_), b = aPixel(x, ymax_);
        p.drawLine(a, b);
    }
    for (int y = (int)std::ceil(ymin_); y <= (int)std::floor(ymax_); ++y) {
        QPointF a = aPixel(xmin_, y), b = aPixel(xmax_, y);
        p.drawLine(a, b);
    }

    // --- Ejes ---
    QPen axisPen(QColor(150, 160, 180));
    axisPen.setWidth(2);
    p.setPen(axisPen);
    p.drawLine(aPixel(xmin_, 0), aPixel(xmax_, 0));   // eje X
    p.drawLine(aPixel(0, ymin_), aPixel(0, ymax_));   // eje Y

    // Numeros en los ejes
    p.setPen(QColor(120, 130, 150));
    QFont f = p.font(); f.setPointSize(8); p.setFont(f);
    for (int x = (int)std::ceil(xmin_); x <= (int)std::floor(xmax_); ++x) {
        if (x == 0) continue;
        QPointF pt = aPixel(x, 0);
        p.drawText(QPointF(pt.x() + 2, pt.y() + 12), QString::number(x));
    }
    for (int y = (int)std::ceil(ymin_); y <= (int)std::floor(ymax_); ++y) {
        if (y == 0) continue;
        QPointF pt = aPixel(0, y);
        p.drawText(QPointF(pt.x() + 4, pt.y() - 2), QString::number(y));
    }

    // --- Curva objetivo (lo que hay que lograr) ---
    if (mostrarObjetivo_)
        dibujarCurva(p, objetivo_, QColor(90, 150, 255), 2, true);

    // --- Curva del jugador ---
    if (mostrarJugador_)
        dibujarCurva(p, jugador_, QColor(80, 230, 140), 3, false);

    // --- Puntos / blancos destacados ---
    for (const QPointF &m : puntos_) {
        QPointF pt = aPixel(m.x(), m.y());
        p.setBrush(QColor(255, 210, 70));
        p.setPen(Qt::NoPen);
        p.drawEllipse(pt, 6, 6);
    }
}
