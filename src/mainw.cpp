#include "mainw.h"
#include "./ui_mainw.h"

#include <QDesktopServices>
#include <QUrl>
#include <cmath>

MainW::MainW(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainW)
{
    ui->setupUi(this);

    // Sidebar: iconos y tooltip
    ui->btnCalc->setCheckable(true);
    ui->btnForm->setCheckable(true);

    ui->btnCalc->setToolTip("Calculadora");
    ui->btnForm->setToolTip("Formulario");

    // Botones números
    QPushButton* botonesn[10] = {
        ui->btn0, ui->btn1, ui->btn2, ui->btn3, ui->btn4,
        ui->btn5, ui->btn6, ui->btn7, ui->btn8, ui->btn9
    };

    for (int i = 0; i < 10; i++) {
        connect(botonesn[i], &QPushButton::clicked, this, &MainW::numPressed);
    }

    // Operadores
    QPushButton* operadores[5] = {
        ui->btnSum, ui->btnMin, ui->btnMult, ui->btnDiv, ui->btnPow
    };

    for (int i = 0; i < 5; i++) {
        connect(operadores[i], &QPushButton::clicked, this, &MainW::operatorPressed);
    }

    connect(ui->btnEq,   &QPushButton::clicked, this, &MainW::equalPressed);
    connect(ui->btnLog,  &QPushButton::clicked, this, &MainW::logPressed);
    connect(ui->btnRaiz, &QPushButton::clicked, this, &MainW::sqrtPressed);
    connect(ui->btnC,    &QPushButton::clicked, this, &MainW::clearPressed);
    connect(ui->btnCE,   &QPushButton::clicked, this, &MainW::cePressed);
    connect(ui->btnDel,  &QPushButton::clicked, this, &MainW::delPressed);
    connect(ui->btnNeg,  &QPushButton::clicked, this, &MainW::negatePressed);

    connect(ui->btnSun, &QPushButton::clicked, this, []() {
        QDesktopServices::openUrl(QUrl("https://youtu.be/um0ETkJABmI?si=mZgDiMidKMGh4upX"));
    });

    // sidebar
    connect(ui->btnCalc, &QPushButton::clicked, this, &MainW::btnCalc_Pressed);
    connect(ui->btnForm, &QPushButton::clicked, this, &MainW::btnForm_Pressed);

    // Botones con stackedWidget
    connect(ui->stackedWidget, &QStackedWidget::currentChanged,
            this, &MainW::actualizarBotonesMenu);

    // Página inicial
    ui->stackedWidget->setCurrentWidget(ui->pageCalc);
    actualizarBotonesMenu();
}

// Funciones :D

void MainW::numPressed()
{
    QPushButton *boton = qobject_cast<QPushButton*>(sender());
    if (!boton) return;

    if (ui->display2->text() == "Error") {
        ui->display2->setText("0");
    }

    if (esperandoNuevoNumero) {
        ui->display2->setText(boton->text());
        esperandoNuevoNumero = false;
    } else {
        if (ui->display2->text() == "0") {
            ui->display2->setText(boton->text());
        } else {
            ui->display2->setText(ui->display2->text() + boton->text());
        }
    }
}

void MainW::operatorPressed()
{
    QPushButton *boton = qobject_cast<QPushButton*>(sender());
    if (!boton) return;

    if (ui->display2->text() == "Error") return;

    QString operador = boton->text();
    double numeroActual = ui->display2->text().toDouble();

    if (operacionPendiente.isEmpty()) {
        acumulado = numeroActual;
    } else if (!esperandoNuevoNumero) {
        double resultado = calcular(acumulado, numeroActual, operacionPendiente);

        if (std::isnan(resultado)) {
            ui->display2->setText("Error");
            ui->display1->clear();
            operacionPendiente.clear();
            acumulado = 0.0;
            esperandoNuevoNumero = true;
            return;
        }

        acumulado = resultado;
        ui->display2->setText(QString::number(resultado));
    }

    operacionPendiente = operador;
    ui->display1->setText(QString::number(acumulado) + " " + operador);
    esperandoNuevoNumero = true;
}

