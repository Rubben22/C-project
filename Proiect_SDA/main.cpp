//
// Created by rubyn on 22.05.2022.
//
#include "Entity/User.h"
#include "User_Interface/User_Interface.h"
#include "Retea/Retea.h"
#include <iostream>
#include "Interfaces/IContainer.h"
#include "TAD-uri/MultipleMap/MultipleMapContainer.h"
#include "TAD-uri/SimpleList/ListContainer.h"
#include "Entity/Message.h"
#include "Repository/RepositoryMessage.h"
#include "Interfaces/IIterator.h"

int main() {
    IContainer* list = new ListContainer("users.txt");
    IContainer* multiple_map = new MultipleMapContainer("friends.txt");
    RepositoryMessage repo("messages.txt");
    Retea service(list, multiple_map, repo);
    User_Interface user_interface(service);
    user_interface.run_login_menu();
    return 0;
};