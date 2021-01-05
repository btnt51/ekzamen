#ifndef SETTINGSWINDOWS_H
#define SETTINGSWINDOWS_H

#include <QDialog>

namespace Ui {
class settingsWindows;
}

class settingsWindows : public QDialog
{
    Q_OBJECT

public:
    explicit settingsWindows(QWidget *parent = nullptr);
    ~settingsWindows();

private:
    Ui::settingsWindows *ui;
};

#endif // SETTINGSWINDOWS_H
