//
// Created by rubyn on 19.05.2022.
//

#ifndef PROIECT_STD_RETEA_H
#define PROIECT_STD_RETEA_H
#include "../TAD-uri/SimpleList/ListContainer.h"
#include "../TAD-uri/MultipleMap/NumePrenumeKey.h"
#include "../TAD-uri/MultipleMap/Pair.h"
#include "../Entity/User.h"
#include <iostream>
#include <utility>
#include "../Repository/RepositoryMessage.h"
#include "../Entity/MyException.h"


class Retea {
private:
    IContainer* lista;
    IContainer* multiple_map_container;
    RepositoryMessage repo_messages;
public:
    Retea() = default;
    Retea(IContainer* container, IContainer* multiple_map, RepositoryMessage &repo_mesaje):
    lista(container), multiple_map_container(multiple_map), repo_messages(repo_mesaje){}
    ~Retea() = default;
    void add_user(string id, string nume, string prenume, int varsta, string password){
        if(!lista->contain_id(id)) {
            User *f = new User(std::move(id), std::move(nume), std::move(prenume),
                               varsta, std::move(password));
            lista->addElem(f);
        }
    }

    bool delete_user(string nume, string prenume, string password){
        User* u = new User(std::move(nume), std::move(prenume), std::move(password));
        if(lista->contains(u)) {
            lista->removeElem(u);
            return true;
        }
        throw MyException("The user you want to delete doesn't exist!");
    }
    void update_user(string nume, string prenume, string password, string new_id, string new_name, string new_prenume,
                     int new_age, string new_password) {
        User *u = new User(std::move(nume), std::move(prenume), std::move(password));
        User *new_us = new User(std::move(new_id), std::move(new_name), std::move(new_prenume),
                                new_age, std::move(new_password));
        lista->update_element(u, new_us);
    }
    IContainer* get_all_users(){
        return this->lista;
    }
    bool login(string nume, string prenume, string password){
        User* u = new User(std::move(nume), std::move(prenume), std::move(password));
        if (lista->contains(u)){
            return true;}
        return false;
    }
    //void availabile_users(string nume_key, string prenume_key);
    void add_friend(string nume_key, string prenume_key, string id, string nume, string prenume,
                    int varsta, string password){
        auto* key = new NumePrenumeKey(std::move(nume_key), std::move(prenume_key));
        auto* us = new User(std::move(id), std::move(nume), std::move(prenume), varsta, std::move(password));
        if(lista->contains_without_password(us)) {
            IE *p = new Pair(key, us);
            multiple_map_container->addElem(p);
        }
        else
            throw MyException("The user you want to add as friend is not registered!");
    }
    void delete_friend(string nume_key, string prenume_key, string id, string nume, string prenume, int varsta){
        auto* key = new NumePrenumeKey(std::move(nume_key), std::move(prenume_key));
        User* u = new User(std::move(id), std::move(nume), std::move(prenume), varsta, "");
        IE* pair = new Pair(key, u);
        if(multiple_map_container->contains(pair))
            multiple_map_container->removeElem(pair);
        else
            throw MyException("The friend you want to delete doesn't exist!");
    }
    IContainer* get_all_friends(){
        return this->multiple_map_container;
    }

    void send_message(const string& id, const string& nume_from, const string& prenume_from,
                      const string& nume_to, const string& prenume_to, string message){
        User from(nume_from, prenume_from, "");
        User to(nume_to, prenume_to, "");
        Message m(id, from, to, std::move(message));
        User *p = new User(nume_to, prenume_to, "");
        if(lista->contains_without_password(p)) {
            if(!this->repo_messages.contain_id(id))
                this->repo_messages.send_message(m);
        }
        else
            throw MyException("Error: The user you want to send is not registered!");
    }

    vector<Message> sent_messages(string nume_from, string prenume_from){
        User to(std::move(nume_from), std::move(prenume_from), "");
        vector<Message> all_messages = this->repo_messages.get_all();
        vector<Message> rezultat;
        for(Message m:all_messages){
            if(m.get_from() == to)
                rezultat.push_back(m);
        }
        return rezultat;
    }

    vector<Message> received_messages(string nume_to, string prenume_to){
        User to(std::move(nume_to), std::move(prenume_to), "");
        vector<Message> all_messages = this->repo_messages.get_all();
        vector<Message> rezultat;
        for(Message m:all_messages){
            if(m.get_to() == to)
                rezultat.push_back(m);
        }
        return rezultat;
    }

    void delete_message(const string& id){
        vector<Message> all_messages = this->repo_messages.get_all();
        bool ok = false;
        for(Message m: all_messages){
            if(m.get_id() == id) {
                this->repo_messages.delete_message(m);
                ok = true;
            }
        }
        if(!ok)
            throw MyException("The message you want to delete doesn't exist");
    }

    vector<Message> get_all_messages(){
        return this->repo_messages.get_all();
    }
};

#endif //PROIECT_STD_RETEA_H
