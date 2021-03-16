#ifndef GENERIC_HPP
#define GENERIC_HPP

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
enum DataType
{
    tnone,
    tint,
    tfloat,
    tdouble,
    tchar,
    tstring,
    tpoint2d,
    tpoint3d
};

class Point2d
{
public:
    float m_x, m_y;
    Point2d(float x, float y) : m_x(x), m_y(y){};
};
class Point3d
{
public:
    float m_x, m_y, m_z;
    Point3d(float x, float y, float z) : m_x(x), m_y(y), m_z(z){};
};

class GenericElement
{
private:
    void *m_data;
    DataType m_dataType;

public:
    GenericElement();
    GenericElement(int v);
    GenericElement(float v);
    GenericElement(double v);
    GenericElement(char v);
    GenericElement(string v);
    GenericElement(Point2d v);
    GenericElement(Point3d v);

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