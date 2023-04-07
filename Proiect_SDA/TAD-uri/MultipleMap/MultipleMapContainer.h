//
// Created by rubyn on 21.05.2022.
//

#ifndef PROIECT_STD_MULTIPLEMAPCONTAINER_H
#define PROIECT_STD_MULTIPLEMAPCONTAINER_H
#include "../../Interfaces/IContainer.h"
#include "../../Interfaces/SNode.h"
#include "Pair.h"
#include "../../Entity/User.h"
#include <fstream>
#include <string>
#include <cstring>
#include "NumePrenumeKey.h"

using namespace std;

class MultipleMapContainer : public IContainer{
private:
    SNode* head;
    string filename;
public:
    MultipleMapContainer();
    MultipleMapContainer(const MultipleMapContainer &);
    explicit MultipleMapContainer(const string& filename){
        this->filename = filename;
        head = nullptr;
        ifstream f(filename);
        while (!f.eof()){
            string key_nume, key_prenume;
            string id, nume, prenume, password;
            int varsta;
            f >> key_nume >> key_prenume;
            auto *key = new NumePrenumeKey(key_nume, key_prenume);
            f >> id >> nume >> prenume >> varsta;
            User* u1 = new User(id, nume, prenume, varsta, "");
            IE* e = new Pair(key, u1);
            auto* aux = new SNode();
            aux->setInfo(e);
            SNode* crt = head;
            SNode* prev = nullptr;
            while ((crt != nullptr)){
                prev = crt;
                crt = (SNode*)crt->getNext();
            }
            if (prev == nullptr){
                aux->setNext(crt);
                head = aux;
            }
            else{
                aux->setNext(crt);
                prev->setNext(aux);
            }
        }
    }
    void save_to_file(){
        ofstream f(filename);
        SNode *crt = head;
        while (crt){
            f << crt->getInfo()->to_string() << endl;
            crt = (SNode *) crt->getNext();
        }
    }
    ~MultipleMapContainer() override;
    MultipleMapContainer& operator=(const MultipleMapContainer &);
    bool contain_id(string id) override{ return false; }
    void addElem(IE*) override;
    void removeElem(IE*) override;
    void update_element(IE*, IE*) override{}
    int getSize() override;
    bool containsKey(IE*);
    bool contains(IE*) override;//containsElem
    bool contains_without_password(IE* k) override{
        SNode* crt = head;
        while (crt != nullptr){
            Pair* p = (Pair*) crt->getInfo();
            IE* keyCrt = p->getKey();
            if (keyCrt->compareTo(k) == 0)
                return true;
            crt = (SNode*)crt->getNext();
        }
        return false;
    }
    friend class MultipleMapIterator;
    IIterator* getIterator() override;
};

class MultipleMapIterator : public IIterator{
private:
    MultipleMapContainer* container;
    SNode* crtPos;
public:
    explicit MultipleMapIterator(MultipleMapContainer* lc){
        container = lc;
        crtPos = lc->head;
    }
    ~MultipleMapIterator() override= default;
    void moveNext() override{
        crtPos = (SNode*)crtPos->getNext();
    }
    bool hasNext() override{
        return (crtPos->getNext() != nullptr);
    }
    bool isValid() override{
        return (crtPos != nullptr);
    }
    IE* getCrtElem() override{
        return crtPos->getInfo();
    }
    void moveFirst() override{
        crtPos = container->head;
    }
};


#endif //PROIECT_STD_MULTIPLEMAPCONTAINER_H
