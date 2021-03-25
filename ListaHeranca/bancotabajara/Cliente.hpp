#ifndef CLI_HPP
#define CLI_HPP
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "Contas.hpp"
using namespace std;
enum DataType
{
    t_CC,
    t_CE
};

class GenericConta
{
protected:
    void *_conta;
    DataType _type;

public:
    GenericConta();
    GenericConta(ContaCorrente *c);
    GenericConta(ContaEspecial *c);
    ~GenericConta()
    {
        if (_type == t_CC)
        {
            delete ((ContaCorrente *)_conta);
        }
        else
        {
            delete ((ContaEspecial *)_conta);
        }
    }

public:
    void pedirContaEspecial();
    bool pedirContaCorrente();
    string toString();
    bool sacar(float qnt);
    ContaCorrente *getConta() { return (ContaCorrente *)_conta; }
};
class Cliente
{
private:
    string _nome;
    vector<GenericConta *> _contas;

public:
    Cliente() : _nome("NONAME") { _contas.push_back(new GenericConta); };
    Cliente(string n)
    {
        _nome = n;
        _contas.push_back(new GenericConta);
    };
    Cliente(string n, float v)
    {
        _nome = n;
        _contas.push_back(new GenericConta(new ContaCorrente(v)));
    };
    ~Cliente()
    {
        for (size_t i = 0; i < _contas.size(); i++)
        {
            delete (_contas.at(i));
        }
    }

public:
    string toString()
    {
        stringstream s;
        s << "Nome: " << _nome << endl;
        for (size_t i = 0; i < _contas.size(); i++)
        {
            s << "Conta #" << i + 1 << ": " << _contas.at(i)->toString() << endl;
        }
        return s.str();
    }
    string getNome() { return _nome; }
    void setNome(string n) { _nome = n; }
    void push_back(ContaEspecial *c) { _contas.push_back(new GenericConta(c)); }
    void push_back(ContaCorrente *c) { _contas.push_back(new GenericConta(c)); }
    void pedirContaEspecial(size_t i)
    {
        if (i - 1 >= 0)
            _contas.at(i - 1)->pedirContaEspecial();
    };
    bool pedirContaCorrente(size_t i)
    {
        if (i - 1 >= 0)
            return _contas.at(i - 1)->pedirContaCorrente();
        return false;
    };
    bool sacar(size_t i, float qnt)
    {
        if (i - 1 < 0)
            return false;
        return _contas.at(i - 1)->sacar(qnt);
    }
    GenericConta *at(size_t i)
    {
        if (i - 1 < 0)
            return nullptr;
        return _contas.at(i - 1);
    }
};

#endif