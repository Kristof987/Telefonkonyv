#ifndef RETIRED_H
#define RETIRED_H

#include "record.h"
#include "memtrace.h"
//#include <string>

class Retired :public Record { //retired osztaly
    string hobby; //hobbi
public:
    Retired* nextElement; //kovetkezo adatra mutato pointer
    Retired(Address address, //konstruktor
        Number worknumber,
        Number phonenumber,
        string name,
        string nickname,
        string email,
        string comment,
        string hobby);
    Retired(); //nullparameteres konstruktor

    string getHobby() const;  //hobbi getter
    void setHobby(string hobby); //hobbi setter
     /*
        a "frissito" fuggveny,
        ami az adott rekordot frissiti a megadott retired parameterrel
        nincs visszateresi erteke
     */
    void update(Retired* newValue); //frissit fuggveny
    ~Retired();
};

/*
    beolvaso operator, ha szokozoket hasznalnank
    hellyettesitsuk "_" irasjellel!!
    ketparameteres fuggveny, istream& es retired& tipusokkal
*/
inline std::istream& operator>>(std::istream& is, Retired& rr) { //beolvaso operator
    Record* r;
    r = &rr;
    cin >> *r;
    cout << "Enter your hobby!" << endl;
    string input = "";
    getline(is, input);
    rr.setHobby(input);
    return is;
}

/*
kiiro operator, fajlba(!) irashoz
ketparameteres fuggveny, ostream& es retired& tipusokkal
*/
inline std::ostream& operator<< (ostream& os, Retired& re) { //kiiro operator
    Record* r;
    os << "2;";
    os << re.getHobby() << ";";
    r = &re;
    os << *r;
    return os;
}

#endif
