#ifndef BOOK_H
#define BOOK_H

#include <cstdlib>
#include <iostream>
#include "record.h"
#include "number.h"
#include <fstream>
#include <sstream>
#include "retired.h"
#include "adult.h"
#include "student.h"
#include "memtrace.h"
//#include "cross_platform.h"



class Book { //Book osztaly

public:
    Student* studentBook; //diakokat tartalmazo lancolt lista
    Adult* adultBook; //felnotteket tartalmazo lancolt lista
    Retired* retiredBook; //nyugdijasokat tartalmazo lancolt lista

    Book(); //nullparameteres konstruktor

    /*
        a fuggveny bool tipussal ter vissza
        ami azt vizsgalja, hogy van-e elem a book valamelyik lancolt listajaban
        ha van false, amugy true a visszateresi erteke
        nincs parametere
    */
    bool isEmpty();

    /*
        a book felszabaditasara szolgal
        ezt a fuggvenyt felhasznaljuk a destruktorban
        nincs visszateresi erteke, parameter nelkuli
    */
    void free_book(); //a book felszabaditasa (felhasznaljuk a destruktorban)

    /*
        egyparameteres fuggveny, ami egy number tipusu erteket var
        azt ellenorizzuk, hogy az adott number tipus
        benne van-e mar az adott lancolt listaban
        ha mar igen, true a visszateresi ertek, amugy false
    */

    bool isContain(Number input);

    /*
        egyparameteres fuggveny, ami egy student tipusu erteket var
        azt ellenorizzuk, hogy az adott student tipus
        benne van-e mar az adott lancolt listaban
        ha mar igen, true a visszateresi ertek, amugy false
    */
    bool isContain(Student* input);

    /*
        egyparameteres fuggveny, ami egy adult tipusu erteket var
        azt ellenorizzuk, hogy az adott adult tipus
        benne van-e mar az adott lancolt listaban
        ha mar igen, true a visszateresi ertek, amugy false
    */
    bool isContain(Adult* input);

    /*
        egyparameteres fuggveny, ami egy retired tipusu erteket var
        azt ellenorizzuk, hogy az adott retired tipus
        benne van-e mar az adott lancolt listaban
        ha mar igen, true a visszateresi ertek, amugy false
    */
    bool isContain(Retired* input);

    /*
        egyparameteres fuggveny, parametere egy number tipusu ertekre mutato pointer
        minden magantelefonszam kulonbozo (mivel egy magantelefonszamrol feltetelezzuk, hogy csak 1 emberhez tartozik...)
        a magantelefonszam altal visszater a fuggveny az adott studentre mutato pointerrel
    */
    Student* getStudentByNumber(Number* input);

    /*
        egyparameteres fuggveny, parametere egy number tipusu ertekre mutato pointer
        minden magantelefonszam kulonbozo (mivel egy magantelefonszamrol feltetelezzuk, hogy csak 1 emberhez tartozik...)
        a magantelefonszam altal visszater a fuggveny az adott adultra mutato pointerrel
    */
    Adult* getAdultByNumber(Number* input);

    /*
        egyparameteres fuggveny, parametere egy number tipusu ertekre mutato pointer
        minden magantelefonszam kulonbozo (mivel egy magantelefonszamrol feltetelezzuk, hogy csak 1 emberhez tartozik...)
        a magantelefonszam altal visszater a fuggveny az adott adultra mutato pointerrel
    */
    Retired* GetRetiredByNumber(Number* input);

    /*
        egyparameteres fuggveny, parametere egy student tipusu ertekre mutato pointer
        a studenteket tartalmazo lancolt listahoz hozzafuzi (nev betuje alapjan abc sorrendben) az adott studentet
        visszateresi erteke nincs
    */
    void add(Student* p);

    /*
        egyparameteres fuggveny, parametere egy adult tipusu ertekre mutato pointer
        az adultokat tartalmazo lancolt listahoz hozzafuzi (nev betuje alapjan abc sorrendben) az adott adultot
        visszateresi erteke nincs
    */
    void add(Adult* p);

    /*
        egyparameteres fuggveny, parametere egy retired tipusu ertekre mutato pointer
        a retiredeket tartalmazo lancolt listahoz hozzafuzi (nev betuje alapjan abc sorrendben) az adott retiredet
        visszateresi erteke nincs
    */
    void add(Retired* p);

    /*
        egyparameteres fuggveny, parametere egy adult tipusu ertekre mutato pointer
        az adultokat tartalmazo lancolt listabol torli az adott adultot
        visszateresi erteke nincs
    */
    void removeByPointer(Adult* p);

    /*
        egyparameteres fuggveny, parametere egy student tipusu ertekre mutato pointer
        a studenteket tartalmazo lancolt listabol torli az adott studentet
        visszateresi erteke nincs
    */
    void removeByPointer(Student* p);

    /*
        egyparameteres fuggveny, parametere egy retired tipusu ertekre mutato pointer
        a retiredeket tartalmazo lancolt listabol torli az adott retiredet
        visszateresi erteke nincs
    */
    void removeByPointer(Retired* p);

