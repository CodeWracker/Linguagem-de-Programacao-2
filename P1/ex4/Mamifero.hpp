#ifndef MAMIFERO_HPP
#define MAMIFERO_HPP

#include "SerVivo.hpp"
class Mamifero : public SerVivo
{
protected:
    size_t _numMamas;

public:
    Mamifero() { cout << "Construindo Mamifero" << endl; };
    Mamifero(size_t cr, size_t pt, size_t nmama) : _numMamas(nmama)
    {
        _numCromossomos = cr;
        _qtdPatas = pt;
    };
    Mamifero(size_t nmama) : _numMamas(nmama){};
    ~Mamifero() { cout << "Destruindo Mamifero" << endl; };

public:
    virtual size_t getNumMamas() { return _numMamas; };
    virtual void setNumMamas(size_t m) { _numMamas = m; };
};

#endif