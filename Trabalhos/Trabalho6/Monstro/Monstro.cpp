#include "./Monstro.hpp"
#include "../Item/Item.hpp"
Monstro::Monstro()
{
    Item i(15, "Orelha de Goblin");
    _drop = i;
    _raca = "Goblin";
    _xpDrop = 1;
}
Monstro::Monstro(string raca, string drop, int val, int xp, int lvl)
{
    Item i(val, drop);
    _drop = i;
    _raca = raca;
    _xpDrop = xp;
    _stats.setCon(_stats.getCon() * lvl);
    _stats.setFor(_stats.getFor() * lvl);
    _hp += 3 * lvl;
    _sp += 3 * lvl;
}
Monstro::~Monstro()
{
    //delete (_drop);
}