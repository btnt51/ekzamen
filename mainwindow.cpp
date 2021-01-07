#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    widget = new QWidget();
    widget->setLayout(ui->gridLayout);
    setCentralWidget(widget);
    ui->newNote->setText(tr("New note"));
    ui->allNotes->setText(tr("All notes"));
    connect(ui->actionWhite_theme, SIGNAL(triggered()), this, SLOT(setLightTheme()));
    connect(ui->actionDark_theme, SIGNAL(triggered()),this, SLOT(setDarkTheme()));
    note = new noteWindows();
    allnotes = new allNotes();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_newNote_clicked()
{
    note->show();
}

void MainWindow::on_allNotes_clicked()
{
    allnotes->show();
}

void MainWindow::setDarkTheme()
{
    note->setDarkTheme();
    ui->statusbar->setStyleSheet("background-color:rgb(46, 52, 54)");
    widget->setStyleSheet("background-color:rgb(46, 52, 54)");
    this->setStyleSheet("background-color:rgb(46, 52, 54)");
    ui->allNotes->setStyleSheet("background-color:rgb(85, 87, 83); color:white");
    ui->newNote->setStyleSheet("background-color:rgb(85, 87, 83); color:white");
    ui->menubar->setStyleSheet("background-color:rgb(85, 87, 83); color:white");
    ui->menumenu->setStyleSheet("background-color:rgb(85, 87, 83); color:white");
}


void MainWindow::setLightTheme()
{
    note->setLightTheme();
    widget->setStyleSheet("");
    ui->statusbar->setStyleSheet("");
    this->setStyleSheet("");
    ui->menumenu->setStyleSheet("");
    ui->allNotes->setStyleSheet("");
    ui->newNote->setStyleSheet("");
    ui->menubar->setStyleSheet("");
}


//void MainWindow::setRusLang()
//{
//    qApp->removeTranslator(&translater);
//    translater.load(":/translate_ru/QtLanguage_ru");
//    qApp->installTranslator(&translater);
//}


//void MainWindow::setEngLang()
//{
//    qApp->removeTranslator(&translater);
//    translater.load(":/translate_en/QtLanguage_en");
//    qApp->installTranslator(&translater);
//}


//void MainWindow::on_changeLangBut_clicked()
//{
//    if(isCHanged)
//    {
//        setRusLang();
//        isCHanged = false;
//    }
//    else
//    {
//        setEngLang();
//        isCHanged = true;
//    }
//}


//void MainWindow::changeEvent(QEvent* event)
//{
//   if(event->type() == QEvent::LanguageChange)
//       ui->retranslateUi(this);
//}


