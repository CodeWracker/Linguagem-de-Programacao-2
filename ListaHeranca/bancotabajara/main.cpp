#include "Cliente.hpp"

int main()
{
    Cliente cli1("Rodrigo", 130);
    cout << cli1.toString() << endl;
    cli1.push_back(new ContaCorrente(250));

    cout << endl;
    cout << cli1.toString() << endl
         << "-------------------------------" << endl;

    cli1.pedirContaEspecial(2);
    cout << endl;
    cout << cli1.toString() << endl
         << "-------------------------------" << endl;

    cli1.push_back(new ContaEspecial(280, 100));
    cout << endl;
    cout << cli1.toString() << endl
         << "-------------------------------" << endl;

    cli1.sacar(2, 310);
    cout << endl;
    cout << cli1.toString() << endl
         << "-------------------------------" << endl;

    Cliente cli2("Joao", 300);
    cli1.at(3)->pedirContaCorrente();
    cout << endl;
    cout << cli1.toString() << endl
         << cli2.toString() << endl
         << "-------------------------------" << endl;

    cli2.at(1)->getConta()->transferir(cli1.at(2)->getConta(), 100);
    cout << endl;
    cout << cli1.toString() << endl
         << cli2.toString() << endl
         << "-------------------------------" << endl;

    return 0;
}