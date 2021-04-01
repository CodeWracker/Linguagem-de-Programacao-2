#ifndef UTILS_HPP
#define UTILS_HPP
#include <vector>
#include <iostream>
#include <fstream>
#include "Monstro/Monstro.hpp"
#include "Pessoa/Pessoa.hpp"
using namespace std;
vector<string> splitString(string s, char it);
bool loadData(vector<string> &dataList, string path);
void getMonsterData(vector<string> &dataList, vector<Monstro> &monsterList);
void getItemsData(vector<string> &dataList, Pessoa &hito);

#endif