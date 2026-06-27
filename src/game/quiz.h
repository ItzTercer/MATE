#ifndef definiciones_quiz
#define definiciones_quiz

#include <QWidget>
#include "niveles.h"
#include "plano.h"

class QLabel;
class QPushButton;

/*
 * QuizWidget — reto "Adivina la Funcion".
 * Se dibuja una curva y el jugador elige, entre 4 opciones, la expresion
 * que le corresponde. Acertar suma puntos; fallar gasta una vida.
 */
class QuizWidget : public QWidget {
    Q_OBJECT
public:
    explicit QuizWidget(const NivelDef &def, QWidget *parent = nullptr);

signals:
    void respondido(bool correcto, int puntos);
    void volverAlMapa();

private:
    NivelDef def_;
    QLabel *mensaje_;
    QVector<QPushButton*> botones_;
    bool resuelto_ = false;
};

#endif
