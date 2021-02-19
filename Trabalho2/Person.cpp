#include "Person.hpp"

bool loadDatabase(string path, vector<PersonPF> &listPF, vector<PersonPJ> &listPJ)
{
    ifstream freader(path);
    if (!freader.is_open())
    {
        ofstream fWritter(path);
        return false;
    }
    string tmp;
    while (getline(freader, tmp))
    {
        if (tmp == "1")
        {
            PersonPF p;
            getline(freader, tmp);
            p.nome = tmp;
            getline(freader, tmp);
            p.nomeMae = tmp;
            getline(freader, tmp);
            p.cpf = tmp;
            getline(freader, tmp);
            p.endereco = tmp;
            getline(freader, tmp);
            p.telefone = tmp;
            listPF.push_back(p);
        }
        if (tmp == "2")
        {
            PersonPJ p;
            getline(freader, tmp);
            p.razaoSocial = tmp;
            getline(freader, tmp);
            p.cnpj = tmp;
            getline(freader, tmp);
            p.endereco = tmp;
            getline(freader, tmp);
            p.telefone = tmp;
            getline(freader, tmp);
            p.capitalSocial = atoi(tmp.c_str());
            listPJ.push_back(p);
        }
    }
    return true;
}
bool saveDatabase(string path, const vector<PersonPF> &listPF, const vector<PersonPJ> &listPJ)
{

    ofstream fWriter(path);
    if (!fWriter.is_open())
    {
        cout << "ERRO AO SALVAR" << endl;
    }

    for (PersonPF p : listPF)
    {
        fWriter << "1" << endl;
        fWriter << p.nome << endl;
        fWriter << p.nomeMae << endl;
        fWriter << p.cpf << endl;
        fWriter << p.endereco << endl;
        fWriter << p.telefone << endl;
    }

    for (PersonPJ p : listPJ)
    {
        fWriter << "2" << endl;
        fWriter << p.razaoSocial << endl;
        fWriter << p.cnpj << endl;
        fWriter << p.endereco << endl;
        fWriter << p.telefone << endl;
        fWriter << p.capitalSocial << endl;
    }
    fWriter.close();
    return true;
}
bool removeFromPF(string t, vector<PersonPF> &listPF)
{
    if (atoi(t.c_str()) > (listPF.size() - 1) || listPF.size() == 0)
        return false;
    listPF.erase(listPF.begin() + atoi(t.c_str()));
    return true;
}
bool removeFromPJ(string t, vector<PersonPJ> &listPJ)
{
    if (atoi(t.c_str()) > (listPJ.size() - 1) || listPJ.size() == 0)
        return false;
    listPJ.erase(listPJ.begin() + atoi(t.c_str()));
    return true;
}
bool ordenaNomes(vector<string> &nomes, const vector<PersonPF> &listPF, const vector<PersonPJ> &listPJ)
{
    for (PersonPF p : listPF)
        nomes.push_back(p.nome);
    for (PersonPJ p : listPJ)
        nomes.push_back(p.razaoSocial);
    for (int i = 0; i < nomes.size(); i++)
    {
        for (int j = 0; j < nomes.size(); j++)
        {
            if (i == j)
                continue;
            string a = nomes[i];
            string b = nomes[j];
            transform(a.begin(), a.end(), a.begin(), ::tolower);
            transform(b.begin(), b.end(), b.begin(), ::tolower);
            int cmp = strcmp(a.c_str(), b.c_str());
            if (cmp < 0)
            {
                string tmp = nomes[i];
                nomes[i] = nomes[j];
                nomes[j] = tmp;
            }
        }
    }
    return true;
}