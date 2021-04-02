#include "./Pessoa.hpp"

Pessoa::Pessoa()
{
    _pontos = 3;
    _nivel = 1;
    _nome = "NONAME";
    _armaEquipada = new Arma();
    _armaduraEquipada = new Armadura();
    _xp = 0;
}
Pessoa::Pessoa(string nome, size_t dinheiro)
{
    _nome = nome;
    _dinheiro = dinheiro;
    _pontos = 3;
    _nivel = 1;
    _armaEquipada = new Arma();
    _armaduraEquipada = new Armadura();
    _xp = 0;
}
Pessoa::~Pessoa()
{
    for (GenericItem *i : _mochila)
    {
        delete i;
    }
}
bool Pessoa::upar(string atr, size_t qnt)
{
    if (qnt > _pontos)
        return false;
    if (atr == "for")
        _stats.setFor(qnt);
    if (atr == "con")
    {
        _stats.setCon(qnt);
        _hp += 3 * qnt;
    }
    if (atr == "dex")
        _stats.setDex(qnt);
    _pontos -= qnt;
    return true;
};
string Pessoa::str()
{
    stringstream s;
    s << "Nome: " << _nome << " // Dinheiro: " << _dinheiro << " // Nivel: " << _nivel << " // XP: " << _xp << " //Pontos: " << _pontos << endl;
    s << "Seus Atributos: " << showStats() << endl;
    s << "HP: " << _hp.str() << " // SP: " << _sp.str() << endl;
    s << "Arma Equipada: " << _armaEquipada->str() << " // Armadura Equipada: " << _armaduraEquipada->str() << endl;
    s << "Mochila:" << endl;
    s << bagToStr();
    return s.str();
};

string Pessoa::bagToStr()
{
    stringstream s;
    for (size_t i = 0; i < _mochila.size(); i++)
    {
        s << i << " - " << _mochila.at(i)->str() << endl;
    }

    return s.str();
}