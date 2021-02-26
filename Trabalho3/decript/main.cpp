#include "Encript.hpp"
#include "Decript.hpp"
int main()
{

    /*
    if (NDEBUG)
        cout << "Enter a alphabet" << endl;
    string pathEncoding;
    cin >> pathEncoding;
    
    
    if (!loadAlphabet(pathEncoding, alfabeto))
        return 1;
    */

    if (NDEBUG)
        cout << "Enter a text file to decode" << endl;
    string pathData;
    cin >> pathData;
    stringstream dataStr;
    if (!loadMessage(pathData, dataStr))
        return 2;

    vector<pair<size_t, size_t>> listaFreq(256);
    loadFrequency(dataStr, listaFreq);

    vector<char> alfabeto;
    getAlphabetFromMessage(dataStr, alfabeto, listaFreq);

    if (NDEBUG)
        cout << "Enter a alphabet" << endl;
    string pathFreqOrig;
    cin >> pathFreqOrig;

    vector<char> frequenciaOrig;
    if (!loadFreqOrig(pathFreqOrig, frequenciaOrig))
        return 1;
    for (size_t i = 0; i < frequenciaOrig.size(); i++)
    {
        cout << frequenciaOrig[i] << " -> " << (char)alfabeto[i] << endl;
    }
    /*if (listaFreq.size() > alfabeto.size())
    {
        if (NDEBUG)
            cout << "ALfabeto pequeno demais" << endl;
        return 3;
    }

    printEcription(dataStr, listaFreq, alfabeto);
*/
    return 0;
}