#ifndef NOTEWINDOWS_H
#define NOTEWINDOWS_H

#include <QDialog>
#include <QDebug>
#include "cparser.h"
#include "noteBook.h"

namespace Ui {
class noteWindows;
}



class noteWindows : public QDialog
{
    Q_OBJECT

public:
    explicit noteWindows(QWidget *parent = nullptr, noteBook *book = nullptr);
    ~noteWindows();

public slots:
    void setLightTheme();               //слот установки светлой темы
    void setDarkTheme();                //слот установки темной темы
    void on_saveButton_clicked();       //слот кнопки сохранения

private:
    Ui::noteWindows *ui;                //указатель формы заметок
    noteBook &book;

};

#endif // NOTEWINDOWS_H
