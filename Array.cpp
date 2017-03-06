#include "Array.h"
#include <iostream>

Array::~Array()
{
    for(std::vector<Value *>::const_iterator it = vals.begin(); it != vals.end(); ++it)
    {
        delete *it;
    }
}

void Array::print()
{
    std::cout << "\[";
    for(std::vector<Value *>::const_iterator it = vals.begin(); it != vals.end(); ++it)
    {
        Value * valPtr = *it;
        valPtr->print();
        if(it != (vals.end() - 1)) std::cout << " , ";
    }
    std::cout << "]";
}

int Array::getValue()
{
    int val = 1;
    for(std::vector<Value *>::const_iterator it = vals.begin(); it != vals.end(); ++it)
    {
        Value * valPtr = *it;
        val += valPtr->getValue();
    }
    return val;
}
