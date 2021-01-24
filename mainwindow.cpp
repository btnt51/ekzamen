#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);                          // установка формы
    widget = new QWidget();                     // создание объектаа виджета
    widget->setLayout(ui->gridLayout);          // установка слоя на виджет
    setCentralWidget(widget);                   // установка центрального виджета
    ui->newNote->setText("New note");       // установка названия кнопок
    ui->allNotes->setText("All notes");     //
    connect(ui->actionNew_note,SIGNAL(triggered()), this, SLOT(on_newNote_clicked()));
    connect(ui->actionAll_notes,SIGNAL(triggered()), this, SLOT(on_allNotes_clicked()));
    Book.getFromFile();
    setWindowTitle("Notebook");
    QWidget *PARENT = nullptr;
    note = new noteWindows(PARENT, &Book);
    connect(note,SIGNAL(openMain()), this,SLOT(show()));
}

MainWindow::~MainWindow()
{
    Book.saveInFile();
    delete ui;   //удаление формы
    delete note;
    delete allnotes;
}


void MainWindow::on_newNote_clicked()
{
    this->close();
    note->show();                                 //отображение окна при нажатии на кнопку

}

void MainWindow::on_allNotes_clicked()
{
    this->close();
    QWidget *PARENT = nullptr;
    CNote *notes = new CNote(" ", " ");
    editingWindow *edWin = new editingWindow(PARENT, &Book, notes);
    allnotes = new allNotes(PARENT,&Book, edWin);
    connect(edWin,SIGNAL(openMain()), this,SLOT(show()));
    connect(allnotes,SIGNAL(openMain()), this,SLOT(show()));
    allnotes->show();                                               //
}


