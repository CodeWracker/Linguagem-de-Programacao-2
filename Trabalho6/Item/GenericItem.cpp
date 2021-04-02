
#include "./GenericItem.hpp"
GenericItem::GenericItem(/* args */)
{
}

GenericItem::~GenericItem()
{
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