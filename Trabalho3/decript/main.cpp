#include "Encript.hpp"
#include "Decript.hpp"
#include "choices.hpp"
#include <stdlib.h>
#include <map>
int main()
{
    typedef void (*funcP)(stringstream & dataStr, vector<pair<size_t, size_t>> & listaFreq, vector<char> & alfabeto, vector<char> & frequenciaOrig, vector<char> & shiftedAlpha, int &shift);
    map<char, funcP> myMap;
    myMap['1'] = abrirArq;
    myMap['2'] = takeAlphabet;
    myMap['3'] = showShifts;
    myMap['4'] = printShiftedALph;
    myMap['5'] = decrypt;
    myMap['6'] = changeShiftedAlpha;
    stringstream dataStr;
    vector<pair<size_t, size_t>> listaFreq(256);
    vector<char> alfabeto;
    vector<char> frequenciaOrig;
    vector<char> shiftedAlpha;
    int shift = 0;
    while (1)
    {
        if (NDEBUG)
        {
            cout << "shift = " << shift << endl;
            cout << "Menu do quebrador de criptografia, by Rodrigo & Manoella" << endl;
            cout << "1 - Abrir arquivo criptografado" << endl;
            cout << "2 - Escolher um alfabeto" << endl;
            cout << "3 - Mostrar possibilidades de shift da dica" << endl;
            cout << "4 - Printar alfabeto para traducao" << endl;
            cout << "5 - Decriptar" << endl;
            cout << "6 - Mudar o alfabeto para traducao" << endl;
            cout << "7 - Sair" << endl;
        }
        char esc;
        cin >> esc;
        cin.ignore();
        if (esc == '7')
            break;
        else
            (*myMap[esc])(dataStr, listaFreq, alfabeto, frequenciaOrig, shiftedAlpha, shift);
    }

    return 0;
}