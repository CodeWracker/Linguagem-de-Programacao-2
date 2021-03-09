#include "Dictionary.hpp"
#include <fstream>
void Dictionary::Initialize()
{
    this->listaLinhas.clear();
}
bool Dictionary::LoadDictionary(string path)
{
    this->Initialize();
    ifstream freader(path);
    if (!freader.is_open())
    {
        //cout << "Falha ao abrir o arquivo." << endl;
        return false;
    }
    string leitura;

    while (freader >> leitura)
    {
        this->listaLinhas.push_back(leitura);
    }
    this->listaLinhas.erase(this->listaLinhas.begin());
    freader.close();
    this->path = path;
    return true;
}
string Dictionary::GetWord(size_t i)
{
    string s;
    if (i < this->GetSize())
        s = this->listaLinhas.at(i);
    return s;
}
size_t Dictionary::GetWordIndex(string pal)
{
    for (size_t i = 0; i < this->listaLinhas.size(); i++)
    {
        if (listaLinhas.at(i) == pal)
            return i;
    }
    return -1;
}

string Dictionary::RemoveItem(size_t i)
{
    string s;
    s = this->GetWord(i);
    if (s != "")
        this->listaLinhas.erase(this->listaLinhas.begin() + i);
    return s;
}
string Dictionary::RemoveItem(string pal)
{
    size_t i;
    string s;
    i = this->GetWordIndex(pal);
    if (i != -1)
    {
        this->listaLinhas.erase(this->listaLinhas.begin() + i);
        s = pal;
    }

    return s;
}
vector<string> Dictionary::SearchSubstring(string search)
{
    vector<string> substrings;
    for (string item : this->listaLinhas)
    {

        if (item.find(search) <= item.length())
            substrings.push_back(item);
    }
    return substrings;
}
bool Dictionary::RemoveSubstringLine(string search)
{
    int i = 0;
    int aux = this->listaLinhas.size();
    vector<string> temp;
    for (string item : this->listaLinhas)
    {

        if (item.find(search) > item.length())
            temp.push_back(item);
        i++;
    }
    this->listaLinhas = temp;

    return aux != this->listaLinhas.size();
}