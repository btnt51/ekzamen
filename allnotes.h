#ifndef ALLNOTES_H
#define ALLNOTES_H

#include <QDialog>
#include <QTableWidget>
#include <QCloseEvent>
#include "cparser.h"
#include "noteBook.h"
#include "editingwindow.h"


namespace Ui {
class allNotes;
}

class allNotes : public QDialog
{
    Q_OBJECT

public:
    explicit allNotes(QWidget *parent = nullptr, noteBook *Book = nullptr, editingWindow *EDWIN = nullptr);
    ~allNotes();
    void closeEvent(QCloseEvent *event) override;           //закрытие формы

private slots:
    void openNoteWindow();          //слот открытия окна заметок
signals:
    void openMain();                //сигнал открытия главного окна

private:
    Ui::allNotes *ui;      //привязка формы
    QTableWidget *table;   //указатель на таблицу для отображения элементов
    noteBook &book;         //ссылка на записную книжку
    editingWindow *edWin;   //указатель на окно редактирования заметок
};

#endif // ALLNOTES_H
