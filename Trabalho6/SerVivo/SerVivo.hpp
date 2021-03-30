#ifndef SERVIVO_HPP
#define SERVIVO_HPP
#include "./Point.hpp"
#include "./Stats.hpp"
#include "../Pessoa/Pessoa.hpp"
#include "../Item/Item.hpp"
using namespace std;

class SerVivo
{
protected:
    Point _hp;
    Point _sp;
    Stats _stats;
    Arma *_armaEquipada;
    Armadura *_armaduraEquipada;

public:
    SerVivo();
    ~SerVivo();

public:
    bool atacar(SerVivo *inimigo);
    bool fugir(SerVivo *inimigo); //verifica se a destreza do inimigo é maior que a sua
};

#endif