#include "book.h"


Book::Book() { //nullparameteres konstruktor
    this->retiredBook = NULL;
    this->adultBook = NULL;
    this->studentBook = NULL;
}

bool Book::isEmpty() { //azt ellenorzi, hogy a book osztalynak van e adattagja (tehat hogy ne adjon vissza null pointert)
    if (this->retiredBook == NULL && this->adultBook == NULL && this->studentBook == NULL)
        return true;
    else return false;
}


void Book::free_book() //a book felszabaditasa (felhasznaljuk a destruktorban)
{
    Student* currentStudent = this->studentBook; //jelenlegi elem
    //Loop in the Student
    while (currentStudent != NULL)
    {
        Student* nextStudent = currentStudent->nextElement; //a kovetkezo elemre allitjuk
        this->removeByPointer(currentStudent); //a jelenlegit toroljuk
        currentStudent = nextStudent; //a kovetkezo lesz az uj jelenlegi elem...
    }
    Adult* currentAdult = this->adultBook; //ugyanez
    //Loop in the Adult
    while (currentAdult != NULL)
    {
        Adult* nextAdult = currentAdult->nextElement;
        this->removeByPointer(currentAdult);
        currentAdult = nextAdult;
    }
    Retired* currentRetired = this->retiredBook; //ugyanez
    //Loop in the Retired
    while (currentRetired != NULL)
    {
        Retired* nextRetired = currentRetired->nextElement;
        this->removeByPointer(currentRetired);
        currentRetired = nextRetired;
    }
}

bool Book::isContain(Number input) //azt ellenorizzuk, hogy tartalmaz e szamot
{
    Student* currentStudent = this->studentBook;
    while (currentStudent != NULL) //vegigmegyunk a studenten
    {
        if (currentStudent->getPhonenumber() == input)
        {
            return true;
        }
        currentStudent = currentStudent->nextElement;
    }

    Adult* currentAdult = this->adultBook;
    while (currentAdult != NULL) //vegigmegyunk az adulton
    {
        if (currentAdult->getPhonenumber() == input)
        {
            return true;
        }
        currentAdult = currentAdult->nextElement;
    }

    Retired* currentRetired = this->retiredBook; //vegigmegyunk a retireden
    //Loop in the Retired
    while (currentRetired != NULL)
    {
        if (currentRetired->getPhonenumber() == input)
        {
            return true;
        }
        currentRetired = currentRetired->nextElement;
    }
    return false;
}

bool Book::isContain(Student* input) //megnezzuk, hogy tartalmaz e studentet
{
    Student* currentStudent = this->studentBook;
    //Loop in the Student
    while (currentStudent != NULL)
    {
        if (currentStudent->getPhonenumber() == input->getPhonenumber())
        {
            return true;
        }
        currentStudent = currentStudent->nextElement;
    }
    return false;
}

bool Book::isContain(Adult* input) //megnezzuk, hogy tartalmaz-e adultot
{
    Adult* currentAdult = this->adultBook;
    //Loop in the Adult
    while (currentAdult != NULL)
    {
        if (currentAdult->getPhonenumber() == input->getPhonenumber())
        {
            return true;
        }
        currentAdult = currentAdult->nextElement;
    }
    return false;
}

bool Book::isContain(Retired* input) //megnezzuk, hogy tartalmaz-e retiredet
{
    Retired* currentRetired = this->retiredBook;
    //Loop in the Retired
    while (currentRetired != NULL)
    {
        if (currentRetired->getPhonenumber() == input->getPhonenumber())
        {
            return true;
        }
        currentRetired = currentRetired->nextElement;
    }
    return false;
}


Student* Book::getStudentByNumber(Number* input) //maganszam alapjan keresunk studentet
{
    Student* currentStudent = this->studentBook;
    while (currentStudent != NULL) //
    {
        if (currentStudent->getPhonenumber() == *input)
        {
            return currentStudent;
        }
        currentStudent = currentStudent->nextElement;
    }
    return NULL;
}

