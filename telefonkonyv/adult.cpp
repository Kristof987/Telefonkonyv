#include "adult.h"

Adult::Adult() :Record(), workplace("") {} //nullparameteres konstruktor
Adult::Adult(Address address, //konstruktor
    Number worknumber,
    Number phonenumber,
    string name,
    string nickname,
    string email,
    string comment,
    string workplace)
    :Record(address, worknumber, phonenumber, name, nickname, email, comment)
    , workplace(workplace) {}

string Adult::getWorkplace() const {  //munkahely getter
    return workplace;
}
void Adult::setWorkplace(string workplace) { //munkahely setter
    this->workplace = workplace;
}

void Adult::update(Adult* newValue) //"frissit" fuggveny
{
    this->setWorkplace(newValue->getWorkplace()); //munkahely beallitasa
    Record* currentRecord;
    Record* newRecord;
    currentRecord = this; //megkapja this recordot
    newRecord = newValue; //megkapja newvalue erteket
    currentRecord->update(newRecord); //record update fuggvenyet meghivva, frissiti a rekordot
}
Adult::~Adult() {} //destruktor
