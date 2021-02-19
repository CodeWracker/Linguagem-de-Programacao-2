#define inDebug false

#include "Person.hpp"

int main()
{

    vector<PersonPF> listPF;
    vector<PersonPJ> listPJ;

    if (!loadDatabase("database.dat", listPF, listPJ))
    {
        if (inDebug)
            cout << "Database could not be found. Creating one" << endl;
    }

    if (inDebug)
        cout << "MY PAPA'S COMPANY - SIG" << endl;
    if (inDebug)
        cout << "1. Add PF..." << endl;
    if (inDebug)
        cout << "2. Add PJ..." << endl;
    if (inDebug)
        cout << "3. Remove PF Index..." << endl;
    if (inDebug)
        cout << "4. Remove PJ Index..." << endl;
    if (inDebug)
        cout << "5. Print Names in Ascending Order" << endl;
    if (inDebug)
        cout << "6. Exit" << endl;

    while (1)
    {
        saveDatabase("database.dat", listPF, listPJ);
        if (inDebug)
            cout
                << "Enter an option : ";
        char ch;
        cin >> ch;

        //fflush();
        cin.ignore();
        if (ch == '1')
        {
            PersonPF p;
            if (inDebug)
                cout << "Digite os dados da pessoa (Nome, Mãe, CPF, endereco, telefone)" << endl;
            getline(cin, p.nome);
            getline(cin, p.nomeMae);
            getline(cin, p.cpf);
            getline(cin, p.endereco);
            getline(cin, p.telefone);

            listPF.push_back(p);
            continue;
        }
        if (ch == '2')
        {
            PersonPJ p;
            if (inDebug)
                cout << "Digite os dados da pessoa juridica (Nome, Mãe, CPF, endereco, telefone)" << endl;
            getline(cin, p.razaoSocial);
            getline(cin, p.cnpj);
            getline(cin, p.endereco);
            getline(cin, p.telefone);
            cin >> p.capitalSocial;

            listPJ.push_back(p);
            continue;
        }
        if (ch == '3')
        {
            string t;
            if (inDebug)
                if (inDebug)
                    cout << "Digite o numero a ser deletado da Pessoa Fisica: ";
            cin >> t;
            if (!removeFromPF(t, listPF))
                if (inDebug)
                    cout << "ERRO: IMPOSSIVEL EXCLUIR, INDICE INVALIDO" << endl;

            continue;
        }

        if (ch == '4')
        {
            string t;
            if (inDebug)
                if (inDebug)
                    cout << "Digite o numero a ser deletado da Pessoa Juridica: ";
            cin >> t;
            if (!removeFromPJ(t, listPJ))
                if (inDebug)
                    cout << "ERRO: IMPOSSIVEL EXCLUIR, INDICE INVALIDO" << endl;

            continue;
        }
        if (ch == '5')
        {

            cout << "Names in Ascending Order: " << endl;
            vector<string> nomes;
            ordenaNomes(nomes, listPF, listPJ);
            for (string nome : nomes)
            {
                cout << nome << endl;
            }
            continue;
        }
        if (ch == '6')
        {
            break;
        }
    }

    return 0;
}