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
    //connect();
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


void edditingWindow::on_editButton_clicked()
{
    if(!(ui->lineEdit->text().toStdString() == note.getName()))
        note.setName(ui->lineEdit->text().toStdString());
    if(!(ui->plainTextEdit->toPlainText().toStdString() == note.getNote()))
        note.setNote(ui->plainTextEdit->toPlainText().toStdString());
    book.AddingNote(note);
    emit close();
}

void edditingWindow::closeEvent(QCloseEvent* event)
{
    book.AddingNote(note);
    event->accept();
}

void edditingWindow::on_delButton_clicked()
{
    emit close();
}
