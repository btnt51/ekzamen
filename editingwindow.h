#ifndef editingWindow_H
#define editingWindow_H

#include <QDialog>
#include <noteBook.h>


namespace Ui {
class editingWindow;
}

class editingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit editingWindow(QWidget *parent = nullptr, noteBook *Book = nullptr, CNote *note=nullptr);
    ~editingWindow();



    void closeEvent(QCloseEvent *event) override;     //закрытие формы
public slots:

    void opM();                                       //слот отправки сигнала
    void setNote(CNote &note);                        //слот установки записки
signals:
    void openMain();                                  //сигнал открытия главного окна

private:
    Ui::editingWindow *ui;                            //привязка формы
    CNote &note;                                      //ссылка на заметку
    noteBook &book;                                   //ссылка на записную книжку
};

#endif // editingWindow_H
