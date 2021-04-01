#include <stdlib.h>
#include "Utils.hpp"
#include <map>
#include "choices.hpp"
int main()
{
    vector<Monstro> monsterList;
    vector<string> data;
    loadData(data, "monstros.txt");
    getMonsterData(data, monsterList);
    loadData(data, "itensMercador.txt");
    Pessoa mercador("Mercador", 50000);
    getItemsData(data, mercador);

    for (Monstro m : monsterList)
        cout << m.str() << endl;
    typedef void (*funcP)(Pessoa & mercador, Pessoa & heroi);
    map<string, funcP> myMap;
    myMap["1"] = upgradeStatus;
    myMap["2"] = openStore;
    //myMap["3"] = hunt;
    myMap["4"] = showData;

    cout << "Voce renasceu em um Isekai, agora voce esta em um mundo de fantasia como SAO, ou seja, nada de magias, mas ainda existem os atributos" << endl;
    cout << "Digite o seu nome: " << endl;
    string choice;
    getline(cin, choice);
    Pessoa heroi(choice, 100);

    while (1)
    {
        cout << heroi.getNome() << ", você possui " << heroi.getPontos() << " pontos" << endl;
        cout << "1 - Usar pontos nos atributos" << endl;
        cout << "2 - Ir para loja de Itens" << endl;
        cout << "3 - Ir caçar" << endl;
        cout << "4 - Mostrar dados do personagem" << endl;
        cout << "5 - Sair" << endl;
        cout << "Escolha" << endl;

        cin >> choice;
        if (atoi(choice.c_str()) > 5)
            continue;
        if (choice == "5")
            break;
        else

            (*myMap[choice])(mercador, heroi);
    }
    return 0;
}