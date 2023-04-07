//
// Created by rubyn on 19.05.2022.
//

#ifndef PROIECT_STD_USER_INTERFACE_H
#define PROIECT_STD_USER_INTERFACE_H
#include "../Retea/Retea.h"
#include "../Entity/MyException.h"
#include <iomanip>


class User_Interface {
private:
    Retea service;
    string nume_utilizator, prenume_utilizator;
    void create_account();
    void delete_user();
    void update_user();
    void get_all_users();
    void add_friend();
    void delete_friend();
    void get_all_friends();
    void send_message();
    void delete_message();
    void get_all_messages_admin();
    void get_all_received_messages();
    void get_all_sent_messages();
    bool login();
    void login_as_administrator();
public:
    User_Interface() = default;
    explicit User_Interface(Retea & service): service(service) {}
    static void print_login_menu(){
        cout << "1. Login" << endl;
        cout << "2. Create new account" << endl;
        cout << "3. Login as administrator" << endl;
        cout << "0. Exit" << endl;
    }
    void run_login_menu();

    static void print_CRUD_users_menu(){
        cout << "1. Add user" << endl;
        cout << "2. Delete user" << endl;
        cout << "3. Update user" << endl;
        cout << "4. Get all users" << endl;
        cout << "5. Show all messages" << endl;
        cout << "6. Delete message" << endl;
        cout << "0. Back to principal menu" << endl;
    }
    void run_CRUD_users_menu();

    static void after_login(){
        cout << "1. Add friend" << endl;
        cout << "2. Delete friend" << endl;
        cout << "3. Show all friends" << endl;
        cout << "4. Send message" << endl;
        cout << "5. Delete message" << endl;
        cout << "6. Show all sent messages" << endl;
        cout << "7. Show all received messages" << endl;
        cout << "0. Log out" << endl;
    }
    void run_after_login_menu();

    ~User_Interface() = default;
};


#endif //PROIECT_STD_USER_INTERFACE_H
