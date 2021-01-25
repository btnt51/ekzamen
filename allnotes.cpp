#include "allnotes.h"
#include "ui_allnotes.h"

allNotes::allNotes(QWidget *parent, noteBook *Book, editingWindow *EDWIN) :
    QDialog(parent), ui(new Ui::allNotes), book(*Book), edWin(EDWIN)
{
    ui->setupUi(this);                                              //установка формы
    setWindowFlag(Qt::WindowContextHelpButtonHint,false);           //удаление кнопки
    table = new QTableWidget(book.getNoteList().size(),3,this);     //создание таблицы
    QTableWidgetItem *hnm_1 = new QTableWidgetItem();               //создание объекта
        hnm_1->setText("Name");                                     //название первого столбца
    table->setHorizontalHeaderItem(0,hnm_1);                        //установка названия в таблицу
    QTableWidgetItem *hnm_2 = new QTableWidgetItem();               //создание объекта
        hnm_2->setText("Note");                                     //название второго стобца
    table->setHorizontalHeaderItem(1,hnm_2);                        //установка названия таблицы
    long long i = 0;
    for(auto &element : book.getNoteList())                         //заполнение таблицы
    {
        QTableWidgetItem *item = new QTableWidgetItem();            //создание объектов для заполнения
        QTableWidgetItem *item2 = new QTableWidgetItem();
        QTableWidgetItem *item3 = new QTableWidgetItem();
        item->setText(QString::fromStdString(element.getName()));   //содежимое первого столбца
        item->setFlags(item->flags() &~ Qt::ItemIsEditable);
        table->setItem(i, 0, item);                                 //установка названий заметок в таблицу
        item2->setText(QString::fromStdString(element.getNote()));  //содержимое второго столбца
        item2->setFlags(item2->flags() &~ Qt::ItemIsEditable);      //установка текста заметок в таблицу
        table->setItem(i, 1, item2);                                //установка заметок в таблицу
        item3->setText(QString::number(element.getId()));           //содежимое третьего столбца
        item3->setFlags(item3->flags() &~ Qt::ItemIsEditable);
        table->setItem(i, 2, item3);                                //установка номеров заметок в таблицу
        table->setRowHeight(i,(this->height() / 8));                //установка высоты таблицы
        i++;
    }
    table->setColumnHidden(2, true);                                //отключение отображение 3 столбца
    table->setShowGrid(false);                                      //отключение сетки
    table->setSelectionMode(QAbstractItemView::SingleSelection);    //установка возможности максимального количества выделеных ячеек
    table->setSelectionBehavior(QAbstractItemView::SelectRows);     //установка возможности выбрать только целый ряд
    table->setColumnWidth(0, (this->width()/2) - 8);                //установка ширины столбца
    table->setColumnWidth(1, (this->width()/2) - 8);                //установка ширины столбца
    ui->verticalLayout->addWidget(table);                           //добавление виджета вертикального слоя в таблицу
    connect(table, &QTableWidget::itemSelectionChanged, this, &allNotes::openNoteWindow);

}

allNotes::~allNotes()
{
    delete ui;
    delete table;
    delete edWin;
}

void allNotes::closeEvent(QCloseEvent *event)
{
    emit openMain();                                                        //отпрака сигнала на открытие главного окна
    event->accept();     //окно закрыто
}


void allNotes::openNoteWindow()
{
    int row = table->currentRow();                                          //индекс текущего ряда
    QString name{},note{};                                                  //создание переменных
    name = table->item(row, 0)->text();                                     //получение данных названия из таблицы
    note = table->item(row, 1)->text();                                     //получение данных содержимого из таблицы
    CNote *notes = new CNote(name.toStdString(), note.toStdString());       //создание указателя на заметку
    edWin->setNote(*notes);                                                 //установка заметки
    int id = table->item(row, 2)->text().toInt();                           //получение id заметки из таблицы
    book.DeletingNote(id);                                                  //удаление заметки из записной книжки по id
    edWin->show();                                                          //показать окно, отвечающее за изменение заметки
    this->reject();                                                         //закрытие окна
}

