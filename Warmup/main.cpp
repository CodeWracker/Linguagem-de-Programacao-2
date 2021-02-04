
#include "dictionary.hpp"

int main()
{
    cout << "Digite o nome do arquivo: ";
    string path;
    cin >> path;
    cout << "Abrindo " << path << endl;

    vector<string> lines = loadDictionary(path);
    if (lines.size() == 0)
    {
        cout << "Falha ao tentar abrir";
        return 1;
    }
    for (string line : lines)
    {
        cout << line << endl;
    }
    return 0;
}