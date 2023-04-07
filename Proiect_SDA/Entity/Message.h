//
// Created by rubyn on 22.05.2022.
//

#ifndef PROIECT_STD_MESSAGE_H
#define PROIECT_STD_MESSAGE_H
#include "User.h"
#include <string>
#include <fstream>
#include <cstring>
#include <utility>
#include <vector>


class Message {
private:
    string id;
    User from;
    User to;
    string message;
public:
    Message() = default;
    Message(string id, User &from, User &to, string meesage):id(std::move(id)), from(from), to(to), message(std::move(meesage)){}
    Message &operator=(const Message &m){
        if(this != &m){
            this->id = m.id;
            this->from = m.from;
            this->to = m.to;
            this->message = m.message;
        }
        return *this;
    }
    User get_from(){
        return this->from;
    }
    User get_to(){
        return this->to;
    }
    string get_message(){
        return this->message;
    }
    string get_id(){
        return this->id;
    }

    bool operator == (const Message& mesaj){
        return this->id == mesaj.id;
    }

    friend std::ostream &operator << (std::ostream &fout, const Message &m){
        fout << m.id;
        fout << " ";
        fout << m.from;
        fout << " ";
        fout << m.to;
        fout << " ";
        fout << m.message;
        return fout;
    }
    ~Message() = default;

};


#endif //PROIECT_STD_MESSAGE_H
