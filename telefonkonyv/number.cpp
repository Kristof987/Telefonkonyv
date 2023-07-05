#include "number.h"

Number::Number() :areacode(""), number("") {} //nullparameteres konstruktor
Number::Number(string areacode, string number) :areacode(areacode), number(number) {} //konstruktor

string Number::getAreacode() const {  //areacode getter
    return areacode;
}
void Number::setAreacode(string areacode) { //areacode setter
    this->areacode = areacode;
}

string Number::getNumber() const {  //number getter
    return number;
}
void Number::setNumber(string number) { //number setter
    this->number = number;
}
Number::~Number() {} //destruktor