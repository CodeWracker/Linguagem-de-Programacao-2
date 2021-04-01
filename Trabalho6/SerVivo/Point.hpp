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
    void operator+(size_t q)
    {
        _atual += q;
        if (_atual > _maximo)
            _atual = _maximo;
    };
    void operator-(size_t q)
    {
        _atual -= q;
        if (_atual < 0)
            _atual = 0;
    };
    string str()
    {
        stringstream s;
        s << "[ " << _atual << "/ " << _maximo << " ]";
        return s.str();
    }
    size_t getAtual() { return _atual; };
    size_t getMax() { return _maximo; };
    bool isMax() { return _atual == _maximo; }
};

#endif