#include "allnotes.h"
#include "ui_allnotes.h"

allNotes::allNotes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::allNotes)
{
    ui->setupUi(this);
    table = new QTableWidget(250,3,this);
    ui->verticalLayout->addWidget(table);

}

allNotes::~allNotes()
{
    delete ui;
}
