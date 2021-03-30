
#include "Utils.hpp"
int main()
{
    vector<Monstro> monsterList;
    vector<string> data;
    loadData(data, "monstros.txt");
    getMonsterData(data, monsterList);
    for (Monstro m : monsterList)
    {
        cout << m.str() << endl;
    }
    return 0;
}