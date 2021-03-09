#include "Dictionary.hpp"
#include "Choices.hpp"

#include <map>

int main()
{
    typedef void (*funcP)(vector<Dictionary> &myDictionaries);
    map<char, funcP> optionMap;
    optionMap['1'] = load;
    optionMap['2'] = searchSubstring;
    optionMap['3'] = removeSubstring;
    optionMap['4'] = showStats;

    vector<Dictionary> myDictionaries;

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
        char opt;
        if (NDEBUG)
            cout << "Option: ";
        cin >> opt;

        if (opt == '5')
            break;
        else
            (*optionMap[opt])(myDictionaries);
    }
    return 0;
}