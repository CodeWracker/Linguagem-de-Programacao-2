
#include "dictionary.hpp"

int main()
{
    cout << "Digite o nome do arquivo: ";
    string path;
    cin >> path;
    cout << "Abrindo " << path << endl;

    vector<string> lines = LoadDictionary(path);
    if (lines.size() == 0)
    {
        cout << "Nada pode ser encontrado";
        return 1;
    }
    for (string line : lines)
    {
        cout << line << endl;
    }
    return 0;
}