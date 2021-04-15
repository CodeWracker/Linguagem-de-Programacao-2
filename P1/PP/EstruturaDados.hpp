#ifndef ESTRUTURAS_HPP
#define ESTRUTURAS_HPP

#include <stdlib.h>
#include <vector>
#include <new>
using namespace std;
class EstruturaDados
{
protected:
    vector<int> _lista;

public:
    EstruturaDados(){};
    EstruturaDados(vector<int> l) { _lista = l; };
    ~EstruturaDados() {}
    virtual void remover(){};

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

class Pilha : public EstruturaDados
{
public:
    Pilha(){};
    Pilha(EstruturaDados l) { _lista = l.getVector(); };
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
class Fila : public EstruturaDados
{

public:
    Fila(){};
    Fila(EstruturaDados l) { _lista = l.getVector(); };
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