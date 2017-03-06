#include "Object.h"
#include <iostream>

int Object::getValue()
{
    int i = 1;
    for(std::vector<std::pair<std::string, Value *>>::const_iterator it = objVec.begin();
        it != objVec.end(); ++it)
    {
        i += it->second->getValue();
    }
    return i;
}

void Object::print()
{
    std::cout << "\{";
    for(std::vector<std::pair<std::string, Value *>>::const_iterator it = objVec.begin();
        it != objVec.end(); ++it)
    {
        std::cout << "\"" << it->first << "\" : ";
        it->second->print();
        if(it != objVec.end() - 1) std::cout << ", ";
    }
    std::cout << "\}";
}
