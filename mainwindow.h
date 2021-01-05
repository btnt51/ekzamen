#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "settingswindows.h"
#include "notewindows.h"

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
    void on_lineEdit_returnPressed();

    void on_newNote_clicked();

    void on_Settings_clicked();

private:
    Ui::MainWindow *ui;
    settingsWindows *sWindow;
    noteWindows *note;
};
#endif // MAINWINDOW_H
