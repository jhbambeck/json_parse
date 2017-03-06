#ifndef VALUE_H
#define VALUE_H


struct Value
{
    virtual int getValue() = 0;
    virtual ~Value() = default;
    virtual void print() {};
    virtual int typeVal()
        { return 0;};
};

#endif // VALUE_H
