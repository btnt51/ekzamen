#ifndef NOTEWINDOWS_H
#define NOTEWINDOWS_H

#include <QDialog>
#include <QDebug>
#include "cparser.h"

namespace Ui {
class noteWindows;
}

class noteWindows : public QDialog
{
    Q_OBJECT

public:
    explicit noteWindows(QWidget *parent = nullptr);
    ~noteWindows();

public slots:
    void setLightTheme();
    void setDarkTheme();
    void on_saveButton_clicked();

private:
    Ui::noteWindows *ui;
};

#endif // NOTEWINDOWS_H
