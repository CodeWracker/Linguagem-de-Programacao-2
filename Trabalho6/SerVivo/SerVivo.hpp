#ifndef SERVIVO_HPP
#define SERVIVO_HPP
#include "Point.hpp"
#include "Stats.hpp"
#include "Pessoa/Pessoa.hpp"
#include "Monstro/Monstro.hpp"

class SerVivo
{
protected:
    Point _hp;
    Point _sp;
    Stats _stats;
    //Arma _armaEquipada;
    //Armadura _armaduraEquipada;

public:
    SerVivo(/* args */);
    ~SerVivo();

public:
    bool atacar(SerVivo *inimigo);
    bool fugir(SerVivo *inimigo); //verifica se a destreza do inimigo é maior que a sua
};

#endif