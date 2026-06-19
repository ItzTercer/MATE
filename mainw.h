#ifndef MAINW_H
#define MAINW_H

#include <QMainWindow>
#include <cmath>
#include <QKeyEvent>
#include <QIcon>
#include <QDesktopServices>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainW;
}
QT_END_NAMESPACE

class MainW : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainW(QWidget *parent = nullptr);
    ~MainW() override;

private slots:
    void numPressed();
    void operatorPressed();
    void equalPressed();
    void logPressed();
    void sqrtPressed();
    void clearPressed();
    void cePressed();
    void delPressed();
    void negatePressed();

    void btnCalc_Pressed();
    void btnForm_Pressed();
    void actualizarBotonesMenu();

private:
    Ui::MainW *ui;

    double calcular(double a, double b, const QString& op);
    double acumulado = 0.0;
    QString operacionPendiente = "";
    bool esperandoNuevoNumero = true;

};
#endif // MAINW_H
