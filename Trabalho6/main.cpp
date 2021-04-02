#include <stdlib.h>
#include "Utils.hpp"
#include <map>
#include "choices.hpp"
int main()
{
    vector<vector<vector<string>>> monsterList;
    vector<string> data;
    loadData(data, "monstros.txt");
    getMonsterData(data, monsterList);
    loadData(data, "itensMercador.txt");
    Pessoa mercador("Mercador", 50000);
    getItemsData(data, mercador);

    typedef void (*funcP)(Pessoa & mercador, Pessoa & heroi, vector<vector<vector<string>>> & monsterList);
    map<string, funcP> myMap;
    myMap["1"] = upgradeStatus;
    myMap["2"] = openStore;
    myMap["3"] = hunt;
    myMap["4"] = showData;

    if (NDEBUG)
        cout << "Voce renasceu em um Isekai, agora voce esta em um mundo de fantasia como SAO, ou seja, nada de magias, mas ainda existem os atributos" << endl;
    if (NDEBUG)
        cout << "Digite o seu nome: " << endl;
    string choice;
    getline(cin, choice);
    Pessoa heroi(choice, 100);

    while (1)
    {
        if (!heroi.isAlive())
        {
            if (NDEBUG)
                cout << "Voce morreu" << endl;
            break;
        }
        if (NDEBUG)
            cout << heroi.getNome() << ", você possui " << heroi.getPontos() << " pontos" << endl;
        if (NDEBUG)
            cout << "1 - Usar pontos nos atributos" << endl;
        if (NDEBUG)
            cout << "2 - Ir para loja de Itens" << endl;
        if (NDEBUG)
            cout << "3 - Ir caçar" << endl;
        if (NDEBUG)
            cout << "4 - Mostrar dados do personagem" << endl;
        if (NDEBUG)
            cout << "5 - Sair" << endl;
        if (NDEBUG)
            cout << "Escolha" << endl;

        cin >> choice;
        if (atoi(choice.c_str()) > 5 || atoi(choice.c_str()) < 1)
            continue;
        if (choice == "5")
            break;
        else

            (*myMap[choice])(mercador, heroi, monsterList);
    }
    return 0;
}