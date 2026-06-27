#include "ventanajuego.h"
#include "nivel.h"
#include "quiz.h"

#include <QStackedWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QFont>
#include <QPixmap>
#include <QByteArray>

// Nombres y colores de cada mundo
static const char *NOMBRE_MUNDO[] = {
    "", "Rectas", "Parabolas", "Raices", "Log / Exponencial"
};

VentanaJuego::VentanaJuego() {
    setWindowTitle("MATE: Incógnita Grafica");
    resize(940, 640);
    setStyleSheet("QMainWindow{background:#1F1F1F;}");

    niveles_ = construirNiveles();

    stack_ = new QStackedWidget(this);
    setCentralWidget(stack_);

    stack_->addWidget(crearMenu());        // indice 0
    stack_->addWidget(crearComoJugar());   // indice 1
    stack_->setCurrentIndex(0);

    // Atajo de desarrollo para inspeccionar pantallas directamente.
    // Uso: MATE_DEBUG=mapa  |  MATE_DEBUG=nivel0 (indice de nivel)
    QByteArray dbg = qgetenv("MATE_DEBUG");
    if (dbg == "mapa") mostrarMapa();
    else if (dbg.startsWith("nivel")) jugarNivel(dbg.mid(5).toInt());
}

// ----------------------------- Estado -----------------------------
QString VentanaJuego::textoHUD() const {
    QString corazones;
    for (int i = 0; i < 3; ++i) corazones += (i < vidas_) ? "♥" : "♡";
    return QString("Puntaje: %1     ❤️ Vidas: %2").arg(puntaje_).arg(corazones);
}

int VentanaJuego::totalNivelesMundo(int mundo) const {
    int n = 0;
    for (const auto &d : niveles_) if (d.mundo == mundo) ++n;
    return n;
}

int VentanaJuego::completadosMundo(int mundo) const {
    int n = 0;
    for (int i = 0; i < niveles_.size(); ++i)
        if (niveles_[i].mundo == mundo && completados_.contains(i)) ++n;
    return n;
}

// --------------------------- Pantallas ---------------------------
QWidget *VentanaJuego::crearMenu() {
    auto *w = new QWidget();
    auto *lay = new QVBoxLayout(w);
    lay->setAlignment(Qt::AlignCenter);

    // Logo opcional (si el ejecutable encuentra el archivo)
    QPixmap logo("logo2.png");
    if (logo.isNull()) logo = QPixmap("../logo2.png");
    if (!logo.isNull()) {
        auto *img = new QLabel();
        img->setPixmap(logo.scaledToWidth(220, Qt::SmoothTransformation));
        img->setAlignment(Qt::AlignCenter);
        lay->addWidget(img);
    }

    auto *titulo = new QLabel("MATE: Incógnita Grafica");
    QFont ft = titulo->font(); ft.setPointSize(26); ft.setBold(true); titulo->setFont(ft);
    titulo->setStyleSheet("color:#7fd1ff;");
    titulo->setAlignment(Qt::AlignCenter);
    lay->addWidget(titulo);

    auto *sub = new QLabel("Aprende a graficar funciones jugando");
    sub->setStyleSheet("color:#aab4c8;font-size:14px;");
    sub->setAlignment(Qt::AlignCenter);
    lay->addWidget(sub);
    lay->addSpacing(24);

    auto estilo = QString(
        "QPushButton{background:%1;color:#fff;padding:12px 40px;border-radius:8px;font-size:16px;font-weight:bold;}"
        "QPushButton:hover{background:%2;}");

    auto *btnJugar = new QPushButton("▶  Jugar");
    btnJugar->setStyleSheet(estilo.arg("#2e7d32", "#388e3c"));
    connect(btnJugar, &QPushButton::clicked, this, [this]() { mostrarMapa(); });
    lay->addWidget(btnJugar, 0, Qt::AlignCenter);

    auto *btnComo = new QPushButton("?  Como jugar");
    btnComo->setStyleSheet(estilo.arg("#37415a", "#445074"));
    connect(btnComo, &QPushButton::clicked, this, [this]() { stack_->setCurrentIndex(1); });
    lay->addWidget(btnComo, 0, Qt::AlignCenter);

    auto *btnSalir = new QPushButton("✕  Salir");
    btnSalir->setStyleSheet(estilo.arg("#7a2e2e", "#9a3a3a"));
    connect(btnSalir, &QPushButton::clicked, this, [this]() { close(); });
    lay->addWidget(btnSalir, 0, Qt::AlignCenter);

    return w;
}

