#include "Choices.hpp"

void load(vector<Dictionary> &myDictionaries)
{
    string path;
    if (NDEBUG)
        cout << "Enter a dictionary file: ";
    cin >> path;
    Dictionary myDict;
    if (!myDict.LoadDictionary(path))
    {
        if (NDEBUG)
            cout << "Error, File Not Found";
        return;
    }
    myDictionaries.push_back(myDict);
}
void searchSubstring(vector<Dictionary> &myDictionaries)
{
    if (NDEBUG)
        cout << "Enter a substring to search: ";
    string search;
    cin >> search;
    vector<string> substrings;
    for (Dictionary myDict : myDictionaries)
    {
        substrings = myDict.SearchSubstring(search);
        for (string line : substrings)
        {
            cout << line << endl;
        }
    }
}
void removeSubstring(vector<Dictionary> &myDictionaries)
{
    if (NDEBUG)
        cout << "Enter a substring to remove all occurrences: ";
    string search;
    cin >> search;
    for (size_t i = 0; i < myDictionaries.size(); i++)
        if (myDictionaries.at(i).RemoveSubstringLine(search))
            if (NDEBUG)
                cout << "Removed" << endl;
}
void showStats(vector<Dictionary> &myDictionaries)
{
    cout << "Statistics:" << endl;
    for (Dictionary myDict : myDictionaries)
    {
        cout << myDict.GetPath() << " -> " << myDict.GetSize() << " words" << endl;
    }
}