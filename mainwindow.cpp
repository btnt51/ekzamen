#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *widget = new QWidget();
    widget->setLayout(ui->gridLayout);//verticalLayout имя переменной в ui форме
    setCentralWidget(widget);
    ui->newNote->setText(tr("New note"));
    ui->allNotes->setText(tr("All notes"));
    ui->Settings->setText(tr("Settings"));
    sWindow = new settingsWindows();
    note = new noteWindows();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_newNote_clicked()
{
    note->show();
}

void MainWindow::on_Settings_clicked()
{
    sWindow->show();
}
