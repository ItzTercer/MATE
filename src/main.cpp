#include "mainw.h"

#include <QApplication>
#include <QFontDatabase>
#include <QFont>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainW w;
    w.setWindowTitle("MATE");
    w.setWindowIcon(QIcon(":/icons/resources/logomate.png"));
    w.show();
    return a.exec();
}