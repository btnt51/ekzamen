#ifndef NOTEWINDOWS_H
#define NOTEWINDOWS_H

#include <QDialog>

namespace Ui {
class noteWindows;
}

class noteWindows : public QDialog
{
    Q_OBJECT

public:
    explicit noteWindows(QWidget *parent = nullptr);
    ~noteWindows();

private:
    Ui::noteWindows *ui;
};

#endif // NOTEWINDOWS_H