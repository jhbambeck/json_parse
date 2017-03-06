#ifndef STRING_H
#define STRING_H
#include <string>
#include <iostream>
#include "Value.h"

struct String : Value
{
    std::string val;
    int getValue() override
        { return 1; };
    void print()
        { std::cout << "\"" << val<< "\""; };
};

#endif // STRING_H
