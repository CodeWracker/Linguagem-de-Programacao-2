#ifndef ESTRUTURAS_HPP
#define ESTRUTURAS_HPP

#include <stdlib.h>
#include <vector>
#include <new>
using namespace std;
class EstruturaDeDados
{
protected:
    vector<int> _lista;

public:
    EstruturaDeDados(){};
    EstruturaDeDados(vector<int> l) { _lista = l; };
    ~EstruturaDeDados() {}
    void remover(){};
    void adicionar(){};

public:
    vector<int> getVector()
    {
        return _lista;
    }
    virtual void adicionar(int a)
    {
        _lista.push_back(a);
    }
};

class Pilha : public EstruturaDeDados
{
public:
    Pilha(){};
    Pilha(vector<int> l) { _lista = l; };
    ~Pilha(){};

public:
    void remover()
    {
        if (_lista.size() > 0)
        {
            _lista.erase(_lista.begin() + (_lista.size() - 1));
        }
    }
};
class Fila : public EstruturaDeDados
{

public:
    Fila(){};
    Fila(vector<int> l) { _lista = l; };
    ~Fila(){};

public:
    void remover()
    {
        if (_lista.size() > 0)
        {
            _lista.erase(_lista.begin() + 0);
        }
    }
};

#endif