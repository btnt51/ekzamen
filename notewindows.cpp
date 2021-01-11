#include "notewindows.h"
#include "ui_notewindows.h"


noteWindows::noteWindows(QWidget *parent, bool isNew) :
    QDialog(parent),
    ui(new Ui::noteWindows)
{
    if(isNew)
    {
        ui->setupUi(this);                                                  //установка формы
        setWindowTitle(tr("New note"));                                     //установка названия окна
        setWindowFlag(Qt::WindowContextHelpButtonHint,false);               //удаление кнопки
        ui->delButton->setText(tr("Delete"));                               //установка названий кнопок
        ui->saveButton->setText(tr("Save"));                                //
        ui->lineEdit->setPlaceholderText(tr("Enter name of the note"));     //установка плэйсхолдера
        //connect(this, &QDialog::done, this, &noteWindows::emitSignal);
    }
}

noteWindows::noteWindows(QWidget *parent, QString name, QString note, bool isNew) :
    QDialog(parent), ui(new Ui::noteWindows)
{
    if(!isNew)
    {
        ui->setupUi(this);                                                  //установка формы
        setWindowTitle(tr("Note") + name);                                     //установка названия окна
        setWindowFlag(Qt::WindowContextHelpButtonHint,false);               //удаление кнопки
        ui->delButton->setText(tr("Delete"));                               //установка названий кнопок
        ui->saveButton->setText(tr("Save"));
        ui->lineEdit->setText(name);
        ui->plainTextEdit->appendPlainText(note);
        connect(this, &QDialog::finished, this, &noteWindows::emitSignal);
    }
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
    ui->delButton->setStyleSheet("background-color:rgb(85, 87, 83); color:white");
    ui->saveButton->setStyleSheet("background-color:rgb(85, 87, 83); color:white");
}

void noteWindows::setLightTheme()
{
    this->setStyleSheet("");                //установка цветовой темы
    ui->lineEdit->setStyleSheet("");
    ui->plainTextEdit->setStyleSheet("");
    ui->delButton->setStyleSheet("");
    ui->saveButton->setStyleSheet("");
}


void noteWindows::on_saveButton_clicked()
{
    /*QString nameOfNote = ui->lineEdit->text();             // создание строк и заполнение
    QString note = ui->plainTextEdit->toPlainText();       //
    ui->lineEdit->clear();                                 //очистка поля названия
    ui->plainTextEdit->clear();                            //очистка поля заметки
    CParser::SaveFile(nameOfNote,note);                    //вызов функции сохранеия файла
    emit close();   */                                       //отправка сигнала закрытия
    CObjectNote note(ui->lineEdit->text().toStdString(),ui->plainTextEdit->toPlainText().toStdString());
    CParser::SaveFile(note);
}

void noteWindows::emitSignal()
{
    emit allNote();
}
