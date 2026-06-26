#ifndef MAINW_H
#define MAINW_H

#include <QMainWindow>
#include <cmath>
#include <QKeyEvent>
#include <QIcon>
#include <QDesktopServices>
#include <QUrl>
#include <QtCore>
#include <QtGui>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QMessageBox>
#include <QColor>
#include <QPainter>
#include <QSvgWidget>
#include <QPixmap>

// Juego
#include "game/ventanajuego.h"

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
    void dotPressed();
    void btnCalc_Pressed();
    void btnForm_Pressed();
    void btnFrac_Pressed();
    void btnJuego_Pressed();       //botón del juego :3
    void actualizarBotonesMenu();
    void graficarFraccion();

private:
    Ui::MainW *ui;

    void ponerSvgEnWidget(QWidget *contenedor, const QString &rutaSvg);

    double calcular(double a, double b, const QString& op);
    double acumulado = 0.0;
    QString operacionPendiente = "";
    bool esperandoNuevoNumero = true;

    VentanaJuego *ventanaJuego = nullptr;
};
#endif // MAINW_H