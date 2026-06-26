#include "nivel.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>
#include <QLabel>
#include <QPushButton>
#include <QProgressBar>
#include <QFont>

// Umbral de precision para dar el nivel por superado
static const double UMBRAL = 90.0;

NivelWidget::NivelWidget(const NivelDef &def, QWidget *parent)
    : QWidget(parent), def_(def) {

    // La funcion del jugador parte del mismo tipo; la base (b) de log/exp
    // viene "dada" cuando no es ajustable, para que el reto sea alcanzable.
    jugador_ = FuncionMatematica(def_.objetivo.tipo(), 1, 0, 0);
    if (!def_.usaB) jugador_.setB(def_.objetivo.b());

    auto *root = new QVBoxLayout(this);

    // --- Encabezado ---
    auto *titulo = new QLabel(QString("Mundo %1  ·  %2").arg(def_.mundo).arg(def_.titulo));
    QFont ft = titulo->font(); ft.setPointSize(15); ft.setBold(true); titulo->setFont(ft);
    titulo->setStyleSheet("color:#7fd1ff;");
    root->addWidget(titulo);

    auto *sub = new QLabel("Mueve los controles para que tu curva VERDE encaje sobre la AZUL punteada.");
    sub->setStyleSheet("color:#aab4c8;");
    sub->setWordWrap(true);
    root->addWidget(sub);

    // --- Zona central: grafico + controles ---
    auto *centro = new QHBoxLayout();
    plano_ = new PlanoWidget(this);
    plano_->setRango(-10, 10, -10, 10);
    plano_->setObjetivo(def_.objetivo);
    plano_->setJugador(jugador_);
    centro->addWidget(plano_, 3);

    auto *panel = new QVBoxLayout();
    panel->setSpacing(6);

    if (def_.usaA) sliderA_ = crearFila("a", def_.minA, def_.maxA, &valorA_, panel);
    if (def_.usaB) sliderB_ = crearFila("b", def_.minB, def_.maxB, &valorB_, panel);
    if (def_.usaC) sliderC_ = crearFila("c", def_.minC, def_.maxC, &valorC_, panel);

    panel->addSpacing(10);

    expr_ = new QLabel();
    QFont fe = expr_->font(); fe.setPointSize(13); fe.setBold(true); expr_->setFont(fe);
    expr_->setStyleSheet("color:#56e68c;");
    panel->addWidget(expr_);

    barra_ = new QProgressBar();
    barra_->setRange(0, 100);
    barra_->setFormat("Precision: %p%");
    barra_->setStyleSheet(
        "QProgressBar{border:1px solid #3a4256;border-radius:5px;text-align:center;color:#fff;background:#1a1f2e;}"
        "QProgressBar::chunk{background:#56e68c;border-radius:4px;}");
    panel->addWidget(barra_);

    auto *pista = new QLabel("💡 " + def_.pista);
    pista->setWordWrap(true);
    pista->setStyleSheet("color:#ffd24a;");
    panel->addWidget(pista);

    mensaje_ = new QLabel();
    mensaje_->setWordWrap(true);
    QFont fm = mensaje_->font(); fm.setBold(true); mensaje_->setFont(fm);
    panel->addWidget(mensaje_);

    panel->addStretch();

    auto *btnComprobar = new QPushButton("✓ Comprobar");
    btnComprobar->setStyleSheet("QPushButton{background:#2e7d32;color:#fff;padding:8px;border-radius:6px;font-weight:bold;}"
                                "QPushButton:hover{background:#388e3c;}");
    connect(btnComprobar, &QPushButton::clicked, this, &NivelWidget::alComprobar);
    panel->addWidget(btnComprobar);

    auto *btnVolver = new QPushButton("← Volver al mapa");
    btnVolver->setStyleSheet("QPushButton{background:#37415a;color:#fff;padding:6px;border-radius:6px;}"
                             "QPushButton:hover{background:#445074;}");
    connect(btnVolver, &QPushButton::clicked, this, &NivelWidget::volverAlMapa);
    panel->addWidget(btnVolver);

    centro->addLayout(panel, 2);
    root->addLayout(centro);

    actualizar();
}

// Crea una fila: etiqueta + slider + valor numerico. Slider entero = valor*2
QSlider *NivelWidget::crearFila(const QString &nombre, double minv, double maxv,
                                QLabel **etiquetaValor, QVBoxLayout *layout) {
    auto *fila = new QHBoxLayout();
    auto *lab = new QLabel(nombre + " =");
    lab->setStyleSheet("color:#dfe6f2;font-weight:bold;");
    lab->setFixedWidth(34);
    fila->addWidget(lab);

    auto *s = new QSlider(Qt::Horizontal);
    s->setMinimum((int)(minv * 2));
    s->setMaximum((int)(maxv * 2));
    s->setValue(nombre == "a" ? 2 : 0);   // a empieza en 1.0, resto en 0
    connect(s, &QSlider::valueChanged, this, &NivelWidget::alMoverSlider);
    fila->addWidget(s);

    auto *val = new QLabel("0");
    val->setStyleSheet("color:#7fd1ff;font-weight:bold;");
    val->setFixedWidth(40);
    fila->addWidget(val);
    *etiquetaValor = val;

    layout->addLayout(fila);
    return s;
}

void NivelWidget::alMoverSlider() { actualizar(); }

void NivelWidget::actualizar() {
    if (sliderA_) { double v = sliderA_->value() / 2.0; jugador_.setA(v); valorA_->setText(QString::number(v)); }
    if (sliderB_) { double v = sliderB_->value() / 2.0; jugador_.setB(v); valorB_->setText(QString::number(v)); }
    if (sliderC_) { double v = sliderC_->value() / 2.0; jugador_.setC(v); valorC_->setText(QString::number(v)); }

    plano_->setJugador(jugador_);
    expr_->setText(QString::fromStdString(jugador_.expresion()));

    int prec = (int)plano_->precision();
    barra_->setValue(prec);
}

void NivelWidget::alComprobar() {
    ++intentos_;
    double prec = plano_->precision();
    if (prec >= UMBRAL) {
        // Puntaje: 100 base, menos 10 por intento extra, minimo 40
        int puntos = 100 - (intentos_ - 1) * 10;
        if (puntos < 40) puntos = 40;
        mensaje_->setStyleSheet("color:#56e68c;");
        mensaje_->setText(QString("🎉 ¡Lo lograste! +%1 puntos\nLa funcion era %2")
                              .arg(puntos)
                              .arg(QString::fromStdString(def_.objetivo.expresion())));
        emit nivelGanado(puntos);
    } else {
        mensaje_->setStyleSheet("color:#ff8a80;");
        mensaje_->setText(QString("Todavia no (%1%). Ajusta los controles y vuelve a intentar.")
                              .arg((int)prec));
    }
}
