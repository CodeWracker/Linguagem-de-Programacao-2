#ifndef GENITEM_HPP
#define GENITEM_HPP
#include "./Item.hpp"

enum ItemType
{
    t_Item,
    t_Arma,
    t_Armadura,
    t_Consumivel
};
class GenericItem
{
private:
    ItemType _tipo;
    void *_item;

public:
    GenericItem();
    GenericItem(Item *i);

    GenericItem(Item i);
    GenericItem(Armadura *am);
    GenericItem(Arma *a);
    GenericItem(Consumivel *c);
    ~GenericItem();

public:
    string str()
    {
        stringstream s;
        if (_tipo == t_Item)
            s << ((Item *)_item)->str();
        if (_tipo == t_Arma)
            s << ((Arma *)_item)->str();
        if (_tipo == t_Armadura)
            s << ((Armadura *)_item)->str();
        if (_tipo == t_Consumivel)
            s << ((Consumivel *)_item)->str();
        return s.str();
    };
    size_t getValue()
    {
        return ((Item *)_item)->getValue();
    };
    ItemType getTipo() { return _tipo; };
    void *getPointer() { return _item; };
    void operator<<(int q)
    {
        *((Item *)_item) << q;
    }
};

#endif