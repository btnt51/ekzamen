#ifndef ALLNOTES_H
#define ALLNOTES_H

#include <QDialog>
#include <QTableWidget>
#include "cparser.h"

namespace Ui {
class allNotes;
}

class allNotes : public QDialog
{
    Q_OBJECT

public:
    explicit allNotes(QWidget *parent = nullptr);
    ~allNotes();

private slots:
    void updateTable();

private:
    Ui::allNotes *ui;      //привязка формы
    QTableWidget *table;   //указатель на таблицу для отображения элементов
    QStringList notes;     //лист QString для записи данных из файла
};

#endif // ALLNOTES_H
