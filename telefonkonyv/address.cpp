#include "address.h"

Address::Address() :postalcode(0), city(""), streetname(""), number("") {} //nullparameteres konstruktor
Address::Address(int postalcode, std::string city, std::string streetname, std::string number) :postalcode(postalcode), city(city), streetname(streetname), number(number) {} //konstruktor

int Address::getPostalcode() const {  ///iranyitoszam getter
    return postalcode;
}
void Address::setPostalcode(int postalcode) { //iranyitoszam setter
    this->postalcode = postalcode;
}
std::string Address::getCity() const {  //varos getter
    return city;
}
void Address::setCity(std::string City) { //varos setter
    this->city = City;
}
std::string Address::getStreetname() const {  //utcanev getter
    return streetname;
}
void Address::setStreetname(std::string streetname) { //utcanev setter
    this->streetname = streetname;
}
std::string Address::getNumber() const {  //hazszam getter
    return number;
}
void Address::setNumber(std::string number) { //hazszam setter
    this->number = number;
}
Address::~Address() {} //destruktor