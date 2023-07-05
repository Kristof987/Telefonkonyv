#ifndef STUDENT_H
#define STUDENT_H

#include "record.h"
#include "memtrace.h"

class Student :public Record { //student osztaly
    string school; //iskola
public:
    Student* nextElement; //kovetkezo elemre mutato pointer
    Student(Address address, //konstruktor
        Number worknumber,
        Number phonenumber,
        string name,
        string nickname,
        string email,
        string comment,
        string school);

    Student(); //nullparameteres konstruktor

    string getSchool() const;  //iskola getter

    void setSchool(string school); //iskola setter
    /*
        a "frissito" fuggveny,
        ami az adott rekordot frissiti a megadott student parameterrel
        nincs visszateresi erteke
     */
    void update(Student* newValue); //frissit fuggveny

    ~Student(); //destruktor
};

/*
    beolvaso operator, ha szokozoket hasznalnank
    hellyettesitsuk "_" irasjellel!!
    ketparameteres fuggveny, istream& es student& tipusokkal
*/
inline std::istream& operator>>(std::istream& is, Student& s) { //beolvaso operator
    Record* r;
    r = &s;
    cin >> *r;
    cout << "Enter the school!" << endl << endl;
    string input = "";
    getline(is, input);
    s.setSchool(input);

    return is;
}

/*
kiiro operator, fajlba(!) irashoz
ketparameteres fuggveny, ostream& es student& tipusokkal
*/
inline std::ostream& operator << (ostream& os, const Student& s) { //kiiro operator (fajlba!)
    const Record* r;
    os << "0;";
    os << s.getSchool() << ";";
    r = &s;
    os << *r;
    return os;
}

#endif
