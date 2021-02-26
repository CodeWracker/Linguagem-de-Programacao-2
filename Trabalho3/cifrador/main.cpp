#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

bool ordenaLista(const pair<size_t, size_t> &a, const pair<size_t, size_t> &b)
{

    return a.second > b.second;
}

int main()
{

    cout << "Enter a alphabet" << endl;
    string pathEncoding;
    cin >> pathEncoding;

    ifstream frEncoding(pathEncoding);
    if (!frEncoding.is_open())
    {
        cout << "ERRO ao abrir" << endl;
        return 1;
    }
    vector<char> alfabeto;
    string tmp;
    while (getline(frEncoding, tmp))
    {
        alfabeto.push_back(tmp[0]);
    }
    cout << "Enter a text file to encode" << endl;
    string pathData;
    cin >> pathData;

    ifstream frData(pathData);
    if (!frData.is_open())
    {
        cout << "ERRO ao abrir" << endl;
        return 1;
    }
    stringstream dataStr;
    char ch;
    while (frData.get(ch))
        dataStr << ch;

    vector<pair<size_t, size_t>> listaFreq(256);
    for (size_t i; i < 256; i++)
    {
        listaFreq.at(i).first = i;
        listaFreq.at(i).second = 0;
    }
    for (size_t i = 0; i < dataStr.str().size(); i++)
    {
        char ch = dataStr.str().at(i);
        listaFreq.at(ch).second++;
    }

    stable_sort(listaFreq.begin(), listaFreq.end(), ordenaLista);

    for (size_t i = 0; i < listaFreq.size(); i++)
    {
        if (listaFreq[i].second == 0)
        {
            listaFreq.erase(listaFreq.begin() + i, listaFreq.end());
        }
    }
    if (listaFreq.size() > alfabeto.size())
    {
        cout << "ALfabeto pequeno demais" << endl;
        return 3;
    }

    return 0;
}