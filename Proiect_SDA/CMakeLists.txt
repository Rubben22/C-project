cmake_minimum_required(VERSION 3.20)
project(Proiect_STD)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proiect_STD Interfaces/IE.h Interfaces/IAdress.h Interfaces/IContainer.h Interfaces/SNode.h Entity/User.h TAD-uri/SimpleList/ListContainer.h Interfaces/IIterator.h Retea/Retea.h User_Interface/User_Interface.h User_Interface/User_Interface.cpp TAD-uri/SimpleList/ListContainer.cpp TAD-uri/MultipleMap/NumePrenumeKey.h TAD-uri/MultipleMap/Pair.h TAD-uri/MultipleMap/MultipleMapContainer.cpp TAD-uri/MultipleMap/MultipleMapContainer.h Entity/Message.h Repository/RepositoryMessage.h main.cpp Entity/MyException.h)
