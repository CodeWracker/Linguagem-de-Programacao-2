#include "Encript.hpp"

int main()
{

    if (NDEBUG)
        cout << "Enter a alphabet" << endl;
    string pathEncoding;
    cin >> pathEncoding;
    vector<char> alfabeto;

    if (!loadAlphabet(pathEncoding, alfabeto))
        return 1;

    if (NDEBUG)
        cout << "Enter a text file to encode" << endl;
    string pathData;
    cin >> pathData;
    stringstream dataStr;
    if (!loadMessage(pathData, dataStr))
        return 2;

    vector<pair<size_t, size_t>> listaFreq(256);
    loadFrequency(dataStr, listaFreq);

    if (listaFreq.size() > alfabeto.size())
    {
        if (NDEBUG)
            cout << "ALfabeto pequeno demais" << endl;
        return 3;
    }

    printEcription(dataStr, listaFreq, alfabeto);

    return 0;
}