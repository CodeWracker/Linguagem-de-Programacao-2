#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

#define NDEBUG 1

using namespace std;
bool ordenaLista(const pair<size_t, size_t> &a, const pair<size_t, size_t> &b);
bool loadAlphabet(string path, vector<char> &alphaList);
bool loadMessage(string path, stringstream &dataStr);
void loadFrequency(const stringstream &dataStr, vector<pair<size_t, size_t>> &listaFreq);
void printEcription(const stringstream &, vector<pair<size_t, size_t>> listaFreq, const vector<char> &alphaList);
stringstream encriptMessage(const stringstream &dataStr, vector<pair<size_t, size_t>> listaFreq, const vector<char> &alphaList);