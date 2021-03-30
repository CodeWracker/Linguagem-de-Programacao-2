#ifndef UTILS_HPP
#define UTILS_HPP
#include <vector>
#include <iostream>
#include <fstream>
#include "Monstro/Monstro.hpp"
using namespace std;
bool loadData(vector<string> &dataList, string path);
void getMonsterData(vector<string> &dataList, vector<Monstro *> &monsterList);

#endif