Adult* Book::getAdultByNumber(Number* input) //maganszam alapjan keresunk adultot
{
    Adult* currentAdult = this->adultBook;
    //Loop in the Adult
    while (currentAdult != NULL)
    {
        if (currentAdult->getPhonenumber() == *input)
        {
            return currentAdult;
        }
        currentAdult = currentAdult->nextElement;
    }
    return NULL;
}

Retired* Book::GetRetiredByNumber(Number* input) //maganszam alapjan keresunk retiredet
{
    Retired* currentRetired = this->retiredBook;
    //Loop in the Retired
    while (currentRetired != NULL)
    {
        if (currentRetired->getPhonenumber() == *input)
        {
            return currentRetired;
        }
        currentRetired = currentRetired->nextElement;
    }
    return NULL;
}


void Book::add(Student* p)
{
    p->nextElement = NULL;
    if (this->studentBook == NULL)
    {
        this->studentBook = p;
    }
    else
    {
        Student* last = this->studentBook;
        while (last->nextElement != NULL)
        {

            if (tolower(last->getName()[0]) > tolower(p->getName()[0]))
            {
                break;
            }
            last = last->nextElement;
        }
        if (this->studentBook->nextElement == NULL)
        {

            if (tolower(last->getName()[0]) < tolower(p->getName()[0]))
            {
                last->nextElement = p;
            }
            else
            {
                p->nextElement = this->studentBook;
                this->studentBook = p;
            }
        }
        else
        {
            Student* insert = this->studentBook;
            if (last == this->studentBook)
            {
                p->nextElement = this->studentBook;
                this->studentBook = p;
            }
            else if (last->nextElement == NULL)
            {
                if (tolower(last->getName()[0]) < tolower(p->getName()[0]))
                {
                    last->nextElement = p;
                }
                else
                {
                    while (insert->nextElement != last && insert->nextElement != NULL)
                    {
                        insert = insert->nextElement;
                    }
                    p->nextElement = last;
                    insert->nextElement = p;
                }
            }
            else
            {
                while (insert->nextElement != last && insert->nextElement != NULL)
                {
                    insert = insert->nextElement;
                }
                p->nextElement = last;
                insert->nextElement = p;
            }

        }
    }
}


void Book::add(Adult* p)
{
    p->nextElement = NULL;
    if (this->adultBook == NULL)
    {
        this->adultBook = p;
    }
    else
    {

        Adult* last = this->adultBook;
        while (last->nextElement != NULL)
        {

            if (tolower(last->getName()[0]) > tolower(p->getName()[0]))
            {
                break;
            }
            last = last->nextElement;
        }
        if (this->adultBook->nextElement == NULL)
        {

            if (tolower(last->getName()[0]) < tolower(p->getName()[0]))
            {
                last->nextElement = p;
            }
            else
            {
                p->nextElement = this->adultBook;
                this->adultBook = p;
            }
        }
        else
        {
            Adult* insert = this->adultBook;
            if (last == this->adultBook)
            {
                p->nextElement = this->adultBook;
                this->adultBook = p;
            }
            else if (last->nextElement == NULL)
            {
                if (tolower(last->getName()[0]) < tolower(p->getName()[0]))
                {
                    last->nextElement = p;
                }
                else
                {
                    while (insert->nextElement != last && insert->nextElement != NULL)
                    {
                        insert = insert->nextElement;
                    }
                    p->nextElement = last;
                    insert->nextElement = p;
                }
            }
            else
            {
                while (insert->nextElement != last && insert->nextElement != NULL)
                {
                    insert = insert->nextElement;
                }
                p->nextElement = last;
                insert->nextElement = p;
            }

        }
    }
}


