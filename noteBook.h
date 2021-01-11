//
// Created by btnt51 on 1/11/2021.
//

#ifndef NOTEBOOK_NOTEBOOK_H
#define NOTEBOOK_NOTEBOOK_H
#include <iostream>
#include <list>
#include <utility>
#include <algorithm>

#include <QDebug>


class CNote{
public:
    CNote()
    {
        id={};
        name="";
        note="";
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
    /*friend QDataStream &operator<<(QDataStream &out,  CNote& note);
//    friend QDataStream &operator>>(QDataStream &stream, const CNote& note);*/
private:
    std::string name={};
    std::string note={};
    int id={};
};


//inline QDataStream &operator<<(QDataStream &out, CNote& note)
//{
//    out << note.name;
//    out << note.note;
//    out.setVersion(QDataStream::Qt_5_12);
//    out << (quint32*)note.id;
//    return out;
//}
class noteBook {
public:
    noteBook();
    ~noteBook();
    void AddingNote(std::string NAME, std::string NOTE);
    void DeletingNote(int ID);
    CNote getNote(int ID);
    std::list<CNote> getNoteList(){return notelist;}
    CNote Editing(int ID);
    void AddingNote(CNote Obj);
    int gettingId(std::string);
    void print();
//    friend QDataStream &operator<<(QDataStream &out, const noteBook& Book);
//    friend QDataStream &operator>>(QDataStream &stream, const noteBook& Book);


private:
    std::list<CNote> notelist;
};

//inline QDataStream &operator <<(QDataStream &stream, const noteBook& Book) // сериализуем;
//{

////    std::for_each(Book.notelist.begin(),Book.notelist.end(),[&stream](CNote &el){
////                      stream << el;
////                  });
//    stream.writeRawData
//    return stream;
//}

//inline QDataStream &operator >>(QDataStream &stream, const noteBook& Book) // десериализуем;
//{
//    stream >> sC.a;
//    stream >> sC.b;
//    stream >> sC.c;
//    return stream;
//}

#endif //NOTEBOOK_NOTEBOOK_H
