//
// Created by rubyn on 21.05.2022.
//

#ifndef PROIECT_STD_PAIR_H
#define PROIECT_STD_PAIR_H
#include "../../Interfaces/IE.h"
#include "../../Entity/User.h"
#include <vector>
#include <cstring>
#include "NumePrenumeKey.h"
#include <string>

class Pair : public IE{
private:
    IE* key;
    IE* value;
public:
    Pair(IE* k, IE* v){
        key = k->clone();
        value = v->clone();
    }
    Pair(const Pair &p){
        key = p.key->clone();
        value = p.value->clone();
    }
    ~Pair(){
        if (key){
            delete key;
            key = nullptr;
        }
        if (value){
            delete value;
            value = nullptr;
        }
    }
    Pair& operator=(const Pair &p){
        if (this != &p){
            setKey(p.key);
            setValue(p.value);
        }
        return *this;
    }
    IE* clone(){
        Pair* p = new Pair(key, value);
        return p;
    }
    void setKey(IE* k){
        if (key)
            delete key;
        key = k->clone();
    }
    void setValue(IE* v){
        if (value)
            delete value;
        value = v->clone();
    }
    IE* getKey(){
        return key;
    }
    IE* getValue(){
        return value;
    }
    void copy(IE* e){
        key = ((Pair*)e)->key->clone();
        value = ((Pair*)e)->value->clone();
    }
    bool equals(IE* e){
        return key->equals(((Pair*)e)->key);
    }
    int compareTo(IE* e){
        Pair* p = (Pair*)e;
        auto* keyV = (NumePrenumeKey*)p->value;
        auto* keyP = (NumePrenumeKey*)p->key;
        if (value->compareTo(keyV) && key->compareTo(keyP))
            return 0;
        return -1;
    }
    virtual bool equals_without_password(IE* e){
        return true;
    }

    string to_string_without_key() {
        return value->to_string();
    }
    string to_string(){
        string sK = key->to_string();
        string sV = value->to_string();
        return sK + sV;
    }
};

#endif //PROIECT_STD_PAIR_H
