#include "record.h"

Record::Record() : //nullparameteres konstuktor
    add(), worknumber(), phonenumber(), name(""), nickname(""), email(""), comment("") {}//type + adata(Data) + type

Record::Record(Address add, Number worknumber, Number phonenumber, string name, string nickname, string email, string comment) : ///ctor
    add(add), worknumber(worknumber), phonenumber(phonenumber), name(name), nickname(nickname), email(email), comment(comment) {} //konstruktor

Address Record::getAddress() const { //lakcim getter
    return add;
}

void Record::setAddress(Address add) { //lakcim setter
    this->add = add;
}

Number Record::getWorknumber() const {  //munkahelyi telefonszam getter
    return worknumber;
}
void Record::setWorknumber(Number worknumber) { //munkahelyi telefonszam setter
    this->worknumber = worknumber;
}

Number Record::getPhonenumber() const { //maganszam getter
    return phonenumber;
}

void Record::setPhonenumber(Number phonenumber) { //maganszam setter
    this->phonenumber = phonenumber;
}

string Record::getName() const {  //nev getter
    return name;
}
void Record::setName(string name) { //nev setter
    this->name = name;
}

string Record::getNickname() const { //becenev getter
    return nickname;
}
void Record::setNickname(string nickname) { //becenev setter
    this->nickname = nickname;
}

string Record::getEmail() const {  //email getter
    return email;
}
void Record::setEmail(string email) { //email setter
    this->email = email;
}

string Record::getComment() const {  //comment getter
    return comment;
}
void Record::setComment(string comment) { //comment setter
    this->comment = comment;
}

void Record::update(Record* newValue) //frissit fuggveny
{
    this->setAddress(newValue->getAddress()); //minden erteket frissit...
    this->setWorknumber(newValue->getWorknumber());
    this->setPhonenumber(newValue->getPhonenumber());
    this->setName(newValue->getName());
    this->setNickname(newValue->getNickname());
    this->setEmail(newValue->getEmail());
    this->setComment(newValue->getComment());
}
Record::~Record() {} //destruktor