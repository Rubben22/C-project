//
// Created by rubyn on 19.05.2022.
//

#ifndef PROIECT_STD_ICONTAINER_H
#define PROIECT_STD_ICONTAINER_H
#include "IE.h"
#include "IIterator.h"

class IContainer{
public:
    virtual void addElem(IE*) = 0;
    virtual void removeElem(IE*) = 0;
    virtual void update_element(IE*, IE*) = 0;
    virtual int getSize() = 0;
    virtual bool contains(IE*) = 0;
    virtual bool contains_without_password(IE*) = 0;
    virtual bool contain_id(std::string id) = 0;
    //virtual bool contains_id(IE*) = 0;
    friend class IIterator;
    virtual IIterator* getIterator() = 0;
    virtual ~IContainer()= default;
};

#endif //PROIECT_STD_ICONTAINER_H
