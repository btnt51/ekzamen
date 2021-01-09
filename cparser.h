#ifndef CPARSER_H
#define CPARSER_H
#include <QFile>
#include <QDebug>


class CParser
{
public:
    CParser();
    void static SaveFile(QString nameOfNote, QString Note);   //сохранение заметок
    QStringList static ReadFile();                            //чтение заметок из файла
};

#endif // CPARSER_H
