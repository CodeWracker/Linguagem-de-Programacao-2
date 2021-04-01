#include "choices.hpp"

void showData(Pessoa &mercador, Pessoa &heroi)
{
    system("clear");
    while (1)
    {
        cout << heroi.str() << endl;
        cout << "Deseja equipar algum item? (S/N)" << endl;
        string choice;
        cin >> choice;
        if (choice == "n" || choice == "N")
            break;
        if (choice == "s" || choice == "S")
        {
            cout << "Que item quer Equipar ou usar?" << endl;
            cin >> choice;
            int c = atoi(choice.c_str());
            system("clear");
            heroi.equipar(c);
        }
    }
}
void upgradeStatus(Pessoa &mercador, Pessoa &heroi)
{
    system("clear");
    while (1)
    {
        cout << "Seus Atributos: " << heroi.showStats() << endl;
        if (heroi.getPontos() > 0)
        {
            cout << "Pontos Disponiveis: " << heroi.getPontos() << endl;
            string choice1;
            string choice2;
            string atr;
            cout << "Adicionar Pontos em:" << endl;
            cout << "1 - FOR" << endl;
            cout << "2 - CON" << endl;
            cout << "3 - DEX" << endl;
            cout << "4 - Voltar para o Menu" << endl;
            cin >> choice1;
            if (choice1 == "4")
                break;
            cout << "Quantos pontos deseja adicionar? " << endl;
            cin >> choice2;
            if (choice1 == "1")
                atr = "for";
            if (choice1 == "2")
                atr = "con";
            if (choice1 == "3")
                atr = "dex";

            if (!heroi.upar(atr, atoi(choice2.c_str())))
                cout << "QUANTIDADE DE PONTOS INVALIDA" << endl;
        }
        else
        {
            cout << "Você não possui pontos disponiveis, vá caçar!" << endl;
            break;
        }
    }
}
bool storeTransaction(Pessoa &comprador, Pessoa &vendedor)
{
    string choice;
    cout << vendedor.bagToStr() << endl;
    cout << "Escolha o item (PARA VOLTAR DIGITE B)" << endl;
    cin >> choice;
    system("clear");
    if (choice == "b" || choice == "B")
        return false;
    GenericItem *i = vendedor.pop_bag(atoi(choice.c_str()));
    if (i == nullptr)
        cout << "Item invalido!" << endl;
    else
    {
        if (comprador.gastar(i->getValue()))
        {
            comprador.push_bag(i);
            vendedor.depositar(i->getValue());
        }
        else
        {
            cout << "Sem Dinheiro, sem item! Devolve isso ai *****!!" << endl;
            vendedor.push_bag(i);
        }
    }
    return true;
}
void openStore(Pessoa &mercador, Pessoa &heroi)
{
    system("clear");
    while (1)
    {

        cout << "Você possui " << heroi.getDinheiro() << "PP" << endl;
        string choice;
        cout << "Quer (C)omprar ou (V)ender? (PARA SAIR DIGITE S)" << endl;
        cin >> choice;
        system("clear");
        if (choice == "s" || choice == "S")
            break;

        if (choice == "c" || choice == "C")
        {
            while (1)
            {
                if (!storeTransaction(heroi, mercador))
                    break;
            }
        }
        if (choice == "v" || choice == "V")
        {
            while (1)
            {
                if (!storeTransaction(mercador, heroi))
                    break;
            }
        }
    }
}