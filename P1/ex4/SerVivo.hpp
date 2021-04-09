#ifndef SERVIVO_HPP
#define SERVIVO_HPP
#include <iostream>
using namespace std;

class SerVivo
{
protected:
    size_t _numCromossomos, _qtdPatas;

public:
    SerVivo() { cout << "Construindo SerVivo" << endl; };
    SerVivo(size_t cr, size_t qt) : _numCromossomos(cr), _qtdPatas(qt){};
    SerVivo(size_t qt) : _numCromossomos(0), _qtdPatas(qt){};
    ~SerVivo() { cout << "Destruindo SerVivo" << endl; }

public:
    virtual size_t getCromossomos() { return _numCromossomos; }
    virtual size_t getPatas() { return _qtdPatas; }
    virtual void setCromossomos(size_t c) { _numCromossomos = c; };
    virtual void setPatas(size_t p) { _qtdPatas = p; };
};
#endif