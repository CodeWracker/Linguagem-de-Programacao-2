#ifndef CONTAS_HPP
#define CONTAS_HPP
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
class ContaEspecial;
class ContaCorrente;
class ContaCorrente
{
protected:
    float _saldo;

public:
    ContaCorrente() : _saldo(0){};
    ContaCorrente(float s) : _saldo(s){};

public:
    float getSaldo() { return _saldo; };
    void depositar(float qnt) { _saldo = _saldo + qnt; };
    virtual bool sacar(float qnt);
    string toString();
    bool transferir(ContaCorrente *conta, float qnt);
    void operator+=(float qnt)
    {
        depositar(qnt);
    };

    //bool transferir(ContaEspecial conta,float qnt);
};
class ContaEspecial : public ContaCorrente
{
private:
    float _limite;

public:
    ContaEspecial(float s, float l) : _limite(l) { _saldo = s; };
    ContaEspecial(ContaCorrente *c);

public:
    bool sacar(float qnt)
    {
        if (_saldo - qnt < 0 - _limite)
            return false;
        _saldo -= qnt;
        return true;
    };
    string toString()
    {
        stringstream s;
        s.precision(2);
        s << "Saldo: " << fixed << _saldo << "; Limite: " << _limite;
        return s.str();
    };

    bool transferir(ContaCorrente *conta, float qnt);
};
#endif