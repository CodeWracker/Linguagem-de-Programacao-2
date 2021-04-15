#include <iostream>
#include "EstruturaDados.hpp"
#define NDEBUG 1
int main()
{
    EstruturaDados *data = new EstruturaDados();
    if (NDEBUG)
    {
        cout << "1. Inserir um número -> Pilha" << endl;
        cout << "2. Inserir um número -> Fila" << endl;
        cout << "3. Remover um número -> Pilha" << endl;
        cout << "4. Remover um número -> Fila" << endl;
        cout << "5. Imprimir indice e valor numero" << endl;
        cout << "6. Sair do Sistema" << endl;
    }
    while (1)
    {

        string c;
        cin >> c;
        if (c == "2" || c == "1")
        {
            if (NDEBUG)
                cout << "Digite o numero a ser adicionado" << endl;
            cin >> c;

            data->adicionar(atoi(c.c_str()));

            continue;
        }
        if (c == "3")
        {
            Pilha p(*data);
            p.remover();
            *data = p;
            continue;
        }
        if (c == "4")
        {
            Fila f(data->getVector());
            f.remover();
            *data = f;
            continue;
        }
        if (c == "5")
        {
            vector<int> l = data->getVector();
            for (int i = 0; i < l.size(); i++)
            {
                cout << "Posição " << i << " -> " << l.at(i) << endl;
            }
            continue;
        }
        if (c == "6")
            break;
    }
    delete data;
    return 0;
}