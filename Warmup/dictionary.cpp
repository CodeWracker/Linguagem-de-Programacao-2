#include "dictionary.hpp"

bool loadDictionary(string path, vector<string> &lines)
{
    ifstream freader(path);
    if (!freader.is_open())
    {
        cout << "Falha ao abrir o arquivo." << endl;
        return false;
    }
    string leitura;
    string search;
    cout << "Digite a palavra a ser buscada: ";
    cin >> search;
    cout << endl;
    while (freader >> leitura)
    {
        if (leitura.find(search) <= leitura.length())
        {
            lines.push_back(leitura);
        }
    }
    return true;
}