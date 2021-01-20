#include "edditingwindow.h"
#include "ui_edditingwindow.h"


edditingWindow::edditingWindow(QWidget *parent, noteBook *Book, CNote *Note) :
    QDialog(parent), ui(new Ui::edditingWindow), note(*Note), book(*Book)
{
    ui->setupUi(this);                                                  //установка формы
    setWindowTitle("Note " + QString::fromStdString(note.getName()));              //установка названия окна
    setWindowFlag(Qt::WindowContextHelpButtonHint,false);               //удаление кнопки
    ui->delButton->setText("Delete");                               //установка названий кнопок
    ui->editButton->setText("Editing");
    ui->lineEdit->setText(QString::fromStdString(note.getName()));
    ui->plainTextEdit->appendPlainText(QString::fromStdString(note.getNote()));
}
void edditingWindow::setNote(CNote &note)
{
    this->note = note;
}

edditingWindow::~edditingWindow()
{
    book.AddingNote(note);
    delete ui;                              //удаление формы
}

void edditingWindow::setDarkTheme()
{
    this->setStyleSheet("background-color:rgb(46, 52, 54)");            //установка цветовой темы
    ui->lineEdit->setStyleSheet("color: rgb(255, 0, 255)");
    ui->plainTextEdit->setStyleSheet("color: rgb(182, 0, 255)");
    ui->delButton->setStyleSheet("background-color:rgb(85, 87, 83); color:white");
    ui->editButton->setStyleSheet("background-color:rgb(85, 87, 83); color:white");
}

void edditingWindow::setLightTheme()
{
    this->setStyleSheet("");                //установка цветовой темы
    ui->lineEdit->setStyleSheet("");
    ui->plainTextEdit->setStyleSheet("");
    ui->delButton->setStyleSheet("");
    ui->editButton->setStyleSheet("");
}


void edditingWindow::on_editButton_clicked()
{
    if(!(ui->lineEdit->text().toStdString() == note.getName()))
        note.setName(ui->lineEdit->text().toStdString());
    if(!(ui->plainTextEdit->toPlainText().toStdString() == note.getNote()))
        note.setNote(ui->plainTextEdit->toPlainText().toStdString());
    book.AddingNote(note);
    emit close();
}



void edditingWindow::on_delButton_clicked()
{
    emit close();
}
