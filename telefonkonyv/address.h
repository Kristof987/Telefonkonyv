#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include "memtrace.h"
#include <limits>
#include <string>


class Address { //lakcim osztaly
    int postalcode; //iranyitoszam
    std::string city; //varos
    std::string streetname; //utcanev
    std::string number; //hazszam (+ide irhato az emelet, ajto, stb.)
public:
    Address(); //nullparameteres konstruktor
    Address(int postalcode, std::string city, std::string streetname, std::string number); //konstruktor
    int getPostalcode() const;  ///iranyitoszam getter
    void setPostalcode(int postalcode); //iranyitoszam setter
    std::string getCity() const; //varos getter
    void setCity(std::string City); //varos setter
    std::string getStreetname() const;  //utcanev getter
    void setStreetname(std::string streetname); //utcanev setter
    std::string getNumber() const;  //hazszam getter
    void setNumber(std::string number); //hazszam setter
    ~Address(); //destruktor
};

/*
    beolvaso operator
    ket parametere van, melyek std::istream& es address& tipusuak
    visszateresi erteke istream& tipusu
    ha szokozoket hasznalnank
    hellyettesitsuk "_" irasjellel!!
*/
inline std::istream& operator>> (std::istream& is, Address& a) {

    std::string input_string = ""; //string input
    int input_int = 0; //int input

    std::cout << "Enter the postalcode!" << std::endl; //adatok bekerese...
    std::cin.clear();
    std::fflush(stdin);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (input_int == 0)
    {
        getline(is, input_string);
        input_int = atoi(input_string.c_str());
        a.setPostalcode(input_int); //beallitjuk az iranyitoszamot
        if (input_int != 0)
        {
            a.setPostalcode(input_int); //beallitjuk az iranyitoszamot
        }
        else
        {
            std::cout << "Wrong input data format. Please enter the postalcode in numbers" << std::endl;
        }

    }

    std::cout << "Enter the city!" << std::endl; //ugyanez
    getline(is, input_string);
    a.setCity(input_string);

    std::cout << "Enter the streetname!" << std::endl; //ugyanez
    getline(is, input_string);
    a.setStreetname(input_string);

    std::cout << "Enter the number!" << std::endl; //ugyanez
    getline(is, input_string);
    a.setNumber(input_string);

    return is;
}

/*
    egyenlosegjel operator address tipusokra
    visszateresi erteke bool
    ha a ket address tipusu ertek megegyezik true
    egyebkent false
*/
inline bool operator==(const Address& lhs, const Address& rhs) //egyenlosegjel operator
{
    return (lhs.getPostalcode() == rhs.getPostalcode()) && (lhs.getCity() == rhs.getCity()) && (lhs.getStreetname() == rhs.getStreetname()) && (lhs.getNumber() == rhs.getNumber());
}

/*
   kiiro operator
*/
inline std::ostream& operator << (std::ostream& os, const Address& a) { //kiiro operator, fajlba(!) irashoz
    os << a.getPostalcode() << ";" << a.getCity() << ";" << a.getStreetname() << ";" << a.getNumber();
    return os;
}

#endif
