#ifndef EMP_HPP
#define EMP_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

class Empregado
{
private:
    string _nome;

protected:
    float _salario;

public:
    string getNome() { return _nome; };
    float getSalario() { return _salario; };
    void setNome(string n) { _nome = n; };
    void setSalario(float s) { _salario = s; };
    string toString()
    {
        stringstream s;
        s.precision(2);
        s << "Nome: " << _nome << "; Salario: " << fixed << _salario;
        return s.str();
    };
    string toString(size_t precision)
    {
        stringstream s;
        s.precision(precision);
        s << "Nome: " << _nome << "; Salario: " << fixed << _salario;
        return s.str();
    };

public:
    Empregado() : _nome("NONAME"), _salario(0){};
    Empregado(string nome) : _salario(0) { _nome = nome; };
    Empregado(float v) : _nome("NONAME") { _salario = v; };
    Empregado(string n, float v)
    {
        _salario = v;
        _nome = n;
    };
    ~Empregado(){};
};
class Vendedor : public Empregado
{
private:
    float _percentualComissao;

public:
    string toString()
    {
        stringstream s;
        s.precision(2);
        s << "Nome: " << getNome() << "; Salario: " << fixed << _salario << "; Comissao: " << _percentualComissao << " // Salario Com Comissão:" << calculaSalario();
        return s.str();
    };
    string toString(size_t precision)
    {
        stringstream s;
        s.precision(precision);
        s << "Nome: " << getNome() << "; Salario: " << fixed << _salario << "; Comissao: " << _percentualComissao << " // Salario Com Comissão:" << calculaSalario();
        return s.str();
    };
    float calculaSalario()
    {
        return (1 + _percentualComissao / 100) * _salario;
    }

public:
    Vendedor()
    {
        setNome("NONAME");
        _salario = 0;
    };
    Vendedor(string nome)
    {
        setNome(nome);
        _salario = 0;
    };
    Vendedor(float v)
    {
        _salario = v;
        setNome("NONAME");
    };
    Vendedor(string n, float v)
    {
        _salario = v;
        setNome(n);
    };
    Vendedor(string n, float v, float c)
    {
        _salario = v;
        setNome(n);
        _percentualComissao = c;
    };
    ~Vendedor(){};
    float getComissao() { return _percentualComissao; };
    void setComissao(float c) { _percentualComissao = c; };
};
class Gerente : public Empregado
{
private:
    string _departamento;

public:
    string getDepartamento() { return _departamento; };
    void setDepartamento(string d) { _departamento = d; };
    Gerente()
    {
        setNome("NONAME");
        _salario = 0;
    };
    Gerente(string nome)
    {
        setNome(nome);
        _salario = 0;
    };
    Gerente(float v)
    {
        _salario = v;
        setNome("NONAME");
    };
    Gerente(string n, float v)
    {
        _salario = v;
        setNome(n);
    };
    Gerente(string n, float v, string d)
    {
        _salario = v;
        setNome(n);
        _departamento = d;
    };
    ~Gerente(){};

public:
    string toString()
    {
        stringstream s;
        s.precision(2);
        s << "Nome: " << getNome() << "; Salario: " << fixed << _salario << "; Departamento: " << _departamento;
        return s.str();
    };
    string toString(size_t precision)
    {
        stringstream s;
        s.precision(precision);
        s << "Nome: " << getNome() << "; Salario: " << fixed << _salario << "; Departamento: " << _departamento;
        return s.str();
    };
};
#endif