void Book::add(Retired* p)
{
    p->nextElement = NULL;
    if (this->retiredBook == NULL)
    {
        this->retiredBook = p;
    }
    else
    {

        Retired* last = this->retiredBook;
        while (last->nextElement != NULL)
        {

            if (tolower(last->getName()[0]) > tolower(p->getName()[0]))
            {
                break;
            }
            last = last->nextElement;
        }
        if (this->retiredBook->nextElement == NULL)
        {

            if (tolower(last->getName()[0]) < tolower(p->getName()[0]))
            {
                last->nextElement = p;
            }
            else
            {
                p->nextElement = this->retiredBook;
                this->retiredBook = p;
            }
        }
        else
        {
            Retired* insert = this->retiredBook;
            if (last == this->retiredBook)
            {
                p->nextElement = this->retiredBook;
                this->retiredBook = p;
            }
            else if (last->nextElement == NULL)
            {
                if (tolower(last->getName()[0]) < tolower(p->getName()[0]))
                {
                    last->nextElement = p;
                }
                else
                {
                    while (insert->nextElement != last && insert->nextElement != NULL)
                    {
                        insert = insert->nextElement;
                    }
                    p->nextElement = last;
                    insert->nextElement = p;
                }
            }
            else
            {
                while (insert->nextElement != last && insert->nextElement != NULL)
                {
                    insert = insert->nextElement;
                }
                p->nextElement = last;
                insert->nextElement = p;
            }

        }
    }
}


void Book::removeByPointer(Adult* p)
{

    Adult* previouse = this->adultBook;
    if (this->adultBook != NULL) //ha van a bookban adat
    {
        if (this->adultBook == p) //ha megtalaltuk az elemet
        {
            if (this->adultBook->nextElement != NULL)
            {
                this->adultBook = this->adultBook->nextElement; //kovetkezo elem lesz az uj aktualis elem
            }
            delete p; //a regi aktualis elem torlese

        }
        else //ha nem talaltuk meg meg
        {
            while (previouse->nextElement != p && previouse->nextElement != NULL) //addig haladunk a ciklusban amig megtalaljuk, vagy amig el nem erjuk a lista veget
            {
                previouse = previouse->nextElement; // leptetjuk az elemet
            }
            if (p->nextElement != NULL) //ha megtalaltuk, es van utana adat
            {
                previouse->nextElement = p->nextElement; //akkor az utana kovetkezore allitjuk a pointert
            }
            else
            {
                previouse->nextElement = NULL;
            }
            delete p;
        }
    }
}

void Book::removeByPointer(Student* p)
{

    Student* previouse = this->studentBook;
    if (this->studentBook != NULL)
    {
        if (this->studentBook == p)
        {
            if (this->studentBook->nextElement != NULL)
            {
                this->studentBook = this->studentBook->nextElement;
            }
            delete p;

        }
        else
        {
            while (previouse->nextElement != p && previouse->nextElement != NULL)
            {
                previouse = previouse->nextElement;
            }
            if (p->nextElement != NULL)
            {
                previouse->nextElement = p->nextElement;
            }
            else
            {
                previouse->nextElement = NULL;
            }
            delete p;
        }
    }
}

void Book::removeByPointer(Retired* p)
{

    Retired* previouse = this->retiredBook;
    if (this->retiredBook != NULL)
    {
        if (this->retiredBook == p)
        {
            if (this->retiredBook->nextElement != NULL)
            {
                this->retiredBook = this->retiredBook->nextElement;
            }
            delete p;

        }
        else
        {
            while (previouse->nextElement != p && previouse->nextElement != NULL)
            {
                previouse = previouse->nextElement;
            }
            if (p->nextElement != NULL)
            {
                previouse->nextElement = p->nextElement;
            }
            else
            {
                previouse->nextElement = NULL;
            }
            delete p;
        }
    }
}
void Book::cutByPointer(Adult* p)
{
    Adult* previouse = this->adultBook;
    if (this->adultBook != NULL)
    {
        if (this->adultBook == p)
        {
            if (this->adultBook->nextElement != NULL)
            {
                this->adultBook = this->adultBook->nextElement;
            }
            else
            {
                this->adultBook = NULL;
            }

        }
        else
        {
            while (previouse->nextElement != p && previouse->nextElement != NULL)
            {
                previouse = previouse->nextElement;
            }
            if (p->nextElement != NULL)
            {
                previouse->nextElement = p->nextElement;
            }
            else
            {
                previouse->nextElement = NULL;
            }
        }
    }
    p->nextElement = NULL;


}

