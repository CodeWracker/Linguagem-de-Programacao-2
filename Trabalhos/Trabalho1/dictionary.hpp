#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool loadDictionary(string path, vector<pair<string, vector<string>>> &listaLinhas);
bool searchSubstring(string search, const vector<pair<string, vector<string>>> &listaLinhas, vector<string> &substrings);
bool removeSubstringLine(string search, vector<pair<string, vector<string>>> &listaLinhas);