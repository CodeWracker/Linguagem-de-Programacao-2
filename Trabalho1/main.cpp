#include "dictionary.hpp"
using namespace std;

int main()
{
    vector<pair<string, vector<string>>> listaLinhas; // [{ path, [linhas]}]

    cout << "DICTIONARY MANIPULATOR HACK" << endl;
    cout << "Select an option:" << endl;
    cout << "1. Open Dictionary" << endl;
    cout << "2. Search Substrings" << endl;
    cout << "3. Remove Words Containing Substring" << endl;
    cout << "4. Show Statistics" << endl;
    cout << "5. Exit" << endl
         << endl;
    while (true)
    {

        string opt;
        cout << "Option: ";
        cin >> opt;
        if (opt == "1")
        {
            string path;
            cout << "Enter a dictionary file: ";
            cin >> path;
            if (!loadDictionary(path, listaLinhas))
            {
                cout << "Falha ao tentar abrir";
                return 1;
            }
            continue;
        }
        if (opt == "2")
        {
            cout << "Enter a substring to search: ";
            string search;
            cin >> search;
            vector<string> substrings = searchSubstring(search, listaLinhas);
            for (string line : substrings)
            {
                cout << line << endl;
            }
            continue;
        }
        if (opt == "3")
        {
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
        {

            break;
        }
    }
    return 0;
}