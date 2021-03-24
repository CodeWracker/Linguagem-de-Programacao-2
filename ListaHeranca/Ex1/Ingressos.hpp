#ifndef INGRESSOS_HPP
#define INGRESSOS_HPP

#include <iostream>
#include <string>
using namespace std;

class Ingresso
{
protected:
    size_t _valor;

public:
    Ingresso() : _valor(10){};
    string toString()
    {
        return to_string(_valor);
    };
};
class IngressoVIP : public Ingresso
{
protected:
    size_t _valorAdicional;

public:
    IngressoVIP() : _valorAdicional(10){};
    string toString()
    {
        return to_string(_valor + _valorAdicional);
    };
};

#endif