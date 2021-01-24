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



    void closeEvent(QCloseEvent *event) override;
public slots:

    void opM();
    void setNote(CNote &note);
signals:
    void openMain();

private:
    Ui::editingWindow *ui;
    CNote &note;
    noteBook &book;
};

#endif // editingWindow_H