void Book::cutByPointer(Student* p)
{
    Student* previouse = this->studentBook;
    if (this->studentBook != NULL)
    {
        if (this->studentBook == p)
        {
            if (this->studentBook->nextElement != NULL)
            {
                this->studentBook = this->studentBook->nextElement;
            }
            else
            {
                this->studentBook = NULL;
            }

        }
        else
        {
            while (previouse->nextElement != p && previouse->nextElement != NULL)
            {
                previouse = previouse->nextElement;
            }
            if (p->nextElement != NULL)
            {
                previouse->nextElement = p->nextElement;
            }
            else
            {
                previouse->nextElement = NULL;
            }
        }
    }
    p->nextElement = NULL;
}

void Book::cutByPointer(Retired* p)
{
    Retired* previouse = this->retiredBook;
    if (this->retiredBook != NULL)
    {
        if (this->retiredBook == p)
        {
            if (this->retiredBook->nextElement != NULL)
            {
                this->retiredBook = this->retiredBook->nextElement;
            }
            else
            {
                this->retiredBook = NULL;
            }

        }
        else
        {
            while (previouse->nextElement != p && previouse->nextElement != NULL)
            {
                previouse = previouse->nextElement;
            }
            if (p->nextElement != NULL)
            {
                previouse->nextElement = p->nextElement;
            }
            else
            {
                previouse->nextElement = NULL;
            }
        }
    }
    p->nextElement = NULL;
}

