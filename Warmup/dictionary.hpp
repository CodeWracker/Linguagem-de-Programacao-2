#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool loadDictionary(string path, vector<string> &lines);
vector<string> serchSubstring(string search, const vector<string> lines);