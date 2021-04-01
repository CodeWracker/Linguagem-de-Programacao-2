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
void openStore(Pessoa &mercador, Pessoa &heroi)
{
    system("clear");
    while (1)
    {

        cout << mercador.bagToStr() << endl;
        cout << "Você possui " << heroi.getDinheiro() << "PP" << endl;
        string choice;
        cout << "Que item quer comprar? (PARA SAIR DIGITE S)" << endl;
        cin >> choice;
        system("clear");
        if (choice == "s" || choice == "S")
            break;
        GenericItem *i = mercador.pop_bag(atoi(choice.c_str()));
        if (i == nullptr)
            cout << "Item invalido!" << endl;
        else
        {
            if (heroi.gastar(i->getValue()))
                heroi.push_bag(i);
            else
            {
                cout << "Sem Dinheiro, sem item! Devolve isso ai!!" << endl;
                mercador.push_bag(i);
            }
        }
    }
}