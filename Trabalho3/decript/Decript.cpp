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
    while (getline(frEncoding, tmp))
    {
        list.push_back(tmp);
    }
    /*for (string line : list)
    {
        stringstream sstream(line);
        size_t gg;
        sstream >> gg;
        cout << gg << endl;
        alphaList.push_back(gg);
    }*/
    return true;
}