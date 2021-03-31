#ifndef STATS_HPP
#define STATS_HPP
#include <iostream>
#include <sstream>
using namespace std;
class Stats
{
protected:
    int _forca;
    int _constituicao;
    int _destreza;

public:
    Stats() : _forca(1), _constituicao(1), _destreza(1){};
    ~Stats(){};

public:
    void setFor(int q) { _forca += q; };

    void setCon(int q) { _constituicao += q; };

    void setDex(int q) { _destreza += q; };

    string str()
    {
        stringstream s;
        s << "FOR: " << _forca << " // CON: " << _constituicao << " // DEX: " << _destreza;
        return s.str();
    }
};

#endif