double MainW::calcular(double a, double b, const QString& op)
{
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*" || op == "×") return a * b;
    if (op == "/") {
        if (b == 0) return NAN;
        return a / b;
    }
    if (op == "^") return std::pow(a, b);

    return NAN;
}

void MainW::equalPressed()
{
    if (operacionPendiente.isEmpty() || ui->display2->text() == "Error") return;

    double numeroActual = ui->display2->text().toDouble();
    double resultado = calcular(acumulado, numeroActual, operacionPendiente);

    if (std::isnan(resultado)) {
        ui->display2->setText("Error");
        ui->display1->clear();
        operacionPendiente.clear();
        acumulado = 0.0;
        esperandoNuevoNumero = true;
        return;
    }

    ui->display1->setText(QString::number(acumulado) + " " +
                          operacionPendiente + " " +
                          QString::number(numeroActual) + " =");

    ui->display2->setText(QString::number(resultado));

    acumulado = resultado;
    operacionPendiente.clear();
    esperandoNuevoNumero = true;
}

void MainW::logPressed()
{
    if (ui->display2->text() == "Error") return;

    double numeroActual = ui->display2->text().toDouble();

    if (numeroActual <= 0) {
        ui->display2->setText("Error");
        ui->display1->setText("log indef");
        acumulado = 0.0;
        operacionPendiente.clear();
        esperandoNuevoNumero = true;
        return;
    }

    double resultado = std::log10(numeroActual);

    ui->display1->setText("log(" + QString::number(numeroActual) + ")");
    ui->display2->setText(QString::number(resultado));

    acumulado = resultado;
    operacionPendiente.clear();
    esperandoNuevoNumero = true;
}

void MainW::sqrtPressed()
{
    if (ui->display2->text() == "Error") return;

    double numeroActual = ui->display2->text().toDouble();

    if (numeroActual < 0) {
        ui->display2->setText("Error");
        ui->display1->setText("sqrt indef");
        acumulado = 0.0;
        operacionPendiente.clear();
        esperandoNuevoNumero = true;
        return;
    }

    double resultado = std::sqrt(numeroActual);

    ui->display1->setText("√(" + QString::number(numeroActual) + ")");
    ui->display2->setText(QString::number(resultado));

    acumulado = resultado;
    operacionPendiente.clear();
    esperandoNuevoNumero = true;
}

void MainW::clearPressed()
{
    ui->display1->clear();
    ui->display2->setText("0");

    acumulado = 0.0;
    operacionPendiente.clear();
    esperandoNuevoNumero = true;
}

void MainW::cePressed()
{
    ui->display2->setText("0");
    esperandoNuevoNumero = true;
}

void MainW::delPressed()
{
    if (esperandoNuevoNumero || ui->display2->text() == "Error") return;

    QString texto = ui->display2->text();
    texto.chop(1);

    if (texto.isEmpty() || texto == "-") {
        ui->display2->setText("0");
        esperandoNuevoNumero = true;
    } else {
        ui->display2->setText(texto);
    }
}

void MainW::negatePressed()
{
    if (ui->display2->text() == "Error") return;

    QString texto = ui->display2->text();
    double valor = texto.toDouble();

    if (valor > 0.0) {
        texto.prepend("-");
    } else if (valor < 0.0) {
        texto.remove(0, 1);
    }

    ui->display2->setText(texto);
}

void MainW::btnCalc_Pressed()
{
    ui->stackedWidget->setCurrentWidget(ui->pageCalc);
    ui->textPage->setText("Calculadora");
    actualizarBotonesMenu();
}

void MainW::btnForm_Pressed()
{
    ui->stackedWidget->setCurrentWidget(ui->pageForm);
    ui->textPage->setText("Formulario");
    actualizarBotonesMenu();
}

void MainW::actualizarBotonesMenu()
{
    const bool enCalculadora = (ui->stackedWidget->currentWidget() == ui->pageCalc);
    const bool enFormulario  = (ui->stackedWidget->currentWidget() == ui->pageForm);

    ui->btnCalc->setChecked(enCalculadora);
    ui->btnForm->setChecked(enFormulario);

    if (enCalculadora) {
        ui->textPage->setText("Calculadora");
    } else if (enFormulario) {
        ui->textPage->setText("Formulario");
    }
}

// Destructor
MainW::~MainW()
{
    delete ui;
}