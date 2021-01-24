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
    auto iter = std::find_if(notelist.begin(),notelist.end(),[&ID](auto &el)
    {return el.getId() == ID;});
    CNote note = *iter;
    notelist.erase(iter);
    return note;
}

void noteBook::AddingNote(std::string NAME, std::string NOTE) {
    int ID={};
    if(!notelist.empty())
         ID = notelist.front().getId();
    else
         ID = 0;
    notelist.push_front(CNote(std::move(NAME), std::move(NOTE),ID+1));
}

void noteBook::AddingNoteFromFIle(std::string NAME, std::string NOTE,int ID)
{
    notelist.push_back(CNote(std::move(NAME), std::move(NOTE),std::move(ID)));
}

void noteBook::AddingNote(CNote Obj) {
    if(Obj.getId() == 0)
    {
        if(!notelist.empty())
             Obj.setId(notelist.front().getId()+1);
        else
             Obj.setId(1);
    }
    notelist.push_front(Obj);
}


void noteBook::DeletingNote(int ID) {
    auto iter = std::find_if(notelist.begin(),notelist.end(),[&ID](auto &el)
    {return el.getId() == ID;});
    notelist.erase(iter);
}

CNote noteBook::getNote(int ID) {
    CNote note;
    std::for_each(notelist.begin(),notelist.end(),[&note,&ID](auto &el){
        if(el.getId() == ID)
            note = el;
    });
    return note;
}

int noteBook::gettingId(std::string name) {
    auto iter = std::find_if(notelist.begin(),notelist.end(),[&name](auto &el)
    {return el.getName() == name;});
    return iter->getId();
}


void noteBook::saveInFile()
{
    std::for_each(notelist.begin(),notelist.end(),[](CNote &el)
    {
       CParser::SaveFile(QString::fromStdString(el.getName()), QString::fromStdString(el.getNote()));
    });
}

void noteBook::getFromFile()
{
    QStringList notesF = CParser::ReadFile();
    QStringList names{};
    QStringList notes{};
    std::for_each(notesF.begin(), notesF.end(),[&names, &notes](QString &element){
            //цикл для отделения названия заметки от ее содержимого
            int index = element.indexOf("_");
            QString temp = {};
            for (int i = 0; i < index; i++)
               temp += element[i];
            names.append(temp);
            temp.clear();
            for(int i = index+1; i < element.size();i++)
                temp += element[i];
            temp.replace("@%","\n");
            notes.append(temp);
        });

    for(int i = 0;i < names.size();i++)
    {
        this->AddingNoteFromFIle(names[i].toStdString(),notes[i].toStdString(),names.size()-i);
    }
}

