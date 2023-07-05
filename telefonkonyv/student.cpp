#include "student.h"

Student::Student(Address address, //konstruktor
    Number worknumber,
    Number phonenumber,
    string name,
    string nickname,
    string email,
    string comment,
    string school) :Record(address, worknumber, phonenumber, name, nickname, email, comment),
    school(school) {}

Student::Student() :Record(), //nullparameteres konstruktor
school("") {}

string Student::getSchool() const {  //iskola getter
    return school;
}
void Student::setSchool(string school) { //iskola setter
    this->school = school;
}

void Student::update(Student* newValue) //frissit fuggveny, szintugy mint adultnal
{
    this->setSchool(newValue->getSchool());
    Record* currentRecord;
    Record* newRecord;
    currentRecord = this;
    newRecord = newValue;
    currentRecord->update(newRecord);
}
Student::~Student() {} //destruktor
