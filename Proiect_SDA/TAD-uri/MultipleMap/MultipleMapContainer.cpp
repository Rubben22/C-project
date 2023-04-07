//
// Created by rubyn on 21.05.2022.
//

#include "MultipleMapContainer.h"
MultipleMapContainer::MultipleMapContainer(){
    head = nullptr;
}

MultipleMapContainer::MultipleMapContainer(const MultipleMapContainer &mc){
    if (mc.head != nullptr){
        head = new SNode();
        head->setInfo(mc.head->getInfo());
        head->setNext(nullptr);
        auto* crtMc = (SNode*)mc.head->getNext();
        SNode* crt = head;
        while (crtMc){
            auto* aux = new SNode();
            aux->setInfo(crtMc->getInfo());
            aux->setNext(nullptr);
            crt->setNext(aux);
            crt = aux;
            crtMc = (SNode*)crtMc->getNext();
        }
    }
}

MultipleMapContainer::~MultipleMapContainer(){
    SNode* crt = head;
    while(crt){
        SNode* aux = crt;
        crt = (SNode*)crt->getNext();
        delete aux;
    }
}
MultipleMapContainer& MultipleMapContainer::operator=(const MultipleMapContainer &mc){
    if (this != &mc){
        SNode* crt = head;
        while(crt){
            SNode* aux = crt;
            crt = (SNode*)crt->getNext();
            delete aux;
        }
        if (mc.head != nullptr){
            head = new SNode();
            head->setInfo(mc.head->getInfo());
            head->setNext(nullptr);
            auto* crtMc = (SNode*)mc.head->getNext();
            SNode* crt2 = head;
            while (crtMc){
                auto* aux = new SNode();
                aux->setInfo(crtMc->getInfo());
                aux->setNext(nullptr);
                crt2->setNext(aux);
                crt2 = aux;
                crtMc = (SNode*)crtMc->getNext();
            }
        }
    }
    return *this;
}

void MultipleMapContainer::addElem(IE* e){
//	if (!containsKey(((Pair*)e)->getKey())){
    auto* aux = new SNode();
    aux->setInfo(e);
    SNode* crt = head;
    SNode* prev = nullptr;
    while ((crt != nullptr)) {
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
    save_to_file();
//	}
}
void MultipleMapContainer::removeElem(IE* k){
    if ((head != nullptr) && (((Pair*)head->getInfo())->getKey()->to_string() +
    ((Pair*)head->getInfo())->getValue()->to_string() == k->to_string())) {
        SNode *crt = head;
        head = (SNode *) head->getNext();
        delete crt;
    }
    else{
        SNode* crt = head;
        SNode* prev = head;
        while (crt != nullptr && ((Pair*)crt->getInfo())->getKey()->to_string() +
        ((Pair*)crt->getInfo())->getValue()->to_string() != k->to_string()){
            prev = crt;
            crt = (SNode*)crt->getNext();
        }
        while ((crt != nullptr) && (((Pair*)crt->getInfo())->getKey()->to_string() +
        ((Pair*)crt->getInfo())->getValue()->to_string() == k->to_string())){
            prev->setNext(crt->getNext());
            delete crt;
            crt = (SNode*)prev->getNext();
        }
    }
    save_to_file();
}
int MultipleMapContainer::getSize(){
    SNode* crt = head;
    int n = 0;
    while (crt != nullptr){
        crt = (SNode*)crt->getNext();
        n++;
    }
    return n;
}
bool MultipleMapContainer::containsKey(IE* k){
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
bool MultipleMapContainer::contains(IE* e){
    SNode* crt = head;
    while (crt != nullptr){
        if (crt->getInfo()->compareTo(e) == 0)
            return true;
        crt = (SNode*)crt->getNext();
    }
    return false;
}
IIterator* MultipleMapContainer::getIterator(){
    return new MultipleMapIterator(this);
}
