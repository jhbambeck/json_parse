#ifndef ARRAY_H
#define ARRAY_H
#include <vector>
#include "Value.h"

struct Array : Value
{
    std::vector<Value *> vals;
    ~Array();
    void print() override;
    int getValue() override;
};

#endif // ARRAY_H
