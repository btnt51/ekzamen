#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //CParser::ReadFile(true);
    QApplication a(argc, argv); //создания объекта приложения
    MainWindow w;               //создание объекта главного окна
    w.show();                   //отображение главного окна
    return a.exec();            //запуск приложения
}
