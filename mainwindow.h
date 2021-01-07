#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "notewindows.h"
#include "allnotes.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_newNote_clicked();
    void on_allNotes_clicked();
    void setDarkTheme();
    void setLightTheme();

private:
    Ui::MainWindow *ui;
    noteWindows *note;
    allNotes *allnotes;
    QWidget *widget;
};
#endif // MAINWINDOW_H
