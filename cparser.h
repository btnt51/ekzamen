#ifndef CPARSER_H
#define CPARSER_H
#include <QFile>
#include <QList>
#include <QDebug>


class CParser
{
public:
    CParser();
    void static SaveFile(QString ID, QString Data, QString Notelist);
    QList <QString> static ReadFile();
};

#endif // CPARSER_H
