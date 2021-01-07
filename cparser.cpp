#include "cparser.h"

CParser::CParser(){
}
QStringList CParser::ReadFile()
{
    QStringList Notelist;
    QFile file("D:\\db.txt");
    QByteArray str;
    if (file.open(QIODevice::ReadOnly))
        str = file.readAll();
    file.close();
    Notelist = QString(str).split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
    qDebug() << Notelist;
    return Notelist;
}
void CParser::SaveFile(QString nameOfNote, QString date, QString note)
{
    QString saveLine = "NameofNote_"+nameOfNote+"_Date_"+ date + "_Note_"+note.remove("\n");
    QFile file("D:\\db.txt");

    if(file.open(QIODevice::Append |QIODevice::Text))
    {
        QTextStream in(&file);
        in << "\n" << saveLine;
    }
    file.close();
}
