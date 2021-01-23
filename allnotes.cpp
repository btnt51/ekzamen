#include "allnotes.h"
#include "ui_allnotes.h"

allNotes::allNotes(QWidget *parent, noteBook *Book, editingWindow *EDWIN) :
    QDialog(parent), ui(new Ui::allNotes), book(*Book), edWin(EDWIN)
{
    ui->setupUi(this);             //установка формы
    setWindowFlag(Qt::WindowContextHelpButtonHint,false);               //удаление кнопки
    table = new QTableWidget(book.getNoteList().size(),3,this);    //создание таблицы
    QTableWidgetItem *hnm_1 = new QTableWidgetItem();       //создание объекта
        hnm_1->setText("Name");                         //название первого столбца
    table->setHorizontalHeaderItem(0,hnm_1);                //установка названия в таблицу
    QTableWidgetItem *hnm_2 = new QTableWidgetItem();       //создание объекта
        hnm_2->setText("Note");                         //название второго стобца
    table->setHorizontalHeaderItem(1,hnm_2);                //установка названия таблицы
    long long i = 0;
    for(auto &element : book.getNoteList())           //заполнение таблицы
    {
        QTableWidgetItem *item = new QTableWidgetItem();    //создание объектов для заполнения
        QTableWidgetItem *item2 = new QTableWidgetItem();
        QTableWidgetItem *item3 = new QTableWidgetItem();
        item->setText(QString::fromStdString(element.getName()));                      //содежимое первого столбца
        item->setFlags(item->flags() &~ Qt::ItemIsEditable);
        table->setItem(i, 0, item);                         //установка навзаний заметок в таблицу
        item2->setText(QString::fromStdString(element.getNote()));                   //содержимое второго столбца
        item2->setFlags(item2->flags() &~ Qt::ItemIsEditable);          //установка текста заметок в таблицу
        table->setItem(i, 1, item2);
        item3->setText(QString::number(element.getId()));
        item3->setFlags(item3->flags() &~ Qt::ItemIsEditable);
        table->setItem(i, 2, item3);
        i++;
    }
    table->setColumnHidden(2, true);
    table->setShowGrid(false);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->verticalLayout->addWidget(table);                   //добавление виджета вертикального слоя в таблицу
    connect(table, &QTableWidget::itemSelectionChanged, this, &allNotes::openNoteWindow);
}

allNotes::~allNotes()
{
    delete ui;
    delete table;
}

void allNotes::closeEvent(QCloseEvent *event)
{
    emit openMain();
    event->accept();
}


void allNotes::openNoteWindow()
{
    int row = table->currentRow();
    QString name{},note{};
    name = table->item(row, 0)->text();
    note = table->item(row, 1)->text();
    CNote *notes = new CNote(name.toStdString(), note.toStdString());
    //edWin = new editingWindow(Parent, &book, notes);
    edWin->setNote(*notes);
    int id = table->item(row, 2)->text().toInt();
    book.Editing(id);
    edWin->show();
    this->reject();
}

