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

void noteWindows::closeEvent(QCloseEvent *event)
{
    emit openMain();        //отпрака сигнала на открытие главного окна
    event->accept();        //окно закрыто
}

void noteWindows::on_saveButton_clicked()
{
    if(ui->lineEdit->text().toStdString().length() != 0 && ui->plainTextEdit->toPlainText().toStdString().length() != 0)
    {
        book.AddingNote(ui->lineEdit->text().toStdString(), ui->plainTextEdit->toPlainText().toStdString());      //добавление заметки
    }
    ui->lineEdit->clear();                                 //очистка поля названия
    ui->plainTextEdit->clear();                            //очистка поля заметки
    emit close();                                          //отправка сигнала закрытия
}


