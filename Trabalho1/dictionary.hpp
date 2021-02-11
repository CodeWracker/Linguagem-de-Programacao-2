#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool loadDictionary(string path, vector<pair<string, vector<string>>> &listaLinhas);
vector<string> searchSubstring(string search, const vector<pair<string, vector<string>>> &listaLinhas);
bool removeSubstringLine(string search, vector<pair<string, vector<string>>> &listaLinhas);