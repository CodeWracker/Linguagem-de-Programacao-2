#include "./SerVivo.hpp"

SerVivo::SerVivo()
{
}

SerVivo::~SerVivo()
{
    delete _armaduraEquipada;
    delete _armaEquipada;
}