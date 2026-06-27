#include "quiz.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFont>

QuizWidget::QuizWidget(const NivelDef &def, QWidget *parent)
    : QWidget(parent), def_(def) {

    auto *root = new QVBoxLayout(this);

    auto *titulo = new QLabel(QString("Mundo %1  ·  Adivina la Funcion").arg(def_.mundo));
    QFont ft = titulo->font(); ft.setPointSize(15); ft.setBold(true); titulo->setFont(ft);
    titulo->setStyleSheet("color:#7fd1ff;");
    root->addWidget(titulo);

    auto *sub = new QLabel("Observa la curva azul. ¿Que expresion la representa?");
    sub->setStyleSheet("color:#aab4c8;");
    root->addWidget(sub);

    // Grafico: mostramos SOLO la curva objetivo (sin la del jugador)
    auto *plano = new PlanoWidget(this);
    plano->setRango(-10, 10, -10, 10);
    plano->setObjetivo(def_.objetivo);
    plano->setMostrarJugador(false);
    root->addWidget(plano, 1);

    // Botones de opciones
    for (int i = 0; i < def_.opciones.size(); ++i) {
        auto *b = new QPushButton(def_.opciones[i]);
        b->setStyleSheet("QPushButton{background:#2a3245;color:#fff;padding:10px;border-radius:6px;font-size:14px;}"
                         "QPushButton:hover{background:#37415a;}");
        int idx = i;
        connect(b, &QPushButton::clicked, this, [this, idx]() {
            if (resuelto_) return;
            resuelto_ = true;
            bool correcto = (idx == def_.correcta);
            // Pinta verde la correcta y roja la elegida si fallo
            botones_[def_.correcta]->setStyleSheet(
                "QPushButton{background:#2e7d32;color:#fff;padding:10px;border-radius:6px;font-size:14px;font-weight:bold;}");
            if (!correcto)
                botones_[idx]->setStyleSheet(
                    "QPushButton{background:#a52727;color:#fff;padding:10px;border-radius:6px;font-size:14px;}");

            if (correcto) {
                mensaje_->setStyleSheet("color:#56e68c;");
                mensaje_->setText("✓ ¡Correcto! +80 puntos");
            } else {
                mensaje_->setStyleSheet("color:#ff8a80;");
                mensaje_->setText("✗ Incorrecto. " + def_.pista + " (pierdes una vida)");
            }
            emit respondido(correcto, correcto ? 80 : 0);
        });
        botones_.push_back(b);
        root->addWidget(b);
    }

    mensaje_ = new QLabel(def_.pista);
    mensaje_->setWordWrap(true);
    mensaje_->setStyleSheet("color:#ffd24a;");
    root->addWidget(mensaje_);

    auto *btnVolver = new QPushButton("← Volver al mapa");
    btnVolver->setStyleSheet("QPushButton{background:#37415a;color:#fff;padding:6px;border-radius:6px;}"
                             "QPushButton:hover{background:#445074;}");
    connect(btnVolver, &QPushButton::clicked, this, &QuizWidget::volverAlMapa);
    root->addWidget(btnVolver);
}
