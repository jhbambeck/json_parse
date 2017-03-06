#ifndef BOOL_H
#define BOOL_H
#include <iostream>
#include "Value.h"

struct Bool : Value
{
    bool val;
    int getValue() override
        { return 1; };
    void print() override
        { if (val) std::cout << "true";
          else std::cout << "false"; }
};

#endif // BOOL_H
