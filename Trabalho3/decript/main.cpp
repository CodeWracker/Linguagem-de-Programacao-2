#include "Encript.hpp"
#include "Decript.hpp"
#include <stdlib.h>
#include <map>

void abrirArq(stringstream &dataStr, vector<pair<size_t, size_t>> &listaFreq, vector<char> &alfabeto, vector<char> &frequenciaOrig, vector<char> &shiftedAlpha, int &shift)
{
    system("clear");
    if (NDEBUG)
        cout
            << "Enter a text file to decode" << endl;
    string pathData;
    cin >> pathData;
    if (!loadMessage(pathData, dataStr))
        cout << "Não foi possivel abrir o arquivo criptografado" << endl;

    loadFrequency(dataStr, listaFreq);
}
void takeAlphabet(stringstream &dataStr, vector<pair<size_t, size_t>> &listaFreq, vector<char> &alfabeto, vector<char> &frequenciaOrig, vector<char> &shiftedAlpha, int &shift)
{
    system("clear");
    if (NDEBUG)
        cout << "Digite o nome do arquivo com as dicas" << endl;
    string pathFreqOrig;
    cin >> pathFreqOrig;

    if (!loadFreqOrig(pathFreqOrig, frequenciaOrig))
        cout << "Falha ao abrir o arquivo com as dicas";

    getAlphabetFromMessage(dataStr, alfabeto, listaFreq);
}
void showShifts(stringstream &dataStr, vector<pair<size_t, size_t>> &listaFreq, vector<char> &alfabeto, vector<char> &frequenciaOrig, vector<char> &shiftedAlpha, int &shift)
{
    system("clear");
    // descobrir o shift na mão
    for (int shif = 0; shif < 51; shif++)
    {
        cout << endl
             << "shift = " << shif << endl
             << endl;
        shiftedAlpha.clear();
        for (size_t i = 0; i < frequenciaOrig.size(); i++)
        {
            char ch = ((size_t)frequenciaOrig[i]) - shif;
            //cout << ch << " -> " << (char)alfabeto[i] << endl;
            shiftedAlpha.push_back(ch);
        }

        printEncription(dataStr, listaFreq, shiftedAlpha);
        cout << endl;
    }
    string a;
    cout << "Digite o shift que quer utilizar: " << endl;
    cin >> a;
    shift = atoi(a.c_str());
    shiftedAlpha.clear();
    for (size_t i = 0; i < frequenciaOrig.size(); i++)
    {
        char ch = ((size_t)frequenciaOrig[i]) - shift;
        cout << i << " -> " << ch << endl;
        shiftedAlpha.push_back(ch);
    }
    system("clear");
}
void decrypt(stringstream &dataStr, vector<pair<size_t, size_t>> &listaFreq, vector<char> &alfabeto, vector<char> &frequenciaOrig, vector<char> &shiftedAlpha, int &shift)
{
    printDecription(dataStr, listaFreq, shiftedAlpha);
    /*
    char choice;
    cout << "1 - shift "
         << " // 2 - alpha por arq : ";
    cin >> choice;
    if (choice == '1')
    {

        printEncription(dataStr, listaFreq, shiftedAlpha);
    }
    else
    {
        // carrega um alfabeto de um arquivo para decodificar (ou encriptar novamente)
        if (NDEBUG)
            cout << "Enter a alphabet" << endl;
        string pathEncoding;
        cin >> pathEncoding;

        if (!loadAlphabet(pathEncoding, shiftedAlpha))
            cout << "Falha ao abrir o alfabeto";
        printEncription(dataStr, listaFreq, shiftedAlpha);
    }*/
}

void printShiftedALph(stringstream &dataStr, vector<pair<size_t, size_t>> &listaFreq, vector<char> &alfabeto, vector<char> &frequenciaOrig, vector<char> &shiftedAlpha, int &shift)
{
    system("clear");
    for (size_t i = 0; i < listaFreq.size(); i++)
    {
        cout << i << ": " << (char)listaFreq[i].first << " - " << (char)shiftedAlpha[i] << endl;
    }
}
void changeShiftedAlpha(stringstream &dataStr, vector<pair<size_t, size_t>> &listaFreq, vector<char> &alfabeto, vector<char> &frequenciaOrig, vector<char> &shiftedAlpha, int &shift)
{
    system("clear");
    while (1)
    {
        system("clear");
        printShiftedALph(dataStr, listaFreq, alfabeto, frequenciaOrig, shiftedAlpha, shift);
        decrypt(dataStr, listaFreq, alfabeto, frequenciaOrig, shiftedAlpha, shift);
        string choice;
        cout << "Digite o indice do item que deseja alterar(deixe vazio para sair)" << endl;
        getline(cin, choice);
        if (choice.size() == 0)
            break;
        int i = atoi(choice.c_str());
        cout << endl
             << "Digite o caractere a ser colocado no lugar" << endl;
        getline(cin, choice);
        shiftedAlpha[i] = choice[0];
    }
}

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
        cout << "shift = " << shift << endl;
        ;
        cout << "Menu do quebrador de criptografia, by Rodrigo & Manoella" << endl;
        cout << "1 - Abrir arquivo criptografado" << endl;
        cout << "2 - Escolher um alfabeto" << endl;
        cout << "3 - Mostrar possibilidades de shift da dica" << endl;
        cout << "4 - Printar alfabeto para traducao" << endl;
        cout << "5 - Decriptar" << endl;
        cout << "6 - Mudar o alfabeto para traducao" << endl;
        char esc;
        cin >> esc;
        cin.ignore();
        (*myMap[esc])(dataStr, listaFreq, alfabeto, frequenciaOrig, shiftedAlpha, shift);
    }

    /*
   */

    cout << endl
         << endl;
    ;
    cout << dataStr.str() << endl;

    return 0;
}