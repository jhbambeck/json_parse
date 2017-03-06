#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib> strtol(s.c_str(),0,10);
#include "Value.h"
#include "Null.h"
#include "Bool.h"
#include "String.h"
#include "Number.h"
#include "Range.h"
#include "Object.h"
#include "Array.h"

using namespace std;

void skip(Range *);
Value * parse(Range *);
Value * parse_string(Range *);
Value * parse_true(Range *);
Value * parse_false(Range *);
Value * parse_null(Range *);
Value * parse_number(Range *);
bool isNumber(char);
Value * parse_object(Range *);
Value * parse_array(Range *);

int main()
{
    ifstream document;
    document.open("document.txt");
    string doc((istreambuf_iterator<char>(document)), (istreambuf_iterator<char>()));
    vector<char> vecDoc(doc.begin(), doc.end());
    vecDoc.push_back('/0');
    Range * r = new Range;
    r->f = &vecDoc[0];
    r->l = &vecDoc[vecDoc.size()];
    Value * Doc = parse(r);
    int weight = Doc->getValue();
    cout << "weight: " << weight << endl;

    return 0;
}

void skip(Range *r)
{
    while((r->f != r->l) && (isspace(*(r->f))))
    {
        ++r->f;
    }
}

Value * parse(Range *r)
{
    skip(r);
    if(*(r->f) == '\"') return parse_string(r);
    if(*(r->f) == 't') return parse_true(r);
    if(*(r->f) == 'f') return parse_false(r);
    if(*(r->f) == 'n') return parse_null(r);
    if(isNumber(*(r->f))) return parse_number(r);
    if(*(r->f) == '\{') return parse_object(r);
    if(*(r->f) == '\[') return parse_array(r);
    //else cout << "unrecognized character" << endl;
}

Value * parse_string(Range *r)
{
    if(*(r->f) != '"') cout << "Error" << endl;
    String * str = new String;
    char * cstr = new char[2];
    cstr[1] = '\0';
    ++r->f;
    while(*(r->f) != '"')
    {
        if(*(r->f) == '\\')
        {
            ++r->f;
        }
        else
        {
            cstr[0] = *(r->f);
            str->val.append(cstr);
        }
        ++r->f;
    }
    ++r->f;
    return str;
}

Value * parse_true(Range *r)
{
    if(*(r->f) != 't') cout << "Error" << endl;
    ++r->f;
    Bool *tru = new Bool;
    while(*(r->f) != 'e')
    {
        ++r->f;
    }
    ++r->f;
    tru->val = true;
    return tru;
}

Value * parse_null(Range *r)
{
    if(*(r->f) != 'n') cout << "Error" << endl;
    ++r->f;
    Null *nul = new Null;
    while(*(r->f) != 'l')
    {
        ++r->f;
    }
    ++r->f;
    ++r->f;
    return nul;
}

Value * parse_false(Range *r)
{
    if(*(r->f) != 'f') cout << "Error" << endl;
    ++r->f;
    Bool *fals = new Bool;
    while(*(r->f) != 'e')
    {
        ++r->f;
    }
    ++r->f;
    fals->val = false;
    return fals;
}

Value * parse_number(Range *r)
{
    if(!isNumber(*(r->f))) cout << "Error" << endl;
    Number * num = new Number;
    string stdStr;
    char * cstr = new char[2];
    cstr[1] = '\0';
    while(isNumber(*(r->f)))
    {
        if(isdigit(*(r->f)))
        {
            cstr[0] = *(r->f);
            stdStr.append(cstr);
        }
        ++r->f;
    }

    num->val = atoi(stdStr.c_str());
    return num;
}

bool isNumber(char c)
{
    if(isdigit(c)) return true;
    if(c == '-' || c == '+' || c == '.' || c == 'E' || c == 'e') return true;
    return false;
}

Value * parse_object(Range *r)
{
    if(*(r->f) != '\{') cout << "Error no bracket" << endl;
    Object *o = new Object;
    string nam;
    Value *valPtr;
    char * cstr = new char[2];
    ++r->f;
    while(*(r->f) != '\}')
    {
        nam = "";
        skip(r);
        if(*(r->f) != '\"') cout << "Error not a quote" << endl;
        cstr[1] = '\0';
        ++r->f;
        while(*(r->f) != '\"')
        {
            if(*(r->f) == '\\')
            {
                ++r->f;
            }
            else
            {
                cstr[0] = *(r->f);
                nam.append(cstr);
            }
            ++r->f;
        }
        ++r->f;
        skip(r);
        if(*(r->f) != '\:') cout << "Error no \':\'" << endl;
        ++r->f;
        skip(r);
        valPtr = parse(r);
        skip(r);
        if(*(r->f) == ',') ++r->f;
        skip(r);
        o->objVec.emplace_back(nam, valPtr);
    }
    ++r->f;//added
    return o;//added
}

Value * parse_array(Range *r)
{
    if(*(r->f) != '\[') cout << "Error" << endl;
    Array * arr = new Array;
    ++r->f;
    while(*(r->f) != '\]')
    {
        skip(r);
        Value * valPtr = parse(r);
        arr->vals.push_back(valPtr);
        skip(r);
        if(*(r->f) == ',') ++r->f;
    }
    ++r->f;
    return arr;
}

