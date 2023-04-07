//
// Created by rubyn on 22.05.2022.
//

#ifndef PROIECT_STD_REPOSITORYMESSAGE_H
#define PROIECT_STD_REPOSITORYMESSAGE_H
#include "../Entity/Message.h"
#include <fstream>
#include "../Entity/User.h"
#include <algorithm>
#include <istream>

class RepositoryMessage {
private:
    vector<Message> mesaje;
    string filename;
public:
    bool contain_id(const string& id){
        for(Message u: mesaje){
            if(u.get_id() == id)
                throw MyException("DuplicateIDError: Messages can't have the same ID");
        }
        return false;
    }
    RepositoryMessage() = default;
    explicit RepositoryMessage(const string& filename){
        this->filename = filename;
        ifstream f(filename);
        while(!f.eof()){
            string nume, prenume, nume_destinatar, prenume_destinatar, id, s, message;
            message = "";
            f >> id;
            f >> nume >> prenume;
            User u(nume, prenume, "");
            f >> nume_destinatar >> prenume_destinatar;
            User u2(nume_destinatar, prenume_destinatar, "");
            while (message.find('.') == std::string::npos && f >> s) {
                message += s;
                message += " ";
            }
            Message m(id,u,u2 , message);
            mesaje.push_back(m);
        }
    }
    void send_message(Message &message){
        mesaje.push_back(message);
        save_to_file();
    }
    int delete_message(Message &mesaj){
        auto it = find(mesaje.begin(), mesaje.end(), mesaj);
        if (it != mesaje.end()){
            mesaje.erase(it);
            save_to_file();
            return 0;
        }
        return -1;
    }
    void save_to_file(){
        ofstream f(this->filename);
        for(const Message& m: mesaje)
            f << m << endl;
    }
    vector<Message> get_all(){
        return this->mesaje;
    }
    ~RepositoryMessage() = default;
};

#endif //PROIECT_STD_REPOSITORYMESSAGE_H
