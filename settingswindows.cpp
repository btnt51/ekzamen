#include "settingswindows.h"
#include "ui_settingswindows.h"

settingsWindows::settingsWindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settingsWindows)
{
    ui->setupUi(this);
    ui->LangSwitcher->setText(tr("Language"));
    ui->ThemeSwitcher->setText(tr("Theme"));
    setWindowTitle(tr("Settings"));
    setWindowFlag(Qt::WindowContextHelpButtonHint,false);
}

settingsWindows::~settingsWindows()
{
    delete ui;
}
