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
    Ui::allNotes *ui;
    QTableWidget *table;
    QStringList notes;
};

#endif // ALLNOTES_H
