#ifndef ALLNOTES_H
#define ALLNOTES_H

#include <QDialog>
#include <QTableWidget>
#include "cparser.h"
#include "noteBook.h"

namespace Ui {
class allNotes;
}

class allNotes : public QDialog
{
    Q_OBJECT

public:
    explicit allNotes(QWidget *parent = nullptr, noteBook *Book = nullptr);
    ~allNotes();

private slots:
    void updateTable();
    void openNoteWindow();


private:
    Ui::allNotes *ui;      //привязка формы
    QTableWidget *table;   //указатель на таблицу для отображения элементов
    noteBook &book;
};

#endif // ALLNOTES_H
