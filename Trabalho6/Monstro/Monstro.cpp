#include "./Monstro.hpp"
#include "../Item/Item.hpp"
Monstro::Monstro()
{
    Item i(15, "Orelha de Goblin");
    _drop = i;
    _raca = "Goblin";
}
Monstro::Monstro(string raca, string drop, int val, int xp)
{
    Item i(val, drop);
    _drop = i;
    _raca = raca;
    _xpDrop = xp;
}
Monstro::~Monstro()
{
    //delete (_drop);
}