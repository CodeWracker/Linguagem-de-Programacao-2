#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstring>

using namespace std;

struct PersonPF
{
    string nome;
    string nomeMae;
    string cpf;
    string endereco;
    string telefone;
};

struct PersonPJ
{
    string razaoSocial;
    string cnpj;
    string endereco;
    string telefone;
    size_t capitalSocial;
};

bool loadDatabase(string path, vector<PersonPF> &listPF, vector<PersonPJ> &listPJ);
bool saveDatabase(string path, const vector<PersonPF> &listPF, const vector<PersonPJ> &listPJ);
bool removeFromPF(string t, vector<PersonPF> &listPF);
bool removeFromPJ(string t, vector<PersonPJ> &listPJ);
bool ordenaNomes(vector<string> &nomes, const vector<PersonPF> &listPF, const vector<PersonPJ> &listPJ);
#endif