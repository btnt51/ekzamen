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
#include <QDebug>


class CNote{
public:
    CNote()
    {
        id={};
        name="";
        note="";
    }
    CNote(std::string NAME,std::string NOTE):name(std::move(NAME)),note(std::move(NOTE))
    {
        id={};
    }
    CNote(std::string NAME, std::string NOTE, int ID)
            : name(std::move(NAME)),note(std::move(NOTE)),id(ID)
    {
    }
    int getId() {return this->id;}
    std::string getName(){return this->name;}
    std::string getNote(){return this->note;}
    void setName(std::string Name){this->name = Name;}
    void setNote(std::string Note){this->note = Note;}
    void setId(int ID){this->id = ID;}
    void print(){
       // qDebug() << "Name" << name << " Note" << note << " id" << id;
    }
private:
    std::string name={};
    std::string note={};
    int id={};
};



class noteBook {
public:
    noteBook();
    ~noteBook();
    void AddingNote(CNote Obj);
    void AddingNote(std::string NAME, std::string NOTE);
    void AddingNoteFromFIle(std::string NAME, std::string NOTE, int id);
    void DeletingNote(int ID);
    CNote getNote(int ID);
    std::list<CNote> getNoteList(){return notelist;}
    CNote Editing(int ID);

    int gettingId(std::string);
    void print();
    void saveInFile();
    void getFromFile();

private:
    std::list<CNote> notelist;
};



#endif //NOTEBOOK_NOTEBOOK_H
