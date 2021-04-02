#ifndef ITEM_HPP
#define ITEM_HPP
#define NDEBUG 1
#include <iostream>
#include <sstream>
using namespace std;
class Item
{
protected:
    int _valor;
    string _nome;

public:
    Item();
    Item(int v, string n);
    ~Item();

public:
    void operator<<(int q)
    {
        if (_valor - q > 0)
            _valor -= q;
        else
            _valor = 1;
    }
    string str()
    {
        stringstream s;
        s << _nome << ", " << _valor << "PP";
        return s.str();
    };
    size_t getValue() { return _valor; };
};

class Arma : public Item
{
private:
    int _atk;

public:
    Arma();
    Arma(int v, string n, int a);
    ~Arma();

public:
    string str()
    {
        stringstream s;
        s << _nome << ", " << _valor << "PP / ATK = " << _atk;
        return s.str();
    }
    int getATK() { return _atk; }
};
class Armadura : public Item
{
private:
    int _def;

public:
    Armadura();
    Armadura(int v, string n, int d);
    ~Armadura();

public:
    string str()
    {
        stringstream s;
        s << _nome << ", " << _valor << "PP / DEF = " << _def;
        return s.str();
    }
    int getDEF() { return _def; }
};
class Consumivel : public Item
{
private:
    int _atr;
    string _acao;

public:
    Consumivel();
    Consumivel(int v, string n, int atr, int acao);
    ~Consumivel();

public:
    string str()
    {
        stringstream s;
        s << _nome << ", " << _valor << "PP / Recupera " << _atr << " de " << _acao;
        return s.str();
    };
    string getAcao() { return _acao; };
    size_t getAtr() { return _atr; };
};

#endif