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
        int ch = atoi(tmp.c_str());
        alphaList.push_back(static_cast<char>(ch));
    }

    return true;
}
stringstream decriptMessage(const stringstream &dataStr, vector<pair<size_t, size_t>> listaFreq, const vector<char> &alphaList)
{
    stringstream returnData;

    for (size_t i = 0; i < listaFreq.size(); i++)
    {
        listaFreq[i].second = alphaList[i];
    }
    int dif = listaFreq.size() - alphaList.size();

    cout << endl
         << "frqSize: " << listaFreq.size() << " | alphSize: " << alphaList.size() << " | dif: " << dif << endl
         << endl;
    int cont = 1;
    for (size_t i = dif + 1; i < listaFreq.size(); i++)
    {

        listaFreq[i].second = listaFreq[dif + cont].first;
        //listaFreq[i].second = 63;
        cont++;
    }

    for (pair<size_t, size_t> f : listaFreq)
    {
        cout << (char)f.second << endl;
    }
    for (char ch : dataStr.str())
    {
        for (size_t i = 0; i < listaFreq.size(); i++)
        {

            if (ch == (listaFreq[i].first))
            {
                returnData << (char)listaFreq[i].second;
                break;
            }
        }
    }
    return returnData;
}
void printDecription(const stringstream &dataStr, vector<pair<size_t, size_t>> listaFreq, const vector<char> &alphaList)
{
    stringstream encriptedMessage;
    encriptedMessage = decriptMessage(dataStr, listaFreq, alphaList);
    cout << encriptedMessage.str();
}