#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv); //создания объекта приложения
    QApplication::setStyle("Fusion");   //установка стиля
    MainWindow w;               //создание объекта главного окна
    w.show();                   //отображение главного окна
    return app.exec();            //запуск приложения
}
