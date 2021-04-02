#ifndef MONSTRO_HPP
#define MONSTRO_HPP
#include <sstream>
#include "../SerVivo/SerVivo.hpp"
#include "../Item/Item.hpp"
class Monstro : public SerVivo
{
protected:
    Item _drop;
    string _raca;
    size_t _xpDrop;

public:
    Monstro();
    Monstro(string raca, string drop, int val, int xp, int lvl);
    ~Monstro();

public:
    string str()
    {
        stringstream s;

        s << _raca << " - HP:" << _hp.str() << " | Drop: " << _drop.str() << " // XP drop: " << _xpDrop;
        return s.str();
    };
    void equipar(Arma *i)
    {
        _armaEquipada = i;
    }
    void equipar(Armadura *i)
    {
        _armaduraEquipada = i;
    }
    Item getDrop() { return _drop; }
    size_t getXp() { return _xpDrop; }
};

#endif