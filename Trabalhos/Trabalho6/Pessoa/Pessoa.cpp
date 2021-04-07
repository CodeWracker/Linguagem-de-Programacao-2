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
        _sp += 3 * qnt;
    }
    if (atr == "dex")
        _stats.setDex(qnt);
    _pontos -= qnt;
    return true;
};
string Pessoa::resumo()
{
    stringstream s;
    s << "Nome: " << _nome << " // Nivel: " << _nivel << endl;
    s << "HP: " << _hp.str() << " // SP: " << _sp.str() << endl;
    s << "Arma Equipada: " << _armaEquipada->str() << " // Armadura Equipada: " << _armaduraEquipada->str() << endl;

    return s.str();
}
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
bool Pessoa::operator>>(size_t n)
{

    if (NDEBUG)
        cout << "equipando" << endl;
    if (n < 0 || n >= _mochila.size())
        return false;
    GenericItem *i = pop_bag(n);

    if (NDEBUG)
        cout << i->getTipo() << endl;
    if (i->getTipo() == t_Item)
    {
        push_bag(i);
        return false;
    }

    if (i->getTipo() == t_Consumivel)
    {
        Consumivel *it = (Consumivel *)i->getPointer();
        if (it->getAcao() == "HP")
        {
            if (!_hp.isMax())
            {
                _hp + it->getAtr();
                delete i;
            }
            else
                push_bag(i);
        }
    }
    if (i->getTipo() == t_Arma)
    {
        GenericItem *rem = new GenericItem(_armaEquipada);
        if (_armaEquipada->getValue() != 0)
        {
            push_bag(rem);
            //delete i;
        }
        else
        {
            delete rem;
        }
        _armaEquipada = new Arma(*(Arma *)i->getPointer());
        delete i;
        return true;
    }
    if (i->getTipo() == t_Armadura)
    {

        if (NDEBUG)
            cout << "colocarndo armor" << endl;
        GenericItem *rem = new GenericItem(_armaduraEquipada);
        if (_armaduraEquipada->getValue() != 0)
        {
            push_bag(rem);
            // delete i;
        }
        else
            delete rem;
        _armaduraEquipada = new Armadura(*(Armadura *)i->getPointer());
        delete i;
        return true;
    }
    return true;
}