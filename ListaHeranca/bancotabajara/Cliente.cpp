#include "Cliente.hpp"
#include "Contas.hpp"

GenericConta::GenericConta()
{
    _type = t_CC;
    _conta = new ContaCorrente;
}

GenericConta::GenericConta(ContaCorrente *c)
{
    _type = t_CC;
    _conta = c;
}
GenericConta::GenericConta(ContaEspecial *c)
{
    _type = t_CE;
    _conta = c;
}
void GenericConta::pedirContaEspecial()
{
    _type = t_CE;
    ContaEspecial *aux = new ContaEspecial(((ContaCorrente *)_conta));
    delete ((ContaCorrente *)_conta);
    _conta = aux;
}
bool GenericConta::pedirContaCorrente()
{
    if (_type == t_CE && ((ContaEspecial *)_conta)->getSaldo() >= 0)
    {
        _type = t_CC;
        ContaCorrente *aux = new ContaCorrente(*((ContaEspecial *)_conta));
        delete ((ContaEspecial *)_conta);
        _conta = aux;
    }
    return false;
}
bool GenericConta::sacar(float qnt)
{
    if (_type == t_CC)
        return ((ContaCorrente *)_conta)->sacar(qnt);
    return ((ContaEspecial *)_conta)->sacar(qnt);
}
string GenericConta::toString()
{
    stringstream s;
    if (_type == t_CC)
    {
        s << "(Conta Corrente) - " << ((ContaCorrente *)_conta)->toString();
    }
    else
    {
        s << "(Conta Especial) - " << ((ContaEspecial *)_conta)->toString();
    }
    return s.str();
}
bool ContaCorrente::sacar(float qnt)
{
    if (_saldo < qnt)
        return false;
    _saldo -= qnt;
    return true;
}
