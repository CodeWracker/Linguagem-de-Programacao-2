#include "./SerVivo.hpp"

SerVivo::SerVivo()
{
    _vivo = true;
}

SerVivo::~SerVivo()
{
    delete _armaduraEquipada;
    delete _armaEquipada;
}