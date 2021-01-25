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
    ui->allNotes->setText("All notes");
    Book.getFromFile();                         //загрузка всех заметок
    setWindowTitle("Notebook");                 //установка названия главного окна
    QWidget *PARENT = nullptr;                  //необходимо для создания объекта
    note = new noteWindows(PARENT, &Book);      //создание окна новой заметки
    connect(ui->actionNew_note, SIGNAL(triggered()), this, SLOT(on_newNote_clicked()));      //установка связей
    connect(ui->actionAll_notes, SIGNAL(triggered()), this, SLOT(on_allNotes_clicked()));
    connect(note,SIGNAL(openMain()), this,SLOT(show()));              //установка связи
    connect(ui->actionHelp, SIGNAL(triggered()), this, SLOT(openHelp()));
}

MainWindow::~MainWindow()
{
    Book.saveInFile();                          //сохранение заметки
    delete ui;                                  //удаление формы
    delete note;                                //удаление окна новой заметки
    delete allnotes;                            //удаление окна всвех заметок
    delete widget;
}


void MainWindow::on_newNote_clicked()
{
    this->close();                                //закрытие главного окна
    note->show();                                 //отображение окна при нажатии на кнопку

}

void MainWindow::on_allNotes_clicked()
{
    this->close();                                //закрытие главного окна
    QWidget *PARENT = nullptr;                    //необходимо для создания объекта
    CNote *notes = new CNote(" ", " ");
    editingWindow *edWin = new editingWindow(PARENT, &Book, notes);           //создания окна редактирования заметок
    allnotes = new allNotes(PARENT,&Book, edWin);                             //создание окна всех заметок
    connect(edWin,SIGNAL(openMain()), this,SLOT(show()));                     //установка связей
    connect(allnotes,SIGNAL(openMain()), this,SLOT(show()));
    allnotes->show();                                                         //открытие окна со всеми заметками
}

void MainWindow::openHelp()
{
    helpWindow * help = new helpWindow;
    help->show();
}


