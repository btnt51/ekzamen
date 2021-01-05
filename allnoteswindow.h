#ifndef ALLNOTESWINDOW_H
#define ALLNOTESWINDOW_H

#include <QWidget>
#include "allNotesform.ui"

QT_BEGIN_NAMESPACE
namespace Ui { class allNotesWindow; }
QT_END_NAMESPACE


class allNotesWindow : public QWidget
{
    Q_OBJECT
public:
    explicit allNotesWindow(QWidget *parent = nullptr);

signals:

private:
    Ui::allNotesWindow *ui;

};

allNotesWindow::allNotesWindow(QWidget *parent) : QWidget(parent)
{

}

#endif // ALLNOTESWINDOW_H
