#include "allnotes.h"
#include "ui_allnotes.h"

allNotes::allNotes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::allNotes)
{
    ui->setupUi(this);

    updateTable();
}

allNotes::~allNotes()
{
    delete ui;
}

void allNotes::updateTable()
{
    notes = CParser::ReadFile();
    std::reverse(notes.begin(),notes.end());
    qDebug() << notes;
    QStringList nameOfNotes;
    QStringList notesToOutput;
    for (int i =0;i < notes.size();i++ ) {
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
    qDebug() << "name of note " << nameOfNotes;
    qDebug() << "notes to output" << notesToOutput;
    int counts = nameOfNotes.size();
    table = new QTableWidget(counts,2,this);

    QStringList nameTable;
    nameTable << "Name" << "note";
    QTableWidgetItem *hnm_1 = new QTableWidgetItem();
        hnm_1->setText(tr("Name"));
    table->setHorizontalHeaderItem(0,hnm_1);
    QTableWidgetItem *hnm_2 = new QTableWidgetItem();
        hnm_2->setText(tr("Note"));
    table->setHorizontalHeaderItem(1,hnm_2);
    for(int i = 0; i < notesToOutput.size(); i++)
    {
          // Читать лучше из потока, если уже его создали. :)
        QTableWidgetItem *item = new QTableWidgetItem();
        QTableWidgetItem *item2 = new QTableWidgetItem();
        item->setText(nameOfNotes[i]);
        table->setItem(i, 0, item);
        item2->setText(notesToOutput[i]);
        table->setItem(i, 1, item2);
    }
    ui->verticalLayout->addWidget(table);
}
