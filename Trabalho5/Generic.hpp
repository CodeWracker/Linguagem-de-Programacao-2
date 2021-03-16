#ifndef GENERIC_HPP
#define GENERIC_HPP

#include "Shapes.hpp"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
enum DataType
{
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
    GenericElement(){};
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
        saida << "DataType is: " << m_dataType;
        if (m_dataType == tnone)
            saida << " -> "
                  << "NULL";
        if (m_dataType == tint)
            saida << " -> " << *((int *)m_data);
        if (m_dataType == tfloat)
            saida << " -> " << *((float *)m_data);
        if (m_dataType == tdouble)
            saida << " -> " << *((double *)m_data);
        if (m_dataType == tchar)
            saida << " -> " << *((char *)m_data);
        if (m_dataType == tstring)
            saida << " -> " << *((string *)m_data);
        if (m_dataType == tpoint2d)
            saida << " -> " << ((Point2d *)m_data)->m_x << " - " << ((Point2d *)m_data)->m_y;
        if (m_dataType == tpoint3d)
            saida << " -> " << ((Point3d *)m_data)->m_x << " - " << ((Point3d *)m_data)->m_y << " - " << ((Point3d *)m_data)->m_z;
        return saida.str();
    };
};

#endif