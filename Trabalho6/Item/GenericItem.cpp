
#include "./GenericItem.hpp"
GenericItem::GenericItem()
{
}

GenericItem::~GenericItem()
{
    if (_tipo == t_Item)
        delete ((Item *)_item);
    if (_tipo == t_Arma)
        delete ((Arma *)_item);
    if (_tipo == t_Armadura)
        delete ((Armadura *)_item);
    if (_tipo == t_Consumivel)
        delete ((Consumivel *)_item);
}
GenericItem::GenericItem(Item *i)
{
    _item = i;
    _tipo = t_Item;
}
GenericItem::GenericItem(Item i)
{
    _item = new Item(i);
    _tipo = t_Item;
}
GenericItem::GenericItem(Armadura *am)
{
    _item = am;
    _tipo = t_Armadura;
}
GenericItem::GenericItem(Arma *a)
{
    _item = a;
    _tipo = t_Arma;
}
GenericItem::GenericItem(Consumivel *c)
{
    _item = c;
    _tipo = t_Consumivel;
}