//
// Created by rubyn on 19.05.2022.
//

#ifndef PROIECT_STD_LISTCONTAINER_H
#define PROIECT_STD_LISTCONTAINER_H
#include "../../Interfaces/IContainer.h"
#include "../../Interfaces/SNode.h"
#include "../../Entity/MyException.h"
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#include "../../Entity/User.h"
using namespace std;

class ListContainer : public IContainer{
private:
    SNode* first;
    vector<User> elem;
    string filename;
public:
    bool contain_id(string id) override{
        for(User u: elem){
            if(u.get_id() == id)
                throw MyException("DuplicateIDError: ");
        }
        return false;
    }
    ListContainer();
    ListContainer(const ListContainer &);
    explicit ListContainer(const string& filename);
    ListContainer& operator=(const ListContainer &);
    ~ListContainer() override;
    void addElem(IE*) override;
    void removeElem(IE*) override;
    void update_element(IE*, IE*) override;
    int getSize() override;
    bool contains(IE*) override;
    bool contains_without_password(IE* e) override{
        SNode* crt = first;
        while (crt){
            if (e->equals_without_password(crt->getInfo()))
                return true;
            crt = (SNode*)crt->getNext();
        }
        return false;
    }
    void save_to_file();
    friend class ListIterator;
    IIterator* getIterator() override;
};

class ListIterator : public IIterator{
private:
    ListContainer* container;
    SNode* crtPos;
public:
    explicit ListIterator(ListContainer* lc){
        container = lc;
        crtPos = lc->first;
    }
    ~ListIterator() override = default;
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
        crtPos = container->first;
    }
};

#endif //PROIECT_STD_LISTCONTAINER_H
