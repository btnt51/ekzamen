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
    QString temp = QString::fromUtf8(str);
    Notelist = temp.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
    //qDebug() << Notelist;
    return Notelist;
}
void CParser::SaveFile(QString nameOfNote, QString note)
{
    QString saveLine = "_"+nameOfNote+""+"_"+note;
    QFile file("D:\\db.txt");

    if(file.open(QIODevice::Append |QIODevice::Text))
    {
        QTextStream in(&file);
        in.setCodec("UTF-8");
        in << "\n" << saveLine.toUtf8();
    }
    file.close();
}
