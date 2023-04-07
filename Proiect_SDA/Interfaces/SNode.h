//
// Created by rubyn on 19.05.2022.
//

#ifndef PROIECT_STD_SNODE_H
#define PROIECT_STD_SNODE_H
#include "IE.h"
#include "IAdress.h"

class SNode : public IAddress {
protected:
    IE *info;
    SNode *next;
public:
    SNode() {
        info = nullptr;
        next = nullptr;
    }

    SNode(IE *e, SNode *n) {
        info = e->clone();
        next = n;
    }

    SNode(const SNode &n) {
        info = n.info->clone();
        next = n.next;
    }

    ~SNode() override {
        if (info) {
            delete info;
            info = nullptr;
        }
    }

    SNode &operator=(const SNode &n) {
        if (this != &n) {
            info = n.info->clone();
            next = n.next;
        }
        return *this;
    }

    void setInfo(IE *e) override {
        info = e->clone();
    }

    void setNext(IAddress *n) override {
        next = (SNode *) n;
    }

    IE *getInfo() override {
        return info;
    }

    IAddress *getNext() override {
        return next;
    }
};

#endif //PROIECT_STD_SNODE_H
