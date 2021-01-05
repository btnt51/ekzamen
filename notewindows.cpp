#include "notewindows.h"
#include "ui_notewindows.h"

noteWindows::noteWindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::noteWindows)
{
    ui->setupUi(this);
    setWindowTitle(tr("New note"));
    setWindowFlag(Qt::WindowContextHelpButtonHint,false);
}

noteWindows::~noteWindows()
{
    delete ui;
}
