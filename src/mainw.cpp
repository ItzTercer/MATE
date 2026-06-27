#include "mainw.h"
#include "./ui_mainw.h"
#include "calc.h"

MainW::MainW(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainW)
{
    ui->setupUi(this);

    ui->scrollAreaForm->setWidgetResizable(true);
    ui->scrollAreaForm->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

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
    //Límites
    ponerSvgEnWidget(ui->widgetFormula28, ":/resources/Limites/sen-notable.svg");
    ponerSvgEnWidget(ui->widgetFormula29, ":/resources/Limites/cos-notable.svg");
    ponerSvgEnWidget(ui->widgetFormula30, ":/resources/Limites/cos-notable-2.svg");
    ponerSvgEnWidget(ui->widgetFormula31, ":/resources/Limites/e.svg");
    ponerSvgEnWidget(ui->widgetFormula32, ":/resources/Limites/e-2.svg");
    ponerSvgEnWidget(ui->widgetFormula33, ":/resources/Limites/e-3.svg");
    ponerSvgEnWidget(ui->widgetFormula34, ":/resources/Limites/ln-1.svg");
    ponerSvgEnWidget(ui->widgetFormula35, ":/resources/Limites/ln-2.svg");
    //Derivadas
    ponerSvgEnWidget(ui->widgetFormula36, ":/resources/Derivadas/constante.svg");
    ponerSvgEnWidget(ui->widgetFormula37, ":/resources/Derivadas/funcion.svg");
    ponerSvgEnWidget(ui->widgetFormula38, ":/resources/Derivadas/division.svg");
    ponerSvgEnWidget(ui->widgetFormula39, ":/resources/Derivadas/der-e.svg");
    ponerSvgEnWidget(ui->widgetFormula40, ":/resources/Derivadas/producto.svg");
    ponerSvgEnWidget(ui->widgetFormula41, ":/resources/Derivadas/der-sen.svg");
    ponerSvgEnWidget(ui->widgetFormula42, ":/resources/Derivadas/der-cos.svg");
    ponerSvgEnWidget(ui->widgetFormula43, ":/resources/Derivadas/punto.svg");
    ponerSvgEnWidget(ui->widgetFormula44, ":/resources/Derivadas/der-ln.svg");
    ponerSvgEnWidget(ui->widgetFormula45, ":/resources/Derivadas/potencia.svg");
    ponerSvgEnWidget(ui->widgetFormula46, ":/resources/Derivadas/Cadena.svg");
    //Trigonometría
    ponerSvgEnWidget(ui->widgetFormula47, ":/resources/Trigonometria/Pitagorica.svg");
    ponerSvgEnWidget(ui->widgetFormula48, ":/resources/Trigonometria/Pitagorica2.svg");
    ponerSvgEnWidget(ui->widgetFormula49, ":/resources/Trigonometria/Pitagorica3.svg");
    ponerSvgEnWidget(ui->widgetFormula50, ":/resources/Trigonometria/Tan.svg");
    ponerSvgEnWidget(ui->widgetFormula51, ":/resources/Trigonometria/cos-doble.svg");
    ponerSvgEnWidget(ui->widgetFormula52, ":/resources/Trigonometria/cos-suma.svg");
    ponerSvgEnWidget(ui->widgetFormula53, ":/resources/Trigonometria/cot.svg");
    ponerSvgEnWidget(ui->widgetFormula54, ":/resources/Trigonometria/sec.svg");
    ponerSvgEnWidget(ui->widgetFormula55, ":/resources/Trigonometria/tan-suma.svg");
    ponerSvgEnWidget(ui->widgetFormula56, ":/resources/Trigonometria/tan-doble.svg");
    ponerSvgEnWidget(ui->widgetFormula57, ":/resources/Trigonometria/csc.svg");
    ponerSvgEnWidget(ui->widgetFormula58, ":/resources/Trigonometria/sen-suma.svg");

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
    connect(ui->btnJuego, &QPushButton::clicked, this, &MainW::btnJuego_Pressed);
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
    ui->graphicsView->hide();
    ui->labelPlaceholderFrac->show();

    // Al final del constructor MainW::MainW en mainw.cpp
    ui->stackedWidget->removeWidget(ui->pageForm);
    ui->pageForm->setParent(nullptr, Qt::Window);
    ui->pageForm->setWindowTitle("Formulario Matemático");
    ui->pageForm->resize(450, 600);

    // Asignar un diseño para que el scrollArea ocupe toda la ventana flotante
    QVBoxLayout *layoutForm = new QVBoxLayout(ui->pageForm);
    layoutForm->setContentsMargins(0, 0, 0, 0);
    layoutForm->addWidget(ui->scrollAreaForm);

    // Al final del constructor MainW::MainW en mainw.cpp
    QPushButton *btnPi = new QPushButton("π", this);
    QPushButton *btnE = new QPushButton("e", this);

    // Se añaden a la fila 6. Cada uno ocupa 1 fila de alto y 2 columnas de ancho
    ui->gridLayout->addWidget(btnPi, 6, 0, 1, 2);
    ui->gridLayout->addWidget(btnE, 6, 2, 1, 2);

    // Conexión de señales a la lógica de la calculadora
    connect(btnPi, &QPushButton::clicked, this, &MainW::constantPressed);
    connect(btnE, &QPushButton::clicked, this, &MainW::constantPressed);

    // Dentro del constructor MainW::MainW de mainw.cpp
    btnGraficadora = new QToolButton(ui->widgetMenu);
    btnGraficadora->setToolTip("Graficadora Animada");
    btnGraficadora->setCheckable(true);
    btnGraficadora->setGeometry(30, 210, 41, 41);

    // Configuración del elemento como icono de recursos
    btnGraficadora->setIcon(QIcon(":/icons/resources/graficon.png"));
    btnGraficadora->setToolButtonStyle(Qt::ToolButtonIconOnly);

    connect(btnGraficadora, &QToolButton::clicked, this, &MainW::btnGraficadora_Pressed);
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

        if (std::isnan(resultado) || std::isinf(resultado)) {
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

    if (std::isnan(resultado) || std::isinf(resultado)) {
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

    QDialog dialog(this);
    dialog.setWindowTitle("Cálculo de Logaritmo");
    dialog.setStyleSheet(
        "QDialog { background-color: #202020; color: white; }"
        "QLabel { color: white; font-size: 14px; font-weight: bold; }"
        "QLineEdit { background-color: #3a3a3a; color: white; border: 1px solid #242424; border-radius: 5px; padding: 6px; font-size: 14px; }"
        "QPushButton { background-color: #3a3a3a; color: white; border: 1px solid #242424; border-radius: 6px; padding: 6px 14px; font-size: 14px; }"
        "QPushButton:hover { background-color: #2f2f2f; }"
        "QPushButton:pressed { background-color: #272727; }"
        );

    QFormLayout form(&dialog);
    form.setContentsMargins(20, 20, 20, 20);
    form.setSpacing(12);

    QLineEdit *txtBase = new QLineEdit(&dialog);
    txtBase->setText("10");

    QLineEdit *txtArgumento = new QLineEdit(&dialog);

    QString valorActual = ui->display2->text();
    if (valorActual != "0" && valorActual != "Error") {
        txtArgumento->setText(valorActual);
    }

    form.addRow("Base (e y pi, disponible):", txtBase);
    form.addRow("Argumento:", txtArgumento);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);

    buttonBox.button(QDialogButtonBox::Ok)->setStyleSheet(
        "QPushButton { background-color: #0096c7; color: white; font-weight: bold; }"
        "QPushButton:hover { background-color: #023e8a; }"
        "QPushButton:pressed { background-color: #03045e; }"
        );

    connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {
        // Expresión lambda interna para evaluar texto o constantes mapeadas
        auto parseValor = [](const QString &texto) -> double {
            QString t = texto.trimmed().toLower();
            if (t == "e") return constante_e;
            if (t == "pi" || t == "π") return constante_pi;
            bool ok;
            double v = t.toDouble(&ok);
            if (!ok) return -1.0;
            return v;
        };

        double base = parseValor(txtBase->text());
        double argumento = parseValor(txtArgumento->text());

        // Validación de restricciones de dominio o errores de sintaxis (-1.0)
        if (base <= 0.0 || base == 1.0 || argumento <= 0.0) {
            ui->display2->setText("Error");
            ui->display1->setText("log indefinido");
            acumulado = 0.0;
            operacionPendiente.clear();
            esperandoNuevoNumero = true;
            return;
        }

        double resultado = std::log(argumento) / std::log(base);

        ui->display1->setText(QString("log_%1(%2)")
                                  .arg(txtBase->text().trimmed())
                                  .arg(txtArgumento->text().trimmed()));
        ui->display2->setText(QString::number(resultado, 'g', 12));

        acumulado = resultado;
        operacionPendiente.clear();
        esperandoNuevoNumero = true;
    }
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
    if (ui->pageForm) {
        ui->pageForm->show();
        ui->pageForm->raise();
        ui->pageForm->activateWindow();
    }
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

    ui->btnCalc->setChecked(enCalculadora);
    ui->btnForm->setChecked(false);

    if (enCalculadora) {
        ui->textPage->setText("Calculadora");
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

    ui->labelPlaceholderFrac->hide();
    ui->graphicsView->show();
}

void MainW::ponerSvgEnWidget(QWidget *contenedor, const QString &rutaSvg)
{
    if (!contenedor) return;

    // Forzar a la página contenedora del QToolBox a usar un layout responsivo si no lo tiene
    QWidget *paginaPadre = contenedor->parentWidget();
    if (paginaPadre && !paginaPadre->layout()) {
        QVBoxLayout *layoutPadre = new QVBoxLayout(paginaPadre);
        layoutPadre->setContentsMargins(0, 0, 0, 0);
        layoutPadre->addWidget(contenedor);
    }

    // Limpieza de elementos del layout previo para evitar duplicidad
    if (contenedor->layout()) {
        QLayoutItem *item;
        while ((item = contenedor->layout()->takeAt(0)) != nullptr) {
            if (item->widget()) delete item->widget();
            delete item;
        }
        delete contenedor->layout();
    }

    // Permitir la expansión dimensional del contenedor dentro del espacio disponible de la pestaña
    contenedor->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Configurar el layout interno con márgenes de seguridad para evitar desbordamiento perimetral
    QVBoxLayout *layoutInterno = new QVBoxLayout(contenedor);
    layoutInterno->setContentsMargins(16, 16, 16, 16);

    QSvgWidget *svg = new QSvgWidget(contenedor);
    svg->load(rutaSvg);
    svg->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    // Centrar el elemento preservando sus dimensiones y relaciones de aspecto nativas sin recortarlo
    layoutInterno->addWidget(svg, 0, Qt::AlignCenter);
}

void MainW::constantPressed()
{
    QPushButton *boton = qobject_cast<QPushButton*>(sender());
    if (!boton) return;

    if (ui->display2->text() == "Error") {
        ui->display2->setText("0");
    }

    double valorConstante = 0.0;
    if (boton->text() == "π") {
        valorConstante = constante_pi;
    } else if (boton->text() == "e") {
        valorConstante = constante_e;
    }

    // Formatea el número flotante con formato general 'g' de hasta 12 dígitos de precisión
    ui->display2->setText(QString::number(valorConstante, 'g', 12));
    esperandoNuevoNumero = false;
}

void MainW::btnGraficadora_Pressed()
{
    btnGraficadora->setChecked(false);
    if (!ventanaGraficadora) {
        ventanaGraficadora = new GraficadoraWindow();
    }
    ventanaGraficadora->show();
    ventanaGraficadora->raise();
    ventanaGraficadora->activateWindow();
    ventanaGraficadora->iniciarAnimacion();
}

//Juego ^^
void MainW::btnJuego_Pressed()
{

    if (!ventanaJuego) {
        ventanaJuego = new VentanaJuego();
    }
    ventanaJuego->show();
    ventanaJuego->raise();
    ventanaJuego->activateWindow();
}

// Destructor
MainW::~MainW()
{
    delete ui;
}