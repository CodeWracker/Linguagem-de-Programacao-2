#ifndef POINT_HPP
#define POINT_HPP

class Point
{
protected:
    int _maximo;
    int _atual;

public:
    Point() : _maximo(1), _atual(1){};
    ~Point(){};

public:
    void setMaximo(int q) { _maximo = q; };
    void operator+=(int q)
    {
        _atual += q;
    }
    void operator-=(int q)
    {
        _atual -= q;
    }
};

#endif