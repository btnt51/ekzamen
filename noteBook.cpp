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

void noteBook::AddingNote(CNote Obj) {
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

void noteBook::print()
{
    std::for_each(notelist.begin(), notelist.end(),[](CNote &el)
    {
       el.print();
       std::cout << std::endl;
    });
}

