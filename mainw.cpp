#include "mainw.h"
#include "./ui_mainw.h"

MainW::MainW(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainW)
{
    ui->setupUi(this);

    //Svg😿
    //Productos Notables
    ponerSvgEnWidget(ui->widgetFormula1, ":/resources/Cuadrado de binomio.svg");
    ponerSvgEnWidget(ui->widgetFormula2, ":/resources/Diferencia de Cuadrados.svg");
    ponerSvgEnWidget(ui->widgetFormula3, ":/resources/Suma y resta de Cubos.svg");
    ponerSvgEnWidget(ui->widgetFormula4, ":/resources/Ecc Cuadratica.svg");
    //Fracciones
    ponerSvgEnWidget(ui->widgetFormula5, ":/resources/Fracciones/Div.svg");
    ponerSvgEnWidget(ui->widgetFormula6, ":/resources/Fracciones/Mul.svg");
    ponerSvgEnWidget(ui->widgetFormula7, ":/resources/Fracciones/SuRe.svg");
    //Logaritmos
    ponerSvgEnWidget(ui->widgetFormula8, ":/resources/Logaritmos/Camba.svg");
    ponerSvgEnWidget(ui->widgetFormula9, ":/resources/Logaritmos/Cance.svg");
    ponerSvgEnWidget(ui->widgetFormula10, ":/resources/Logaritmos/Def.svg");
    ponerSvgEnWidget(ui->widgetFormula11, ":/resources/Logaritmos/Div.svg");
    ponerSvgEnWidget(ui->widgetFormula12, ":/resources/Logaritmos/Ln.svg");
    ponerSvgEnWidget(ui->widgetFormula13, ":/resources/Logaritmos/Pot.svg");
    ponerSvgEnWidget(ui->widgetFormula14, ":/resources/Logaritmos/Pro.svg");
    //Raíces
    ponerSvgEnWidget(ui->widgetFormula15, ":/resources/Raices/Def.svg");
    ponerSvgEnWidget(ui->widgetFormula16, ":/resources/Raices/DivRaiz.svg");
    ponerSvgEnWidget(ui->widgetFormula17, ":/resources/Raices/Mismo.svg");
    ponerSvgEnWidget(ui->widgetFormula18, ":/resources/Raices/RaizPot.svg");
    ponerSvgEnWidget(ui->widgetFormula19, ":/resources/Raices/RaizProd.svg");
    ponerSvgEnWidget(ui->widgetFormula20, ":/resources/Raices/RaizRaiz.svg");
    //Potencias
    ponerSvgEnWidget(ui->widgetFormula21, ":/resources/Potencias/Def.svg");
    ponerSvgEnWidget(ui->widgetFormula22, ":/resources/Potencias/DivBase.svg");
    ponerSvgEnWidget(ui->widgetFormula23, ":/resources/Potencias/IgualBase.svg");
    ponerSvgEnWidget(ui->widgetFormula24, ":/resources/Potencias/Negativo.svg");
    ponerSvgEnWidget(ui->widgetFormula25, ":/resources/Potencias/PorProd.svg");
    ponerSvgEnWidget(ui->widgetFormula26, ":/resources/Potencias/PotPot.svg");
    ponerSvgEnWidget(ui->widgetFormula27, ":/resources/Potencias/PotRaiz.svg");

    // Sidebar: iconos y tooltip
    ui->btnCalc->setCheckable(true);
    ui->btnForm->setCheckable(true);

    ui->btnCalc->setToolTip("Calculadora");
    ui->btnForm->setToolTip("Formulario");
    ui->btnGit->setToolTip("Revisa nuestro código de Git!! :D");

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
    connect(ui->btnDot, &QPushButton::clicked, this, &MainW::dotPressed);

    connect(ui->btnSun, &QPushButton::clicked, this, []() {
        QDesktopServices::openUrl(QUrl("https://youtu.be/um0ETkJABmI?si=mZgDiMidKMGh4upX"));
    });

    // sidebar
    connect(ui->btnCalc, &QPushButton::clicked, this, &MainW::btnCalc_Pressed);
    connect(ui->btnForm, &QPushButton::clicked, this, &MainW::btnForm_Pressed);
    connect(ui->btnFrac, &QPushButton::clicked, this, &MainW::btnFrac_Pressed);
    connect(ui->btnGit, &QPushButton::clicked, this, []() {
        QDesktopServices::openUrl(QUrl("https://github.com/ItzTercer/MATE"));
    });

    // Botones con stackedWidget
    connect(ui->stackedWidget, &QStackedWidget::currentChanged,
            this, &MainW::actualizarBotonesMenu);

    // Página inicial
    ui->stackedWidget->setCurrentWidget(ui->pageCalc);
    actualizarBotonesMenu();

    //Graficadora de fracciones
    connect(ui->btnGraficarF, &QPushButton::clicked,
            this, &MainW::graficarFraccion);
    ui->graphicsView->setStyleSheet("background: #1F1F1F; border: none;");
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

void MainW::dotPressed()
{
    if (ui->display2->text() == "Error") {
        ui->display2->setText("0");
    }

    QString texto = ui->display2->text();

    if (esperandoNuevoNumero) {
        ui->display2->setText("0.");
        esperandoNuevoNumero = false;
        return;
    }

    if (!texto.contains(".")) {
        ui->display2->setText(texto + ".");
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
    if (op == "^") {
        if (a == 0 && b == 0) return NAN;
        if (b == 0) return 1.0;
        if (a == 0 && b < 0) return NAN;

        return std::pow(a, b);
    }

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

void MainW::btnFrac_Pressed()
{
    ui->stackedWidget->setCurrentWidget(ui->pageFrac);
    ui->textPage->setText("Fracciones");
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

void MainW::graficarFraccion()
{
    bool okNum = false;
    bool okDen = false;

    int num = ui->lineEditNum->text().toInt(&okNum); // numerador
    int den = ui->lineEditDen->text().toInt(&okDen);   // denominador

    if (!okNum || !okDen) {
        QMessageBox::warning(this, "Error", "Ingrese números válidos.");
        return;
    }

    if (den <= 0) {
        QMessageBox::warning(this, "Error", "El denominador debe ser mayor que 0.");
        return;
    }

    if (num < 0 || num > den) {
        QMessageBox::warning(this, "Error", "El numerador debe estar entre 0 y el denominador.");
        return;
    }

    QPieSeries *series = new QPieSeries();
    series->setPieSize(0.75);

    for (int i = 0; i < den; i++) {
        QPieSlice *slice = series->append("", 1);

        if (i < num) {
            slice->setBrush(QColor("#2bbec0"));
        } else {
            slice->setBrush(Qt::white);
        }

        slice->setPen(QPen(QColor("#0b5e8e"), 2));
        slice->setLabelVisible(false);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->legend()->hide();
    chart->setTitle("Representación de fracción");
    chart->setTitleBrush(QBrush(Qt::white));
    chart->setBackgroundVisible(false);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setChart(chart);
}

void MainW::ponerSvgEnWidget(QWidget *contenedor, const QString &rutaSvg)
{
    if (!contenedor) return;

    QLayout *layoutExistente = contenedor->layout();
    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(layoutExistente);

    if (!layout) {
        layout = new QVBoxLayout(contenedor);
        layout->setContentsMargins(0, 0, 0, 0);
    }

    QSvgWidget *svg = new QSvgWidget(contenedor);
    svg->load(rutaSvg);

    layout->addWidget(svg, 0, Qt::AlignCenter);
}

// Destructor
MainW::~MainW()
{
    delete ui;
}