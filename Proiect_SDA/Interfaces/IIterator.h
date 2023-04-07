//
// Created by rubyn on 19.05.2022.
//

#ifndef PROIECT_STD_IITERATOR_H
#define PROIECT_STD_IITERATOR_H
#include "IE.h"

class IIterator{
public:
    virtual void moveNext() = 0;
    virtual bool hasNext() = 0;
    virtual bool isValid() = 0;
    virtual IE* getCrtElem() = 0;
    virtual void moveFirst() = 0;
    virtual ~IIterator()= default;
    //virtual bool operator!=(IIterator*) = 0;
};

#endif //PROIECT_STD_IITERATOR_H
