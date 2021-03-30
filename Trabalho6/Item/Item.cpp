#include "./Item.hpp"

Item::Item(/* args */)
{
    _nome = ("NONAME");
    _valor = 1;
}
Item::Item(int v, string n)
{
    _nome = n;
    _valor = v;
}

Item::~Item()
{
}

Arma::Arma()
{
    _atk = 1;
    _nome = ("NONAME");
    _valor = 1;
}
Arma::Arma(int v, string n, int a)
{
    _atk = a;
    _nome = n;
    _valor = v;
}

Arma::~Arma()
{
}
Armadura::Armadura()
{
    _def = 1;
    _nome = ("NONAME");
    _valor = 1;
}
Armadura::Armadura(int v, string n, int d)
{
    _def = d;
    _nome = n;
    _valor = v;
}

Armadura::~Armadura()
{
}