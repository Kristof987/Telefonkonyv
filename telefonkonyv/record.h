#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include "number.h"
#include "address.h"
#include "memtrace.h"
#include <string>

class Record { //record osztaly
protected:

    Address add; //lakcim
    Number worknumber; //munkahelyi telefonszam
    Number phonenumber; //maganszam
    string name; //nev
    string nickname; //becenev
    string email; //email
    string comment; //komment

public:
    Record* nextElement; //kovetkezo elemre mutato pointer
    Record(); //nullparameteres konstuktor
    Record(Address add, Number worknumber, Number phonenumber, string name, string nickname, string email, string comment); ///ctor

    Address getAddress() const; //lakcim getter

    void setAddress(Address add); //lakcim setter

    Number getWorknumber() const;  //munkahelyi telefonszam getter

    void setWorknumber(Number worknumber); //munkahelyi telefonszam setter


    Number getPhonenumber() const; //maganszam getter

    void setPhonenumber(Number phonenumber); //maganszam setter

    string getName() const;  //nev getter
    void setName(string name); //nev setter

    string getNickname() const; //becenev getter
    void setNickname(string nickname); //becenev setter

    string getEmail() const;  //email getter
    void setEmail(string email); //email setter

    string getComment() const; //comment getter
    void setComment(string comment); //comment setter

    void update(Record* newValue); //frissit fuggveny
    ~Record(); //destruktor

};
inline std::istream& operator>> (istream& is, Record& r) { //beolvaso operator
    string input = "";
    Address input_address;
    cout << "Enter the address!" << endl; //lakcim bekerese
    cin >> input_address;
    r.setAddress(input_address); //beallitjuk az adatot
    cout << endl << "Enter the name!" << endl; //es igy tovabb
    getline(is, input);
    r.setName(input);
    cout << endl << "Enter the nickname!" << endl;
    getline(is, input);
    r.setNickname(input);
    cout << endl << "Enter the email!" << endl;
    getline(is, input);
    r.setEmail(input);
    cout << endl << "Enter the comment!" << endl;
    getline(is, input);
    r.setComment(input);
    cout << endl << "Enter your phonenumber!" << endl;
    Number input_number;
    cin >> input_number;
    r.setPhonenumber(input_number);
    cout << endl << "Enter your worknumber!" << endl;
    cin >> input_number;
    r.setWorknumber(input_number);
    return is;
}

/*inline std::stringstream& operator<< (std::stringstream& out, const Record& r) //?
{
    out << r.getName(); //class public method
    return out;
}*/

/*
    kiiro operator, fajlba(!) irashoz
    ketparameteres fuggveny, ostream& es record& tipusokkal
*/
inline std::ostream& operator << (ostream& os, const Record& r) { //kiiro operator fajlba
    os << r.getAddress() << ";";
    os << r.getPhonenumber() << ";" << r.getWorknumber() << ";";
    os << r.getName() << ";" << r.getNickname() << ";" << r.getEmail() << ";" << r.getComment();
    return os;
}
#endif
