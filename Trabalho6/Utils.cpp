#include "Utils.hpp"

vector<string> splitString(string s, char it)
{
    string str;
    vector<string> ret;
    for (char c : s)
    {
        if (c == it)
        {
            ret.emplace_back(str);
            str.clear();
        }
        else
        {
            str = str + c;
        }
    }
    ret.emplace_back(str);
    return ret;
}
bool loadData(vector<string> &dataList, string path)
{
    dataList.clear();
    ifstream freader(path);
    if (!freader.is_open())
        return false;
    string tmp;
    while (getline(freader, tmp))
    {
        dataList.push_back(tmp);
    }
    return true;
}
Monstro *createMonster(vector<vector<string>> monsterData, size_t nivel)
{
    int i = 0;

    vector<string>
        splitL = monsterData.at(i);
    Monstro *m = new Monstro(splitL.at(0), splitL.at(1), atoi(splitL.at(2).c_str()), atoi(splitL.at(3).c_str()), nivel);
    i++;

    splitL = monsterData.at(i);
    int val = atoi(splitL.at(1).c_str());
    int atk = atoi(splitL.at(2).c_str());
    Arma *arma = new Arma(val, splitL.at(0), atk);
    m->equipar(arma);

    i++;
    splitL = monsterData.at(i);
    val = atoi(splitL.at(1).c_str());
    int def = atoi(splitL.at(2).c_str());
    Armadura *armd = new Armadura(val, splitL.at(0), def);
    m->equipar(armd);
    return m;
}
void getMonsterData(vector<string> &dataList, vector<vector<vector<string>>> &monsterList)
{
    for (size_t i = 0; i < dataList.size(); i++)
    {
        vector<vector<string>> aux;
        vector<string> splitL = splitString(dataList.at(i), ',');
        aux.push_back(splitL);
        if (splitL.at(0) == "Raça")
            continue;
        if (splitL.size() == 4)
        {
            splitString(dataList.at(i), ',');
            aux.push_back(splitL);

            splitL = splitString(dataList.at(i), ',');
            aux.push_back(splitL);

            monsterList.push_back(aux);
        }
    }
}
void getItemsData(vector<string> &dataList, Pessoa &hito)
{
    for (string l : dataList)
    {
        vector<string> splitL = splitString(l, ',');
        if (splitL.at(0) == "Tipo")
            continue;
        if (splitL.at(0) == "Item")
        {
            Item *item = new Item(atoi(splitL.at(2).c_str()), splitL.at(1));
            GenericItem *i = new GenericItem(item);
            hito.push_bag(i);
        }
        if (splitL.at(0) == "Arma")
        {
            int val = atoi(splitL.at(2).c_str());
            int atk = atoi(splitL.at(3).c_str());
            Arma *item = new Arma(val, splitL.at(1), atk);
            GenericItem *i = new GenericItem(item);
            hito.push_bag(i);
        }
        if (splitL.at(0) == "Armadura")
        {
            int val = atoi(splitL.at(2).c_str());
            int def = atoi(splitL.at(3).c_str());
            Armadura *item = new Armadura(val, splitL.at(1), def);
            GenericItem *i = new GenericItem(item);
            hito.push_bag(i);
        }
        if (splitL.at(0) == "Consumivel")
        {
            int val = atoi(splitL.at(2).c_str());
            int atr = atoi(splitL.at(3).c_str());
            int acao = atoi(splitL.at(4).c_str());
            Consumivel *item = new Consumivel(val, splitL.at(1), atr, acao);
            GenericItem *i = new GenericItem(item);
            hito.push_bag(i);
        }
    }
}