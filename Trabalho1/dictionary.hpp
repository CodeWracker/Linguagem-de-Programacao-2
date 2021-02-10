#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool loadDictionary(string path, vector<string> &lines, vector<pair<string, string>> &arquivosStats);
vector<string> serchSubstring(string search, const vector<string> lines);
bool removeSubstringLine(string path, string search, vector<string> &lines, vector<pair<string, string>> &arquivosStats);