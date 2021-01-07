#include "notewindows.h"
#include "ui_notewindows.h"
#include <QDate>

noteWindows::noteWindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::noteWindows)
{

    ui->setupUi(this);
    setWindowTitle(tr("New note"));
    setWindowFlag(Qt::WindowContextHelpButtonHint,false);
    ui->delButton->setText(tr("Delete"));
    ui->saveButton->setText(tr("Save"));
    ui->lineEdit->setPlaceholderText(tr("Enter name of the note"));
}

noteWindows::~noteWindows()
{

    delete ui;
}

void noteWindows::setDarkTheme()
{
    this->setStyleSheet("background-color:rgb(46, 52, 54)");
    ui->lineEdit->setStyleSheet("color: rgb(255, 0, 255)");
    ui->plainTextEdit->setStyleSheet("color: rgb(182, 0, 255)");
    ui->delButton->setStyleSheet("background-color:rgb(85, 87, 83); color:white");
    ui->saveButton->setStyleSheet("background-color:rgb(85, 87, 83); color:white");
}

void noteWindows::setLightTheme()
{
    this->setStyleSheet("");
    ui->lineEdit->setStyleSheet("");
    ui->plainTextEdit->setStyleSheet("");
    ui->delButton->setStyleSheet("");
    ui->saveButton->setStyleSheet("");
}


void noteWindows::on_saveButton_clicked()
{
    QString nameOfNote = ui->lineEdit->text();
    QString date = QDate::currentDate().toString("dd.MM.yyyy");
    QString note = ui->plainTextEdit->toPlainText();
    CParser::SaveFile(nameOfNote,date,note);
    emit close();
}
