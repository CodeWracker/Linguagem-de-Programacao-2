#ifndef MONSTRO_HPP
#define MONSTRO_HPP
#include <sstream>
#include "../SerVivo//SerVivo.hpp"
#include "../Item/Item.hpp"
class Monstro : public SerVivo
{
protected:
    Item _drop;
    string _raca;

public:
    Monstro();
    Monstro(string drop, string raca, int val);
    ~Monstro();

public:
    string str()
    {
        stringstream s;

        s << _raca << ": " << _drop.str() << " PP";
        return s.str();
    };
};

#endif