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
    void closeEvent(QCloseEvent *event) override;

public slots:
    void on_saveButton_clicked();       //слот кнопки сохранения

signals:
    void openMain();


private:
    Ui::noteWindows *ui;                //указатель формы заметок
    noteBook &book;

};

#endif // NOTEWINDOWS_H
