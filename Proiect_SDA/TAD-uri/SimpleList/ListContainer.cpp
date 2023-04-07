//
// Created by rubyn on 19.05.2022.
//
#include "ListContainer.h"

ListContainer::ListContainer(){
    this->first = nullptr;
}
ListContainer::ListContainer(const string &filename) {
    first = nullptr;
    this->filename = filename;
    ifstream f(filename);
    while(!f.eof()) {
        string id, nume, prenume ,pass;
        int age;
        f >> id >> nume >> prenume >> age >> pass;
        User u_e(id, nume, prenume, age, pass);
        elem.push_back(u_e);
        auto *f1 = new User(id, nume, prenume, age, pass);

        auto *aux = new SNode();
        aux->setInfo(f1);
        aux->setNext(first);
        first = aux;
    }
    f.close();
}

ListContainer::ListContainer(const ListContainer &ac){
    if (ac.first != nullptr){
        first = new SNode();
        first->setInfo(ac.first->getInfo());
        first->setNext(nullptr);
        auto* crtAc = (SNode*)ac.first->getNext();
        SNode* crt = first;
        while (crtAc){
            auto* aux = new SNode();
            aux->setInfo(crtAc->getInfo());
            aux->setNext(nullptr);
            crt->setNext(aux);
            crt = aux;
            crtAc = (SNode*)crtAc->getNext();
        }
    }
}
ListContainer::~ListContainer(){
    SNode* crt = first;
    while(crt){
        SNode* aux = crt;
        crt = (SNode*)crt->getNext();
        delete aux;
    }
}
ListContainer& ListContainer::operator=(const ListContainer &ac){
    if (this != &ac){
        SNode* crt = first;
        while(crt){
            SNode* aux = crt;
            crt = (SNode*)crt->getNext();
            delete aux;
        }
        if (ac.first != nullptr){
            first = new SNode();
            first->setInfo(ac.first->getInfo());
            first->setNext(nullptr);
            auto* crtAc = (SNode*)ac.first->getNext();
            SNode* crt = first;
            while (crtAc){
                auto* aux = new SNode();
                aux->setInfo(crtAc->getInfo());
                aux->setNext(nullptr);
                crt->setNext(aux);
                crt = aux;
                crtAc = (SNode*)crtAc->getNext();
            }
        }
    }
    return *this;
}

void ListContainer::addElem(IE* e){
    //if(!contain_id(e.g))
    auto* aux = new SNode();
    aux->setInfo(e);
    aux->setNext(first);
    first = aux;
    save_to_file();
}

void ListContainer::removeElem(IE* e){
    SNode* crt = first;
    if (e->equals(crt->getInfo())){
        first = (SNode*)first->getNext();
        delete crt;
    }
    else{
        while (crt){
            auto* nodeToBeDeleted = (SNode*)crt->getNext();
            if (nodeToBeDeleted != nullptr){
                if (e->equals(nodeToBeDeleted->getInfo())){
                    crt->setNext(nodeToBeDeleted->getNext());
                    delete nodeToBeDeleted;
                }
            }
            crt = (SNode*)crt->getNext();
        }
    }
    save_to_file();
}
/*bool ListContainer::contains_id(IE* e) {
    SNode* crt = first;
    auto* node_id = new SNode();
    if (e->equals_id(crt->getInfo())){
        first = (SNode*)first->getNext();
        node_id->setInfo(crt->getInfo());
        return true;
    }
    else{
        while (crt){
            auto* nodeToBeDeleted = (SNode*)crt->getNext();
            if (nodeToBeDeleted != nullptr){
                if (e->equals_id(nodeToBeDeleted->getInfo())){
                    node_id->setInfo(nodeToBeDeleted->getInfo());
                    return true;
                }
            }
            crt = (SNode*)crt->getNext();
        }
    }
    return false;
}*/
void ListContainer::update_element(IE *old, IE *new_element) {
    SNode* crt = first;
    auto* aux = new SNode();
    if (old->equals(crt->getInfo())){
        crt->setInfo(new_element);
    }
    else{
        while (crt){
            auto* node_to_be_modify = (SNode*)crt->getNext();
            if (node_to_be_modify != nullptr){
                if (old->equals(node_to_be_modify->getInfo())){
                    //crt->setNext(node_to_be_modify->getNext());
                    node_to_be_modify->setInfo(new_element);
                }
            }
            crt = (SNode*)crt->getNext();
        }
    }
    save_to_file();
}

int ListContainer::getSize(){
    int size = 0;
    SNode* crt = first;
    while (crt){
        size++;
        crt = (SNode*)crt->getNext();
    }
    return size;
}

bool ListContainer::contains(IE* e){
    SNode* crt = first;
    while (crt){
        if (e->equals(crt->getInfo()))
            return true;
        crt = (SNode*)crt->getNext();
    }
    return false;
}

IIterator* ListContainer::getIterator(){
    return new ListIterator(this);
}

void ListContainer::save_to_file() {
    ofstream f(filename);
    SNode* crt = first;
    while (crt){
        f << crt->getInfo()->to_string() << endl;
        crt = (SNode *) crt->getNext();
    }
    f.close();
}
