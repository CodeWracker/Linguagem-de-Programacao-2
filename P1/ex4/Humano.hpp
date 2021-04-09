#ifndef HUMANO_HPP
#define HUMANO_HPP

#include "Mamifero.hpp"
class Humano : public Mamifero
{
protected:
    string _nome;

public:
    Humano() { cout << "Construindo Human" << endl; };
    Humano(size_t cr, size_t pt, size_t nmama)
    {
        _numMamas = nmama;
        _numCromossomos = cr;
        _qtdPatas = pt;
    };
    Humano(string n) : _nome(n){};
    ~Humano() { cout << "Destruindo Humano" << endl; };

public:
    virtual string getNome() { return _nome; };
    void setNome(string n) { _nome = n; };
};

#endif