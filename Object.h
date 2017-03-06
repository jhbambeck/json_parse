#ifndef OBJECT_H
#define OBJECT_H
#include <vector>
#include <string>
#include "Value.h"


struct Object : Value
{
    std::vector<std::pair<std::string, Value *>> objVec;
    int getValue() override;
    void print() override;
    int typeVal() override
        { return 1;};
};

#endif // OBJECT_H
