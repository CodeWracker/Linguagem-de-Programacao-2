#ifndef CACHORRO_HPP
#define CACHORRO_HPP

#include "Mamifero.hpp"
class Cachorro : public Mamifero
{
    string _raca;

public:
    Cachorro() { cout << "Construindo Dog" << endl; };
    Cachorro(size_t cr, size_t pt, size_t nmama)
    {
        _numMamas = nmama;
        _numCromossomos = cr;
        _qtdPatas = pt;
    };
    Cachorro(string r) : _raca(r){};
    ~Cachorro() { cout << "Destruindo og" << endl; };

public:
    virtual string getRaca() { return _raca; };
    virtual void setRaca(string r) { _raca = r; };
};
#endif