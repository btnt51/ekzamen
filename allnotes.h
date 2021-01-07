#ifndef ALLNOTES_H
#define ALLNOTES_H

#include <QDialog>
#include <QTableWidget>

namespace Ui {
class allNotes;
}

class allNotes : public QDialog
{
    Q_OBJECT

public:
    explicit allNotes(QWidget *parent = nullptr);
    ~allNotes();

private:
    Ui::allNotes *ui;
    QTableWidget *table;
};

#endif // ALLNOTES_H
