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
    Arma *_armaEquipada;
    Armadura *_armaduraEquipada;
    bool _vivo;

public:
    SerVivo();
    ~SerVivo();

public:
    bool atacar(SerVivo *inimigo)
    {

        _sp - 1;
        if (_sp.getAtual() < 0)
        {
            kill();
        }
        return !inimigo->defender(_armaEquipada->getATK() + _stats.getFor(), _stats.getDex());
    }
    bool defender(int atk, int dex)
    {
        if (dex < _stats.getDex())
            return true;
        int dano = atk - _armaduraEquipada->getDEF();
        if (dano <= 0)
            return true;
        _hp - dano;
        if (_hp.getAtual() <= 0)
            kill();
        return false;
    }
    bool perseguir(int dex)
    {
        return dex <= _stats.getDex();
    }
    bool fugir(SerVivo *inimigo)
    {
        return !(inimigo->perseguir(_stats.getDex()));
    }
    string showStats()
    {
        return _stats.str();
    };
    void kill() { _vivo = false; }
    bool isAlive() { return _vivo; }
};

#endif