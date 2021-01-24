#include "cparser.h"

CParser::CParser(){
}
QStringList CParser::ReadFile()
{
    QStringList Notelist;                       //создания листа QString с заметками
    QFile file("D:\\db.txt");                   //открытие файла
    QByteArray str;                             //создание массива
    if (file.open(QIODevice::ReadOnly))
        str = file.readAll();                    //чтение файла
    file.close();                                //закрытие файла
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    file.close();
    QString temp = QString::fromUtf8(str);       //преобразование массива байтов в строку кодировки UTF8
    Notelist = temp.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);       //разделение на заметки
    //qDebug() << Notelist;
    return Notelist;
}
void CParser::SaveFile(QString nameOfNote, QString note)
{
    note.replace("\n","@%");                         //замена символов
    QString saveLine = nameOfNote + "_" + note;      //создание объекта для разделения названия и текста
    QFile file("D:\\db.txt");                           //открытие файла
    if(file.open(QIODevice::Append |QIODevice::Text))   //цикл для записи с сохранением перехода на новую строку
    {
        QTextStream in(&file);                          //Создание текстового потока в файл
        in.setCodec("UTF-8");                           //установка кодировки
        in << "\n" << saveLine.toUtf8();                //сохранение по линиям
    }
    file.close();                                        //закрытие файла
}
