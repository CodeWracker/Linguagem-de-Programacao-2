#include "Generic.hpp"

GenericElement::GenericElement()
{
    m_data = NULL;
    m_dataType = tnone;
};
GenericElement::GenericElement(int v)
{
    m_data = new int(v);
    m_dataType = tint;
}
GenericElement::GenericElement(float v)
{
    m_data = new float(v);
    m_dataType = tfloat;
}
GenericElement::GenericElement(double v)
{
    m_data = new double(v);
    m_dataType = tdouble;
}
GenericElement::GenericElement(char v)
{
    m_data = new char(v);
    m_dataType = tchar;
}
GenericElement::GenericElement(string v)
{
    m_data = new string(v);
    m_dataType = tstring;
}
GenericElement::GenericElement(Point2d v)
{
    m_data = new Point2d(v);
    m_dataType = tpoint2d;
}
GenericElement::GenericElement(Point3d v)
{
    m_data = new Point3d(v);
    m_dataType = tpoint3d;
}