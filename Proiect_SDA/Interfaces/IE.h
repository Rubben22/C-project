//
// Created by rubyn on 19.05.2022.
//

#ifndef PROIECT_STD_IE_H
#define PROIECT_STD_IE_H
#include <cstdlib>
#include <string>

class IE{
public:
    virtual IE* clone() = 0;
    virtual void copy(IE*) = 0;
    virtual bool equals(IE*) = 0;
    //virtual bool equals_id(IE*) = 0;
    virtual bool equals_without_password(IE*) = 0;
    virtual int compareTo(IE*) = 0;
    virtual std::string to_string() = 0;
    virtual std::string to_string_without_key() = 0;
    virtual ~IE()= default;
};

#endif //PROIECT_STD_IE_H
