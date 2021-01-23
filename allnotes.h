#ifndef ALLNOTES_H
#define ALLNOTES_H

#include <QDialog>
#include <QTableWidget>
#include <QCloseEvent>
#include "cparser.h"
#include "noteBook.h"
#include "editingWindow.h"


namespace Ui {
class allNotes;
}

class allNotes : public QDialog
{
    Q_OBJECT

public:
    explicit allNotes(QWidget *parent = nullptr, noteBook *Book = nullptr, editingWindow *EDWIN = nullptr);
    ~allNotes();
    void closeEvent(QCloseEvent *event) override;

private slots:
    void openNoteWindow();
signals:
    void openMain();

private:
    Ui::allNotes *ui;      //привязка формы
    QTableWidget *table;   //указатель на таблицу для отображения элементов
    noteBook &book;
    editingWindow *edWin;
};

#endif // ALLNOTES_H
