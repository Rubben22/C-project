//
// Created by rubyn on 21.05.2022.
//

#ifndef PROIECT_STD_NUMEPRENUMEKEY_H
#define PROIECT_STD_NUMEPRENUMEKEY_H
#include <utility>

#include "../../Interfaces/IE.h"


class NumePrenumeKey: public IE{
private:
    string key_nume;
    string key_prenume;
public:
    NumePrenumeKey() {
        key_nume = "";
        key_prenume = "";
    }
    NumePrenumeKey(string key_nume1, string key_prenume1){
        key_nume = std::move(key_nume1);
        key_prenume = std::move(key_prenume1);
    }
    NumePrenumeKey(const NumePrenumeKey &k){
        key_nume = k.key_nume;
        key_prenume = k.key_prenume;
    }
    ~NumePrenumeKey() override= default;
    NumePrenumeKey& operator=(const NumePrenumeKey &k){
        if (this != &k){
            key_nume = k.key_nume;
            key_prenume = k.key_prenume;
        }
        return *this;
    }
    void setKeyValue(string k_nume, string k_prenume){
        key_nume = std::move(k_nume);
        key_prenume = std::move(k_prenume);
    }
    string getKeyValue(){
        return key_nume;
    }
    IE* clone() override{
        auto* k = new NumePrenumeKey(key_nume, key_prenume);
        return k;
    }
    void copy(IE* e) override{
        auto* k = (NumePrenumeKey*)e;
        key_nume = k->key_nume;
        key_prenume = k->key_prenume;
    }
    bool equals(IE* e) override{
        return (key_nume == ((NumePrenumeKey*)e)->key_nume && key_prenume == ((NumePrenumeKey*)e)->key_prenume);
    }
    int compareTo(IE* e) override{
        if (key_nume < ((NumePrenumeKey*)e)->key_nume && key_prenume < ((NumePrenumeKey*)e)->key_prenume)
            return -1;
        if (key_nume > ((NumePrenumeKey*)e)->key_nume && key_prenume > ((NumePrenumeKey*)e)->key_prenume)
            return 1;
        if(key_nume + key_prenume == ((NumePrenumeKey*)e)->key_nume && key_prenume == ((NumePrenumeKey*)e)->key_prenume)
            return 0;
    }
    string to_string_without_key() override {
        return "";
    }
    bool equals_without_password(IE* e) override{
        return true;
    }
    string to_string() override{
        return key_nume + " " + key_prenume + " ";
    }
};


#endif //PROIECT_STD_NUMEPRENUMEKEY_H
