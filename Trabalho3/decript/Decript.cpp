#include "Decript.hpp"

void getAlphabetFromMessage(const stringstream &dataStr, vector<char> &alfabeto, vector<pair<size_t, size_t>> &listaFreq)
{

    for (pair<size_t, size_t> f : listaFreq)
        alfabeto.push_back(f.first);
}
bool loadFreqOrig(string path, vector<char> &alphaList)
{
    ifstream frEncoding(path);
    vector<string> list;
    if (!frEncoding.is_open())
    {
        if (NDEBUG)
            cout << "ERRO ao abrir" << endl;
        return false;
    }

    string tmp;
    while (frEncoding >> tmp)
    {
        cout << tmp << endl;
        int ch = atoi(tmp.c_str());
        char gg = (size_t) ch;
        cout << gg << endl;
    }
    
    return true;
}