
#include "dictionary.hpp"

int main()
{
    cout << "Digite o nome do arquivo: ";
    string path;
    cin >> path;
    cout << "Abrindo " << path << endl;

    vector<string> lines;
    if (!loadDictionary(path, lines))
    {
        cout << "Falha ao tentar abrir";
        return 1;
    }
    string search;
    cout << "Digite a palavra a ser buscada: ";
    cin >> search;
    cout << endl;
    for (string line : lines)
    {
        if (line.find(search) <= line.length())
            cout << line << endl;
    }
    return 0;
}