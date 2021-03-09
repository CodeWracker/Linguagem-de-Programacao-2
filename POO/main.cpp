#include "Dictionary.hpp"

int main()
{

    vector<Dictionary> myDictionaries; // [{ path, [linhas]}]

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
            Dictionary myDict;
            if (!myDict.LoadDictionary(path))
            {
                if (NDEBUG)
                    cout << "Error, File Not Found";
                continue;
            }
            myDictionaries.push_back(myDict);

            continue;
        }
        if (opt == "2")
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

            continue;
        }
        if (opt == "3")
        {
            if (NDEBUG)
                cout << "Enter a substring to remove all occurrences: ";
            string search;
            cin >> search;
            for (size_t i = 0; i < myDictionaries.size(); i++)
                if (myDictionaries.at(i).RemoveSubstringLine(search))
                    if (NDEBUG)
                        cout << "Removed" << endl;
            continue;
        }
        if (opt == "4")
        {
            cout << "Statistics:" << endl;
            for (Dictionary myDict : myDictionaries)
            {
                cout << myDict.GetPath() << " -> " << myDict.GetSize() << " words" << endl;
            }

            continue;
        }
        if (opt == "5")

            break;
    }
    return 0;
}