//
// Created by rubyn on 19.05.2022.
//

#ifndef PROIECT_STD_IADRESS_H
#define PROIECT_STD_IADRESS_H
#include "IE.h"

class IAddress{
public:
    virtual void setInfo(IE*) = 0;
    virtual void setNext(IAddress*) = 0;
    virtual IE* getInfo() = 0;
    virtual IAddress* getNext() = 0;
    virtual ~IAddress()= default;
};

#endif //PROIECT_STD_IADRESS_H
