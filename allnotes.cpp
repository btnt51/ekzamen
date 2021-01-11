#include "allnotes.h"
#include "ui_allnotes.h"

allNotes::allNotes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::allNotes)
{
    ui->setupUi(this);             //установка формы
    setWindowFlag(Qt::WindowContextHelpButtonHint,false);               //удаление кнопки

    updateTable();
}

allNotes::~allNotes()
{
    delete ui;
}

void allNotes::updateTable()
{
    notes = CParser::ReadFile();               //чтение файла
    std::reverse(notes.begin(),notes.end());   //разворот листа
    //qDebug() << notes;                         //отладочная информация
    QStringList nameOfNotes;                   //лист названий заметок
    QStringList notesToOutput;                 //лист содержимого заметок
    std::for_each(notes.begin(), notes.end(),[&nameOfNotes, &notesToOutput](QString &element){
        //цикл для отделения названия заметки от ее содержимого
        int index = element.indexOf("_");
        QString temp = {};
        for (int i = 0; i < index; i++)
           temp += element[i];
        nameOfNotes.append(temp);
        temp.clear();
        for(int i = index+1; i < element.size();i++)
            temp += element[i];
        notesToOutput.append(temp);
    });
    std::for_each(notesToOutput.begin(),notesToOutput.end(),[](QString &element){
        element.replace("@%","\n");
    });
    //qDebug() << "name of note " << nameOfNotes;             //отладочная информация, вывод листа имен
    //qDebug() << "notes to output" << notesToOutput;         //отладочная информация, вывод листа заметок
    table = new QTableWidget(nameOfNotes.size(),2,this);    //создание таблицы
    QTableWidgetItem *hnm_1 = new QTableWidgetItem();       //создание объекта
        hnm_1->setText(tr("Name"));                         //название первого столбца
    table->setHorizontalHeaderItem(0,hnm_1);                //установка названия в таблицу
    QTableWidgetItem *hnm_2 = new QTableWidgetItem();       //создание объекта
        hnm_2->setText(tr("Note"));                         //название второго стобца
    table->setHorizontalHeaderItem(1,hnm_2);                //установка названия таблицы
    for(int i = 0; i < notesToOutput.size(); i++)           //заполнение таблицы
    {
        QTableWidgetItem *item = new QTableWidgetItem();    //создание объектов для заполнения
        QTableWidgetItem *item2 = new QTableWidgetItem();
        item->setText(nameOfNotes[i]);                      //содежимое первого столбца
        item->setFlags(item->flags() &~ Qt::ItemIsEditable);
        table->setItem(i, 0, item);                         //установка навзаний заметок в таблицу
        item2->setText(notesToOutput[i]);                   //содержимое второго столбца
        item2->setFlags(item2->flags() &~ Qt::ItemIsEditable);
        table->setItem(i, 1, item2);                        //установка текста заметок в таблицу
    }
    table->setShowGrid(false);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->verticalLayout->addWidget(table);                   //добавление виджета вертикального слоя в таблицу
    connect(table,&QTableWidget::itemSelectionChanged,this,&allNotes::openNoteWindow);
}

void allNotes::openNoteWindow()
{
    int row = table->currentRow();
    QString name{},note{};
    name = table->item(row,0)->text();
    note = table->item(row,1)->text();
    QWidget *parent = nullptr;
    this->close();
    noteWindows *noteWindow = new noteWindows(parent,name,note,false);
    connect(noteWindow, &noteWindows::allNote, this, &allNotes::showThis);
    noteWindow->show();
}

void allNotes::showThis()
{
    this->updateTable();
    //this->show();
}
