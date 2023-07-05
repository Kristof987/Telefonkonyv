#include "menu.h"
#include "econio.h"
//#include <string>
using namespace std;

void menu_cout() { //fomenu
    //system("CLS");
    std::cout << "                                            *********PHONEBOOK*********" << endl << endl;
    std::cout << "                               ***Choose from the options below by pressing a number!***" << endl << endl;
    std::cout << "                                  (1) Edit          (2) Add            (3) Delete" << endl;
    std::cout << "                                  (4) List          (5) Search         (6) Exit" << endl;

}

void search_menu_cout() { //almenu kereseshez
    econio_clrscr();
    std::cout << "                                    *********Which record do you want to search?**********" << endl << endl;
    std::cout << "                                   ***Choose from the numbers below by pressing a number!***" << endl << endl;
    std::cout << "                               (1) Name                    (2) Nickname              (3) Address" << endl << endl;
    std::cout << "                                           (4) E-mail                    (5) Comment"  << endl << endl;
    std::cout << "                               (6) Phone number            (7) Work Number           (8) School" << endl << endl;
    std::cout << "                               (9) Workplace               (10) Hobby                (11) Back" << endl << endl;

    cout << "Instructions:" << endl;
    cout << "Enter the number whose record you want to search!" << endl;
    cout << "Press the number to start searching a record of your own choice!" << endl;
}

