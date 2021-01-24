//
// Created by btnt51 on 1/11/2021.
//

#ifndef NOTEBOOK_NOTEBOOK_H
#define NOTEBOOK_NOTEBOOK_H
#include <iostream>
#include <list>
#include <utility>
#include <algorithm>
#include "cparser.h"


class CNote{ //класс записки
public:
    CNote()
    {
        id={}; //номер записки
        name="";//название заметки
        note="";//содержание заметки
    }
    CNote(std::string NAME,std::string NOTE):name(std::move(NAME)),note(std::move(NOTE))
    {
        id={};
    }
    CNote(std::string NAME, std::string NOTE, int ID)
            : name(std::move(NAME)),note(std::move(NOTE)),id(ID)
    {
    }
    int getId() {return this->id;} //получение номера записки
    std::string getName(){return this->name;} //получение названия записки
    std::string getNote(){return this->note;} //получение содержания записки
    void setName(std::string Name){this->name = Name;} //установка названия записки
    void setNote(std::string Note){this->note = Note;} //установка содержания записки
    void setId(int ID){this->id = ID;} //установка номера записки

private:
    std::string name={};//название заметки
    std::string note={};//содержание заметки
    int id={};//номер записки
};



class noteBook {
public:
    noteBook();
    ~noteBook();
    void AddingNote(CNote Obj);                             //добавление записки в стд лист по объекту
    void AddingNote(std::string NAME, std::string NOTE);    //добавление записки в стд лист по названию и содержанию
    void AddingNoteFromFIle(std::string NAME, std::string NOTE, int id); //добавление записки в стд лист из файла
    void DeletingNote(int ID);                                          //удаление записки по номеру
    CNote getNote(int ID);                                              //получение записки по номеру
    std::list<CNote> getNoteList(){return notelist;}                    //получение списка заметок
    CNote Editing(int ID);                                              //изменение записки по номеру

    int gettingId(std::string name);                                         //получение номера записки по названию
    void saveInFile();                                                   //запись списка заметок в файл
    void getFromFile();                                                    //получение запеток из файла

private:
    std::list<CNote> notelist;                                                    //стд список заметок
};



#endif //NOTEBOOK_NOTEBOOK_H
