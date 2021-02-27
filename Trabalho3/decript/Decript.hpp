#include "Encript.hpp"

void getAlphabetFromMessage(const stringstream &dataStr, vector<char> &alfabeto, vector<pair<size_t, size_t>> &listaFreq);
bool loadFreqOrig(string path, vector<char> &alphaList);
void printDecription(const stringstream &, vector<pair<size_t, size_t>> listaFreq, const vector<char> &alphaList);
stringstream dencriptMessage(const stringstream &dataStr, vector<pair<size_t, size_t>> listaFreq, const vector<char> &alphaList);