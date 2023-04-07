//
// Created by rubyn on 19.05.2022.
//
#include "User_Interface.h"

void User_Interface::create_account() {
    try {
        string id, nume, prenume, password;
        int varsta;
        cout << "ID:";
        cin >> id;
        cout << "Nume:";
        cin >> nume;
        cout << "Prenume:";
        cin >> prenume;
        cout << "Varsta:";
        cin >> varsta;
        cout << "Password:";
        cin >> password;
        this->service.add_user(id, nume, prenume, varsta, password);
    }
    catch(MyException &exc){
        cout << exc.what() << "The ID you want to use is not availabile!" << endl;
    }

}

void User_Interface::get_all_users() {
    cout << endl;
    IContainer* lista = this->service.get_all_users();
    IIterator* it = lista->getIterator();
    while (it->isValid()){
        string s = it->getCrtElem()->to_string();
        cout << s << endl;
        it->moveNext();
    }
    cout << endl;
}

void User_Interface::delete_user() {
    try {
        string nume, prenume, password;
        cout << "Nume and prenume:";
        cin >> nume;
        cin >> prenume;
        cout << "Password:";
        cin >> password;
        this->service.delete_user(nume, prenume, password);
        cout << "User succesfully deleted!" << endl;
    }
    catch (MyException &exc){
        cout << "MyException: " << exc.what() << endl;
    }
    catch (...){
        cout << "Other exception.." << endl;
    }
}

void User_Interface::update_user() {
    try {
        string nume, prenume, password, new_id, new_name, new_prenume, new_password;
        int new_varsta;
        cout << "Give the name and prenume:";
        cin >> nume;
        cin >> prenume;
        cout << "Password:";
        cin >> password;
        if (service.login(nume, prenume, password)) {
            cout << "New ID:";
            cin >> new_id;
            cout << "New name:";
            cin >> new_name;
            cout << "New prenume:";
            cin >> new_prenume;
            cout << "New varsta:";
            cin >> new_varsta;
            cout << "New password:";
            cin >> new_password;
            service.update_user(nume, prenume, password, new_id, new_name,
                                    new_prenume, new_varsta, new_password);
            cout << "User successfully updated!" << endl;
        }
        else
            throw MyException("The user you want to update doesn't exist!");
    }
    catch (MyException &exc){
        cout << "MyException: " << exc.what() << endl;
    }
    catch (...){
        cout << "Other exception.." << endl;
    }
}

bool User_Interface::login() {
    string nume, prenume, password;
    cout << "Enter nume and prenume:";
    cin >> nume >> prenume;
    cout << "Password:";
    cin >> password;
    if(this->service.login(nume, prenume, password)){
        nume_utilizator = nume;
        prenume_utilizator = prenume;
        return true;
    }
    return false;
}

void User_Interface::login_as_administrator() {
    string utilizator, password;
    cout << "User:";
    cin>> utilizator;
    cout << "Password:";
    cin >> password;
    if(utilizator == "admin" && password == "admin10")
        run_CRUD_users_menu();
    else
        cout << "Login as administrator failed! Try again" << endl;
}
void User_Interface::add_friend() {
    try {
        string id, nume, prenume, password;
        int varsta;
        cout << "ID:";
        cin >> id;
        cout << "Nume:";
        cin >> nume;
        cout << "Prenume:";
        cin >> prenume;
        cout << "Varsta:";
        cin >> varsta;
        string key_nume = nume_utilizator;
        string key_prenume = prenume_utilizator;
        if(key_nume != nume || key_prenume != prenume) {
            this->service.add_friend(key_nume, key_prenume, id, nume, prenume, varsta, "");
            cout << "Friend succesfully added!" << endl;
        }
        else
            cout << "You can't add yourself as a friend!" << endl;
    }
    catch (MyException &exc){
        cout << "MyException: " << exc.what() << endl;
    }
}

void User_Interface::delete_friend() {
    try {
        string id, nume, prenume, password;
        int varsta;
        cout << "ID:";
        cin >> id;
        cout << "Nume:";
        cin >> nume;
        cout << "Prenume:";
        cin >> prenume;
        cout << "Varsta:";
        cin >> varsta;
        string nume_key = nume_utilizator;
        string prenume_key = prenume_utilizator;
        this->service.delete_friend(nume_key, prenume_key, id, nume, prenume, varsta);
        cout << "User succesfully deleted!" << endl;
    }
    catch (MyException& exc){
        cout << "MyException: " << exc.what() << endl;
    }
}

