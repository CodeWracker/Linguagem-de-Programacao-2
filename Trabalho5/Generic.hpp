#ifndef GENERIC_HPP
#define GENERIC_HPP

#include "Shapes.hpp"
#include <sstream>
#include <map>
#include <iomanip>
#include <cfenv>

enum DataType
{
    tnone,
    tcircle,
    tsquare,
    ttriangle,
    tsphere,
    ttetrahedron,
    tcube
};

class GenericElement
{

private:
    void *m_data;
    DataType m_dataType;

public:
    GenericElement();
    GenericElement(Circle v);
    GenericElement(Square v);
    GenericElement(Triangle v);
    GenericElement(Sphere v);
    GenericElement(Tetrahedron v);
    GenericElement(Cube v);

public:
    string ShowInfo()
    {
        stringstream saida;
        //fesetround(FE_DOWNWARD);
        if (m_dataType == tnone)
            saida << " -> "
                  << "NULL";
        if (m_dataType == tcircle)
            saida << "circle -> " << setprecision(2) << fixed << ((Circle *)m_data)->CalcArea();
        if (m_dataType == tsquare)
            saida << "square -> " << setprecision(2) << fixed << ((Square *)m_data)->CalcArea();
        if (m_dataType == ttriangle)
            saida << "triangle -> " << setprecision(2) << fixed << ((Triangle *)m_data)->CalcArea();
        if (m_dataType == tsphere)
            saida << "sphere -> " << setprecision(2) << fixed << ((Sphere *)m_data)->CalcArea();
        if (m_dataType == ttetrahedron)
            saida << "tetrahedron -> " << setprecision(2) << fixed << ((Tetrahedron *)m_data)->CalcArea();
        if (m_dataType == tcube)
            saida << "cube -> " << setprecision(2) << fixed << ((Cube *)m_data)->CalcArea();

        return saida.str();
    };
};

#endif