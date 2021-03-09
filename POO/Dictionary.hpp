#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP
#define NDEBUG 1
#include <iostream>
#include <vector>

using namespace std;

class Dictionary
{
private:
    vector<string> listaLinhas;
    string path;

public:
    bool LoadDictionary(string path);
    size_t GetSize() const { return listaLinhas.size(); }
    void AddWord(string word) { listaLinhas.push_back(word); }
    string GetWord(size_t i);
    size_t GetWordIndex(string papl);
    string RemoveItem(size_t i);
    string RemoveItem(string pal);
    vector<string> SearchSubstring(string search);
    bool RemoveSubstringLine(string search);
    string GetPath() { return path; }

private:
    void Initialize();
};

#endif