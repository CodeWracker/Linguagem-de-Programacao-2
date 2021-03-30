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
            if (c != ' ')
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
void getMonsterData(vector<string> &dataList, vector<Monstro> &monsterList)
{
    for (string l : dataList)
    {
        vector<string> splitL = splitString(l, ',');
        if (splitL.at(0) == "Tipo")
            continue;
        if (splitL.size() == 3)
        {
            Monstro m(splitL.at(0), splitL.at(1), atoi(splitL.at(2).c_str()));
            monsterList.push_back(m);
        }
    }
}