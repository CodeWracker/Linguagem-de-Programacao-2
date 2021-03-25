
#include "Contas.hpp"
string ContaCorrente::toString()
{
    stringstream s;
    s.precision(2);
    s << "Saldo: " << fixed << _saldo;
    return s.str();
}

bool ContaCorrente::transferir(ContaCorrente *conta, float qnt)
{
    if (!sacar(qnt))
        return false;
    conta->depositar(qnt);
    return true;
}
ContaEspecial::ContaEspecial(ContaCorrente *c)
{
    _limite = 100;
    _saldo = c->getSaldo();
}