#include "./Monstro.hpp"
Monstro::Monstro()
{
    Item i(15, "Orelha de Goblin");
    _drop = i;
    _raca = "Goblin";
};
Monstro::Monstro(string drop, string raca, int val)
{
    Item i(val, drop);
    _drop = i;
    _raca = raca;
}
Monstro::~Monstro(){
    //delete (_drop);
};