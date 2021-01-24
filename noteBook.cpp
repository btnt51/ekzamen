//
// Created by btnt51 on 1/11/2021.
//

#include "noteBook.h"


noteBook::noteBook() {
    notelist={};
}

noteBook::~noteBook() {

}

CNote noteBook::Editing(int ID) {
    auto iter = std::find_if(notelist.begin(),notelist.end(),[&ID](auto &el)        //поиск заметки
    {return el.getId() == ID;});
    CNote note = *iter;         //сохранение заметки для возврата
    notelist.erase(iter);       //удаление заметки из списка
    return note;                //возаращение заметки
}

void noteBook::AddingNote(std::string NAME, std::string NOTE) {
    int ID={};               //создание переменной
    if(!notelist.empty())    //установка id
         ID = notelist.front().getId();
    else
         ID = 0;
    notelist.push_front(CNote(std::move(NAME), std::move(NOTE),ID+1));  //добавление заметки в начало списка
}

void noteBook::AddingNoteFromFIle(std::string NAME, std::string NOTE,int ID)
{
    notelist.push_back(CNote(std::move(NAME), std::move(NOTE),std::move(ID)));      //добавление заметки в конец списка
}

void noteBook::AddingNote(CNote Obj) {
    if(Obj.getId() == 0)        //установка id
    {
        if(!notelist.empty())
             Obj.setId(notelist.front().getId()+1);
        else
             Obj.setId(1);
    }
    notelist.push_front(Obj);       //добавление заметки в начало списка
}


void noteBook::DeletingNote(int ID) {
    auto iter = std::find_if(notelist.begin(),notelist.end(),[&ID](auto &el)        //получение указателя на заметку по id
    {return el.getId() == ID;});
    notelist.erase(iter);               //удаление заметки
}

CNote noteBook::getNote(int ID) {
    CNote note;                 //создание заметки
    std::for_each(notelist.begin(),notelist.end(),[&note,&ID](auto &el){            //поиск и сохранение заметки по id
        if(el.getId() == ID)
            note = el;
    });
    return note;        //возвращаем заметку
}

int noteBook::gettingId(std::string name) {
    auto iter = std::find_if(notelist.begin(),notelist.end(),[&name](auto &el)      //получение указателя на заметку по имени
    {return el.getName() == name;});
    return iter->getId();   //возвращение id
}


void noteBook::saveInFile()
{
    std::for_each(notelist.begin(),notelist.end(),[](CNote &el)         //сохрнение в файл
    {
       CParser::SaveFile(QString::fromStdString(el.getName()), QString::fromStdString(el.getNote()));
    });
}

void noteBook::getFromFile()
{
    QStringList notesF = CParser::ReadFile();       //считываение заметок из файла
    QStringList names{};                            //лист названий
    QStringList notes{};                            //лист содержимого заметок
    std::for_each(notesF.begin(), notesF.end(),[&names, &notes](QString &element){
            //цикл для отделения названия заметки от ее содержимого
            int index = element.indexOf("_");       //получение позиции разделителя
            QString temp = {};                      //создание временной строки
            for (int i = 0; i < index; i++)         //цикл сохранения названия
               temp += element[i];
            names.append(temp);     //добавление названия в список названий
            temp.clear();           //очистка временной переменной
            for(int i = index+1; i < element.size();i++)    //цикл сохрания содержимого заметки
                temp += element[i];
            temp.replace("@%","\n");        //замена символов
            notes.append(temp);             //добавление содержимого заметки в список
        });

    for(int i = 0;i < names.size();i++)     //добавление заметок в записную книжку
    {
        this->AddingNoteFromFIle(names[i].toStdString(),notes[i].toStdString(),names.size()-i);
    }
}

