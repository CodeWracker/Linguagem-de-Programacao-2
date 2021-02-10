#include "dictionary.hpp"
using namespace std;

int main()
{
    vector<pair<string, string>> arquivosStats;

    string path;
    vector<string> lines;
    while (true)
    {
        string opt;
        cout << "DICTIONARY MANIPULATOR HACK" << endl;
        cout << "Select an option:" << endl;
        cout << "1. Open Dictiona" << endl;
        cout << "2. Search Substrings" << endl;
        cout << "3. Remove Words Containing Substring" << endl;
        cout << "4. Show Statistics" << endl;
        cout << "5. Exit" << endl
             << endl;
        cout << "Option: ";
        cin >> opt;
        if (opt == "1")
        {
            cout << "Enter a dictionary file: ";
            cin >> path;
            lines.clear();
            if (!loadDictionary(path, lines, arquivosStats))
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
            vector<string> substrings = serchSubstring(search, lines);
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
            removeSubstringLine(path, search, lines, arquivosStats);
            continue;
        }
        if (opt == "4")
        {
            cout << "Statistics:" << endl;
            for (int i = 0; i < arquivosStats.size(); i++)
            {
                cout << arquivosStats[i].first << " -> " << arquivosStats[i].second << endl;
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