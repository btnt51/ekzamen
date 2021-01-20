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
    Notelist = temp.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
    //qDebug() << Notelist;
    return Notelist;
}
void CParser::SaveFile(QString nameOfNote, QString note)
{
    note.replace("\n","@%");
    QString saveLine = nameOfNote + "_" + note;      //создание объекта для разделения названия и текста
    QFile file("D:\\db.txt");                           //открытие файла
    if(file.open(QIODevice::Append |QIODevice::Text))   //цикл для записи с сохранением перехода на новую строку
    {
        QTextStream in(&file);
        in.setCodec("UTF-8");
        in << "\n" << saveLine.toUtf8();
    }
    file.close();                                        //закрытие файла
}
