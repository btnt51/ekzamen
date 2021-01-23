#include "editingWindow.h"
#include "ui_editingWindow.h"


editingWindow::editingWindow(QWidget *parent, noteBook *Book, CNote *Note) :
    QDialog(parent), ui(new Ui::editingWindow), note(*Note), book(*Book)
{
    ui->setupUi(this);                                                  //установка формы
    setWindowTitle("Note " + QString::fromStdString(note.getName()));              //установка названия окна
    setWindowFlag(Qt::WindowContextHelpButtonHint,false);               //удаление кнопки
    ui->delButton->setText("Delete");                               //установка названий кнопок
    ui->editButton->setText("Save changes");
    ui->lineEdit->setText(QString::fromStdString(note.getName()));
    ui->plainTextEdit->setPlainText(QString::fromStdString(note.getNote()));
    connect(ui->delButton, SIGNAL(clicked()), this, SLOT(reject()));
    connect(ui->delButton, SIGNAL(clicked()), this, SLOT(opM()));
}

void editingWindow::setNote(CNote &Note)
{
    setWindowTitle("Note " + QString::fromStdString(Note.getName()));              //установка названия окна
    ui->lineEdit->setText(QString::fromStdString(Note.getName()));
    ui->plainTextEdit->setPlainText(QString::fromStdString(Note.getNote()));
}

editingWindow::~editingWindow()
{
    //book.AddingNote(note);
    delete ui;                              //удаление формы
}

void editingWindow::on_editButton_clicked()
{
    if(!(ui->lineEdit->text().toStdString() == note.getName()))
        note.setName(ui->lineEdit->text().toStdString());
    if(!(ui->plainTextEdit->toPlainText().toStdString() == note.getNote()))
        note.setNote(ui->plainTextEdit->toPlainText().toStdString());
    //book.AddingNote(note);
    emit close();
}

void editingWindow::opM()
{
    emit openMain();
}

void editingWindow::closeEvent(QCloseEvent* event)
{
    //on_editButton_clicked();
    if(!(ui->lineEdit->text().toStdString() == note.getName()))
        note.setName(ui->lineEdit->text().toStdString());
    if(!(ui->plainTextEdit->toPlainText().toStdString() == note.getNote()))
        note.setNote(ui->plainTextEdit->toPlainText().toStdString());
    emit openMain();
    book.AddingNote(note);
    event->accept();
}
