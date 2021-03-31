#ifndef SERVIVO_HPP
#define SERVIVO_HPP
#include "./Point.hpp"
#include "./Stats.hpp"
#include "../Item/Item.hpp"
#include <iostream>
using namespace std;

class SerVivo
{
protected:
    Point _hp;
    Point _sp;
    Stats _stats;
    Arma _armaEquipada;
    Armadura _armaduraEquipada;

public:
    SerVivo();
    ~SerVivo();

public:
    bool atacar(SerVivo *inimigo);
    bool fugir(SerVivo *inimigo); //verifica se a destreza do inimigo é maior que a sua
    string showStats()
    {
        return _stats.str();
    };
};

#endif