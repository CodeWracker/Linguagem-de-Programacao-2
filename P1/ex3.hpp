#include <string>
using namespace std;
class Moradia
{
protected:
    string _nomeDaRua;
    int _numero;
};
class Apartamento : public Moradia
{
protected:
    int _andar, _numeroApto;
    ;
    char _bloco;
};