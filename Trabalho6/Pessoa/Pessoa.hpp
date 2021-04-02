#ifndef PESSOA_HPP
#define PESSOA_HPP
#include "../SerVivo/SerVivo.hpp"
#include <vector>
#include "../Item/GenericItem.hpp"

class Pessoa : public SerVivo
{
protected:
    string _nome;
    vector<GenericItem *> _mochila;
    size_t _dinheiro;
    size_t _pontos;
    size_t _nivel;
    size_t _xp;

public:
    Pessoa();
    Pessoa(string nome, size_t dinheiro);
    ~Pessoa();

public:
    size_t getPontos() { return _pontos; };
    void depositar(size_t q) { _dinheiro += q; };
    bool gastar(size_t q)
    {
        if (q > _dinheiro)
            return false;
        _dinheiro -= q;
        return true;
    };
    bool upar(string atr, size_t qnt);
    void push_bag(GenericItem *i)
    {
        _mochila.push_back(i);
    };
    string getNome() { return _nome; }
    string str();
    string bagToStr();
    size_t getDinheiro() { return _dinheiro; };
    GenericItem *pop_bag(size_t i)
    {
        if (i >= _mochila.size())
            return nullptr;
        GenericItem *it = _mochila.at(i);
        _mochila.erase(_mochila.begin() + i);
        return it;
    }
    void operator+(size_t q)
    {
        _xp += q;
        if (_xp >= 2 * _nivel)
        {
            _xp -= 2 * _nivel;
            _nivel++;

            if (NDEBUG)
                cout << "Voce Passou de nível!!" << endl;
            _pontos += 3;
        }
    }
    bool equipar(size_t n);

    size_t getNivel()
    {
        return _nivel;
    }
    string resumo();
    void rest() { _sp.recover(); }
};

#endif