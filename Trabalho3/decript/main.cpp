#include "Encript.hpp"

#define NDEBUG 1

bool ordenaLista(const pair<size_t, size_t> &a, const pair<size_t, size_t> &b)
{

    return a.second > b.second;
}

int main()
{

    if (NDEBUG)
        cout << "Enter a alphabet" << endl;
    string pathEncoding;
    cin >> pathEncoding;

    ifstream frEncoding(pathEncoding);
    if (!frEncoding.is_open())
    {
        if (NDEBUG)
            cout << "ERRO ao abrir" << endl;
        return 1;
    }
    vector<char> alfabeto;
    string tmp;
    while (getline(frEncoding, tmp))
    {
        alfabeto.push_back(tmp[0]);
    }
    if (NDEBUG)
        cout << "Enter a text file to encode" << endl;
    string pathData;
    cin >> pathData;

    ifstream frData(pathData);
    if (!frData.is_open())
    {
        if (NDEBUG)
            cout << "ERRO ao abrir" << endl;
        return 1;
    }
    stringstream dataStr;
    char ch;
    while (frData.get(ch))
        dataStr << ch;

    vector<pair<size_t, size_t>> listaFreq(256);
    for (size_t i = 0; i < 256; i++)
    {
        listaFreq[i].first = i;
        listaFreq[i].second = 0;
    }
    for (char ch : dataStr.str())
        listaFreq.at(ch).second++;

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
        if (NDEBUG)
            cout << "ALfabeto pequeno demais" << endl;
        return 3;
    }

    for (size_t i = 0; i < listaFreq.size(); i++)
    {
        listaFreq[i].second = alfabeto[i];
    }

    for (char ch : dataStr.str())
    {
        for (pair<size_t, size_t> freq : listaFreq)
        {

            if (ch == freq.first)
            {
                cout << (char)freq.second;
                break;
            }
        }
    }

    return 0;
}