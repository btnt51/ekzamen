#include "cparser.h"

CParser::CParser(){
}
QList <QString> CParser::ReadFile()
{
    QList <QString> Notelist;
    QFile file("myfile.txt");
    QString str = "";
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        while(!file.atEnd())
        {
               str << file.readLine());
            qDebug() << str;
        }
    }

}
void CParser::SaveFile(QString, QString, QString)
{

}
