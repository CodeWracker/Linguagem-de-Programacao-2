#include "Encript.hpp"
bool ordenaLista(const pair<size_t, size_t> &a, const pair<size_t, size_t> &b)
{

    return a.second > b.second;
}

bool loadAlphabet(string path, vector<char> &alphaList)
{
    ifstream frEncoding(path);
    if (!frEncoding.is_open())
    {
        if (NDEBUG)
            cout << "ERRO ao abrir" << endl;
        return false;
    }

    string tmp;
    while (getline(frEncoding, tmp))
    {
        alphaList.push_back(tmp[0]);
    }
    return true;
}
bool loadMessage(string path, stringstream &dataStr)
{
    ifstream frData(path);
    if (!frData.is_open())
    {
        if (NDEBUG)
            cout << "ERRO ao abrir" << endl;
        return false;
    }

    char ch;
    while (frData.get(ch))
        dataStr << ch;
    return true;
}
void loadFrequency(const stringstream &dataStr, vector<pair<size_t, size_t>> &listaFreq)
{
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
}
stringstream encriptMessage(const stringstream &dataStr, vector<pair<size_t, size_t>> listaFreq, const vector<char> &alphaList)
{
    stringstream returnData;
    for (size_t i = 0; i < listaFreq.size(); i++)
    {
        listaFreq[i].second = alphaList[i];
    }

    for (char ch : dataStr.str())
    {
        for (pair<size_t, size_t> freq : listaFreq)
        {

            if (ch == freq.first)
            {
                returnData << (char)freq.second;
                break;
            }
        }
    }
    return returnData;
}
void printEncription(const stringstream &dataStr, vector<pair<size_t, size_t>> listaFreq, const vector<char> &alphaList)
{
    stringstream encriptedMessage;
    encriptedMessage = encriptMessage(dataStr, listaFreq, alphaList);
    cout << encriptedMessage.str();
}
