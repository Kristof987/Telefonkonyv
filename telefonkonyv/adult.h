#ifndef ADULT_H
#define ADULT_H

#include "record.h"
#include "memtrace.h"

class Adult :public Record { //felnott osztaly
    string workplace; //munkahely
public:
    Adult* nextElement; //kovetkezo elemre mutato pointer
    Adult(); //nullparameteres konstruktor
    Adult(Address address, //konstruktor
        Number worknumber,
        Number phonenumber,
        string name,
        string nickname,
        string email,
        string comment,
        string workplace);

    string getWorkplace() const;  //munkahely getter
    void setWorkplace(string workplace); //munkahely setter
    /*
        a "frissito" fuggveny,
        ami az adott rekordot frissiti a megadott adult parameterrel
        nincs visszateresi erteke
    */
    void update(Adult* newValue); //"frissit" fuggveny
    ~Adult(); //destruktor
};

/*
    beolvaso operator, ha szokozoket hasznalnank
    hellyettesitsuk "_" irasjellel!!
    ketparameteres fuggveny, istream& es adult& tipusokkal
*/
inline std::istream& operator >> (std::istream& is, Adult& a) {
    Record* r; //eloszor beolvassuk a rekordot
    r = &a; //referencia
    cin >> *r; //beolvasas
    cout << "Enter the workplace!" << endl; //majd a munkahelyet
    string input = "";
    getline(is, input);
    a.setWorkplace(input);
    return is;
}

/*
kiiro operator, fajlba(!) irashoz
ketparameteres fuggveny, ostream& es adult& tipusokkal
*/
inline std::ostream& operator << (ostream& os, const Adult& a) {
    const Record* r;
    os << "1;";
    os << a.getWorkplace() << ";";
    r = &a;
    os << *r;
    return os;
}

#endif

