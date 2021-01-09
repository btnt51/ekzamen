#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);                          // установка формы
    widget = new QWidget();                     // создание объектаа виджета
    widget->setLayout(ui->gridLayout);          // установка слоя на виджет
    setCentralWidget(widget);                   // установка центрального виджета
    ui->newNote->setText(tr("New note"));       // установка названия кнопок
    ui->allNotes->setText(tr("All notes"));     //
    connect(ui->actionWhite_theme, SIGNAL(triggered()), this, SLOT(setLightTheme()));     //привязка действия к слотам выбора тем
    connect(ui->actionDark_theme, SIGNAL(triggered()),this, SLOT(setDarkTheme()));        //
    note = new noteWindows();                    //создание объекта окна
    allnotes = new allNotes();                   //
}

MainWindow::~MainWindow()
{
    delete ui;                                    //удаление формы
}


void MainWindow::on_newNote_clicked()
{
    note->show();                                 //отображение окна при нажатии на кнопку
}

void MainWindow::on_allNotes_clicked()
{
    allnotes->show();                             //
}

void MainWindow::setDarkTheme()
{
    note->setDarkTheme();                         //вызов слота темы
    ui->statusbar->setStyleSheet("background-color:rgb(46, 52, 54)");                   //цветовая тема для отображаемых окон
    widget->setStyleSheet("background-color:rgb(46, 52, 54)");
    this->setStyleSheet("background-color:rgb(46, 52, 54)");
    ui->allNotes->setStyleSheet("background-color:rgb(85, 87, 83); color:white");
    ui->newNote->setStyleSheet("background-color:rgb(85, 87, 83); color:white");
    ui->menubar->setStyleSheet("background-color:rgb(85, 87, 83); color:white");
    ui->menumenu->setStyleSheet("background-color:rgb(85, 87, 83); color:white");
}


void MainWindow::setLightTheme()
{
    note->setLightTheme();                       //вызов слота темы
    widget->setStyleSheet("");
    ui->statusbar->setStyleSheet("");            //цветовая тема для отображаемых окон
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


