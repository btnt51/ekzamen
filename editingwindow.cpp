#include "editingwindow.h"
#include "ui_editingwindow.h"


editingWindow::editingWindow(QWidget *parent, noteBook *Book, CNote *Note) :
    QDialog(parent), ui(new Ui::editingWindow), note(*Note), book(*Book)
{
    ui->setupUi(this);                                                              //установка формы
    setWindowTitle("Note " + QString::fromStdString(note.getName()));               //установка названия окна
    setWindowFlag(Qt::WindowContextHelpButtonHint,false);                           //удаление кнопки подсказки
    ui->delButton->setText("Delete");                                               //установка названий кнопок
    ui->editButton->setText("Save changes");
    connect(ui->delButton, SIGNAL(clicked()), this, SLOT(reject()));                //установка связей
    connect(ui->delButton, SIGNAL(clicked()), this, SLOT(opM()));
    connect(ui->editButton, SIGNAL(clicked()), this, SLOT(close()));
}

void editingWindow::setNote(CNote &Note)
{
    note.setName(Note.getName());
    note.setNote(Note.getNote());
    setWindowTitle("Note " + QString::fromStdString(note.getName()));              //установка названия окна
    ui->lineEdit->setText(QString::fromStdString(note.getName()));                 //установка названия заметки
    ui->plainTextEdit->setPlainText(QString::fromStdString(note.getNote()));       //установка текста заметки
}

editingWindow::~editingWindow()
{
    delete ui;                                                                      //удаление формы
}


void editingWindow::opM()
{
    emit openMain();                        //отпрака сигнала на открытие главного окна
}

void editingWindow::closeEvent(QCloseEvent* event)
{
    if(!(ui->lineEdit->text().toStdString() == note.getName()))
        note.setName(ui->lineEdit->text().toStdString());                       //изменения названия заметки
    if(!(ui->plainTextEdit->toPlainText().toStdString() == note.getNote()))
        note.setNote(ui->plainTextEdit->toPlainText().toStdString());           //изменение текста заметки
    if(!(note.getName().length() == 0 || note.getNote().length() == 0))
        book.AddingNote(note);                                                  //сохранение заметки
    opM();                  //вызов функции отправки сигнала
    event->accept();        //окно закрыто
}
