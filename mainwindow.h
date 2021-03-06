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
    void on_newNote_clicked();   //слот нажатия на кнопку "Новая заметка"
    void on_allNotes_clicked();  //слот нажатия на кнопку "Все заметки"
    void setDarkTheme();         //слот установки темной темы
    void setLightTheme();        //слот установки светлой темы

private:
    Ui::MainWindow *ui;          //указатель на форму главного окна
    noteWindows *note;           //указатель на окно новой заметки
    allNotes *allnotes;          //указатель на окно всех заметок
    QWidget *widget;             //указатель на виджет
};
#endif // MAINWINDOW_H
