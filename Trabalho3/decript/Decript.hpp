#include "Encript.hpp"

void getAlphabetFromMessage(const stringstream &dataStr, vector<char> &alfabeto, vector<pair<size_t, size_t>> &listaFreq);
bool loadFreqOrig(string path, vector<char> &alphaList);