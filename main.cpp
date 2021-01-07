#include "mainwindow.h"
#include "cparser.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    CParser::ReadFile();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
