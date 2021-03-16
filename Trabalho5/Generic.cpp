#include "Generic.hpp"
#include "Shapes.hpp"
GenericElement::GenericElement()
{
    m_data = NULL;
    m_dataType = tnone;
};
GenericElement::GenericElement(Circle v)
{
    m_dataType = tcircle;
    m_data = new Circle(v);
}
GenericElement::GenericElement(Square v)
{
    m_dataType = tsquare;
    m_data = new Square(v);
}
GenericElement::GenericElement(Triangle v)
{
    m_dataType = ttriangle;
    m_data = new Triangle(v);
}
GenericElement::GenericElement(Sphere v)
{
    m_dataType = tsphere;
    m_data = new Sphere(v);
}
GenericElement::GenericElement(Tetrahedron v)
{
    m_dataType = ttetrahedron;
    m_data = new Tetrahedron(v);
}
GenericElement::GenericElement(Cube v)
{
    m_dataType = tcube;
    m_data = new Cube(v);
}