#ifndef GENERIC_HPP
#define GENERIC_HPP

#include <iostream>
#include <string>
using namespace std;
enum DataType
{
    tnone,
    tint,
    tfloat,
    tdouble,
    tchar,
    tstring
};
class GenericElement
{
private:
    void *m_data;
    DataType m_dataType;

public:
    GenericElement();
    GenericElement(int v);
    GenericElement(float v);
    GenericElement(double v);
    GenericElement(char v);
    GenericElement(string v);

public:
    string ShowInfo() { return ""; };
};

#endif