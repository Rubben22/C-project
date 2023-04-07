//
// Created by rubyn on 19.05.2022.
//

#ifndef PROIECT_STD_USER_H
#define PROIECT_STD_USER_H
#include "../Interfaces/IE.h"
#include <cstring>
#include <iostream>
#include <utility>
using namespace std;

class User: public IE {
private:
    string id;
    string nume;
    string prenume;
    int varsta{};
    string password;
public:
    User() = default;

    User(string id, string name, string prenume, int varsta, string password) {
        this->id = std::move(id);
        this->nume = std::move(name);
        this->prenume = std::move(prenume);
        this->varsta = varsta;
        this->password = std::move(password);
    }

    User(string nume, string prenume, string password) {
        this->nume = std::move(nume);
        this->prenume = std::move(prenume);
        this->password = std::move(password);
    }

    void set_id(string id1) { this->id = std::move(id1); }

    void set_nume(string name) { this->nume = std::move(name); }

    void set_prenume(string prenumele) { this->prenume = std::move(prenumele); }

    void set_varsta(int varsta1) { this->varsta = varsta1; }

    void set_password(string pass) { this->password = std::move(pass); }

    string get_id() { return this->id; }

    string get_nume() { return this->nume; }

    string get_prenume() { return this->prenume; }

    string get_password() { return this->password; }

    int get_varsta() const { return this->varsta; }

    User &operator=(const User &user) {
        if (this != &user) {
            this->id = user.id;
            this->nume = user.nume;
            this->prenume = user.prenume;
            this->varsta = user.varsta;
            this->password = user.password;
        }
        return *this;
    }

    bool operator==(const User &user) {
        return (this->nume == user.nume && this->prenume == user.prenume);
    }

    bool operator<(const User &user) const {
        return this->varsta < user.varsta;
    }

    ~User() override = default;

    IE *clone() override {
        User *u = new User;
        u->nume = nume;
        u->id = this->id;
        u->prenume = this->prenume;
        u->varsta = this->varsta;
        u->password = this->password;
        return u;
    }

    void copy(IE *e) override {
        User *u = (User *) u;
        id = u->id;
        nume = u->nume;
        prenume = u->prenume;
        varsta = u->varsta;
        password = u->password;
    }

    bool equals_without_password(IE *e) override {
        return (nume == ((User *) e)->nume && prenume == ((User *) e)->prenume);
    }

    bool equals(IE *e) override {
        return (nume == ((User *) e)->nume && prenume == ((User *) e)->prenume && password == ((User *) e)->password);
    }

    bool equals_id(IE* e){
        return id == ((User*)e)->id;
    }

    int compareTo(IE *e) override {
        if (id == ((User *) e)->id && nume == ((User *) e)->nume && prenume == ((User *) e)->prenume &&
            varsta == ((User *) e)->varsta)
            return 0;
        return 1;
    }

    string to_string_without_key() override {
        return "";
    }

    string to_string() override {
        return id + " " + nume + " " + prenume + " " + ::to_string(varsta) + " " + password;
    }

    friend std::ostream &operator<<(std::ostream &fout, const User &user) {
        fout << user.nume;
        fout << " ";
        fout << user.prenume;
    }
};

#endif //PROIECT_STD_USER_H
