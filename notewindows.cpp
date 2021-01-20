#include "notewindows.h"
#include "ui_notewindows.h"



noteWindows::noteWindows(QWidget *parent, noteBook *Book) :
    QDialog(parent),
    ui(new Ui::noteWindows), book(*Book)
{
    ui->setupUi(this);                                                  //установка формы
    setWindowTitle("New note");                                     //установка названия окна
    setWindowFlag(Qt::WindowContextHelpButtonHint,false);               //удаление кнопки
    ui->saveButton->setText("Save");                                //установка названия кнопки
    ui->lineEdit->setPlaceholderText("Enter name of the note");     //установка плэйсхолдера
}



noteWindows::~noteWindows()
{
    delete ui;                              //удаление формы
}

void noteWindows::setDarkTheme()
{
    this->setStyleSheet("background-color:rgb(46, 52, 54)");            //установка цветовой темы
    ui->lineEdit->setStyleSheet("color: rgb(255, 0, 255)");
    ui->plainTextEdit->setStyleSheet("color: rgb(182, 0, 255)");
    ui->saveButton->setStyleSheet("background-color:rgb(85, 87, 83); color:white");
}

void noteWindows::setLightTheme()
{
    this->setStyleSheet("");                //установка цветовой темы
    ui->lineEdit->setStyleSheet("");
    ui->plainTextEdit->setStyleSheet(""); 
    ui->saveButton->setStyleSheet("");
}


void noteWindows::on_saveButton_clicked()
{
    book.AddingNote(ui->lineEdit->text().toStdString(), ui->plainTextEdit->toPlainText().toStdString());
    ui->lineEdit->clear();                                 //очистка поля названия
    ui->plainTextEdit->clear();                            //очистка поля заметки
    emit close();                                          //отправка сигнала закрытия
}


