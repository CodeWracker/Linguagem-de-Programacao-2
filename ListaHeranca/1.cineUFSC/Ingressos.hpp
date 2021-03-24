#ifndef INGRESSOS_HPP
#define INGRESSOS_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

class Ingresso
{
protected:
    float _valor;

public:
    Ingresso() : _valor(10){};
    Ingresso(float v) { _valor = v; };
    string toString()
    {
        stringstream s;
        s.precision(2);
        s << fixed << _valor;
        return s.str();
    };
};
class IngressoVIP : public Ingresso
{
protected:
    float _valorAdicional;

public:
    IngressoVIP() : _valorAdicional(10){};
    IngressoVIP(float v) { _valorAdicional = v; };
    string toString()
    {
        stringstream s;
        s.precision(2);
        s << fixed << (_valor + _valorAdicional);
        return s.str();
    };
};

#endif