QWidget *VentanaJuego::crearComoJugar() {
    auto *w = new QWidget();
    auto *lay = new QVBoxLayout(w);

    auto *titulo = new QLabel("Como jugar");
    QFont ft = titulo->font(); ft.setPointSize(20); ft.setBold(true); titulo->setFont(ft);
    titulo->setStyleSheet("color:#7fd1ff;");
    lay->addWidget(titulo);

    auto *texto = new QLabel(
        "Objetivo: recorrer los 4 mundos dominando cada tipo de funcion.\n\n"
        "   Atrapa la Curva: veras una curva AZUL punteada (el objetivo).\n"
        "      Mueve los controles a, b y c para que tu curva VERDE encaje encima.\n"
        "      Observa como cada coeficiente cambia la forma:\n"
        "        • a  →  inclinacion / apertura\n"
        "        • b  →  desplazamiento\n"
        "        • c  →  altura\n"
        "      Cuando la precision llegue al 90%, pulsa 'Comprobar'.\n\n"
        "   Adivina la Funcion: elige la expresion que corresponde a la curva.\n"
        "      Si fallas, pierdes una vida.\n\n"
        "    Completa todos los niveles de un mundo para desbloquear el siguiente.\n"
        "    Cuantos menos intentos uses, mas puntos ganas. :D");
    texto->setStyleSheet("color:#cfd6e4;font-size:14px;");
    texto->setWordWrap(true);
    lay->addWidget(texto);
    lay->addStretch();

    auto *btn = new QPushButton("← Volver al menu");
    btn->setStyleSheet("QPushButton{background:#37415a;color:#fff;padding:8px;border-radius:6px;}"
                       "QPushButton:hover{background:#445074;}");
    connect(btn, &QPushButton::clicked, this, [this]() { stack_->setCurrentIndex(0); });
    lay->addWidget(btn);

    return w;
}

void VentanaJuego::mostrarMapa() {
    auto *w = new QWidget();
    auto *lay = new QVBoxLayout(w);

    auto *hud = new QLabel(textoHUD());
    hud->setStyleSheet("color:#ffd24a;font-size:15px;font-weight:bold;");
    lay->addWidget(hud);

    auto *titulo = new QLabel("Mapa de Mundos");
    QFont ft = titulo->font(); ft.setPointSize(22); ft.setBold(true); titulo->setFont(ft);
    titulo->setStyleSheet("color:#7fd1ff;");
    lay->addWidget(titulo);

    auto *grid = new QGridLayout();
    for (int m = 1; m <= TOTAL_MUNDOS; ++m) {
        bool desbloqueado = (m <= mundoDesbloqueado_);
        int hechos = completadosMundo(m);
        int total = totalNivelesMundo(m);

        QString txt = QString("MUNDO %1\n%2\n%3")
                          .arg(m)
                          .arg(NOMBRE_MUNDO[m])
                          .arg(desbloqueado ? QString("%1/%2 niveles").arg(hechos).arg(total)
                                            : QString("Bloqueado"));
        auto *btn = new QPushButton(txt);
        btn->setMinimumSize(200, 110);
        QString color = desbloqueado ? (hechos == total ? "#2e7d32" : "#27406b") : "#2a2f3d";
        btn->setStyleSheet(QString(
                               "QPushButton{background:%1;color:#fff;border-radius:10px;font-size:14px;font-weight:bold;}"
                               "QPushButton:hover{background:#37527f;}"
                               "QPushButton:disabled{color:#ff4d4d;}").arg(color));
        btn->setEnabled(desbloqueado);
        int mundo = m;
        connect(btn, &QPushButton::clicked, this, [this, mundo]() { mostrarSelector(mundo); });
        grid->addWidget(btn, (m - 1) / 2, (m - 1) % 2);
    }
    lay->addLayout(grid);
    lay->addStretch();

    auto *btnMenu = new QPushButton("← Menu principal");
    btnMenu->setStyleSheet("QPushButton{background:#37415a;color:#fff;padding:8px;border-radius:6px;}"
                           "QPushButton:hover{background:#445074;}");
    connect(btnMenu, &QPushButton::clicked, this, [this]() { stack_->setCurrentIndex(0); });
    lay->addWidget(btnMenu);

    irADinamica(w);
}

