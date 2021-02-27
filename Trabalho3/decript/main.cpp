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
    /*
    // descobrir o shift na mão
    for (int shift = 0; shift < 51; shift++)
    {
        cout << endl
             << "shift = " << shift << endl
             << endl;
        vector<char> shiftedAlpha;
        for (size_t i = 0; i < frequenciaOrig.size(); i++)
        {
            char ch = ((size_t)frequenciaOrig[i]) - shift;
            //cout << ch << " -> " << (char)alfabeto[i] << endl;
            shiftedAlpha.push_back(ch);
        }

        printEcription(dataStr, listaFreq, shiftedAlpha);
        cout << endl;
    }*/
    cout << endl
         << "shift = " << 33 << endl
         << endl;
    vector<char> shiftedAlpha;
    for (size_t i = 0; i < frequenciaOrig.size(); i++)
    {
        char ch = ((size_t)frequenciaOrig[i]) - 33;
        cout << i << " -> " << ch << endl;
        shiftedAlpha.push_back(ch);
    }
    printEcription(dataStr, listaFreq, shiftedAlpha);
    cout << endl;
    /* 
    // carrega um alfabeto de um arquivo para decodificar (ou encriptar novamente)
    if (NDEBUG)
        cout << "Enter a alphabet" << endl;
    string pathEncoding;
    cin >> pathEncoding;

    if (!loadAlphabet(pathEncoding, shiftedAlpha))
        return 1;
    printEcription(dataStr, listaFreq, shiftedAlpha);
    cout << endl;
*/
    return 0;
}