void Book::loadFromFile(string path)
{
    string myText = "";

    ifstream MyReadFile(path);


    while (getline(MyReadFile, myText)) {
        istringstream ss(myText);
        Retired* ret_p;
        Adult* ad_p;
        Student* stu_p;

        ret_p = new Retired;
        ad_p = new Adult;
        stu_p = new Student;


        string token;
        string areaCode = "";
        int postalCode = 0;
        string City = "";
        string streetName = "";
        int datCounter = 0; //I count the datas in the string
        int listID = 100; //Default value
        while (getline(ss, token, ';')) {
            if (0 == datCounter)
            {
                listID = stoi(token);
            }
            if (0 == listID) //Student
            {
                switch (datCounter) {
                case 0:
                    delete ad_p;
                    delete ret_p;
                    //stu_p = new Student;
                    //code block
                    break;
                case 1:
                    stu_p->setSchool(token);
                    //code block
                    break;
                case 2:
                    postalCode = stoi(token);
                    //code block
                    break;
                case 3:
                    City = token;
                    // code block
                    break;
                case 4:
                    streetName = token;
                    // code block
                    break;
                case 5:
                {
                    Address a;
                    a.setPostalcode(postalCode);
                    a.setCity(City);
                    a.setStreetname(streetName);
                    a.setNumber(token);
                    stu_p->setAddress(a);
                }
                // code block
                break;
                case 6:
                    areaCode = token;
                    // code block
                    break;
                case 7:
                {
                    Number num;
                    num.setAreacode(areaCode);
                    num.setNumber(token);
                    stu_p->setPhonenumber(num);
                    // code block
                    break;
                }
                case 8:
                    areaCode = token;
                    // code block
                    break;
                case 9:
                {
                    Number num;
                    num.setAreacode(areaCode);
                    num.setNumber(token);
                    stu_p->setWorknumber(num);
                    // code block
                    break;
                }
                case 10:
                    stu_p->setName(token);
                    this->add(stu_p);
                    // code block
                    break;
                case 11:
                    stu_p->setNickname(token);
                    // code block
                    break;
                case 12:
                    stu_p->setEmail(token);
                    // code block
                    break;
                case 13:
                    stu_p->setComment(token);
                    // code block
                    break;
                default:
                    cout << "";
                    // code block
                }
                std::cout.flush();
            }
            else if (1 == listID) //Adult
            {
                switch (datCounter) {
                case 0:
                    delete ret_p;
                    delete stu_p;
                    //ad_p = new Adult;
                    //code block
                    break;
                case 1:
                    ad_p->setWorkplace(token);
                    //code block
                    break;
                case 2:
                    postalCode = stoi(token);
                    //code block
                    break;
                case 3:
                    City = token;
                    // code block
                    break;
                case 4:
                    streetName = token;
                    // code block
                    break;
                case 5:
                {
                    Address a;
                    a.setPostalcode(postalCode);
                    a.setCity(City);
                    a.setStreetname(streetName);
                    a.setNumber(token);
                    ad_p->setAddress(a);
                }
                // code block
                break;
                case 6:
                    areaCode = token;
                    // code block
                    break;
                case 7:
                {
                    Number num;
                    num.setAreacode(areaCode);
                    num.setNumber(token);
                    ad_p->setPhonenumber(num);
                    // code block
                    break;
                }
                case 8:
                    areaCode = token;
                    // code block
                    break;
                case 9:
                {
                    Number num;
                    num.setAreacode(areaCode);
                    num.setNumber(token);
                    ad_p->setWorknumber(num);
                    // code block
                    break;
                }
                case 10:
                    ad_p->setName(token);
                    this->add(ad_p);
                    // code block
                    break;
                case 11:
                    ad_p->setNickname(token);
                    // code block
                    break;
                case 12:
                    ad_p->setEmail(token);
                    // code block
                    break;
                case 13:
                    ad_p->setComment(token);
                    // code block
                    break;
                default:
                    cout << "";
                    // code block
                }
                std::cout.flush();
            }
            else if (2 == listID) //Retired
            {
                switch (datCounter) {
                case 0:
                    //ret_p = new Retired;
                    delete stu_p;
                    delete ad_p;
                    //code block
                    break;
                case 1:
                    ret_p->setHobby(token);
                    //code block
                    break;
                case 2:
                    postalCode = stoi(token);
                    //code block
                    break;
                case 3:
                    City = token;
                    // code block
                    break;
                case 4:
                    streetName = token;
                    // code block
                    break;
                case 5:
                {
                    Address a;
                    a.setPostalcode(postalCode);
                    a.setCity(City);
                    a.setStreetname(streetName);
                    a.setNumber(token);
                    ret_p->setAddress(a);
                }
                // code block
                break;
                case 6:
                    areaCode = token;
                    // code block
                    break;
                case 7:
                {
                    Number num;
                    num.setAreacode(areaCode);
                    num.setNumber(token);
                    ret_p->setPhonenumber(num);
                    // code block
                    break;
                }
                case 8:
                    areaCode = token;
                    // code block
                    break;
                case 9:
                {
                    Number num;
                    num.setAreacode(areaCode);
                    num.setNumber(token);
                    ret_p->setWorknumber(num);
                    // code block
                    break;
                }
                case 10:
                    ret_p->setName(token);
                    this->add(ret_p);
                    // code block
                    break;
                case 11:
                    ret_p->setNickname(token);
                    // code block
                    break;
                case 12:
                    ret_p->setEmail(token);
                    // code block
                    break;
                case 13:
                    ret_p->setComment(token);
                    // code block
                    break;
                default:
                    cout << "";
                    // code block
                }
                std::cout.flush();
            }
            datCounter++;

        }

    }

    MyReadFile.close();
}



//writetofile
void Book::writeToFile(string path)
{
    ofstream MyWriteFile(path);
    Student* current1 = this->studentBook;
    Adult* current2 = this->adultBook;
    Retired* current3 = this->retiredBook;
    while (current1 != NULL)
    {
        MyWriteFile << *current1 << endl;
        current1 = current1->nextElement;
    }

    while (current2 != NULL)
    {
        MyWriteFile << *current2 << endl;
        current2 = current2->nextElement;
    }

    while (current3 != NULL)
    {
        MyWriteFile << *current3 << endl;
        current3 = current3->nextElement;
    }

    MyWriteFile.close();
}

Book::~Book() { //destruktor
    if (!(this->isEmpty())) {
        this->free_book();
    }
}
