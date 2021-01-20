#ifndef EDDITINGWINDOW_H
#define EDDITINGWINDOW_H

#include <QDialog>
#include <noteBook.h>

namespace Ui {
class edditingWindow;
}

class edditingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit edditingWindow(QWidget *parent = nullptr, noteBook *Book = nullptr, CNote *note=nullptr);
    ~edditingWindow();

    void setNote(CNote &note);
public slots:
    void on_editButton_clicked();
    void setLightTheme();               //слот установки светлой темы
    void setDarkTheme();                //слот установки темной темы

private slots:
    void on_delButton_clicked();

private:
    Ui::edditingWindow *ui;
    CNote &note;
    noteBook &book;
};

#endif // EDDITINGWINDOW_H
