#include "retired.h"

Retired::Retired(Address address, //konstruktor
    Number worknumber,
    Number phonenumber,
    string name,
    string nickname,
    string email,
    string comment,
    string hobby)
    :Record(address, worknumber, phonenumber, name, nickname, email, comment)
    , hobby(hobby) {}

Retired::Retired() //nullparameteres konstruktor
    :Record()
    , hobby("") {}

string Retired::getHobby() const {  //hobbi getter
    return hobby;
}
void Retired::setHobby(string hobby) { //hobbi setter
    this->hobby = hobby;
}

void Retired::update(Retired* newValue) //frissit fuggveny, ugyanugy mint az adultnal...
{
    this->setHobby(newValue->getHobby());
    Record* currentRecord;
    Record* newRecord;
    currentRecord = this;
    newRecord = newValue;
    currentRecord->update(newRecord);
}
Retired::~Retired() {} //destruktor