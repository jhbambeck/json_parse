#ifndef NUMBER_H
#define NUMBER_H
#include <iostream>
#include "Value.h"

struct Number : Value
{
    int val;
    int getValue() override
        { return 1; };
    void print() override
    { std::cout << val; };
};

#endif // NUMBER_H
