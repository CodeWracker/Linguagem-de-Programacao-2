
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
    cout << "A" << endl;
    if (!sacar(qnt))
    {
        cout << "C" << endl;
        return false;
    }
    conta->depositar(qnt);
    return true;
}

bool ContaEspecial::transferir(ContaCorrente *conta, float qnt)
{
    cout << "B" << endl;
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