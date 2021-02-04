#include "dictionary.hpp"

vector<string> loadDictionary(string path)
{
    ifstream freader(path);
    vector<string> lines;
    if (!freader.is_open())
    {
        cout << "Falha ao abrir o arquivo." << endl;
        return lines;
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
    return lines;
}