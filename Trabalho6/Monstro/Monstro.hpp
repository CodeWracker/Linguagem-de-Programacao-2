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
    Monstro(string raca, string drop, int val, int xp);
    ~Monstro();

public:
    string str()
    {
        stringstream s;

        s << _raca << " - Drop: " << _drop.str() << " // XP drop: " << _xpDrop;
        return s.str();
    };
};

#endif