void VentanaJuego::mostrarSelector(int mundo) {
    auto *w = new QWidget();
    auto *lay = new QVBoxLayout(w);

    auto *hud = new QLabel(textoHUD());
    hud->setStyleSheet("color:#ffd24a;font-size:15px;font-weight:bold;");
    lay->addWidget(hud);

    auto *titulo = new QLabel(QString("Mundo %1 · %2").arg(mundo).arg(NOMBRE_MUNDO[mundo]));
    QFont ft = titulo->font(); ft.setPointSize(20); ft.setBold(true); titulo->setFont(ft);
    titulo->setStyleSheet("color:#7fd1ff;");
    lay->addWidget(titulo);

    int numero = 0;
    for (int i = 0; i < niveles_.size(); ++i) {
        if (niveles_[i].mundo != mundo) continue;
        ++numero;
        bool hecho = completados_.contains(i);
        QString tipo = niveles_[i].esQuiz ? "Quiz" : "Atrapa la Curva";
        QString txt = QString("Nivel %1 — %2  ·  %3 %4")
                          .arg(numero).arg(niveles_[i].titulo).arg(tipo)
                          .arg(hecho ? "✓" : "");
        auto *btn = new QPushButton(txt);
        btn->setStyleSheet(QString(
            "QPushButton{background:%1;color:#fff;padding:12px;border-radius:8px;font-size:14px;text-align:left;}"
            "QPushButton:hover{background:#37527f;}").arg(hecho ? "#2e7d32" : "#27406b"));
        int idx = i;
        connect(btn, &QPushButton::clicked, this, [this, idx]() { jugarNivel(idx); });
        lay->addWidget(btn);
    }
    lay->addStretch();

    auto *btnMapa = new QPushButton("← Volver al mapa");
    btnMapa->setStyleSheet("QPushButton{background:#37415a;color:#fff;padding:8px;border-radius:6px;}"
                           "QPushButton:hover{background:#445074;}");
    connect(btnMapa, &QPushButton::clicked, this, [this]() { mostrarMapa(); });
    lay->addWidget(btnMapa);

    irADinamica(w);
}

void VentanaJuego::jugarNivel(int indice) {
    const NivelDef &def = niveles_[indice];

    if (def.esQuiz) {
        auto *q = new QuizWidget(def);
        connect(q, &QuizWidget::volverAlMapa, this, [this]() { mostrarMapa(); });
        connect(q, &QuizWidget::respondido, this, [this, indice](bool correcto, int puntos) {
            if (correcto) registrarVictoria(indice, puntos);
            else perderVida("Respuesta incorrecta");
        });
        irADinamica(q);
    } else {
        auto *n = new NivelWidget(def);
        connect(n, &NivelWidget::volverAlMapa, this, [this]() { mostrarMapa(); });
        connect(n, &NivelWidget::nivelGanado, this, [this, indice](int puntos) {
            registrarVictoria(indice, puntos);
        });
        irADinamica(n);
    }
}

// --------------------------- Transiciones ---------------------------
void VentanaJuego::irADinamica(QWidget *w) {
    stack_->addWidget(w);
    stack_->setCurrentWidget(w);
    if (paginaDinamica_ && paginaDinamica_ != w) {
        stack_->removeWidget(paginaDinamica_);
        paginaDinamica_->deleteLater();
    }
    paginaDinamica_ = w;
}

void VentanaJuego::registrarVictoria(int indice, int puntos) {
    bool nuevo = !completados_.contains(indice);
    completados_.insert(indice);
    puntaje_ += puntos;

    if (nuevo) {
        int mundo = niveles_[indice].mundo;
        // ¿Se completo el mundo entero? -> desbloquear el siguiente
        if (completadosMundo(mundo) == totalNivelesMundo(mundo)
            && mundo == mundoDesbloqueado_ && mundo < TOTAL_MUNDOS) {
            mundoDesbloqueado_ = mundo + 1;
            QMessageBox::information(this, "¡Mundo superado!",
                QString("¡Completaste el Mundo %1 (%2)!\n\nSe desbloqueo el Mundo %3: %4")
                    .arg(mundo).arg(NOMBRE_MUNDO[mundo])
                    .arg(mundo + 1).arg(NOMBRE_MUNDO[mundo + 1]));
        } else if (completadosMundo(TOTAL_MUNDOS) == totalNivelesMundo(TOTAL_MUNDOS)
                   && completados_.size() == niveles_.size()) {
            QMessageBox::information(this, "¡Juego completado!",
                QString("¡Felicidades! Dominaste todas las funciones.\n\nPuntaje final: %1")
                    .arg(puntaje_));
        }
    }
}

void VentanaJuego::perderVida(const QString &motivo) {
    --vidas_;
    if (vidas_ <= 0) {
        QMessageBox::warning(this, "Sin vidas",
            QString("%1.\nTe quedaste sin vidas.\n\nPuntaje alcanzado: %2\nVuelves a empezar.")
                .arg(motivo).arg(puntaje_));
        reiniciar();
        stack_->setCurrentIndex(0);
    }
}

void VentanaJuego::reiniciar() {
    puntaje_ = 0;
    vidas_ = 3;
    mundoDesbloqueado_ = 1;
    completados_.clear();
}
