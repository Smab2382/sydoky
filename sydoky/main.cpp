#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <string>

int main(int argc, char *argv[])
{    QApplication a1(argc, argv);
     MainWindow w;

      w.show();
    return a1.exec();
}
