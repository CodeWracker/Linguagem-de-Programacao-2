#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include <sstream>
using namespace std;
class Point
{
protected:
    int _maximo;
    int _atual;

public:
    Point() : _maximo(1), _atual(1){};
    ~Point(){};

public:
    void operator+=(int q)
    {
        _maximo += q;
        _atual = _maximo;
    };
    void operator+(int q)
    {
        _atual += q;
    };
    void operator-(int q)
    {
        _atual -= q;
    };
    string str()
    {
        stringstream s;
        s << "[ Maximo: " << _maximo << ", Atual: " << _atual << " ]";
        return s.str();
    }
};

#endif