void menu() {
    int choice = 0;
    while (choice != 999999) {
        menu_cout();
        string choise_str = "";
        cin >> choise_str;
        choice = atoi(choise_str.c_str());
        switch (choice) {
        case 1:
        {
            cout << "Your choose: Edit Menu" << endl << endl; //szerkesztes
            cout << "Instructions:" << endl;
            cout << "You will be able to set a new data for the specific element by typing Y/y" << endl;
            cout << "And you will be able to set the old data by pressing any other character." << endl;
            cout << "If you have chosen to set new data, you have to type in the specific data." << endl;
            cout << "Press a button to start editing an element of your own choice!" << endl;
            getchar();
            getchar();
            Book* b = new Book();
            b->loadFromFile("szoveg.txt"); //konyv feltoltese fajlbol
            cout << "Enter the phone number whose details you want to edit!" << endl; //TODO!!!
            Number* n = new Number();
            cin >> *n; //telefonszam bekerese
            if (b->getStudentByNumber(n) != NULL)
            {
                string input = "";
                string choose;
                Student* update = b->getStudentByNumber(n); //megkeressuk az adott rekordot telefonszam alapjan (ha nincs ilyen, hibauzenettel jelezzuk)
                cout << "We found a student named " << update->getName() << endl;
                cout << "Edit their details!" << endl << endl;
                Student* s = new Student; //tanulo adatainak megadasa...
                s->setPhonenumber(*n);
                cout << "Enter the school! " << "The old data was: " << update->getSchool() << endl;
                cout << "Do you want to refresh the school data? Type (Y)es/(y)es" << endl << endl;
                getline(cin, choose);
                if (tolower(choose[0]) == 'y') {
                    cout << endl << "Enter the new school you would like to save!" << endl;
                    getline(cin,input);
                    s->setSchool(input);
                    cout << endl << "The new school successfully saved." << endl << endl;
                }
                else {
                    s->setSchool(update->getSchool());
                    cout << endl << "The old school succesfully saved." << endl << endl;
                }
                Address input_address;
                cout << "Enter the address! " << "The old data was: " << update->getAddress().getPostalcode() << " " << update->getAddress().getCity() << " " << update->getAddress().getStreetname() << " " << update->getAddress().getNumber() << " " << endl;
                cout << "Do you want to refresh the address datas? Type (Y)es/(y)es" << endl << endl;
                cin >> choose;
                if (tolower(choose[0]) == 'y') {
                    cin >> input_address;
                    s->setAddress(input_address);
                    cout << endl << "The new address successfully saved." << endl << endl;
                }
                else {
                    s->setAddress(update->getAddress());
                    cout << endl << "The old address succesfully saved." << endl << endl;
                }
                cout << "Enter the name! " << "The old data was: " << update->getName() << endl;
                cout << "Do you want to refresh the name data? Type (Y)es/(y)es" << endl << endl;
                cin >> choose;
                if (tolower(choose[0]) == 'y') {
                    cout << endl << "Enter the new name you would like to save!" << endl;
                    cin.clear();
                    fflush(stdin);
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, input);
                    s->setName(input);
                    cout << endl << "The new name successfully saved." << endl << endl;
                }
                else {
                    s->setName(update->getName());
                    cout << endl << "The old name succesfully saved." << endl << endl;
                }
                cout << "Enter the nickname! " << "The old data was: " << update->getNickname() << endl;
                cout << "Do you want to refresh the nickname data? Type (Y)es/(y)es" << endl << endl;
                cin >> choose;
                if (tolower(choose[0]) == 'y') {
                    cout << endl << "Enter the new nickname you would like to save!" << endl;
                    cin.clear();
                    fflush(stdin);
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, input);
                    s->setNickname(input);
                    cout << endl << "The new nickname successfully saved." << endl << endl;
                }
                else {
                    s->setNickname(update->getNickname());
                    cout << endl << "The old nickname succesfully saved." << endl << endl;
                }
                cout << "Enter the email! " << "The old data was: " << update->getEmail() << endl;
                cout << "Do you want to refresh the email data ? Type(Y)es / (y)es" << endl << endl;
                cin >> choose;
                if (choose == "y") {
                    cout << endl << "Enter the new email you would like to save!" << endl;
                    cin.clear();
                    fflush(stdin);
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, input);
                    s->setEmail(input);
                    cout << endl << "The new email successfully saved." << endl << endl;
                }
                else {
                    s->setEmail(update->getEmail());
                    cout << endl << "The old email succesfully saved." << endl << endl;
                }
                cout << "Enter the comment! " << "The old data was: " << update->getComment() << endl;
                cout << "Do you want to refresh the comment data? Type (Y)es/(y)es" << endl << endl;
                cin >> choose;
                if (choose == "y") {
                    cout << endl << "Enter the new comment you would like to save!" << endl;
                    cin.clear();
                    fflush(stdin);
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, input);
                    s->setComment(input);
                    cout << endl << "The new comment successfully saved." << endl << endl;
                }
                else {
                    s->setComment(update->getComment());
                    cout << endl << "The old comment succesfully saved." << endl << endl;
                }
                Number input_number;
                cout << "Enter the work number! " << "The old data was: " << update->getWorknumber().getAreacode() << " " << update->getWorknumber().getAreacode() << endl;
                cout << "Do you want to refresh the work number data? Type (Y)es/(y)es" << endl << endl;
                cin >> choose;
                if (choose == "y") {
                    cout << endl << "Enter the new work number you would like to save!" << endl;
                    cin.clear();
                    fflush(stdin);
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> input_number;
                    s->setWorknumber(input_number);
                    cout << endl << "The new work number successfully saved." << endl << endl;
                }
                else {
                    s->setWorknumber(update->getWorknumber());
                    cout << endl << "The old work number succesfully saved." << endl << endl;
                }

                update->update(s); //frissitjuk a rekordot az uj/regi adatokkal
                delete s;


            }
            else if (b->getAdultByNumber(n) != NULL) //ugyanez felnottekre
            {
            string input = "";
            string choose;
            Adult* update = b->getAdultByNumber(n); //megkeressuk az adott rekordot telefonszam alapjan (ha nincs ilyen, hibauzenettel jelezzuk)
            cout << "We found an adult named " << update->getName() << endl;
            cout << "Edit their details!" << endl << endl;
            Adult* s = new Adult; //tanulo adatainak megadasa...
            s->setPhonenumber(*n);
            cout << "Enter the workplace! " << "The old data was: " << update->getWorkplace() << endl;
            cout << "Do you want to refresh the workplace data? Type (Y)es/(y)es" << endl << endl;
            getline(cin, choose);
            if (tolower(choose[0]) == 'y') {
                cout << endl << "Enter the new workplace you would like to save!" << endl;
                getline(cin, input);
                s->setWorkplace(input);
                cout << endl << "The new workplace successfully saved." << endl << endl;
            }
            else {
                s->setWorkplace(update->getWorkplace());
                cout << endl << "The old workplace succesfully saved." << endl << endl;
            }
            Address input_address;
            cout << "Enter the address! " << "The old data was: " << update->getAddress().getPostalcode() << " " << update->getAddress().getCity() << " " << update->getAddress().getStreetname() << " " << update->getAddress().getNumber() << " " << endl;
            cout << "Do you want to refresh the address datas? Type (Y)es/(y)es" << endl << endl;
            cin >> choose;
            if (tolower(choose[0]) == 'y') {
                cin >> input_address;
                s->setAddress(input_address);
                cout << endl << "The new address successfully saved." << endl << endl;
            }
            else {
                s->setAddress(update->getAddress());
                cout << endl << "The old address succesfully saved." << endl << endl;
            }
            cout << "Enter the name! " << "The old data was: " << update->getName() << endl;
            cout << "Do you want to refresh the name data? Type (Y)es/(y)es" << endl << endl;
            cin >> choose;
            if (tolower(choose[0]) == 'y') {
                cout << endl << "Enter the new name you would like to save!" << endl;
                cin.clear();
                fflush(stdin);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, input);
                s->setName(input);
                cout << endl << "The new name successfully saved." << endl << endl;
            }
            else {
                s->setName(update->getName());
                cout << endl << "The old name succesfully saved." << endl << endl;
            }
            cout << "Enter the nickname! " << "The old data was: " << update->getNickname() << endl;
            cout << "Do you want to refresh the nickname data? Type (Y)es/(y)es" << endl << endl;
            cin >> choose;
            if (tolower(choose[0]) == 'y') {
                cout << endl << "Enter the new nickname you would like to save!" << endl;
                cin.clear();
                fflush(stdin);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, input);
                s->setNickname(input);
                cout << endl << "The new nickname successfully saved." << endl << endl;
            }
            else {
                s->setNickname(update->getNickname());
                cout << endl << "The old nickname succesfully saved." << endl << endl;
            }
            cout << "Enter the email! " << "The old data was: " << update->getEmail() << endl;
            cout << "Do you want to refresh the email data ? Type(Y)es / (y)es" << endl << endl;
            cin >> choose;
            if (choose == "y") {
                cout << endl << "Enter the new email you would like to save!" << endl;
                cin.clear();
                fflush(stdin);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, input);
                s->setEmail(input);
                cout << endl << "The new email successfully saved." << endl << endl;
            }
            else {
                s->setEmail(update->getEmail());
                cout << endl << "The old email succesfully saved." << endl << endl;
            }
            cout << "Enter the comment! " << "The old data was: " << update->getComment() << endl;
            cout << "Do you want to refresh the comment data? Type (Y)es/(y)es" << endl << endl;
            cin >> choose;
            if (choose == "y") {
                cout << endl << "Enter the new comment you would like to save!" << endl;
                cin.clear();
                fflush(stdin);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, input);
                s->setComment(input);
                cout << endl << "The new comment successfully saved." << endl << endl;
            }
            else {
                s->setComment(update->getComment());
                cout << endl << "The old comment succesfully saved." << endl << endl;
            }
            Number input_number;
            cout << "Enter the work number! " << "The old data was: " << update->getWorknumber().getAreacode() << " " << update->getWorknumber().getAreacode() << endl;
            cout << "Do you want to refresh the work number data? Type (Y)es/(y)es" << endl << endl;
            cin >> choose;
            if (choose == "y") {
                cout << endl << "Enter the new work number you would like to save!" << endl;
                cin.clear();
                fflush(stdin);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> input_number;
                s->setWorknumber(input_number);
                cout << endl << "The new work number successfully saved." << endl << endl;
            }
            else {
                s->setWorknumber(update->getWorknumber());
                cout << endl << "The old work number succesfully saved." << endl << endl;
            }

            update->update(s); //frissitjuk a rekordot az uj/regi adatokkal
            delete s;
            }
            else if (b->GetRetiredByNumber(n) != NULL) //ugyanez nyugdijasokra
            {
            string input = "";
            string choose;
            Retired* update = b->GetRetiredByNumber(n); //megkeressuk az adott rekordot telefonszam alapjan (ha nincs ilyen, hibauzenettel jelezzuk)
            cout << "We found a retired named " << update->getName() << endl;
            cout << "Edit their details!" << endl << endl;
            Retired* s = new Retired; //tanulo adatainak megadasa...
            s->setPhonenumber(*n);
            cout << "Enter the hobby! " << "The old data was: " << update->getHobby() << endl;
            cout << "Do you want to refresh the hobby data? Type (Y)es/(y)es" << endl << endl;
            getline(cin, choose);
            if (tolower(choose[0]) == 'y') {
                cout << endl << "Enter the new hobby you would like to save!" << endl;
                getline(cin, input);
                s->setHobby(input);
                cout << endl << "The new hobby successfully saved." << endl << endl;
            }
            else {
                s->setHobby(update->getHobby());
                cout << endl << "The old hobby succesfully saved." << endl << endl;
            }
            Address input_address;
            cout << "Enter the address! " << "The old data was: " << update->getAddress().getPostalcode() << " " << update->getAddress().getCity() << " " << update->getAddress().getStreetname() << " " << update->getAddress().getNumber() << " " << endl;
            cout << "Do you want to refresh the address datas? Type (Y)es/(y)es" << endl << endl;
            cin >> choose;
            if (tolower(choose[0]) == 'y') {
                cin >> input_address;
                s->setAddress(input_address);
                cout << endl << "The new address successfully saved." << endl << endl;
            }
            else {
                s->setAddress(update->getAddress());
                cout << endl << "The old address succesfully saved." << endl << endl;
            }
            cout << "Enter the name! " << "The old data was: " << update->getName() << endl;
            cout << "Do you want to refresh the name data? Type (Y)es/(y)es" << endl << endl;
            cin >> choose;
            if (tolower(choose[0]) == 'y') {
                cout << endl << "Enter the new name you would like to save!" << endl;
                cin.clear();
                fflush(stdin);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, input);
                s->setName(input);
                cout << endl << "The new name successfully saved." << endl << endl;
            }
            else {
                s->setName(update->getName());
                cout << endl << "The old name succesfully saved." << endl << endl;
            }
            cout << "Enter the nickname! " << "The old data was: " << update->getNickname() << endl;
            cout << "Do you want to refresh the nickname data? Type (Y)es/(y)es" << endl << endl;
            cin >> choose;
            if (tolower(choose[0]) == 'y') {
                cout << endl << "Enter the new nickname you would like to save!" << endl;
                cin.clear();
                fflush(stdin);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, input);
                s->setNickname(input);
                cout << endl << "The new nickname successfully saved." << endl << endl;
            }
            else {
                s->setNickname(update->getNickname());
                cout << endl << "The old nickname succesfully saved." << endl << endl;
            }
            cout << "Enter the email! " << "The old data was: " << update->getEmail() << endl;
            cout << "Do you want to refresh the email data ? Type(Y)es / (y)es" << endl << endl;
            cin >> choose;
            if (choose == "y") {
                cout << endl << "Enter the new email you would like to save!" << endl;
                cin.clear();
                fflush(stdin);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, input);
                s->setEmail(input);
                cout << endl << "The new email successfully saved." << endl << endl;
            }
            else {
                s->setEmail(update->getEmail());
                cout << endl << "The old email succesfully saved." << endl << endl;
            }
            cout << "Enter the comment! " << "The old data was: " << update->getComment() << endl;
            cout << "Do you want to refresh the comment data? Type (Y)es/(y)es" << endl << endl;
            cin >> choose;
            if (choose == "y") {
                cout << endl << "Enter the new comment you would like to save!" << endl;
                cin.clear();
                fflush(stdin);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, input);
                s->setComment(input);
                cout << endl << "The new comment successfully saved." << endl << endl;
            }
            else {
                s->setComment(update->getComment());
                cout << endl << "The old comment succesfully saved." << endl << endl;
            }
            Number input_number;
            cout << "Enter the work number! " << "The old data was: " << update->getWorknumber().getAreacode() << " " << update->getWorknumber().getAreacode() << endl;
            cout << "Do you want to refresh the work number data? Type (Y)es/(y)es" << endl << endl;
            cin >> choose;
            if (choose == "y") {
                cout << endl << "Enter the new work number you would like to save!" << endl;
                cin.clear();
                fflush(stdin);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> input_number;
                s->setWorknumber(input_number);
                cout << endl << "The new work number successfully saved." << endl << endl;
            }
            else {
                s->setWorknumber(update->getWorknumber());
                cout << endl << "The old work number succesfully saved." << endl << endl;
            }

            update->update(s); //frissitjuk a rekordot az uj/regi adatokkal
            delete s;
            }
            else //ha nem talalunk rekordot ilyen telefonszammal, jelezzuk
            {
                cout << "There's no person with the given phone number in the database." << endl << endl;
            }
            b->writeToFile("szoveg.txt"); //fajlba visszairjuk
            delete b;
            delete n;
            cout << "Press a button to return to the main menu." << endl;
            getchar();
            econio_clrscr();
        }
        break;
        case 2:
        {
            cout << "Your choose: Add Menu" << endl << endl; //hozzaadas
            cout << "Instructions:" << endl;
            cout << "First, you will be able to choose what type of record you want to add." << endl;
            cout << "Press (1), if it's a Student, (2) if it's an Adult, and (3) if it's a Retired." << endl;
            cout << "After that, you can add a new record, by typing in the specific datas." << endl;
            cout << "Press a button to start adding an element of your own choice!" << endl << endl;
            getchar();
            getchar();
            int peopleType = 0;
            Book* b = new Book();
            b->loadFromFile("szoveg.txt"); //konyv feltoltese fajlbol
            //Adatbekérés
            std::cout << "What type of record do you want to add?" << endl;
            std::cout << "(1) Student, (2) Adult, (3) Retired" << endl; //kivalasztjuk, hogy milyen típusú legyen a személy
            cin >> choise_str;
            cout << endl;
            peopleType = atoi(choise_str.c_str());
            if (1 == peopleType) //ha tanulo
            {
                Student* student = new Student();
                cin >> *student; //az uj tanulo bekerese
                if (b->isContain(student->getPhonenumber())) //Uniq adatok ellenörzése, megadott számokra való keresés (minden telefonszam egyszer lehet benne az adatbazisban)
                {
                    cout << "The person with the given phone number is already in the database" << endl;
                    cout << "Add a different phone number!" << endl;
                    delete student;
                }
                else //ha uj a telefonszam, akkor hozzaadjuk
                {
                    b->add(student);
                    cout << endl << "The new record successfully saved." << endl << endl;
                }
            }
            else if (2 == peopleType) //ha felnott, egyebkent ugyanaz
            {
                Adult* adult = new Adult();
                cin >> *adult;
                if (b->isContain(adult->getPhonenumber()))
                {
                    cout << "The person with the given phone number is already in the database" << endl;
                    cout << "Add a different phone number!" << endl;
                    delete adult;
                }
                else
                {
                    b->add(adult);
                    cout << endl << "The new record successfully saved." << endl << endl;
                }

            }
            else if (3 == peopleType) //ha nyugdijas, egyebkent ugyanaz
            {
                Retired* retired = new Retired();
                cin >> *retired;
                if (b->isContain(retired->getPhonenumber()))
                {
                    cout << "The person with the given phone number is already in the database" << endl;
                    cout << "Add a different phone number!" << endl;
                    delete retired;
                }
                else
                {
                    b->add(retired);
                    cout << endl << "The new record successfully saved." << endl << endl;
                }
            }
            else if (0 == peopleType)
            {
                cout << "Wrong input data, please enter a number between 1-3" << endl << endl;
            }
            b->writeToFile("szoveg.txt"); //visszairjuk fajlba
            delete b;
            cout << "Press a button to return to the main menu." << endl;
            getchar();
            econio_clrscr();
        }
        break;

        case 3:
        {
            cout << "Your choose: Delete Menu" << endl << endl;
            cout << "Instructions:" << endl;
            cout << "You will be able to delete a record by searching for its phone number!" << endl;
            cout << "Press a button to start deleting a record of your own choice!" << endl << endl;
            getchar();
            getchar();
            Book* b = new Book();
            b->loadFromFile("szoveg.txt"); //konyv feltoltese fajlbol
            Number* n = new Number();
            cin >> *n; //telefonszam beolvasasa
            if (b->getStudentByNumber(n) != NULL)
            {
                Student* update = b->getStudentByNumber(n); //megkeressuk az adott rekordot telefonszam alapjan (ha nincs ilyen, hibauzenettel jelezzuk)
                cout << "We found a student named " << update->getName() << "." << endl;
                b->removeByPointer(update); //törlés
                cout << "The record has been deleted." << endl << endl;

            }
            else if (b->getAdultByNumber(n) != NULL)
            {
                Adult* update = b->getAdultByNumber(n);
                cout << "We found an adult named " << update->getName() << endl;
                b->removeByPointer(update); //törlés
                cout << "The record has been deleted" << endl;

            }
            else if (b->GetRetiredByNumber(n) != NULL)
            {
                Retired* update = b->GetRetiredByNumber(n);
                cout << "We found a retired named " << update->getName() << "." << endl;
                b->removeByPointer(update); //törlés
                cout << "The record has been deleted." << endl;

            }
            else
            {
                cout << "There's no person with the given phone number in the database." << endl << endl;
            }
            b->writeToFile("szoveg.txt"); //visszairjuk fajlba
            delete b;
            delete n;
            cout << "Press a button to return to the main menu." << endl;
            getchar();
            econio_clrscr();
        }
        break;
        case 4:
        {
            cout << "Your choose: List Menu" << endl; //listazas menu
            cout << "Instructions:" << endl;
            cout << "Here you can see each the records in the following order:" << endl;
            cout << "First Student, then Adult and finally Retired, all in alphabetical order by name." << endl << endl;
            cout << "Press a button to list the records!" << endl << endl;
            getchar();
            getchar();
            Book* b = new Book();
            b->loadFromFile("szoveg.txt"); //konyv feltoltese fajlbol
            if (!(b->isEmpty())) {
                cout << *b;
            }
            else {
                cout << "There's no data in the file";
            }
            delete b;
            cout << "Press a button to return to the main menu!" << endl;
            getchar();
            econio_clrscr();
        }
        break;
        case 5: //TODO!!!
        {
            choice = 0;
            while (choice != 11)
            {
                search_menu_cout(); //meghivjuk az almenut
                string choise_str = "";
                cin >> choise_str;
                choice = atoi(choise_str.c_str());
                search_menu(choice);
                econio_clrscr();
            }
        }
        break;
        case 6:
            choice = 999999; //kilepes
            break;
        default:
            cout << "Wrong input" << endl;
            cout << "Please enter a number between 1-6" << endl;
            cout << "Press a key to return to the main menu!" << endl;
            getchar();
            getchar();
            econio_clrscr();
        }
    }
}

