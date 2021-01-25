#include "helpwindow.h"
#include "ui_helpwindow.h"

helpWindow::helpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::helpWindow)
{
    ui->setupUi(this);
    ui->textEdit->setText("    This is a app for creating and saving notes. And called \"Notebook\"."
                          "For create a note press in main window on button \"New note\" or press ctrl+N.\n    "
                          "For saving note you need enter both name and note.\n    "
                          "For open a list of notes and editing already created notes click on button \"All note\""
                          "or press ctrl+O");
    setWindowFlag(Qt::WindowContextHelpButtonHint, false);
}

helpWindow::~helpWindow()
{
    delete ui;
}