    /*
        egyparameteres fuggveny, parametere egy adult tipusu ertekre mutato pointer
        az adott adultot "kiszedi" a lancolt listabol
        a search fuggvenyeknel lesz felhasznalva
        visszateresi erteke nincs
    */
    void cutByPointer(Adult* p);

    /*
        egyparameteres fuggveny, parametere egy student tipusu ertekre mutato pointer
        az adott studentet "kiszedi" a lancolt listabol
        a search fuggvenyeknel lesz felhasznalva
        visszateresi erteke nincs
    */
    void cutByPointer(Student* p);

    /*
        egyparameteres fuggveny, parametere egy retired tipusu ertekre mutato pointer
        az adott retiredet "kiszedi" a lancolt listabol
        a search fuggvenyeknel lesz felhasznalva
        visszateresi erteke nincs
    */
    void cutByPointer(Retired* p);

    /*
        fajlbol (txt-bol) beolvasas a 3 lancolt listaba
        egyparameteres fuggveny, parametere a fajl neve
        a fajlban soronkent vannak az egymashoz tartozo adatok
        egymashoz tartozo adatok pontosvesszõvel kerulnek elvalasztasra egymastol
        visszateresi erteke nincs
    */
    void loadFromFile(string path);//writetofile

    /*
        fajlba(txt-be) valo kiiras a 3 lancolt listabol
        egyparameteres fuggveny, parametere a fajl neve
        a fajlban soronkent vannak az egymashoz tartozo adatok
        egymashoz tartozo adatok pontosvesszõvel kerulnek elvalasztasra egymastol
        visszateresi erteke nincs
    */
    void writeToFile(string path);

    /*
        destruktor, melyben a lista minden elemet felszabaditjuk
        a free_book fuggvenyt hasznaljuk itt
    */
    ~Book();
};

/*
    kiiro operator
    az esztetikus megjelenes erdekeben az adatokat itt nem pontosvesszovel, hanem csillaggal valasztjuk el
    visszateresi erteke std::ostream& tipusu
    ket parametere van, melyek egy std::ostream& tipus, es egy book& tipus
*/
inline std::ostream& operator << (std::ostream& os, const Book& b) {
    Student* current1 = b.studentBook;
    Adult* current2 = b.adultBook;
    Retired* current3 = b.retiredBook;
    if (current1 != NULL)
    {
        cout << "************* List of Students *****************" << endl;
        while (current1 != NULL)
        {
            os << "Name:\t\t\t" << current1->getName() << endl;
            os << "Nickname:\t\t" << current1->getNickname() << endl;
            os << "Phone number:\t\t" << current1->getPhonenumber().getAreacode() << current1->getPhonenumber().getNumber() << endl;
            os << "Work number:\t\t" << current1->getWorknumber().getAreacode() << current1->getWorknumber().getNumber() << endl;
            os << "School:\t\t\t" << current1->getSchool() << endl;
            os << "Address:\t\t" << current1->getAddress().getPostalcode() << " " << current1->getAddress().getCity() << " " << current1->getAddress().getStreetname() << " " << current1->getAddress().getNumber() << endl;
            os << "Email:\t\t\t" << current1->getEmail() << endl;
            os << "Comment:\t\t" << current1->getComment() << endl << endl << endl;
            current1 = current1->nextElement;
        }
    }
    if (current2 != NULL)
    {
        cout << "************* List of Adult *****************" << endl;

        while (current2 != NULL)
        {
            os << "Name: " << current2->getName() << endl;
            os << "Nickname: " << current2->getNickname() << endl;
            os << "Phone number: " << current2->getPhonenumber().getAreacode() << current2->getPhonenumber().getNumber() << endl;
            os << "Work number: " << current2->getWorknumber().getAreacode() << current2->getWorknumber().getNumber() << endl;
            os << "Workplace: " << current2->getWorkplace() << endl;
            os << "Address : " << current2->getAddress().getPostalcode() << " " << current2->getAddress().getCity() << " " << current2->getAddress().getStreetname() << " " << current2->getAddress().getNumber() << endl;
            os << "Email: " << current2->getEmail() << endl;
            os << "Comment: " << current2->getComment() << endl << endl << endl;
            current2 = current2->nextElement;
        }
    }
    if (current3 != NULL)
    {
        cout << "************* List of Retired *****************" << endl;

        while (current3 != NULL)
        {
            os << "Name: " << current3->getName() << endl;
            os << "Nickname: " << current3->getNickname() << endl;
            os << "Phone number: " << current3->getPhonenumber().getAreacode() << current3->getPhonenumber().getNumber() << endl;
            os << "Work number: " << current3->getWorknumber().getAreacode() << current3->getWorknumber().getNumber() << endl;
            os << "Hobby: " << current3->getHobby() << endl;
            os << "Address : " << current3->getAddress().getPostalcode() << " " << current3->getAddress().getCity() << " " << current3->getAddress().getStreetname() << " " << current3->getAddress().getNumber() << endl;
            os << "Email: " << current3->getEmail() << endl;
            os << "Comment: " << current3->getComment() << endl << endl << endl;
            current3 = current3->nextElement;
        }
    }
    return os;
}

#endif