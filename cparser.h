#ifndef CPARSER_H
#define CPARSER_H
#include <QFile>
#include <QDebug>


class CParser
{
public:
    CParser();
    void static SaveFile(QString nameOfNote, QString Date, QString Note);
    QStringList static ReadFile();
};

#endif // CPARSER_H
