#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
#include "memtrace.h"
#include <string>

using namespace std;

class Number { //number osztaly
    string areacode; //orszag/terulet kod
    string number; //telefonszam

public:
    Number(); //nullparameteres konstruktor
    Number(string areacode, string number); //konstruktor

    string getAreacode() const; //areacode getter
    void setAreacode(string areacode); //areacode setter

    string getNumber() const; //number getter
    void setNumber(string number); //number setter
    ~Number(); //destruktor
};

/*
    egyenlosegjel operator number tipusokra
    visszateresi erteke bool
    ha a ket number tipusu ertek megegyezik true
    egyebkent false
*/
inline bool operator==(const Number& lhs, const Number& rhs) //egyenlosegjel operator
{
    return (lhs.getAreacode() == rhs.getAreacode()) && (lhs.getNumber() == rhs.getNumber());
}

/*
    beolvaso operator
    ket parametere van, melyek std::istream& es address& tipusuak
    visszateresi erteke istream& tipusu
    ha szokozoket hasznalnank
    hellyettesitsuk "_" irasjellel!!
*/
inline std::istream& operator>> (istream& is, Number& n) { //beolvaso operator
    cout << "Enter the areacode!" << endl; //bekerjuk az areacode-ot
    string input_string = "";
    getline(is, input_string);
    n.setAreacode(input_string); //ertek beallitasa
    cout << "Enter the phonenumber!" << endl; //majd a szamot is
    getline(is, input_string);
    n.setNumber(input_string); //ertek beallitasa
    return is;
}
/*
    kiiro operator
    ketparameteres fuggveny, ostream& es number& tipusokkal
*/
inline std::ostream& operator<< (ostream& os, const Number& n) { //kiiro operator(fajlba!)
    os << n.getAreacode() << ";" << n.getNumber();
    return os;
}



#endif