void User_Interface::get_all_friends() {
    IContainer* multiple_map = this->service.get_all_friends();
    IIterator* it = multiple_map->getIterator();
    string key_nume = nume_utilizator;
    string key_prenume = prenume_utilizator;
    auto* it2 = new NumePrenumeKey(std::move(key_nume), std::move(key_prenume));
    while (it->isValid()){
        IE * pereche = new Pair(it2, it->getCrtElem());
        if (it->getCrtElem()->equals(pereche))
            cout << it->getCrtElem()->to_string_without_key() << endl;
        it->moveNext();
    }
    cout << endl;
}

void User_Interface::send_message() {
    try {
        string to_nume, to_prenume, id;
        string key_nume = nume_utilizator;
        string key_prenume = prenume_utilizator;
        cout << "Message ID:";
        cin >> id;
        cout << "Nume and prenume destinatar:";
        cin >> to_nume;
        cin >> to_prenume;
        cout << "Message (add '.' to the end):";
        std::string s;
        std::getline(std::cin >> std::ws, s);
        this->service.send_message(id, key_nume, key_prenume, to_nume, to_prenume, s);
        cout << "Message succesfully sent!" << endl;
    }
    catch (MyException &exc){
        cout << exc.what() << endl;
    }
}

void User_Interface::delete_message() {
    try {
        string id;
        cout << "Dati ID:";
        cin >> id;
        this->service.delete_message(id);
        cout << "Message succesfully deleted!" << endl;
    }
    catch (MyException &exc){
        cout << "MyException: " << exc.what() << endl;
    }
}

void User_Interface::get_all_messages_admin() {
    vector<Message> all_messages = this->service.get_all_messages();
    for(Message m: all_messages){
        cout << "ID:" + m.get_id() << "   From:" << m.get_from() << "   To:" << m.get_to() <<
        "    Message:" << m.get_message() << endl;
    }
    cout << endl;
}

void User_Interface::get_all_received_messages() {
    string key_nume = nume_utilizator;
    string key_prenume = prenume_utilizator;
    vector<Message> received = service.received_messages(key_nume, key_prenume);
    for(Message m: received){
        cout << "ID:" + m.get_id() << "   From:" << m.get_from() << "    Message:" << m.get_message() << endl;
    }
    cout << endl;
}

void User_Interface::get_all_sent_messages() {
    string key_nume = nume_utilizator;
    string key_prenume = prenume_utilizator;
    vector<Message> sent = service.sent_messages(key_nume, key_prenume);
    for(Message m: sent){
        cout << "ID: " + m.get_id() << "   To: " << m.get_to() << "    Message: " << m.get_message() << endl;
    }
    cout << endl;
}

void User_Interface::run_login_menu() {
    int choice;
    do{
        print_login_menu();
        cout << "Choose an option:";
        cin >> choice;
        switch (choice) {
            case 0:
                break;
            case 1:
                run_after_login_menu();
                break;
            case 2:
                create_account();
                break;
            case 3:
                login_as_administrator();
                break;
            default:
                cout << "Wrong option! Try again";
        }
    } while (choice != 0);

}

void User_Interface::run_CRUD_users_menu() {
    int choice;
    do{
        print_CRUD_users_menu();
        cout << "Choose an option:";
        cin >> choice;
        switch (choice) {
            case 0:
                break;
            case 1:
                create_account();
                break;
            case 2:
                delete_user();
                break;
            case 3:
                update_user();
                break;
            case 4:
                get_all_users();
                break;
            case 5:
                get_all_messages_admin();
                break;
            case 6:
                delete_message();
                break;
            default:
                cout << "Invalid option! Try again" << endl;
        }
    } while (choice != 0);
}

void User_Interface::run_after_login_menu() {
    int rez = login();
    bool finish = false;
    if (rez) {
        do {
            int choice;
            after_login();
            cout << "Choose an option:";
            cin >> choice;
            switch (choice) {
                case 0:
                    finish = true;
                    break;
                case 1:
                    add_friend();
                    break;
                case 2:
                    delete_friend();
                    break;
                case 3:
                    get_all_friends();
                    break;
                case 4:
                    send_message();
                    break;
                case 5:
                    cout << "Sent messages:" << endl;
                    get_all_sent_messages();
                    delete_message();
                    break;
                case 6:
                    get_all_sent_messages();
                    break;
                case 7:
                    get_all_received_messages();
                    break;
                default:
                    cout << "Wrong option! Try again" << endl;
            }
        } while (!finish);
    }
    else{
        cout << "Your name or password is inccorect! Try again" << endl;
    }
}