void search_menu(int choice) {

    Book* b = new Book();
    b->loadFromFile("szoveg.txt"); //konyv feltoltese fajlbol
    if (choice == 3) //lakcimre torteno kereses
    {
        Address* add = new Address();
        string str = "";
        cin.clear();
        fflush(stdin);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, str);
        cout << endl;
        Book* result = search(b, choice, *add);
        if (!(result->isEmpty())) { //ha van ilyen, kiirjuk
            cout << *result;
        }
        else { //ha nincs, jelezzuk hibauzenettel
            cout << endl << "There's no person with the given address in the database." << endl;
            cout << "Press a button to return to the main menu!" << endl;
        }
        delete result;
        delete add;
    }
    else if (choice == 6 || choice == 7) //telefonszamra valo kereses (munkahelyi vagy magan)
    {
        string str = "";
        Number* num = new Number();
        cin.clear();
        fflush(stdin);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,str);
        cout << endl;
        Book* result = search(b, choice, *num);
        if (!(result->isEmpty())) {
            cout << *result << "asd";
            cout << endl << "Press a button to return to the main menu!" << endl;
        }
        else {
            cout << endl << "There's no person with the given phone number in the database." << endl;
            cout << "Press a button to return to the main menu!" << endl;
            cin.clear();
        }
        delete result;
        delete num;

    }
    else if (choice == 11) //ha vissza akarunk menni a fomenube
    {
        cout << "Press a button to return to the main menu!" << endl;

    }
    else if (choice > 11) //ha ervenytelen szamot adtunk meg
    {
        cout << "Wrong number!" << endl;
        cout << "Next time please enter a number between 1-11!" << endl;
        cout << "Press a button to return to the main menu!" << endl;
        //getchar();

    }
    else
    {
        cout << endl << "Press the enter button and after enter data!!" << endl; //minden mas esetben stringre kerestunk ra, az adott adatokat vizsgaljuk
        string str = "";
        cin.clear();
        fflush(stdin);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, str);
        cout << endl;
        Book* result = search(b, choice, str);
        if (!(result->isEmpty())) {
            cout << *result;
        }
        else { //ha nem talaltunk megfelelot
            cout << endl << "There's no person with the given data in the database." << endl;
            cout << "Press a button to return to the main menu!" << endl;
        }
        delete result;
    }
    delete b;
    cin.clear();
    fflush(stdin);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
