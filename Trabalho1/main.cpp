#include "dictionary.hpp"
#include <functional>
#define NDEBUG 0 // 1 - desenvolvimento | 0 - release

using namespace std;

int main()
{
    vector<pair<string, vector<string>>> listaLinhas; // [{ path, [linhas]}]

    if (NDEBUG)
        cout << "DICTIONARY MANIPULATOR HACK" << endl;
    if (NDEBUG)
        cout << "Select an option:" << endl;
    if (NDEBUG)
        cout << "1. Open Dictionary" << endl;
    if (NDEBUG)
        cout << "2. Search Substrings" << endl;
    if (NDEBUG)
        cout << "3. Remove Words Containing Substring" << endl;
    if (NDEBUG)
        cout << "4. Show Statistics" << endl;
    if (NDEBUG)
        cout << "5. Exit" << endl
             << endl;
    while (true)
    {
        string opt;
        if (NDEBUG)
            cout << "Option: ";
        cin >> opt;

        if (opt == "1")
        {
            string path;
            if (NDEBUG)
                cout << "Enter a dictionary file: ";
            cin >> path;
            if (!loadDictionary(path, listaLinhas))
                if (NDEBUG)
                    cout << "Error, File Not Found";

            continue;
        }
        if (opt == "2")
        {
            if (NDEBUG)
                cout << "Enter a substring to search: ";
            string search;
            cin >> search;
            vector<string> substrings;
            searchSubstring(search, listaLinhas, substrings);
            for (string line : substrings)
            {
                cout << line << endl;
            }
            continue;
        }
        if (opt == "3")
        {
            if (NDEBUG)
                cout << "Enter a substring to remove all occurrences: ";
            string search;
            cin >> search;
            removeSubstringLine(search, listaLinhas);
            continue;
        }
        if (opt == "4")
        {
            cout << "Statistics:" << endl;
            for (pair<string, vector<string>> item : listaLinhas)
            {
                cout << item.first << " -> " << item.second.size() << endl;
            }

            continue;
        }
        if (opt == "5")

            break;
    }
    return 0;
}