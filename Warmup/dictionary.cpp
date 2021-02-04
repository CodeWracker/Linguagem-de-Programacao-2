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

    while (freader >> leitura)
    {
        lines.push_back(leitura);
    }
    lines.erase(lines.begin());
    return true;
}

vector<string> serchSubstring(const vector<string> lines, string search)
{
    vector<string> result;
    for (string line : lines)
    {
        if (line.find(search) <= line.length())
            result.push_back(line);
    }
    return result;
}