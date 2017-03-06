#ifndef NULL_H
#define NULL_H
#include <iostream>
#include "Value.h"


struct Null : Value
{
    int getValue() override
        { return 1; };
    void print() override
        { std::cout << "null"; };
};

#endif // NULL_H
