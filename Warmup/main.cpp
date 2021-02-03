#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
int main()
{
    cout << "Digite o nome do arquivo: ";
    string path;
    cin >> path;
    cout << "Abrindo " << path << endl;

    ifstream freader(path);

    if (!freader.is_open())
    {
        cout << "Falha ao abrir o arquivo." << endl;
        return 1;
    }
    string leitura;
    vector<string> lines;
    string search;
    cout << "Digite a palavra a ser buscada: ";
    cin >> search;
    cout << endl;
    while (freader >> leitura)
    {
        if (leitura.find(search) <= leitura.length())
        {
            lines.push_back(leitura);
            cout << lines[lines.size() - 1] << endl;
        }
    }

    return 0;
}