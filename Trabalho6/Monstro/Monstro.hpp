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

public:
    Monstro()
    {
        Item i(15, "Orelha de Goblin");
        _drop = i;
        _raca = "Goblin";
    };
    Monstro(string drop, string raca, int val)
    {
        Item i(val, drop);
        _drop = i;
        _raca = raca;
    }
    ~Monstro(){
        //delete (_drop);
    };

public:
    string str()
    {
        stringstream s;

        s << _raca << ": " << _drop.str() << " PP";
        return s.str();
    };
};

#endif