#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>
#include <sstream>
using namespace std;
class Item
{
protected:
    int _valor;
    string _nome;

public:
    Item(/* args */)
    {
        _nome = ("NONAME");
        _valor = 1;
    }
    Item(int v, string n)
    {
        _nome = n;
        _valor = v;
    }

    ~Item()
    {
    }

public:
    string str()
    {
        stringstream s;
        s << _nome << ", " << _valor << "PP";
        return s.str();
    }
};

class Arma : public Item
{
private:
    int _atk;

public:
    Arma()
    {
        _atk = 1;
        _nome = ("NONAME");
        _valor = 1;
    }
    Arma(int v, string n, int a)
    {
        _atk = a;
        _nome = n;
        _valor = v;
    }

    ~Arma()
    {
    }

public:
    string str()
    {
        stringstream s;
        s << _nome << ", " << _valor << "PP / ATK = " << _atk;
        return s.str();
    }
};
class Armadura : public Item
{
private:
    int _def;

public:
    Armadura()
    {
        _def = 1;
        _nome = ("NONAME");
        _valor = 1;
    }
    Armadura(int v, string n, int d)
    {
        _def = d;
        _nome = n;
        _valor = v;
    }

    ~Armadura()
    {
    }

public:
    string str()
    {
        stringstream s;
        s << _nome << ", " << _valor << "PP / DEF = " << _def;
        return s.str();
    }
};

#endif