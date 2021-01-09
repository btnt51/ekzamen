#include "allnotes.h"
#include "ui_allnotes.h"

allNotes::allNotes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::allNotes)
{
    ui->setupUi(this);             //установка формы

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
    qDebug() << notes;                         //отладочная информация
    QStringList nameOfNotes;                   //лист названий заметок
    QStringList notesToOutput;                 //лист содержимого заметок
    for (int i =0;i < notes.size();i++ ) {     //цикл для отделения названия заметки от ее содержимого
        QString temp = notes[i];
        QString temp2 = {};
        int k = 0,j=0,l=0;
        int counter={};
        while(temp[k]!='\0')
        {
            if(temp[k]=='_')
            {
                counter++;
                if(counter == 1)
                    j=k+1;
                if(counter == 2)
                {
                    while (j<k) {
                        temp2[l] = temp[j];
                        j++;
                        l++;
                    }
                    nameOfNotes.append(temp2);
                    j++;
                    temp2.clear();
                    l = 0;
                    while(temp[j]!= '\0')
                    {
                        temp2[l] = temp[j];
                        j++;
                        l++;
                    }
                    notesToOutput.append(temp2);
                }
            }
            k++;
        }
    }
    qDebug() << "name of note " << nameOfNotes;             //отладочная информация, вывод листа имен
    qDebug() << "notes to output" << notesToOutput;         //отладочная информация, вывод листа заметок
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
        table->setItem(i, 0, item);                         //установка навзаний заметок в таблицу
        item2->setText(notesToOutput[i]);                   //содержимое второго столбца
        table->setItem(i, 1, item2);                        //установка текста заметок в таблицу
    }
    ui->verticalLayout->addWidget(table);                   //добавление виджета вертикального слоя в таблицу
}
