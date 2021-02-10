#include "dictionary.hpp"

bool loadDictionary(string path, vector<string> &lines, vector<pair<string, string>> &arquivosStats)
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
    freader.close();
    arquivosStats.push_back(make_pair(path, to_string(lines.size())));
    return true;
}

vector<string> serchSubstring(string search, const vector<string> lines)
{
    vector<string> result;
    for (string line : lines)
    {
        if (line.find(search) <= line.length())
            result.push_back(line);
    }
    return result;
}
bool removeSubstringLine(string path, string search, vector<string> &lines, vector<pair<string, string>> &arquivosStats)
{

    ofstream fwriter("temp.txt");
    if (!fwriter.is_open())
    {
        cout << "Falha ao abrir o arquivo." << endl;
        return false;
    }
    fwriter.seekp(0);
    vector<string> temp;
    for (string line : lines)
    {
        if (line.find(search) > line.length())
        {
            fwriter << line << endl;
            temp.push_back(line);
        }
    }
    fwriter.close();
    remove(path.c_str());

    // rename the file
    rename("temp.txt", path.c_str());
    lines = temp;
    for (int i = 0; i < arquivosStats.size(); i++)
    {
        if (arquivosStats[i].first == path)
            arquivosStats[i].second = to_string(lines.size());
    }
    return true;
}